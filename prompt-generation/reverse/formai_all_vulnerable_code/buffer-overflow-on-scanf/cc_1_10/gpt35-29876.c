//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int id;
    char name[MAX_SIZE];
    float price;
    int quantity;
} Product;

void printMenu() {
    printf("============ MENU ============\n");
    printf("[1] Add product\n");
    printf("[2] Remove product\n");
    printf("[3] Display inventory\n");
    printf("[4] Sell product\n");
    printf("[5] Exit\n");
    printf("==============================\n");
}

int getProductIndexById(Product products[], int id, int size) {
    for (int i = 0; i < size; i++) {
        if (products[i].id == id) {
            return i;
        }
    }
    return -1;
}

void addProduct(Product products[], int* size) {
    Product product;
    int id;

    printf("Enter product ID: ");
    scanf("%d", &id);

    if (getProductIndexById(products, id, *size) != -1) {
        printf("Product ID already exists.\n");
        return;
    }

    product.id = id;

    printf("Enter product name: ");
    scanf("%s", product.name);

    printf("Enter product price: ");
    scanf("%f", &product.price);

    printf("Enter product quantity: ");
    scanf("%d", &product.quantity);

    products[*size] = product;
    *size += 1;

    printf("%s added to inventory.\n", product.name);
}

void removeProduct(Product products[], int* size) {
    int id, index;

    printf("Enter product ID: ");
    scanf("%d", &id);

    index = getProductIndexById(products, id, *size);

    if (index == -1) {
        printf("Product ID not found.\n");
        return;
    }

    for (int i = index; i < *size - 1; i++) {
        products[i] = products[i + 1];
    }

    *size -= 1;

    printf("Product removed from inventory.\n");
}

void displayInventory(Product products[], int size) {
    printf("=================================\n");
    printf("ID\tNAME\tPRICE\tQUANTITY\n");
    printf("=================================\n");

    for (int i = 0; i < size; i++) {
        printf("%d\t%s\t%.2f\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }

    printf("=================================\n");
}

void sellProduct(Product products[], int* size) {
    int id, index, quantity;

    printf("Enter product ID: ");
    scanf("%d", &id);

    index = getProductIndexById(products, id, *size);

    if (index == -1) {
        printf("Product ID not found.\n");
        return;
    }

    printf("Enter quantity to sell: ");
    scanf("%d", &quantity);

    if (quantity > products[index].quantity) {
        printf("Not enough quantity in inventory.\n");
        return;
    }

    products[index].quantity -= quantity;

    printf("%s sold.\n", products[index].name);
}

int main() {
    Product products[MAX_SIZE];
    int size = 0;
    int choice;

    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(products, &size);
                break;
            case 2:
                removeProduct(products, &size);
                break;
            case 3:
                displayInventory(products, size);
                break;
            case 4:
                sellProduct(products, &size);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}