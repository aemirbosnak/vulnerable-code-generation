//FormAI DATASET v1.0 Category: Product Inventory System ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 50
#define MAX_NAME_LENGTH 50
#define MAX_CATEGORY_LENGTH 20

typedef struct Product {
    char name[MAX_NAME_LENGTH];
    float price;
    int quantity;
    char category[MAX_CATEGORY_LENGTH];
} Product;

Product inventory[MAX_PRODUCTS];
int numProducts = 0;

void addProduct(char name[], float price, int quantity, char category[]) {
    if (numProducts >= MAX_PRODUCTS) {
        printf("ERROR: MAX PRODUCTS REACHED\n");
        return;
    }

    strcpy(inventory[numProducts].name, name);
    inventory[numProducts].price = price;
    inventory[numProducts].quantity = quantity;
    strcpy(inventory[numProducts].category, category);

    numProducts++;

    printf("Product Added!\n");
}

void removeProduct(char name[]) {
    for (int i = 0; i < numProducts; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < numProducts-1; j++) {
                inventory[j] = inventory[j+1];
            }

            numProducts--;

            printf("Product Removed!\n");
            return;
        }
    }

    printf("Product Not Found!\n");
}

void displayInventory() {
    printf("----------------------------\n");
    printf("|  NAME  |  CATEGORY  |  PRICE  |  QUANTITY  |\n");
    printf("----------------------------\n");

    for (int i = 0; i < numProducts; i++) {
        printf("| %-6s | %-9s | $%.2f | %-9d |\n", inventory[i].name, inventory[i].category, inventory[i].price, inventory[i].quantity);
    }

    printf("----------------------------\n");
}

int main() {
    char name[MAX_NAME_LENGTH];
    float price;
    int quantity;
    char category[MAX_CATEGORY_LENGTH];
    int choice;

    printf("Welcome to the post-apocalyptic Product Inventory System!\n");

    do {
        printf("\n1 - Add Product\n");
        printf("2 - Remove Product\n");
        printf("3 - Display Inventory\n");
        printf("4 - Exit\n");

        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Name: ");
                scanf("%s", name);

                printf("Price: ");
                scanf("%f", &price);

                printf("Quantity: ");
                scanf("%d", &quantity);

                printf("Category: ");
                scanf("%s", category);

                addProduct(name, price, quantity, category);
                break;

            case 2:
                printf("Name: ");
                scanf("%s", name);

                removeProduct(name);
                break;

            case 3:
                displayInventory();
                break;

            case 4:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid Choice!\n");
                break;
        }
    } while (choice != 4);

    return 0;
}