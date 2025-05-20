//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define ITEM_NAME_LENGTH 50
#define FILE_NAME "inventory.dat"

typedef struct {
    int id;
    char name[ITEM_NAME_LENGTH];
    int quantity;
    float price;
} Item;

void add_item();
void display_items();
void remove_item();
void load_items();
void save_items();
int find_item_index(int id);

Item inventory[MAX_ITEMS];
int item_count = 0;

void add_item() {
    if (item_count >= MAX_ITEMS) {
        printf("Inventory full! Cannot add more items.\n");
        return;
    }
    Item newItem;
    printf("Enter Item ID: ");
    scanf("%d", &newItem.id);
    getchar(); // Clear input buffer
    printf("Enter Item Name: ");
    fgets(newItem.name, ITEM_NAME_LENGTH, stdin);
    newItem.name[strcspn(newItem.name, "\n")] = 0; // Remove newline
    printf("Enter Item Quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter Item Price: ");
    scanf("%f", &newItem.price);
    inventory[item_count++] = newItem;
    save_items();
    printf("Item added successfully!\n");
}

void display_items() {
    if (item_count == 0) {
        printf("No items in inventory.\n");
        return;
    }
    printf("\nInventory:\n");
    for (int i = 0; i < item_count; i++) {
        printf("ID: %d | Name: %s | Quantity: %d | Price: %.2f\n",
               inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void remove_item() {
    int id;
    printf("Enter Item ID to remove: ");
    scanf("%d", &id);
    int index = find_item_index(id);
    if (index == -1) {
        printf("Item not found!\n");
        return;
    }
    for (int i = index; i < item_count - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    item_count--;
    save_items();
    printf("Item removed successfully!\n");
}

int find_item_index(int id) {
    for (int i = 0; i < item_count; i++) {
        if (inventory[i].id == id) {
            return i;
        }
    }
    return -1;
}

void load_items() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        return; // No previous inventory, returning
    }
    while (fscanf(file, "%d %49s %d %f", 
                  &inventory[item_count].id,
                  inventory[item_count].name,
                  &inventory[item_count].quantity,
                  &inventory[item_count].price) == 4) {
        item_count++;
    }
    fclose(file);
}

void save_items() {
    FILE *file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        printf("Error saving data.\n");
        return;
    }
    for (int i = 0; i < item_count; i++) {
        fprintf(file, "%d %s %d %.2f\n", 
                inventory[i].id,
                inventory[i].name,
                inventory[i].quantity,
                inventory[i].price);
    }
    fclose(file);
}

int main() {
    int choice;
    load_items();
    do {
        printf("\nWarehouse Management System\n");
        printf("1. Add Item\n");
        printf("2. Display Items\n");
        printf("3. Remove Item\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: 
                add_item();
                break;
            case 2: 
                display_items();
                break;
            case 3: 
                remove_item();
                break;
            case 4: 
                printf("Exiting the program.\n");
                break;
            default: 
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}