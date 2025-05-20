//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    int id;
    int quantity;
    float price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int item_count;
} Warehouse;

void initialize_warehouse(Warehouse *warehouse) {
    warehouse->item_count = 0;
}

void add_item(Warehouse *warehouse) {
    if (warehouse->item_count >= MAX_ITEMS) {
        printf("Warehouse is full! Cannot add more items.\n");
        return;
    }
    
    Item new_item;
    printf("Enter item ID: ");
    scanf("%d", &new_item.id);
    printf("Enter item name: ");
    getchar(); // consume newline
    fgets(new_item.name, sizeof(new_item.name), stdin);
    new_item.name[strcspn(new_item.name, "\n")] = 0; // remove newline
    printf("Enter item quantity: ");
    scanf("%d", &new_item.quantity);
    printf("Enter item price: ");
    scanf("%f", &new_item.price);
    
    warehouse->items[warehouse->item_count++] = new_item;
    printf("Item added successfully!\n");
}

void display_items(const Warehouse *warehouse) {
    if (warehouse->item_count == 0) {
        printf("Warehouse is empty.\n");
        return;
    }
    
    printf("Items in the warehouse:\n");
    for (int i = 0; i < warehouse->item_count; i++) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n",
               warehouse->items[i].id,
               warehouse->items[i].name,
               warehouse->items[i].quantity,
               warehouse->items[i].price);
    }
}

void update_item(Warehouse *warehouse) {
    int id;
    printf("Enter item ID to update: ");
    scanf("%d", &id);
    
    for (int i = 0; i < warehouse->item_count; i++) {
        if (warehouse->items[i].id == id) {
            printf("Current details - Name: %s, Quantity: %d, Price: %.2f\n",
                   warehouse->items[i].name,
                   warehouse->items[i].quantity,
                   warehouse->items[i].price);
            printf("Enter new quantity: ");
            scanf("%d", &warehouse->items[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &warehouse->items[i].price);
            printf("Item updated successfully!\n");
            return;
        }
    }
    printf("Item with ID %d not found.\n", id);
}

void delete_item(Warehouse *warehouse) {
    int id;
    printf("Enter item ID to delete: ");
    scanf("%d", &id);
    
    for (int i = 0; i < warehouse->item_count; i++) {
        if (warehouse->items[i].id == id) {
            for (int j = i; j < warehouse->item_count - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->item_count--;
            printf("Item deleted successfully!\n");
            return;
        }
    }
    printf("Item with ID %d not found.\n", id);
}

void menu() {
    printf("\nWarehouse Management System\n");
    printf("1. Add Item\n");
    printf("2. Display Items\n");
    printf("3. Update Item\n");
    printf("4. Delete Item\n");
    printf("5. Exit\n");
}

int main() {
    Warehouse warehouse;
    initialize_warehouse(&warehouse);
    
    int choice;
    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_item(&warehouse);
                break;
            case 2:
                display_items(&warehouse);
                break;
            case 3:
                update_item(&warehouse);
                break;
            case 4:
                delete_item(&warehouse);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}