//FormAI DATASET v1.0 Category: Product Inventory System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100   // Maximum number of products in the inventory
#define MAX_NAME_LEN 20    // Maximum length of product name
#define MAX_DESC_LEN 100   // Maximum length of product description

struct Product {
    char name[MAX_NAME_LEN];
    char desc[MAX_DESC_LEN];
    float price;
    int stock;
};

struct Inventory {
    struct Product products[MAX_PRODUCTS];
    int size;
};

void displayMenu() {
    printf("\nWelcome to the Puzzle Inventory System\n");
    printf("======================================\n");
    printf("1. Add product\n");
    printf("2. Delete product\n");
    printf("3. Search product\n");
    printf("4. Print inventory\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

void addProduct(struct Inventory* inv) {
    if (inv->size >= MAX_PRODUCTS) {
        printf("Inventory is full!\n");
        return;
    }

    struct Product newProd;

    printf("Enter product name: ");
    scanf("%s", newProd.name);

    printf("Enter product description: ");
    scanf(" %[^\n]s", newProd.desc);

    printf("Enter product price: ");
    scanf("%f", &newProd.price);

    printf("Enter product stock: ");
    scanf("%d", &newProd.stock);

    inv->products[inv->size++] = newProd;

    printf("Product added successfully!\n");
}

void deleteProduct(struct Inventory* inv) {
    if (inv->size <= 0) {
        printf("Inventory is empty!\n");
        return;
    }

    char prodName[MAX_NAME_LEN];

    printf("Enter product name to delete: ");
    scanf("%s", prodName);

    int found = 0;
    for (int i = 0; i < inv->size; ++i) {
        if (strcmp(inv->products[i].name, prodName) == 0) {
            for (int j = i; j < inv->size - 1; ++j) {
                inv->products[j] = inv->products[j + 1];
            }
            --inv->size;
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Product deleted successfully!\n");
    } else {
        printf("Product not found!\n");
    }
}

void searchProduct(struct Inventory* inv) {
    if (inv->size <= 0) {
        printf("Inventory is empty!\n");
        return;
    }

    char prodName[MAX_NAME_LEN];

    printf("Enter product name to search: ");
    scanf("%s", prodName);

    int found = 0;
    for (int i = 0; i < inv->size; ++i) {
        if (strcmp(inv->products[i].name, prodName) == 0) {
            printf("Name: %s\n", inv->products[i].name);
            printf("Description: %s\n", inv->products[i].desc);
            printf("Price: %.2f\n", inv->products[i].price);
            printf("Stock: %d\n", inv->products[i].stock);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Product not found!\n");
    }
}

void printInventory(struct Inventory* inv) {
    if (inv->size <= 0) {
        printf("Inventory is empty!\n");
        return;
    }

    printf("Inventory:\n");
    for (int i = 0; i < inv->size; ++i) {
        printf("%d: %s - %s ($%.2f, %d in stock)\n", i+1, inv->products[i].name, inv->products[i].desc, inv->products[i].price, inv->products[i].stock);
    }
}

int main() {
    struct Inventory inv;
    inv.size = 0;

    int choice;

    do {
        displayMenu();

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(&inv);
                break;

            case 2:
                deleteProduct(&inv);
                break;

            case 3:
                searchProduct(&inv);
                break;

            case 4:
                printInventory(&inv);
                break;

            case 5:
                printf("Exiting puzzle inventory system...\n");
                return 0;
                break;

            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    } while (1);

    return 0;
}