//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Romeo and Juliet
/* Romeo and Juliet's Warehouse Management System */

#include <stdio.h>
#include <string.h>

typedef struct {
    char name[30];
    int quantity;
    float price;
} product;

void printInventory(product[], int);
void addProduct(product[], int *);
void removeProduct(product[], int *);

int main() {
    int choice, size = 0;
    product inventory[50];

    printf("Welcome to Romeo and Juliet's Warehouse!\n");

    do {
        printf("\nWhat would you like to do?\n");
        printf("1. See inventory\n2. Add product\n3. Remove product\n4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printInventory(inventory, size);
                break;
            case 2:
                addProduct(inventory, &size);
                break;
            case 3:
                removeProduct(inventory, &size);
                break;
            case 4:
                printf("Thank you for visiting Romeo and Juliet's Warehouse!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}

/* Function to print the current inventory */
void printInventory(product inventory[], int size) {
    if (size == 0) {
        printf("The warehouse is currently empty.\n");
    } else {
        printf("Current Inventory:\n");
        printf("%-30s %-10s %-10s\n", "Product Name", "Quantity", "Price");
        printf("-----------------------------------------------\n");

        for (int i = 0; i < size; i++) {
            printf("%-30s %-10d $%-9.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
        }
    }
}

/* Function to add a product to the inventory */
void addProduct(product inventory[], int * size) {
    if (*size >= 50) {
        printf("Sorry, the warehouse is full.\n");
    } else {
        product newProduct;

        printf("What is the name of the product? ");
        scanf("%29s", newProduct.name); // limit name length to 29 characters

        printf("How many %ss are you adding to the inventory? ", newProduct.name);
        scanf("%d", &newProduct.quantity);

        printf("What is the price of each %s? $", newProduct.name);
        scanf("%f", &newProduct.price);

        inventory[*size] = newProduct;
        (*size)++; // increment size of inventory
        printf("%d %ss were added to the inventory.\n", newProduct.quantity, newProduct.name);
    }
}

/* Function to remove a product from the inventory */
void removeProduct(product inventory[], int * size) {
    if (*size == 0) {
        printf("The warehouse is currently empty.\n");
    } else {
        char productName[30];
        int productIndex = -1;

        printf("What is the name of the product you would like to remove? ");
        scanf("%29s", productName); // limit name length to 29 characters

        for (int i = 0; i < *size; i++) {
            if (strcmp(productName, inventory[i].name) == 0) {
                productIndex = i;
                break;
            }
        }

        if (productIndex == -1) {
            printf("Sorry, we do not have %ss in the inventory.\n", productName);
        } else {
            int productQuantity;

            printf("How many %ss would you like to remove? ", productName);
            scanf("%d", &productQuantity);

            if (productQuantity > inventory[productIndex].quantity) {
                printf("Sorry, we only have %d %ss in the inventory.\n", inventory[productIndex].quantity, productName);
            } else {
                inventory[productIndex].quantity -= productQuantity;
                printf("%d %ss were successfully removed from the inventory.\n", productQuantity, productName);

                if (inventory[productIndex].quantity == 0) {
                    printf("Warning: %ss are out of stock! Please restock soon.\n", productName);
                }
            }

            if (inventory[productIndex].quantity == 0) {
                // remove product from inventory and shift remaining products
                for (int i = productIndex; i < (*size) - 1; i++) {
                    inventory[i] = inventory[i + 1];
                }

                (*size)--; // decrement size of inventory
            }
        }
    }
}