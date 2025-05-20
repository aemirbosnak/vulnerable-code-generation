//FormAI DATASET v1.0 Category: Product Inventory System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
    int id;
    char name[50];
    float price;
    int quantity;
};

int main() {
    int n;
    printf("Enter the number of products: ");
    scanf("%d", &n);
    struct Product* products = (struct Product*) malloc(n * sizeof(struct Product));

    for (int i = 0; i < n; i++) {
        printf("Enter the product id: ");
        scanf("%d", &products[i].id);
        printf("Enter the product name: ");
        scanf("%s", products[i].name);
        printf("Enter the product price: ");
        scanf("%f", &products[i].price);
        printf("Enter the product quantity: ");
        scanf("%d", &products[i].quantity);
        printf("\n");
    }

    printf("Product Inventory:\n");
    printf("ID\tName\tPrice\tQuantity\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t%.2f\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }

    int choice;
    do {
        printf("\n1. Search a product by id\n");
        printf("2. Search a product by name\n");
        printf("3. Update product quantity\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            int productID, productQuantity, productIndex;
            char productName[50];
            case 1:
                printf("\nEnter the product id: ");
                scanf("%d", &productID);

                for (int i = 0; i < n; i++) {
                    if (productID == products[i].id) {
                        printf("%d\t%s\t%.2f\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
                        break;
                    }
                }
                break;

            case 2:
                printf("\nEnter the product name: ");
                scanf("%s", productName);

                for (int i = 0; i < n; i++) {
                    if (strcmp(productName, products[i].name) == 0) {
                        printf("%d\t%s\t%.2f\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
                        break;
                    }
                }
                break;

            case 3:
                printf("\nEnter the product id: ");
                scanf("%d", &productID);

                for (int i = 0; i < n; i++) {
                    if (productID == products[i].id) {
                        productIndex = i;
                        break;
                    }
                }

                printf("Enter the updated quantity: ");
                scanf("%d", &productQuantity);
                products[productIndex].quantity = productQuantity;
                printf("\nQuantity updated successfully!\n");
                printf("%d\t%s\t%.2f\t%d\n", products[productIndex].id, products[productIndex].name, products[productIndex].price, products[productIndex].quantity);
                break;
            
            case 4:
                printf("\nThank you for using the Product Inventory System!\n");
                break;

            default:
                printf("\nInvalid choice!\n");
                break;
        }
    } while (choice != 4);

    return 0;
}