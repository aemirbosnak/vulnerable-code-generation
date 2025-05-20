//FormAI DATASET v1.0 Category: Product Inventory System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

Product productInventory[MAX_ITEMS];
int itemCount = 0;

void printMenu();
void addProduct();
void updateProduct();
void removeProduct();
void displayInventory();

int main() {
    int choice;

    do {
        printMenu();

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                updateProduct();
                break;
            case 3:
                removeProduct();
                break;
            case 4:
                displayInventory();
                break;
            case 5:
                printf("Exiting program...");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1);
}

void printMenu() {
    printf("\nProduct Inventory System\n");
    printf("------------------------\n\n");
    printf("1. Add product\n");
    printf("2. Update product\n");
    printf("3. Remove product\n");
    printf("4. Display inventory\n");
    printf("5. Exit\n\n");
    printf("Enter your choice: ");
}

void addProduct() {
    if (itemCount >= MAX_ITEMS) {
        printf("Inventory is full. Cannot add more products.\n");
        return;
    }

    Product newProduct;

    printf("\nEnter product details:\n");
    printf("Name: ");
    scanf("%s", newProduct.name);
    printf("Quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Price: ");
    scanf("%f", &newProduct.price);

    productInventory[itemCount] = newProduct;
    itemCount++;

    printf("\nProduct added successfully.\n");
}

void updateProduct() {
    if (itemCount == 0) {
        printf("Inventory is empty. Cannot update products.\n");
        return;
    }

    int i;
    char name[50];

    printf("\nEnter the name of the product to update: ");
    scanf("%s", name);

    for (i = 0; i < itemCount; i++) {
        if (strcmp(productInventory[i].name, name) == 0) {
            printf("\nCurrent details:\n");
            printf("Name: %s\n", productInventory[i].name);
            printf("Quantity: %d\n", productInventory[i].quantity);
            printf("Price: %.2f\n\n", productInventory[i].price);

            printf("Enter new details:\n");
            printf("Name: ");
            scanf("%s", productInventory[i].name);
            printf("Quantity: ");
            scanf("%d", &productInventory[i].quantity);
            printf("Price: ");
            scanf("%f", &productInventory[i].price);

            printf("\nProduct updated successfully.\n");
            return;
        }
    }

    printf("\nProduct not found in inventory.\n");
}

void removeProduct() {
    if (itemCount == 0) {
        printf("Inventory is empty. Cannot remove products.\n");
        return;
    }

    int i, j;
    char name[50];

    printf("\nEnter the name of the product to remove: ");
    scanf("%s", name);

    for (i = 0; i < itemCount; i++) {
        if (strcmp(productInventory[i].name, name) == 0) {
            for (j = i; j < itemCount - 1; j++) {
                productInventory[j] = productInventory[j + 1];
            }

            itemCount--;

            printf("\nProduct removed successfully.\n");
            return;
        }
    }

    printf("\nProduct not found in inventory.\n");
}

void displayInventory() {
    if (itemCount == 0) {
        printf("Inventory is empty.\n");
        return;
    }

    int i;

    printf("\nProduct Inventory\n");
    printf("-----------------\n");

    for (i = 0; i < itemCount; i++) {
        printf("Name: %s\n", productInventory[i].name);
        printf("Quantity: %d\n", productInventory[i].quantity);
        printf("Price: %.2f\n\n", productInventory[i].price);
    }
}