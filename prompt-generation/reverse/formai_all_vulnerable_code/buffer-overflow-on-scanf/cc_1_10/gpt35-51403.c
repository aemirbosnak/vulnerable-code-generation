//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Romeo and Juliet
// Act I: Scene I
// A program to keep track of our products fair,
// To know what we have and what we need to spare.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    char name[30];
    int quantity;
};

void addProduct(struct product inventory[], int *numProducts);
void printInventory(struct product inventory[], int numProducts);

int main() {
    struct product inventory[50];
    int choice, numProducts = 0;

    printf("Welcome to the Product Inventory System!\n");
    printf("Enter 1 to add a product or 2 to print inventory.\n");

    // Act I: Scene II
    // The user is asked for their choice,
    // A new product is added or inventory is voiced.
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            addProduct(inventory, &numProducts);
        } else if (choice == 2) {
            printInventory(inventory, numProducts);
        } else {
            printf("Invalid choice. Please try again.\n");
        }

        printf("Enter 1 to add another product or 2 to exit.\n");
        scanf("%d", &choice);

        if (choice == 2) {
            break;
        }
    }

    printf("Thank you for using our system. Goodbye!\n");
    return 0;
}

// Act II: Scene I
// When adding a product, the user must give
// The name and quantity, so the inventory can live.
void addProduct(struct product inventory[], int *numProducts) {
    struct product newProduct;
    printf("Enter the name of the product: ");
    scanf("%s", newProduct.name);
    printf("Enter the quantity available: ");
    scanf("%d", &newProduct.quantity);

    inventory[*numProducts] = newProduct;
    (*numProducts)++;
}

// Act II: Scene II
// When printing inventory, we simply loop
// Over all the products and their details group.
void printInventory(struct product inventory[], int numProducts) {
    printf("Inventory:\n");
    for (int i = 0; i < numProducts; i++) {
        printf("%s: %d\n", inventory[i].name, inventory[i].quantity);
    }
}