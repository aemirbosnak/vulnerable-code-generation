//FormAI DATASET v1.0 Category: Product Inventory System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000
#define MAX_NAME_LENGTH 50

int numProducts = 0;

struct Product {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
};

struct Product inventory[MAX_PRODUCTS];

void addProduct() {
    if(numProducts == MAX_PRODUCTS) {
        printf("Inventory is full!\n");
        return;
    }

    struct Product p;

    printf("Enter product name: ");
    fgets(p.name, MAX_NAME_LENGTH, stdin);
    p.name[strcspn(p.name, "\n")] = '\0'; // remove trailing newline
    printf("Enter product quantity: ");
    scanf("%d", &p.quantity);
    printf("Enter product price: ");
    scanf("%f", &p.price);

    inventory[numProducts++] = p;

    printf("Product added successfully!\n");
}

void removeProduct() {
    if(numProducts == 0) {
        printf("Inventory is empty!\n");
        return;
    }

    printf("Enter product name to remove: ");
    char nameToRemove[MAX_NAME_LENGTH];
    fgets(nameToRemove, MAX_NAME_LENGTH, stdin);
    nameToRemove[strcspn(nameToRemove, "\n")] = '\0';

    int indexToRemove = -1;

    for(int i = 0; i < numProducts; i++) {
        if(strcmp(inventory[i].name, nameToRemove) == 0) {
            indexToRemove = i;
            break;
        }
    }

    if(indexToRemove == -1) {
        printf("Product not found!\n");
        return;
    }

    for(int i = indexToRemove; i < numProducts-1; i++) {
        inventory[i] = inventory[i+1];
    }

    numProducts--;

    printf("Product removed successfully!\n");
}

void viewInventory() {
    if(numProducts == 0) {
        printf("Inventory is empty!\n");
        return;
    }

    printf("Product Name\t\tQuantity\tPrice\n");

    for(int i = 0; i < numProducts; i++) {
        struct Product p = inventory[i];
        printf("%-20s\t%d\t\t%.2f\n", p.name, p.quantity, p.price);
    }
}

int main() {
    while(1) {
        printf("\n1. Add product\n2. Remove product\n3. View inventory\n4. Exit\n\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addProduct();
                break;
            case 2:
                removeProduct();
                break;
            case 3:
                viewInventory();
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}