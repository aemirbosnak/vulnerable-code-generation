//FormAI DATASET v1.0 Category: Product Inventory System ; Style: optimized
#include <stdio.h>
#include <string.h>
#define MAX_PRODUCTS 100

struct Product {
    int id;
    char name[50];
    float price;
    int quantity;
};

int main() {
    struct Product products[MAX_PRODUCTS];
    int numProducts = 0;

    int choice = 0;
    while (choice != 4) {
        printf("========= Product Inventory System =========\n");
        printf("1. Add a New Product\n");
        printf("2. Display Product Details\n");
        printf("3. Update Product Details\n");
        printf("4. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("===== Add a New Product =====\n");

                struct Product newProduct;
                newProduct.id = numProducts + 1;

                printf("Enter Product Name: ");
                scanf("%s", &newProduct.name);

                printf("Enter Product Price: ");
                scanf("%f", &newProduct.price);

                printf("Enter Product Quantity: ");
                scanf("%d", &newProduct.quantity);

                products[numProducts] = newProduct;
                numProducts++;

                printf("Product Added Successfully!\n");

                break;

            case 2:
                printf("===== Display Product Details =====\n");

                printf("Enter Product ID: ");
                int productID;
                scanf("%d", &productID);

                for (int i = 0; i < numProducts; i++) {
                    if (products[i].id == productID) {
                        printf("Product Name: %s\n", products[i].name);
                        printf("Product Price: %f\n", products[i].price);
                        printf("Product Quantity: %d\n", products[i].quantity);
                        break;
                    } else if (i == numProducts - 1) {
                        printf("Product Not Found!\n");
                    }
                }

                break;

            case 3:
                printf("===== Update Product Details =====\n");

                printf("Enter Product ID: ");
                int prodID;
                scanf("%d", &prodID);

                for (int i = 0; i < numProducts; i++) {
                    if (products[i].id == prodID) {
                        printf("Enter Product Name: ");
                        scanf("%s", &products[i].name);

                        printf("Enter Product Price: ");
                        scanf("%f", &products[i].price);

                        printf("Enter Product Quantity: ");
                        scanf("%d", &products[i].quantity);

                        printf("Product Details Updated Successfully!\n");
                        break;
                    } else if (i == numProducts - 1) {
                        printf("Product Not Found!\n");
                    }
                }

                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid Choice!\n");

        }
    }

    return 0;
}