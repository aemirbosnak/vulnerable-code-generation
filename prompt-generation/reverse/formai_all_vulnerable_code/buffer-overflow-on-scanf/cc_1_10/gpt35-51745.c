//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// a struct to represent a warehouse product
typedef struct {
    char name[20];
    int quantity;
    float price;
} Product;

// function to print the menu
void printMenu() {
    printf("1. Add product\n");
    printf("2. Remove product\n");
    printf("3. Update product price\n");
    printf("4. List all products\n");
    printf("5. Sort products by quantity\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

// function to add a new product
void addProduct(Product* products, int* numProducts) {
    Product newProduct;
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    products[*numProducts] = newProduct;
    (*numProducts)++;
    printf("Product added successfully!\n");
}

// function to remove a product
void removeProduct(Product* products, int* numProducts) {
    char productName[20];
    int i, index = -1;
    printf("Enter product name: ");
    scanf("%s", productName);
    for (i = 0; i < *numProducts; i++) {
        if (strcmp(products[i].name, productName) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Product not found!\n");
    } else {
        for (i = index; i < (*numProducts - 1); i++) {
            products[i] = products[i+1];
        }
        (*numProducts)--;
        printf("Product removed successfully!\n");
    }
}

// function to update the price of a product
void updatePrice(Product* products, int numProducts) {
    char productName[20];
    int i, index = -1;
    float newPrice;
    printf("Enter product name: ");
    scanf("%s", productName);
    for (i = 0; i < numProducts; i++) {
        if (strcmp(products[i].name, productName) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Product not found!\n");
    } else {
        printf("Enter new price: ");
        scanf("%f", &newPrice);
        products[index].price = newPrice;
        printf("Price updated successfully!\n");
    }
}

// function to list all products
void listProducts(Product* products, int numProducts) {
    int i;
    for (i = 0; i < numProducts; i++) {
        printf("%s - %d - %.2f\n", products[i].name, products[i].quantity, products[i].price);
    }
}

// a function to compare two Products by their quantity
int compareQuantity(const void* a, const void* b) {
    const Product* x = (const Product*) a;
    const Product* y = (const Product*) b;
    return (x->quantity - y->quantity);
}

// function to sort the products by quantity
void sortProducts(Product* products, int numProducts) {
    qsort(products, numProducts, sizeof(Product), compareQuantity);
    printf("Products sorted by quantity!\n");
}

// main function
int main() {
    int choice, numProducts = 0, i;
    Product products[100];

    do {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(products, &numProducts);
                break;
            case 2:
                removeProduct(products, &numProducts);
                break;
            case 3:
                updatePrice(products, numProducts);
                break;
            case 4:
                listProducts(products, numProducts);
                break;
            case 5:
                sortProducts(products, numProducts);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 6);

    return 0;
}