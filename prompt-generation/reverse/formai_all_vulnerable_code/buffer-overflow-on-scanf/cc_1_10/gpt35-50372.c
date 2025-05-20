//FormAI DATASET v1.0 Category: Product Inventory System ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Struct to represent a product
typedef struct {
    char name[50];
    int id;
    int quantity;
    float price;
} Product;

// Function to add a product to the inventory
void addProduct(Product inventory[], int *size) {
    Product newProduct;

    printf("Enter product name: ");
    scanf("%s", newProduct.name);

    printf("Enter product ID: ");
    scanf("%d", &newProduct.id);

    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);

    printf("Enter product price: ");
    scanf("%f", &newProduct.price);

    inventory[*size] = newProduct;
    (*size)++;
}

// Function to remove a product from the inventory
void removeProduct(Product inventory[], int *size, int id) {
    for (int i = 0; i < *size; i++) {
        if (inventory[i].id == id) {
            for (int j = i; j < *size - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            (*size)--;
            printf("Product removed from inventory.\n");
            return;
        }
    }
    printf("Product with id %d not found.\n", id);
}

// Function to update the quantity of a product in the inventory
void updateProduct(Product inventory[], int size, int id, int quantity) {
    for (int i = 0; i < size; i++) {
        if (inventory[i].id == id) {
            inventory[i].quantity += quantity;
            printf("Quantity updated.\n");
            return;
        }
    }
    printf("Product with id %d not found.\n", id);
}

// Function to display the current inventory status
void displayInventory(Product inventory[], int size) {
    printf("Product ID\tProduct Name\t\tQuantity\tPrice\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t\t%s\t\t\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

int main() {
    Product inventory[100]; // Maximum inventory size of 100 products
    int inventorySize = 0;

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("Enter 1 to add a product.\n");
        printf("Enter 2 to remove a product.\n");
        printf("Enter 3 to update the quantity of a product.\n");
        printf("Enter 4 to display the inventory.\n");
        printf("Enter 5 to exit.\n");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addProduct(inventory, &inventorySize);
                break;

            case 2:
                printf("Enter product ID: ");
                int idToRemove;
                scanf("%d", &idToRemove);
                removeProduct(inventory, &inventorySize, idToRemove);
                break;

            case 3:
                printf("Enter product ID: ");
                int idToUpdate;
                scanf("%d", &idToUpdate);
                printf("Enter quantity to add/subtract: ");
                int quantityToUpdate;
                scanf("%d", &quantityToUpdate);
                updateProduct(inventory, inventorySize, idToUpdate, quantityToUpdate);
                break;

            case 4:
                displayInventory(inventory, inventorySize);
                break;

            case 5:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}