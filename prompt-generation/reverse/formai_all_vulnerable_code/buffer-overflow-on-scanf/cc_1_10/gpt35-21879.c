//FormAI DATASET v1.0 Category: Product Inventory System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 10
#define MAX_STRING_LENGTH 50

struct Product {
    int id;
    char name[MAX_STRING_LENGTH];
    double price;
    int stock;
};

struct Product products[MAX_PRODUCTS];

int numProducts = 0;

void addProduct();
void removeProduct();
void updateProduct();
void viewProduct();
void viewAllProducts();
void printMenu();

int main() {
    int choice;
    char enter;

    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        scanf("%c", &enter);

        switch (choice) {
            case 1: addProduct(); break;
            case 2: removeProduct(); break;
            case 3: updateProduct(); break;
            case 4: viewProduct(); break;
            case 5: viewAllProducts(); break;
            case 6: break;
            default: printf("Invalid choice!\n"); break;
        }
    } while (choice != 6);

    return 0;
}

void addProduct() {
    struct Product p;

    printf("Enter product name: ");
    fgets(p.name, MAX_STRING_LENGTH, stdin);
    p.name[strcspn(p.name, "\n")] = 0;

    printf("Enter product price: ");
    scanf("%lf", &p.price);

    printf("Enter product stock: ");
    scanf("%d", &p.stock);

    p.id = numProducts++;

    products[p.id] = p;

    printf("Product added successfully!\n");
}

void removeProduct() {
    int id;

    printf("Enter product id to remove: ");
    scanf("%d", &id);

    if (id < 0 || id >= numProducts) {
        printf("Invalid id!\n");
    } else {
        for (int i = id; i < numProducts - 1; i++) {
            products[i] = products[i + 1];
        }
        numProducts--;
        printf("Product removed successfully!\n");
    }
}

void updateProduct() {
    int id;
    struct Product p;

    printf("Enter product id to update: ");
    scanf("%d", &id);

    if (id < 0 || id >= numProducts) {
        printf("Invalid id!\n");
    } else {
        printf("Enter new product name: ");
        fgets(p.name, MAX_STRING_LENGTH, stdin);
        p.name[strcspn(p.name, "\n")] = 0;

        printf("Enter new product price: ");
        scanf("%lf", &p.price);

        printf("Enter new product stock: ");
        scanf("%d", &p.stock);

        p.id = id;

        products[id] = p;

        printf("Product updated successfully!\n");
    }
}

void viewProduct() {
    int id;

    printf("Enter product id to view: ");
    scanf("%d", &id);

    if (id < 0 || id >= numProducts) {
        printf("Invalid id!\n");
    } else {
        struct Product p = products[id];
        printf("Id: %d\nName: %s\nPrice: $%.2lf\nStock: %d\n", p.id, p.name, p.price, p.stock);
    }
}

void viewAllProducts() {
    if (numProducts == 0) {
        printf("No products to display.\n");
    } else {
        printf("Id  Name\t\t\t\t\tPrice\tStock\n");

        for (int i = 0; i < numProducts; i++) {
            struct Product p = products[i];
            printf("%-4d%-30s$%-8.2lf%d\n", p.id, p.name, p.price, p.stock);
        }
    }
}

void printMenu() {
    printf("\nProduct Inventory System\n");
    printf("*************************\n");
    printf("1. Add a product\n");
    printf("2. Remove a product\n");
    printf("3. Update a product\n");
    printf("4. View a product\n");
    printf("5. View all products\n");
    printf("6. Exit\n");
}