//FormAI DATASET v1.0 Category: Product Inventory System ; Style: irregular
/* Product Inventory System */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
    char name[50];
    int qty;
    float price;
};

int main() {

    struct Product inventory[50];
    int count = 0;
    int menu_choice = 0;

    printf("+=== PRODUCT INVENTORY SYSTEM ===+\n\n");

    while (menu_choice != 4) {
        printf("1. Add a product\n");
        printf("2. Display product inventory\n");
        printf("3. Remove a product\n");
        printf("4. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &menu_choice);

        switch (menu_choice) {
            case 1:
                printf("\nADD A PRODUCT\n");
                printf("===============\n");

                if (count < 50) {
                    printf("Enter product name: ");
                    scanf("%s", inventory[count].name);

                    printf("Enter product quantity: ");
                    scanf("%d", &inventory[count].qty);

                    printf("Enter product price: ");
                    scanf("%f", &inventory[count].price);

                    count++;

                    printf("\nPRODUCT ADDED SUCCESSFULLY\n\n");
                } else {
                    printf("\nINVENTORY FULL\n\n");
                }

                break;

            case 2:
                printf("\nPRODUCT INVENTORY\n");
                printf("===================\n");

                if (count == 0) {
                    printf("\nINVENTORY EMPTY\n\n");
                } else {
                    for (int i = 0; i < count; i++) {
                        printf("%d. %s - %d pcs. @ Php %.2f\n", i + 1, inventory[i].name, inventory[i].qty, inventory[i].price);
                    }
                    printf("\n");
                }

                break;

            case 3:
                printf("\nREMOVE A PRODUCT\n");
                printf("==================\n");

                if (count == 0) {
                    printf("\nINVENTORY EMPTY\n\n");
                } else {
                    char product_name[50];
                    int product_index = -1;

                    printf("Enter product name to remove: ");
                    scanf("%s", product_name);

                    for (int i = 0; i < count; i++) {
                        if (strcmp(product_name, inventory[i].name) == 0) {
                            product_index = i;
                            break;
                        }
                    }

                    if (product_index != -1) {
                        for (int i = product_index; i < count - 1; i++) {
                            strcpy(inventory[i].name, inventory[i + 1].name);
                            inventory[i].qty = inventory[i + 1].qty;
                            inventory[i].price = inventory[i + 1].price;
                        }

                        count--;

                        printf("\nPRODUCT REMOVED SUCCESSFULLY\n\n");
                    } else {
                        printf("\nPRODUCT NOT FOUND\n\n");
                    }
                }

                break;

            case 4:
                printf("\nDATA SAVED\nGOODBYE!\n");
                break;

            default:
                printf("\nINVALID CHOICE\n\n");
                break;
        }
    }

    return 0;
}