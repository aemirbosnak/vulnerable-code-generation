//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} product;

void addProduct(product *products, int numProducts) {
    printf("Enter product name: ");
    scanf("%s", &products[numProducts].name);
    printf("Enter quantity: ");
    scanf("%d", &products[numProducts].quantity);
    printf("Enter price: ");
    scanf("%f", &products[numProducts].price);
    numProducts++;
}

void displayProducts(product *products, int numProducts) {
    printf("Product Name\tQuantity\tPrice\n");
    for (int i = 0; i < numProducts; i++) {
        printf("%s\t\t%d\t\t$%.2f\n", products[i].name, products[i].quantity, products[i].price);
    }
}

void updateProductQuantity(product *products, int numProducts, char *name) {
    printf("Enter new quantity for %s: ", name);
    scanf("%d", &products[numProducts].quantity);
}

void deleteProduct(product *products, int *numProducts) {
    printf("Enter product name to delete: ");
    scanf("%s", &products[*numProducts - 1].name);
    *numProducts -= 1;
}

int main() {
    product products[MAX_PRODUCTS];
    int numProducts = 0;

    while (numProducts < MAX_PRODUCTS) {
        printf("Enter 1 to add product\n");
        printf("Enter 2 to display products\n");
        printf("Enter 3 to update product quantity\n");
        printf("Enter 4 to delete product\n");
        printf("Enter 0 to exit\n");
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addProduct(products, numProducts);
                break;
            case 2:
                displayProducts(products, numProducts);
                break;
            case 3:
                printf("Enter product name to update quantity: ");
                scanf("%s", &products[numProducts - 1].name);
                updateProductQuantity(products, numProducts, products[numProducts - 1].name);
                break;
            case 4:
                deleteProduct(products, &numProducts);
                break;
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}