//Falcon2-11B DATASET v1.0 Category: Product Inventory System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

typedef struct item {
    char name[MAX_NAME_LENGTH];
    int quantity;
} Item;

int main() {
    Item items[MAX_ITEMS];
    int numItems = 0;

    int menuChoice = 0;
    int itemID = 0;

    while (1) {
        printf("Product Inventory System\n");
        printf("--------------------------\n");
        printf("1. Add a new item\n");
        printf("2. Update an existing item\n");
        printf("3. Delete an existing item\n");
        printf("4. List all items\n");
        printf("5. Exit\n");
        printf("--------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &menuChoice);

        switch (menuChoice) {
            case 1: {
                printf("Enter item name: ");
                fgets(items[numItems].name, MAX_NAME_LENGTH, stdin);
                items[numItems].quantity = 0;
                numItems++;
                break;
            }
            case 2: {
                printf("Enter item name: ");
                fgets(items[itemID].name, MAX_NAME_LENGTH, stdin);
                printf("Enter new quantity: ");
                scanf("%d", &items[itemID].quantity);
                break;
            }
            case 3: {
                printf("Enter item name: ");
                fgets(items[itemID].name, MAX_NAME_LENGTH, stdin);
                printf("Enter new quantity: ");
                scanf("%d", &items[itemID].quantity);
                break;
            }
            case 4: {
                if (numItems > 0) {
                    printf("Items:\n");
                    for (int i = 0; i < numItems; i++) {
                        printf("Item %d: %s - %d\n", i+1, items[i].name, items[i].quantity);
                    }
                } else {
                    printf("No items added yet.\n");
                }
                break;
            }
            case 5: {
                exit(0);
            }
            default: {
                printf("Invalid choice. Try again.\n");
            }
        }
    }

    return 0;
}