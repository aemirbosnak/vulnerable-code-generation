//MISTRAL-7B DATASET v1.0 Category: Warehouse Management System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WAREHOUSE_SIZE 100
#define MAX_ITEM_NAME_LENGTH 50

typedef struct {
    char name[MAX_ITEM_NAME_LENGTH];
    int stock;
} Item;

typedef struct {
    Item items[MAX_WAREHOUSE_SIZE];
    int current_size;
} Warehouse;

void print_menu() {
    printf("1. Add item to warehouse\n");
    printf("2. Remove item from warehouse\n");
    printf("3. Check stock of an item\n");
    printf("4. Display all items in warehouse\n");
    printf("5. Quit\n");
}

int main() {
    Warehouse my_warehouse = {.current_size = 0};
    int choice = 0;
    char item_name[MAX_ITEM_NAME_LENGTH];
    int quantity = 0;

    while (choice != 5) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", item_name);
                printf("Enter item stock: ");
                scanf("%d", &quantity);

                if (my_warehouse.current_size >= MAX_WAREHOUSE_SIZE) {
                    printf("Warehouse is full.\n");
                    continue;
                }

                strcpy(my_warehouse.items[my_warehouse.current_size].name, item_name);
                my_warehouse.items[my_warehouse.current_size].stock = quantity;
                my_warehouse.current_size++;
                printf("Item added successfully.\n");
                break;
            case 2:
                printf("Enter item name: ");
                scanf("%s", item_name);

                for (int i = 0; i < my_warehouse.current_size; i++) {
                    if (strcmp(my_warehouse.items[i].name, item_name) == 0) {
                        my_warehouse.items[i].stock--;
                        printf("Item stock updated.\n");
                        goto next;
                    }
                }

                printf("Item not found.\n");
                break;
            case 3:
                printf("Enter item name: ");
                scanf("%s", item_name);

                for (int i = 0; i < my_warehouse.current_size; i++) {
                    if (strcmp(my_warehouse.items[i].name, item_name) == 0) {
                        printf("Stock of item %s: %d\n", item_name, my_warehouse.items[i].stock);
                        goto next;
                    }
                }

                printf("Item not found.\n");
                break;
            case 4:
                printf("Items in warehouse:\n");
                for (int i = 0; i < my_warehouse.current_size; i++) {
                    printf("%s: %d\n", my_warehouse.items[i].name, my_warehouse.items[i].stock);
                }
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    next: {}
    }

    return 0;
}