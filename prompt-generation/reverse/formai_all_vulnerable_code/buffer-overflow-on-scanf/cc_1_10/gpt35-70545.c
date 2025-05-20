//FormAI DATASET v1.0 Category: Product Inventory System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

// Structure for product
typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

// Global variables
Product inventory[MAX_PRODUCTS];
int numProducts = 0;

/*********** Function Prototypes ************/
void addProduct();
void removeProduct();
void updateProduct();
void displayInventory();
void searchProduct();

/*********** Main Function ************/
int main() {
    int choice;
    printf("Welcome to the Product Inventory Management System!\n");

    // Main menu
    while(1) {
        printf("\nMAIN MENU\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. Update Product\n");
        printf("4. Display Inventory\n");
        printf("5. Search Product\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addProduct();
                break;

            case 2:
                removeProduct();
                break;

            case 3:
                updateProduct();
                break;

            case 4:
                displayInventory();
                break;

            case 5:
                searchProduct();
                break;

            case 6:
                printf("\nThank you for using the Product Inventory Management System!\n");
                exit(0);

            default:
                printf("\nInvalid choice! Please select again.\n");
        }
    }

    return 0;
}

/*********** Function Definitions ************/
// Function to add product to inventory
void addProduct() {
    if(numProducts < MAX_PRODUCTS) {
        Product p;

        printf("\nEnter the product name: ");
        scanf("%s", p.name);

        printf("Enter the quantity: ");
        scanf("%d", &p.quantity);

        printf("Enter the price: ");
        scanf("%f", &p.price);

        inventory[numProducts] = p;
        numProducts++;

        printf("\nProduct added successfully!\n");
    }
    else {
        printf("\nInventory is full! Cannot add more products.\n");
    }
}

// Function to remove product from inventory
void removeProduct() {
    if(numProducts > 0) {
        char name[50];

        printf("\nEnter the name of the product to remove: ");
        scanf("%s", name);

        for(int i=0;i<numProducts;i++) {
            if(strcmp(inventory[i].name, name) == 0) {
                // Shift the remaining elements to the left
                for(int j=i;j<numProducts-1;j++) {
                    inventory[j] = inventory[j+1];
                }

                numProducts--;
                printf("\nProduct removed successfully!\n");
                return;
            }
        }

        printf("\nProduct not found! Please try again.\n");
    }
    else {
        printf("\nInventory is empty! Cannot remove products.\n");
    }
}

// Function to update product in inventory
void updateProduct() {
    if(numProducts > 0) {
        char name[50];

        printf("\nEnter the name of the product to update: ");
        scanf("%s", name);

        for(int i=0;i<numProducts;i++) {
            if(strcmp(inventory[i].name, name) == 0) {
                printf("\nEnter the new quantity for %s: ", inventory[i].name);
                scanf("%d", &inventory[i].quantity);

                printf("Enter the new price for %s: ", inventory[i].name);
                scanf("%f", &inventory[i].price);

                printf("\nProduct updated successfully!\n");
                return;
            }
        }

        printf("\nProduct not found! Please try again.\n");
    }
    else {
        printf("\nInventory is empty! Cannot update products.\n");
    }
}

// Function to display inventory
void displayInventory() {
    if(numProducts > 0) {
        printf("\nINVENTORY\n");
        printf("Name\tQuantity\tPrice\n");

        for(int i=0;i<numProducts;i++) {
            printf("%s\t%d\t\t%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
        }
    }
    else {
        printf("\nInventory is empty! Nothing to display.\n");
    }
}

// Function to search product in inventory
void searchProduct() {
    if(numProducts > 0) {
        char name[50];

        printf("\nEnter the name of the product to search: ");
        scanf("%s", name);

        for(int i=0;i<numProducts;i++) {
            if(strcmp(inventory[i].name, name) == 0) {
                printf("\nProduct found!\nName: %s\nQuantity: %d\nPrice: %.2f", inventory[i].name, inventory[i].quantity, inventory[i].price);
                return;
            }
        }

        printf("\nProduct not found! Please try again.\n");
    }
    else {
        printf("\nInventory is empty! Nothing to search.\n");
    }
}