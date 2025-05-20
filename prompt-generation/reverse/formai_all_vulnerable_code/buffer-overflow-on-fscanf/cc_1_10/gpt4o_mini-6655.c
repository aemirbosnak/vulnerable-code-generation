//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    int id;
    char name[30];
    int quantity;
    float price;
} Item;

Item items[MAX_ITEMS];
int itemCount = 0;

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Warehouse is full. Cannot add more items.\n");
        return;
    }
    Item newItem;
    printf("Enter item ID: ");
    scanf("%d", &newItem.id);
    getchar();  // Clear newline character from buffer
    printf("Enter item name: ");
    fgets(newItem.name, sizeof(newItem.name), stdin);
    newItem.name[strcspn(newItem.name, "\n")] = 0;  // Remove newline
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter item price: ");
    scanf("%f", &newItem.price);

    items[itemCount++] = newItem;
    printf("Item added successfully!\n");
}

void viewItems() {
    if (itemCount == 0) {
        printf("No items in warehouse.\n");
        return;
    }
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("-------------------------------------------\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", items[i].id, items[i].name, items[i].quantity, items[i].price);
    }
}

void updateItem() {
    int id, found = 0;
    printf("Enter item ID to update: ");
    scanf("%d", &id);
    for (int i = 0; i < itemCount; i++) {
        if (items[i].id == id) {
            found = 1;
            printf("Updating item %s...\n", items[i].name);
            printf("Enter new quantity: ");
            scanf("%d", &items[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &items[i].price);
            printf("Item updated successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Item with ID %d not found.\n", id);
    }
}

void deleteItem() {
    int id, found = 0;
    printf("Enter item ID to delete: ");
    scanf("%d", &id);
    
    for (int i = 0; i < itemCount; i++) {
        if (items[i].id == id) {
            found = 1;
            for (int j = i; j < itemCount - 1; j++) {
                items[j] = items[j + 1];  // Shift left
            }
            itemCount--;
            printf("Item deleted successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Item with ID %d not found.\n", id);
    }
}

void saveItemsToFile() {
    FILE *file = fopen("items.txt", "w");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }
    for (int i = 0; i < itemCount; i++) {
        fprintf(file, "%d,%s,%d,%.2f\n", items[i].id, items[i].name, items[i].quantity, items[i].price);
    }
    fclose(file);
    printf("Items saved to file successfully!\n");
}

void loadItemsFromFile() {
    FILE *file = fopen("items.txt", "r");
    if (!file) {
        printf("No saved items found!\n");
        return;
    }
    while (fscanf(file, "%d,%30[^,],%d,%f", &items[itemCount].id, items[itemCount].name, &items[itemCount].quantity, &items[itemCount].price) != EOF) {
        itemCount++;
        if (itemCount >= MAX_ITEMS) break; // Prevent overflow
    }
    fclose(file);
    printf("Items loaded from file successfully!\n");
}

int main() {
    int choice;
    loadItemsFromFile();
    
    do {
        printf("\nWarehouse Management System\n");
        printf("1. Add Item\n");
        printf("2. View Items\n");
        printf("3. Update Item\n");
        printf("4. Delete Item\n");
        printf("5. Save Items to File\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addItem(); break;
            case 2: viewItems(); break;
            case 3: updateItem(); break;
            case 4: deleteItem(); break;
            case 5: saveItemsToFile(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}