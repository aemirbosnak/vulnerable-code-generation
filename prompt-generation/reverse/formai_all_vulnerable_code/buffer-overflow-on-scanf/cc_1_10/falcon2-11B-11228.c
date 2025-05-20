//Falcon2-11B DATASET v1.0 Category: Warehouse Management System ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

typedef struct item {
    int id;
    char name[50];
    int quantity;
} item;

int main() {
    item items[MAX_ITEMS];
    int num_items = 0;
    int choice;

    printf("Welcome to the Warehouse Management System!\n");

    while (1) {
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Display Inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int id, quantity;
                printf("Enter the item ID: ");
                scanf("%d", &id);

                printf("Enter the item name: ");
                scanf("%s", items[num_items].name);

                printf("Enter the quantity: ");
                scanf("%d", &quantity);

                items[num_items].id = id;
                items[num_items].quantity = quantity;
                num_items++;
                break;
            }
            case 2: {
                int id;
                printf("Enter the item ID to remove: ");
                scanf("%d", &id);

                for (int i = 0; i < num_items; i++) {
                    if (items[i].id == id) {
                        for (int j = i; j < num_items - 1; j++) {
                            items[j] = items[j + 1];
                        }
                        num_items--;
                        break;
                    }
                }
                break;
            }
            case 3: {
                for (int i = 0; i < num_items; i++) {
                    printf("ID: %d, Name: %s, Quantity: %d\n", items[i].id, items[i].name, items[i].quantity);
                }
                break;
            }
            case 4: {
                printf("Exiting the program...\n");
                return 0;
            }
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}