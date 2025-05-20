//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct inventory {
    char item_name[50];
    int item_id;
    int item_quantity;
    float item_cost;
} inventory;

void display_menu() {
    printf("\n\n---WAREHOUSE MANAGEMENT SYSTEM---\n");
    printf("1. Add New Item to Inventory\n");
    printf("2. View Inventory\n");
    printf("3. Edit Quantity of an Item\n");
    printf("4. Remove Item from Inventory\n");
    printf("5. Exit\n");
}

void add_item(inventory items[], int *num_items) {
    printf("Enter item name: ");
    scanf("%s", items[*num_items].item_name);
    printf("Enter item ID: ");
    scanf("%d", &items[*num_items].item_id);
    printf("Enter item quantity: ");
    scanf("%d", &items[*num_items].item_quantity);
    printf("Enter item cost: ");
    scanf("%f", &items[*num_items].item_cost);
    (*num_items)++;
    printf("\nItem added successfully!\n\n");
}

void view_inventory(inventory items[], int num_items) {
    printf("\n\n---CURRENT INVENTORY---\n");
    printf("%-20s%-10s%-10s%s\n", "Item Name", "Item ID", "Quantity", "Cost");
    for (int i = 0; i < num_items; i++) {
        printf("%-20s%-10d%-10d$%.2f\n", items[i].item_name, items[i].item_id, items[i].item_quantity, items[i].item_cost);
    }
    printf("\n");
}

void edit_quantity(inventory items[], int num_items) {
    int id;
    printf("Enter item ID: ");
    scanf("%d", &id);
    for (int i = 0; i < num_items; i++) {
        if (items[i].item_id == id) {
            printf("Enter new quantity: ");
            scanf("%d", &items[i].item_quantity);
            printf("\nQuantity updated successfully!\n\n");
            return;
        }
    }
    printf("\nItem not found.\n\n");
}

void remove_item(inventory items[], int *num_items) {
    int id;
    printf("Enter item ID: ");
    scanf("%d", &id);
    for (int i = 0; i < *num_items; i++) {
        if (items[i].item_id == id) {
            for (int j = i; j < *num_items - 1; j++) {
                items[j] = items[j+1];
            }
            (*num_items)--;
            printf("\nItem removed successfully!\n\n");
            return;
        }
    }
    printf("\nItem not found.\n\n");
}

int main() {
    int choice, num_items = 0, max_items = 100;
    inventory *items = malloc(max_items * sizeof(inventory));

    display_menu();

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_items == max_items) {
                    max_items *= 2;
                    items = realloc(items, max_items * sizeof(inventory));
                }
                add_item(items, &num_items);
                break;
            case 2:
                view_inventory(items, num_items);
                break;
            case 3:
                edit_quantity(items, num_items);
                break;
            case 4:
                remove_item(items, &num_items);
                break;
            case 5:
                free(items);
                exit(0);
            default:
                printf("\nInvalid choice!\n\n");
        }
        display_menu();
    }

    return 0;
}