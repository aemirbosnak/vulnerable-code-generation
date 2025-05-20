//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define MAX_NAME_SIZE 50

typedef struct {
    char name[MAX_NAME_SIZE];
    int quantity;
    double price;
} Product;

void addProduct(Product* inventory, int* size) {
    printf("Enter product name: ");
    scanf("%s", inventory[*size].name);

    printf("Enter quantity: ");
    scanf("%d", &inventory[*size].quantity);

    printf("Enter price: ");
    scanf("%lf", &inventory[*size].price);

    (*size)++;
}

void removeProduct(Product* inventory, int* size) {
    printf("Enter product name: ");
    char name[MAX_NAME_SIZE];
    scanf("%s", name);

    int i;
    for (i = 0; i < *size; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Product removed: %s\n", name);
            *size -= 1;
            break;
        } else {
            printf("Product not found.\n");
        }
    }
}

void updateProduct(Product* inventory, int* size) {
    printf("Enter product name: ");
    char name[MAX_NAME_SIZE];
    scanf("%s", name);

    int i;
    for (i = 0; i < *size; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);

            printf("Enter new price: ");
            scanf("%lf", &inventory[i].price);

            printf("Product updated: %s\n", name);
            break;
        } else {
            printf("Product not found.\n");
        }
    }
}

void displayProducts(Product* inventory, int size) {
    printf("Product Inventory:\n");
    printf("------------------\n");

    int i;
    for (i = 0; i < size; i++) {
        printf("%-20s %-10d $%.2lf\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

int main() {
    Product inventory[MAX_SIZE];
    int size = 0;

    addProduct(inventory, &size);
    addProduct(inventory, &size);
    addProduct(inventory, &size);

    displayProducts(inventory, size);

    removeProduct(inventory, &size);

    displayProducts(inventory, size);

    updateProduct(inventory, &size);

    displayProducts(inventory, size);

    return 0;
}