//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: beginner-friendly
#include <stdio.h>

#define MAX_PRODUCTS 100 // Maximum number of products in the warehouse

typedef struct {
    int id;
    char name[20];
    int quantity;
} Product;

int menu() {
    int choice;

    printf("Warehouse Management System\n");
    printf("===========================\n");
    printf("1. Add Product\n");
    printf("2. Search Product\n");
    printf("3. Display All Products\n");
    printf("4. Remove Product\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    return choice;
}

void addProduct(Product *products, int *numProducts) {
    if (*numProducts == MAX_PRODUCTS) {
        printf("The warehouse is full.\n");
        return;
    }

    printf("Enter product name: ");
    scanf("%s", products[*numProducts].name);

    printf("Enter product quantity: ");
    scanf("%d", &products[*numProducts].quantity);

    products[*numProducts].id = *numProducts + 1;

    printf("Product added successfully.\n");
    (*numProducts)++;
}

void searchProduct(Product *products, int numProducts) {
    int id, i;

    printf("Enter product ID: ");
    scanf("%d", &id);

    for (i = 0; i < numProducts; i++) {
        if (products[i].id == id) {
            printf("Product ID: %d\n", products[i].id);
            printf("Product Name: %s\n", products[i].name);
            printf("Product Quantity: %d\n", products[i].quantity);
            return;
        }
    }

    printf("Product not found.\n");
}

void displayProducts(Product *products, int numProducts) {
    int i;

    printf("%-10s %-20s %-10s\n", "ID", "Name", "Quantity");
    printf("===================================\n");

    for (i = 0; i < numProducts; i++) {
        printf("%-10d %-20s %-10d\n", products[i].id, products[i].name, products[i].quantity);
    }
}

void removeProduct(Product *products, int *numProducts) {
    int id, i, j;

    printf("Enter product ID: ");
    scanf("%d", &id);

    for (i = 0; i < *numProducts; i++) {
        if (products[i].id == id) {
            printf("Product removed successfully.\n");
            for (j = i; j < (*numProducts - 1); j++) {
                products[j] = products[j + 1];
            }
            (*numProducts)--;
            return;
        }
    }

    printf("Product not found.\n");
}

int main() {
    int choice, numProducts = 0; // Initially there are no products in the warehouse
    Product products[MAX_PRODUCTS];

    do {
        choice = menu();

        switch (choice) {
            case 1:
                addProduct(products, &numProducts);
                break;
            case 2:
                searchProduct(products, numProducts);
                break;
            case 3:
                displayProducts(products, numProducts);
                break;
            case 4:
                removeProduct(products, &numProducts);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}