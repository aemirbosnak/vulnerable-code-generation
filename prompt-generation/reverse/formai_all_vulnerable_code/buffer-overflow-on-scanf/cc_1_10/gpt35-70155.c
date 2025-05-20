//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: irregular
/* Welcome to the Warehouse Management System. */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SIZE 100  // Maximum number of products that can be added to the inventory.

/* Create the structure for the products. */
struct product {
    int id;
    char name[50];
    int quantity;
    float price;
};

/* Function to add products to the inventory. */
void addProduct(struct product inventory[], int *numProducts) {
    printf("\n==== Add Product ====\n");
    /* Check if the inventory is full. */
    if (*numProducts >= SIZE) {
        printf("Inventory is full. Cannot add any more products.\n");
    } else {
        /* Get details of the new product from user. */
        printf("Enter product id: ");
        scanf("%d", &inventory[*numProducts].id);
        printf("Enter product name: ");
        scanf("%s", inventory[*numProducts].name);
        printf("Enter product quantity: ");
        scanf("%d", &inventory[*numProducts].quantity);
        printf("Enter product price: ");
        scanf("%f", &inventory[*numProducts].price);

        /* Increment the number of products. */
        (*numProducts)++;
        printf("Product added to inventory.\n");
    }
}

/* Function to delete products from inventory. */
void deleteProduct(struct product inventory[], int *numProducts) {
    printf("\n==== Delete Product ====\n");
    /* Check if there are any products in the inventory. */
    if (*numProducts == 0) {
        printf("Inventory is empty. No products to delete.\n");
    } else {
        /* Get the product id of the product to be deleted. */
        int idToDelete;
        printf("Enter product id to delete: ");
        scanf("%d", &idToDelete);

        /* Find the index of the product to be deleted. */
        int indexToDelete = -1;
        for (int i = 0; i < *numProducts; i++) {
            if (inventory[i].id == idToDelete) {
                indexToDelete = i;
                break;
            }
        }

        /* If product was found, delete it. */
        if (indexToDelete != -1) {
            for (int j = indexToDelete; j < *numProducts - 1; j++) {    // Shift all elements after the deleted element down by 1.
                inventory[j] = inventory[j + 1];
            }
            (*numProducts)--;
            printf("Product with id %d deleted from inventory.\n", idToDelete);
        } else {
            printf("Product with id %d not found.\n", idToDelete);
        }
    }
}

/* Function to search for a product by its name. */
void searchProduct(struct product inventory[], int numProducts) {
    printf("\n==== Search Product ====\n");
    /* Check if there are any products in the inventory. */
    if (numProducts == 0) {
        printf("Inventory is empty. No products to search for.\n");
    } else {
        /* Get the product name to search for. */
        char nameToSearch[50];
        printf("Enter product name to search for: ");
        scanf("%s", nameToSearch);

        /* Find all products with the given name. */
        int numFound = 0;
        for (int i = 0; i < numProducts; i++) {
            if (strcmp(inventory[i].name, nameToSearch) == 0) {
                printf("Product found:\n");
                printf("Id: %d\n", inventory[i].id);
                printf("Name: %s\n", inventory[i].name);
                printf("Quantity: %d\n", inventory[i].quantity);
                printf("Price: %.2f\n", inventory[i].price);
                numFound++;
            }
        }

        /* If no products were found, print a message. */
        if (numFound == 0) {
            printf("No products with name '%s' found.\n", nameToSearch);
        } else {
            printf("Found %d product(s) with name '%s'.\n", numFound, nameToSearch);
        }
    }
}

/* Main function. */
int main() {
    struct product inventory[SIZE];
    int numProducts = 0;    // Number of products currently in the inventory.

    while (1) {
        /* Print the menu. */
        printf("\n===== Warehouse Management System =====\n");
        printf("1. Add Product\n");
        printf("2. Delete Product\n");
        printf("3. Search Product\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        /* Get the user's choice. */
        int choice;
        scanf("%d", &choice);

        /* Perform the action corresponding to the user's choice. */
        switch (choice) {
            case 1:
                addProduct(inventory, &numProducts);
                break;
            case 2:
                deleteProduct(inventory, &numProducts);
                break;
            case 3:
                searchProduct(inventory, numProducts);
                break;
            case 4:
                printf("Exiting program. Thank you for using Warehouse Management System.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}