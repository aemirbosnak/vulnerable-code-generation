//Falcon2-11B DATASET v1.0 Category: Product Inventory System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

struct product {
    char name[50];
    int quantity;
};

struct product products[MAX_ITEMS];

int main() {
    int item_index = 0;

    printf("Product Inventory System\n");
    printf("------------------------\n");

    while (1) {
        printf("Please select an option:\n");
        printf("1. Add a product\n");
        printf("2. Remove a product\n");
        printf("3. Display the inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the product: ");
                scanf("%s", products[item_index].name);
                printf("Enter the quantity of the product: ");
                scanf("%d", &products[item_index].quantity);
                break;

            case 2:
                printf("Enter the name of the product to remove: ");
                scanf("%s", products[item_index].name);
                for (int i = item_index; i < MAX_ITEMS; i++) {
                    if (strcmp(products[i].name, products[item_index].name) == 0) {
                        for (int j = i; j < MAX_ITEMS - 1; j++) {
                            products[j] = products[j + 1];
                        }
                        break;
                    }
                }
                item_index--;
                break;

            case 3:
                printf("The inventory is:\n");
                for (int i = 0; i < MAX_ITEMS; i++) {
                    printf("Name: %s\nQuantity: %d\n", products[i].name, products[i].quantity);
                }
                break;

            case 4:
                printf("Thank you for using the product inventory system!\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}