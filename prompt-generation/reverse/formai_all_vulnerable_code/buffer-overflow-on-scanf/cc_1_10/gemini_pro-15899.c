//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float price;
    int quantity;
} product;

void addProduct(product *products, int *numProducts) {
    printf("Enter product ID: ");
    scanf("%d", &products[*numProducts].id);

    printf("Enter product name: ");
    scanf("%s", products[*numProducts].name);

    printf("Enter product price: ");
    scanf("%f", &products[*numProducts].price);

    printf("Enter product quantity: ");
    scanf("%d", &products[*numProducts].quantity);

    (*numProducts)++;
}

void deleteProduct(product *products, int *numProducts) {
    int id;

    printf("Enter product ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *numProducts; i++) {
        if (products[i].id == id) {
            for (int j = i; j < *numProducts - 1; j++) {
                products[j] = products[j + 1];
            }

            (*numProducts)--;
            break;
        }
    }
}

void updateProduct(product *products, int numProducts) {
    int id;
    int choice;

    printf("Enter product ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < numProducts; i++) {
        if (products[i].id == id) {
            printf("1. Name\n2. Price\n3. Quantity\n\nChoose field to update: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    printf("Enter new product name: ");
                    scanf("%s", products[i].name);
                    break;

                case 2:
                    printf("Enter new product price: ");
                    scanf("%f", &products[i].price);
                    break;

                case 3:
                    printf("Enter new product quantity: ");
                    scanf("%d", &products[i].quantity);
                    break;

                default:
                    printf("Invalid choice!\n");
            }

            break;
        }
    }
}

void displayProducts(product *products, int numProducts) {
    printf("Product Inventory:\n\n");

    for (int i = 0; i < numProducts; i++) {
        printf("Product ID: %d\n", products[i].id);
        printf("Product Name: %s\n", products[i].name);
        printf("Product Price: %.2f\n", products[i].price);
        printf("Product Quantity: %d\n\n", products[i].quantity);
    }
}

int main() {
    product products[100];
    int numProducts = 0;
    int choice;

    while (1) {
        printf("1. Add Product\n2. Delete Product\n3. Update Product\n4. Display Products\n5. Exit\n\nChoose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(products, &numProducts);
                break;

            case 2:
                deleteProduct(products, &numProducts);
                break;

            case 3:
                updateProduct(products, numProducts);
                break;

            case 4:
                displayProducts(products, numProducts);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}