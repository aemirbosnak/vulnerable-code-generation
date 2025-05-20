//FormAI DATASET v1.0 Category: Product Inventory System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    char name[50];
    int quantity;
    double price;
    char location[50];
} Product;

Product inventory[MAX_PRODUCTS];
int numProducts = 0;

void addProduct() {
    printf("Enter product name: ");
    scanf("%s", inventory[numProducts].name);

    printf("Enter product quantity: ");
    scanf("%d", &inventory[numProducts].quantity);

    printf("Enter product price: ");
    scanf("%lf", &inventory[numProducts].price);

    printf("Enter product location: ");
    scanf("%s", inventory[numProducts].location);

    numProducts++;

    printf("Product added successfully!\n");
}

void displayProduct(Product product) {
    printf("%s (qty: %d, price: $%.2lf) - located at %s\n", 
            product.name, product.quantity, product.price, product.location);
}

void viewInventory() {
    printf("Product Inventory:\n");

    for (int i = 0; i < numProducts; i++) {
        displayProduct(inventory[i]);
    }
}

void searchProduct() {
    char searchName[50];
    printf("Enter product name: ");
    scanf("%s", searchName);

    for (int i = 0; i < numProducts; i++) {
        if (strcmp(inventory[i].name, searchName) == 0) {
            displayProduct(inventory[i]);
            return;
        }
    }

    printf("Product not found.\n");
}

void sellProduct() {
    char sellName[50];
    printf("Enter product name to sell: ");
    scanf("%s", sellName);

    for (int i = 0; i < numProducts; i++) {
        if (strcmp(inventory[i].name, sellName) == 0) {
            int sellQuantity;
            printf("Enter quantity to sell: ");
            scanf("%d", &sellQuantity);

            if (sellQuantity > inventory[i].quantity) {
                printf("Not enough quantity in stock.\n");
                return;
            }

            inventory[i].quantity -= sellQuantity;
            printf("Sale successful.\n");
            return;
        }
    }

    printf("Product not found.\n");
}

void saveInventory() {
    FILE *fp;

    fp = fopen("inventory.txt", "w");

    if (fp == NULL) {
        printf("Error saving inventory.\n");
        return;
    }

    for (int i = 0; i < numProducts; i++) {
        fprintf(fp, "%s,%d,%.2lf,%s\n", 
                inventory[i].name, inventory[i].quantity, inventory[i].price, inventory[i].location);
    }

    fclose(fp);
    printf("Inventory saved successfully.\n");
}

void loadInventory() {
    FILE *fp;

    fp = fopen("inventory.txt", "r");

    if (fp == NULL) {
        printf("Error loading inventory.\n");
        return;
    }

    numProducts = 0;

    while (fscanf(fp, "%[^,],%d,%lf,%[^\n]\n", 
             inventory[numProducts].name, &inventory[numProducts].quantity, 
             &inventory[numProducts].price, inventory[numProducts].location) == 4) {
        numProducts++;
    }

    fclose(fp);
    printf("Inventory loaded successfully.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nProduct Inventory Management System\n");
        printf("1. Add product\n");
        printf("2. View inventory\n");
        printf("3. Search product\n");
        printf("4. Sell product\n");
        printf("5. Save inventory\n");
        printf("6. Load inventory\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;

            case 2:
                viewInventory();
                break;

            case 3:
                searchProduct();
                break;

            case 4:
                sellProduct();
                break;

            case 5:
                saveInventory();
                break;

            case 6:
                loadInventory();
                break;

            case 7:
                printf("Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}