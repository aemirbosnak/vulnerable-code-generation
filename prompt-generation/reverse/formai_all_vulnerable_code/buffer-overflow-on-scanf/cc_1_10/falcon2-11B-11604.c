//Falcon2-11B DATASET v1.0 Category: Medical Store Management System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    char name[100];
    int quantity;
    float price;
} Product;

Product products[MAX_PRODUCTS];
int numProducts = 0;

void addProduct(char* name, int quantity, float price) {
    Product newProduct;
    strcpy(newProduct.name, name);
    newProduct.quantity = quantity;
    newProduct.price = price;
    products[numProducts] = newProduct;
    numProducts++;
}

void removeProduct(char* name) {
    for (int i = 0; i < numProducts; i++) {
        if (strcmp(products[i].name, name) == 0) {
            for (int j = i; j < numProducts - 1; j++) {
                products[j] = products[j + 1];
            }
            numProducts--;
            break;
        }
    }
}

void updateProduct(char* name, int quantity, float price) {
    for (int i = 0; i < numProducts; i++) {
        if (strcmp(products[i].name, name) == 0) {
            products[i].quantity = quantity;
            products[i].price = price;
            break;
        }
    }
}

void viewInventory() {
    printf("Current inventory:\n");
    for (int i = 0; i < numProducts; i++) {
        printf("Product: %s\n", products[i].name);
        printf("Quantity: %d\n", products[i].quantity);
        printf("Price: $%.2f\n", products[i].price);
        printf("\n");
    }
}

void searchProduct(char* name) {
    for (int i = 0; i < numProducts; i++) {
        if (strcmp(products[i].name, name) == 0) {
            printf("Product found: %s\n", products[i].name);
            printf("Quantity: %d\n", products[i].quantity);
            printf("Price: $%.2f\n", products[i].price);
            printf("\n");
            break;
        }
    }
}

int main() {
    char productName[100];
    char searchName[100];
    int quantity, price;
    float totalPrice;

    printf("Welcome to the Medical Store Management System!\n");
    printf("1. Add product\n");
    printf("2. Remove product\n");
    printf("3. Update product\n");
    printf("4. View inventory\n");
    printf("5. Search product\n");
    printf("6. Exit\n");

    int choice;
    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter product name: ");
                scanf("%s", productName);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                printf("Enter price: ");
                scanf("%f", &price);
                addProduct(productName, quantity, price);
                break;
            case 2:
                printf("Enter product name to remove: ");
                scanf("%s", searchName);
                removeProduct(searchName);
                break;
            case 3:
                printf("Enter product name to update: ");
                scanf("%s", searchName);
                printf("Enter new quantity: ");
                scanf("%d", &quantity);
                printf("Enter new price: ");
                scanf("%f", &price);
                updateProduct(searchName, quantity, price);
                break;
            case 4:
                viewInventory();
                break;
            case 5:
                printf("Enter product name to search: ");
                scanf("%s", searchName);
                searchProduct(searchName);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 6);

    return 0;
}