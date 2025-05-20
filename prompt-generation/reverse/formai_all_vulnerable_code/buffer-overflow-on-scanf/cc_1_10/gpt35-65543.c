//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

struct product {
    char name[50];
    int quantity;
    float price;
};

void addProduct(struct product *inventory, int *count) {
    if (*count < MAX_PRODUCTS) {
        struct product newProduct;
        printf("Enter product name: ");
        scanf("%s", newProduct.name);
        printf("Enter product quantity: ");
        scanf("%d", &newProduct.quantity);
        printf("Enter product price: ");
        scanf("%f", &newProduct.price);
        inventory[*count] = newProduct;
        (*count)++;
        printf("New product added successfully.\n");
    }
    else {
        printf("Sorry, no more products can be added. Product limit reached.\n");
    }
}

void displayInventory(struct product *inventory, int count) {
    if (count > 0) {
        printf("Product Name\tQuantity\tPrice\n");
        for (int i = 0; i < count; i++) {
            printf("%s\t\t%d\t\t$%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
        }
    }
    else {
        printf("No products in inventory.\n");
    }
}

void searchProduct(struct product *inventory, int count, char *productName) {
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, productName) == 0) {
            printf("%s\t\t%d\t\t$%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Product not found.\n");
    }
}

void removeProduct(struct product *inventory, int *count, char *productName) {
    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (strcmp(inventory[i].name, productName) == 0) {
            for (int j = i; j < (*count)-1; j++) {
                inventory[j] = inventory[j+1];
            }
            (*count)--;
            found = 1;
            printf("Product removed successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Product not found.\n");
    }
}

int main() {
    struct product inventory[MAX_PRODUCTS];
    int count = 0;
    int option;
    char productName[50];

    while (1) {
        printf("\nMedical Store Management System\n");
        printf("1. Add product\n");
        printf("2. Display inventory\n");
        printf("3. Search product\n");
        printf("4. Remove product\n");
        printf("5. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                addProduct(inventory, &count);
                break;
            case 2:
                displayInventory(inventory, count);
                break;
            case 3:
                printf("Enter product name: ");
                scanf("%s", productName);
                searchProduct(inventory, count, productName);
                break;
            case 4:
                printf("Enter product name: ");
                scanf("%s", productName);
                removeProduct(inventory, &count, productName);
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
                break;
            default:
                printf("Invalid option.\n");
                break;
        }
    }

    return 0;
}