//FormAI DATASET v1.0 Category: Product Inventory System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define a struct for product inventory
typedef struct {
    char name[50];
    int id;
    int price;
    int quantity;
} Product;

// function to print all products in inventory
void printInventory(Product* inventory, int size) {
    printf("Product Inventory:\n");

    for (int i = 0; i < size; i++) {
        printf("%d. %s (ID: %d) - $%d - Quantity: %d\n", i+1, inventory[i].name, inventory[i].id, inventory[i].price, inventory[i].quantity);
    }
}

int main() {
    printf("Welcome to the Product Inventory System!\n");

    int inventorySize = 0;
    int userChoice = 0;

    // dynamically allocate memory for the product inventory
    Product* inventory = NULL;

    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a product to inventory\n");
        printf("2. Edit a product in inventory\n");
        printf("3. Remove a product from inventory\n");
        printf("4. Print inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &userChoice);

        switch(userChoice) {
            case 1: ; // add a product to inventory
                inventorySize++;

                // resize the inventory array
                inventory = (Product*) realloc(inventory, sizeof(Product) * inventorySize);

                // get user input for new product
                printf("Enter product name: ");
                scanf("%s", inventory[inventorySize-1].name);
                printf("Enter product ID: ");
                scanf("%d", &inventory[inventorySize-1].id);
                printf("Enter product price: ");
                scanf("%d", &inventory[inventorySize-1].price);
                printf("Enter product quantity: ");
                scanf("%d", &inventory[inventorySize-1].quantity);

                printf("\nProduct added to inventory!\n");
                break;
            case 2: ; // edit a product in inventory
                if (inventorySize == 0) {
                    printf("\nThere are no products in the inventory to edit.\n");
                    break;
                }

                int editChoice = 0;

                printInventory(inventory, inventorySize);

                // get user input for which product to edit
                printf("\nEnter the number of the product you would like to edit: ");
                scanf("%d", &editChoice);

                // check if user entered a valid choice
                if (editChoice < 1 || editChoice > inventorySize) {
                    printf("\nInvalid choice.\n");
                    break;
                }

                // get user input for updated product information
                printf("\nEnter updated product name: ");
                scanf("%s", inventory[editChoice-1].name);
                printf("Enter updated product ID: ");
                scanf("%d", &inventory[editChoice-1].id);
                printf("Enter updated product price: ");
                scanf("%d", &inventory[editChoice-1].price);
                printf("Enter updated product quantity: ");
                scanf("%d", &inventory[editChoice-1].quantity);

                printf("\nProduct updated in inventory!\n");
                break;
            case 3: ; // remove a product from inventory
                if (inventorySize == 0) {
                    printf("\nThere are no products in the inventory to remove.\n");
                    break;
                }

                int removeChoice = 0;

                printInventory(inventory, inventorySize);

                // get user input for which product to remove
                printf("\nEnter the number of the product you would like to remove: ");
                scanf("%d", &removeChoice);

                // check if user entered a valid choice
                if (removeChoice < 1 || removeChoice > inventorySize) {
                    printf("\nInvalid choice.\n");
                    break;
                }

                // shift all elements after the removed product one index to the left
                for (int i = removeChoice-1; i < inventorySize-1; i++) {
                    inventory[i] = inventory[i+1];
                }

                inventorySize--;

                // resize the inventory array
                inventory = (Product*) realloc(inventory, sizeof(Product) * inventorySize);

                printf("\nProduct removed from inventory!\n");
                break;
            case 4: ; // print inventory
                if (inventorySize == 0) {
                    printf("\nThere are no products in the inventory to print.\n");
                    break;
                }

                printInventory(inventory, inventorySize);
                break;
            case 5: ; // exit program
                printf("\nThank you for using the Product Inventory System!\n");
                break;
            default:
                printf("\nInvalid choice.\n");
                break;
        }

    } while(userChoice != 5);

    // free the dynamically allocated memory
    free(inventory);

    return 0;
}