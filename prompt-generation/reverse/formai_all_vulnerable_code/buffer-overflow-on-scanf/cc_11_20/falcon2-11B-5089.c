//Falcon2-11B DATASET v1.0 Category: Product Inventory System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

struct product {
    char name[50];
    int quantity;
    int cost;
};

struct product products[100];
int numProducts = 0;

int main() {
    int choice, productNumber;

    printf("Welcome to the Product Inventory System!\n");

    while (1) {
        printf("Please enter the option you want to perform:\n");
        printf("1. Add a new product\n");
        printf("2. View all products\n");
        printf("3. Update a product's quantity\n");
        printf("4. Update a product's cost\n");
        printf("5. Delete a product\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the product name: ");
                fgets(products[numProducts].name, sizeof(products[numProducts].name), stdin);
                printf("Enter the quantity: ");
                scanf("%d", &products[numProducts].quantity);
                printf("Enter the cost: ");
                scanf("%d", &products[numProducts].cost);
                products[numProducts].name[strcspn(products[numProducts].name, "\n")] = '\0';
                numProducts++;
                break;
            case 2:
                printf("Here are all the products:\n");
                for (int i = 0; i < numProducts; i++) {
                    printf("%d. %s - Quantity: %d, Cost: %d\n", i + 1, products[i].name, products[i].quantity, products[i].cost);
                }
                break;
            case 3:
                printf("Enter the product number: ");
                scanf("%d", &productNumber);
                if (productNumber >= 0 && productNumber <= numProducts - 1) {
                    printf("Enter the new quantity: ");
                    scanf("%d", &products[productNumber].quantity);
                }
                break;
            case 4:
                printf("Enter the product number: ");
                scanf("%d", &productNumber);
                if (productNumber >= 0 && productNumber <= numProducts - 1) {
                    printf("Enter the new cost: ");
                    scanf("%d", &products[productNumber].cost);
                }
                break;
            case 5:
                printf("Enter the product number: ");
                scanf("%d", &productNumber);
                if (productNumber >= 0 && productNumber <= numProducts - 1) {
                    printf("Product %s deleted!\n", products[productNumber].name);
                    numProducts--;
                    for (int i = productNumber; i < numProducts; i++) {
                        strcpy(products[i].name, products[i + 1].name);
                        products[i].quantity = products[i + 1].quantity;
                        products[i].cost = products[i + 1].cost;
                    }
                }
                break;
            case 6:
                printf("Thank you for using the Product Inventory System!\n");
                exit(0);
            default:
                printf("Invalid option.\n");
                break;
        }
    }

    return 0;
}