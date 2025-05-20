//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 1000

struct product {
    char name[MAX_NAME_LENGTH];
    int quantity;
};

int main() {
    int choice;
    struct product products[MAX_PRODUCTS];
    int num_products = 0;

    printf("Welcome to the Product Inventory System!\n\n");

    while (1) {
        printf("\nPlease choose an option:\n");
        printf("1. Add product\n");
        printf("2. View products\n");
        printf("3. Update product quantity\n");
        printf("4. Remove product\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter product name: ");
            scanf("%s", products[num_products].name);
            printf("Enter product quantity: ");
            scanf("%d", &products[num_products].quantity);
            num_products++;
            break;

        case 2:
            printf("\nProduct List:\n");
            for (int i = 0; i < num_products; i++) {
                printf("%s - %d units\n", products[i].name, products[i].quantity);
            }
            break;

        case 3:
            printf("Enter product name: ");
            scanf("%s", products[num_products].name);
            printf("Enter new quantity: ");
            scanf("%d", &products[num_products].quantity);
            break;

        case 4:
            printf("Enter product name: ");
            scanf("%s", products[num_products].name);
            for (int i = 0; i < num_products - 1; i++) {
                strcpy(products[i].name, products[i + 1].name);
                products[i].quantity = products[i + 1].quantity;
            }
            num_products--;
            break;

        case 5:
            printf("Thank you for using the Product Inventory System!\n");
            return 0;

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}