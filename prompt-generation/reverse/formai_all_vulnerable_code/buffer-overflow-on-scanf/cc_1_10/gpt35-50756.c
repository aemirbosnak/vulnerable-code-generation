//FormAI DATASET v1.0 Category: Product Inventory System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 10

struct Product {
    char name[20];
    int quantity;
    double price;
};

int menu() {
    int choice;

    printf("\n-------- MENU --------\n");
    printf("1. Add product\n");
    printf("2. Remove product\n");
    printf("3. List products\n");
    printf("4. Update product quantity\n");
    printf("5. Update product price\n");
    printf("6. Exit\n");
    printf("----------------------\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    return choice;
}

void addProduct(struct Product productList[]) {
    char name[20];
    int quantity;
    double price;

    printf("Enter product name: ");
    scanf("%s", name);

    printf("Enter product quantity: ");
    scanf("%d", &quantity);

    printf("Enter product price: ");
    scanf("%lf", &price);

    int i;
    for (i = 0; i < MAX_PRODUCTS; i++) {
        if (strlen(productList[i].name) == 0) {
            strcpy(productList[i].name, name);
            productList[i].quantity = quantity;
            productList[i].price = price;
            printf("Product added successfully.\n");
            return;
        }
    }

    printf("Product inventory is full.\n");
}

void removeProduct(struct Product productList[]) {
    char name[20];
    int i, found = 0;

    printf("Enter product name: ");
    scanf("%s", name);

    for (i = 0; i < MAX_PRODUCTS; i++) {
        if (strcmp(productList[i].name, name) == 0) {
            memset(productList[i].name, 0, sizeof(productList[i].name));
            productList[i].quantity = 0;
            productList[i].price = 0;
            found = 1;
            printf("Product removed successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Product not found.\n");
    }
}

void listProducts(struct Product productList[]) {
    printf("-----------------------------------------------------\n");
    printf("| %-20s | %-10s | %-10s |\n", "NAME", "QUANTITY", "PRICE");
    printf("-----------------------------------------------------\n");

    int i;
    for (i = 0; i < MAX_PRODUCTS; i++) {
        if (strlen(productList[i].name) != 0) {
            printf("| %-20s | %-10d | %-10.2lf |\n", productList[i].name, productList[i].quantity, productList[i].price);
        }
    }

    printf("-----------------------------------------------------\n");
}

void updateQuantity(struct Product productList[]) {
    char name[20];
    int quantity, i, found = 0;

    printf("Enter product name: ");
    scanf("%s", name);

    printf("Enter new quantity: ");
    scanf("%d", &quantity);

    for (i = 0; i < MAX_PRODUCTS; i++) {
        if (strcmp(productList[i].name, name) == 0) {
            productList[i].quantity = quantity;
            found = 1;
            printf("Product quantity updated successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Product not found.\n");
    }
}

void updatePrice(struct Product productList[]) {
    char name[20];
    double price;
    int i, found = 0;

    printf("Enter product name: ");
    scanf("%s", name);

    printf("Enter new price: ");
    scanf("%lf", &price);

    for (i = 0; i < MAX_PRODUCTS; i++) {
        if (strcmp(productList[i].name, name) == 0) {
            productList[i].price = price;
            found = 1;
            printf("Product price updated successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Product not found.\n");
    }
}

int main() {
    int choice;
    struct Product productList[MAX_PRODUCTS];

    memset(productList, 0, sizeof(productList));

    do {
        choice = menu();

        switch (choice) {
            case 1:
                addProduct(productList);
                break;
            case 2:
                removeProduct(productList);
                break;
            case 3:
                listProducts(productList);
                break;
            case 4:
                updateQuantity(productList);
                break;
            case 5:
                updatePrice(productList);
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (1);

    return 0;
}