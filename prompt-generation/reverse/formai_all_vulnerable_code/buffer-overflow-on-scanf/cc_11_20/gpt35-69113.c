//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int quantity;
    float cost;
} Item;

typedef struct {
    int item_id;
    Item item_details;
} Warehouse;

int main() {
    printf("Welcome to the Warehouse Management System!\n");
    printf("Please choose an option from the following menu:\n");
    printf("1. Add item to warehouse\n");
    printf("2. Remove item from warehouse\n");
    printf("3. Update item quantity\n");
    printf("4. Show item details\n");
    printf("5. Quit program\n");

    Warehouse warehouse[50];
    int num_items = 0;

    char choice;
    do {
        printf("\nEnter your choice: ");
        scanf("%c", &choice);
        getchar();

        switch (choice) {
            case '1': {
                printf("\nEnter item name: ");
                char name[20];
                scanf("%s", &name);
                getchar();

                printf("Enter item quantity: ");
                int quantity;
                scanf("%d", &quantity);
                getchar();

                printf("Enter item cost: ");
                float cost;
                scanf("%f", &cost);
                getchar();

                Item new_item = {name, quantity, cost};
                Warehouse new_warehouse_item = {num_items, new_item};
                warehouse[num_items] = new_warehouse_item;
                num_items++;

                printf("\nItem added successfully!\n");
                break;
            }
            case '2': {
                printf("\nEnter item ID to remove: ");
                int item_id;
                scanf("%d", &item_id);
                getchar();

                for (int i = 0; i < num_items; i++) {
                    if (warehouse[i].item_id == item_id) {
                        for (int j = i; j < num_items - 1; j++) {
                            warehouse[j] = warehouse[j + 1];
                        }
                        num_items--;
                        printf("\nItem removed successfully!\n");
                        break;
                    }
                }
                break;
            }
            case '3': {
                printf("\nEnter item ID to update: ");
                int item_id;
                scanf("%d", &item_id);
                getchar();

                for (int i = 0; i < num_items; i++) {
                    if (warehouse[i].item_id == item_id) {
                        printf("\nEnter updated quantity: ");
                        int quantity;
                        scanf("%d", &quantity);
                        getchar();

                        warehouse[i].item_details.quantity = quantity;

                        printf("\nQuantity updated successfully!\n");
                        break;
                    }
                }
                break;
            }
            case '4': {
                printf("\nEnter item ID to show details: ");
                int item_id;
                scanf("%d", &item_id);
                getchar();

                for (int i = 0; i < num_items; i++) {
                    if (warehouse[i].item_id == item_id) {
                        printf("\nItem ID: %d\n", warehouse[i].item_id);
                        printf("Item name: %s\n", warehouse[i].item_details.name);
                        printf("Item quantity: %d\n", warehouse[i].item_details.quantity);
                        printf("Item cost: %0.2f\n", warehouse[i].item_details.cost);
                        break;
                    }
                }
                break;
            }
            case '5': {
                printf("\nExiting program...");
                exit(0);
            }
            default: {
                printf("\nInvalid choice. Please choose again.\n");
                break;
            }
        }
    } while (choice != '5');

    return 0;
}