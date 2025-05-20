//FormAI DATASET v1.0 Category: Product Inventory System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Product;

Product products[MAX_PRODUCTS];
int numProducts = 0;

void addProduct(char name[], int quantity, float price) {
    if (numProducts >= MAX_PRODUCTS) {
        printf("Maximum number of products reached!\n");
        return;
    }

    strcpy(products[numProducts].name, name);
    products[numProducts].quantity = quantity;
    products[numProducts].price = price;
    numProducts++;
}

void printInventory() {
    printf("Product Inventory\n");
    printf("-----------------\n");
    for (int i = 0; i < numProducts; i++) {
        printf("%s - Quantity: %d - Price: $%.2f\n", products[i].name, products[i].quantity, products[i].price);
    }
}

int main() {
    int choice;
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;

    while (1) {
        printf("\nProduct Inventory System\n");
        printf("------------------------\n");
        printf("1. Add a product\n");
        printf("2. Print inventory\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter product name: ");
                scanf("%s", name);
                
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                
                printf("Enter price: ");
                scanf("%f", &price);

                addProduct(name, quantity, price);
                break;
            case 2:
                printInventory();
                break;
            case 3:
                printf("Exiting program.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}