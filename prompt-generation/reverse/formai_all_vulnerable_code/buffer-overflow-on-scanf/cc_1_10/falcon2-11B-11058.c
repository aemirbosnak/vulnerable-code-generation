//Falcon2-11B DATASET v1.0 Category: Product Inventory System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
    int price;
} Product;

int main() {
    Product products[100];
    int numProducts = 0;
    int choice = 0;

    printf("Welcome to the Future Product Inventory System!\n");
    while (choice!= 4) {
        printf("\nPlease select an option:\n");
        printf("1. Add a product\n");
        printf("2. Remove a product\n");
        printf("3. Display all products\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Enter the product name: ");
                fgets(products[numProducts].name, sizeof(products[numProducts].name), stdin);
                products[numProducts].quantity = 0;
                products[numProducts].price = 0;
                numProducts++;
                printf("Product added successfully!\n");
                break;
            }
            case 2: {
                printf("Enter the product name: ");
                fgets(products[choice].name, sizeof(products[choice].name), stdin);
                printf("Enter the quantity to remove: ");
                scanf("%d", &products[choice].quantity);
                if (products[choice].quantity > 0) {
                    products[choice].quantity--;
                    printf("Quantity removed successfully!\n");
                } else {
                    printf("Cannot remove, quantity is zero.\n");
                }
                break;
            }
            case 3: {
                if (numProducts == 0) {
                    printf("No products in inventory.\n");
                } else {
                    printf("Product Inventory:\n");
                    for (int i = 0; i < numProducts; i++) {
                        printf("%s - Quantity: %d - Price: $%.2f\n", products[i].name, products[i].quantity, products[i].price);
                    }
                }
                break;
            }
            case 4: {
                printf("Exiting...\n");
                break;
            }
        }
    }

    return 0;
}