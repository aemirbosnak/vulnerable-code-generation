//FormAI DATASET v1.0 Category: Product Inventory System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    int id;
    char name[50];
    int quantity;
    float price;
};

typedef struct product Product;

Product* inventory;

int numProducts = 0;

void addProduct() {
    inventory = realloc(inventory, (numProducts + 1) * sizeof(Product));

    if (inventory == NULL) {
        printf("Error: unable to allocate memory.\n");
        exit(1);
    }

    Product newProduct;

    printf("Enter product id:\n");
    scanf("%d", &newProduct.id);

    printf("Enter product name:\n");
    scanf("%s", newProduct.name);

    printf("Enter product quantity:\n");
    scanf("%d", &newProduct.quantity);

    printf("Enter product price:\n");
    scanf("%f", &newProduct.price);

    inventory[numProducts++] = newProduct;

    printf("Product added successfully.\n");
}

void displayInventory() {
    printf("ID   Name                 Quantity   Price\n");
    printf("-----------------------------------------\n");

    for (int i = 0; i < numProducts; i++) {
        printf("%-4d %-20s %-10d $%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

int main() {
    inventory = malloc(0);

    if (inventory == NULL) {
        printf("Error: unable to allocate memory.\n");
        exit(1);
    }

    int choice;

    do {
        printf("===========================\n");
        printf(" Product Inventory System\n");
        printf("===========================\n");
        printf("1. Add product\n");
        printf("2. Display inventory\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                displayInventory();
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 3);

    free(inventory);
    return 0;
}