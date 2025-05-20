//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int quantity;
    double price;
} Item;

Item warehouse[MAX_ITEMS];
int item_count = 0;

void add_item() {
    if (item_count >= MAX_ITEMS) {
        printf("Warehouse is full, cannot add more items.\n");
        return;
    }

    Item new_item;

    printf("Enter item ID: ");
    scanf("%d", &new_item.id);
    printf("Enter item name: ");
    scanf("%s", new_item.name);
    printf("Enter item quantity: ");
    scanf("%d", &new_item.quantity);
    printf("Enter item price: ");
    scanf("%lf", &new_item.price);

    warehouse[item_count++] = new_item;
    printf("Item added successfully!\n");
}

void display_items() {
    if (item_count == 0) {
        printf("No items in the warehouse.\n");
        return;
    }

    printf("\nItems in the warehouse:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("------------------------------------------\n");

    for (int i = 0; i < item_count; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n",
                warehouse[i].id,
                warehouse[i].name,
                warehouse[i].quantity,
                warehouse[i].price);
    }
    printf("------------------------------------------\n");
}

void update_item() {
    int id;
    printf("Enter the ID of the item to update: ");
    scanf("%d", &id);

    for (int i = 0; i < item_count; i++) {
        if (warehouse[i].id == id) {
            printf("Updating item: %s\n", warehouse[i].name);
            printf("Enter new quantity: ");
            scanf("%d", &warehouse[i].quantity);
            printf("Enter new price: ");
            scanf("%lf", &warehouse[i].price);
            printf("Item updated successfully!\n");
            return;
        }
    }
    printf("Item with ID %d not found.\n", id);
}

void delete_item() {
    int id;
    printf("Enter the ID of the item to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < item_count; i++) {
        if (warehouse[i].id == id) {
            for (int j = i; j < item_count - 1; j++) {
                warehouse[j] = warehouse[j + 1];
            }
            item_count--;
            printf("Item deleted successfully!\n");
            return;
        }
    }
    printf("Item with ID %d not found.\n", id);
}

void display_menu() {
    printf("\nWarehouse Management System\n");
    printf("1. Add Item\n");
    printf("2. Display Items\n");
    printf("3. Update Item\n");
    printf("4. Delete Item\n");
    printf("5. Exit\n");
}

int main() {
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                display_items();
                break;
            case 3:
                update_item();
                break;
            case 4:
                delete_item();
                break;
            case 5:
                printf("Exiting the warehouse management system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}