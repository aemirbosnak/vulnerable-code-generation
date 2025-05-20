//FormAI DATASET v1.0 Category: Product Inventory System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_PRODUCT_NAME_SIZE 50
#define MAX_PRODUCT_DESCRIPTION_SIZE 100
#define MAX_MANUFACTURER_NAME_SIZE 50

typedef struct {
    char name[MAX_PRODUCT_NAME_SIZE];
    char description[MAX_PRODUCT_DESCRIPTION_SIZE];
    float price;
    int quantity;
    char manufacturer[MAX_MANUFACTURER_NAME_SIZE];
} Product;

Product inventory[MAX_PRODUCTS];
int numProducts = 0;

void addProduct() {
    if (numProducts == MAX_PRODUCTS) {
        printf("Sorry, inventory is full.\n");
        return;
    }

    printf("Enter product name: ");
    scanf("%s", inventory[numProducts].name);

    printf("Enter product description: ");
    scanf("%s", inventory[numProducts].description);

    printf("Enter product price: ");
    scanf("%f", &inventory[numProducts].price);

    printf("Enter product quantity: ");
    scanf("%d", &inventory[numProducts].quantity);

    printf("Enter manufacturer name: ");
    scanf("%s", inventory[numProducts].manufacturer);

    numProducts++;
}

void removeProduct() {
    char name[MAX_PRODUCT_NAME_SIZE];
    printf("Enter product name to remove: ");
    scanf("%s", name);

    int index = -1;
    for (int i = 0; i < numProducts; i++) {
        if (strcmp(name, inventory[i].name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Sorry, product not found.\n");
        return;
    }

    for (int i = index; i < numProducts - 1; i++) {
        inventory[i] = inventory[i + 1];
    }

    numProducts--;
    printf("Product removed.\n");
}

void displayInventory() {
    printf("Product Name\tDescription\tPrice\tQuantity\tManufacturer\n");
    for (int i = 0; i < numProducts; i++) {
        printf("%s\t%s\t%.2f\t%d\t%s\n", inventory[i].name, inventory[i].description,
               inventory[i].price, inventory[i].quantity, inventory[i].manufacturer);
    }

    printf("Total products: %d\n", numProducts);
}

int main() {
    int choice;
    while (1) {
        printf("\nProduct Inventory System\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Display inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                removeProduct();
                break;
            case 3:
                displayInventory();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}