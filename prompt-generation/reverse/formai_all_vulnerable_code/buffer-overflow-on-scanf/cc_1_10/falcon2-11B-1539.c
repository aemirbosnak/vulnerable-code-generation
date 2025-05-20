//Falcon2-11B DATASET v1.0 Category: Warehouse Management System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

typedef struct item {
    char name[50];
    int quantity;
    double price;
} Item;

typedef struct warehouse {
    Item items[100];
    int num_items;
} Warehouse;

int main() {
    Warehouse warehouse;
    int choice, item_index;

    printf("Welcome to the Warehouse Management System!\n");

    warehouse.num_items = 0;

    while (1) {
        printf("1. Add item\n2. Remove item\n3. Search item\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", warehouse.items[warehouse.num_items].name);

                printf("Enter item quantity: ");
                scanf("%d", &warehouse.items[warehouse.num_items].quantity);

                printf("Enter item price: ");
                scanf("%lf", &warehouse.items[warehouse.num_items].price);

                warehouse.num_items++;
                break;

            case 2:
                printf("Enter item name: ");
                scanf("%s", warehouse.items[item_index].name);

                printf("Enter item quantity: ");
                scanf("%d", &warehouse.items[item_index].quantity);

                printf("Enter item price: ");
                scanf("%lf", &warehouse.items[item_index].price);

                warehouse.num_items--;
                break;

            case 3:
                printf("Enter item name: ");
                scanf("%s", warehouse.items[item_index].name);

                printf("Item found!\n");
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}