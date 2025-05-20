//FormAI DATASET v1.0 Category: Product Inventory System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

// Product struct
typedef struct {
    char name[50];
    float price;
    int quantity;
} Product;

// Function prototypes
void displayMenu();
void addProduct(Product *products, int *count);
void removeProduct(Product *products, int *count);
void displayInventory(Product *products, int count);

int main() {
    Product inventory[MAX_PRODUCTS];
    int count = 0;
    int choice = 0;

    while(choice != 4) {
        // Display menu and get user choice
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform action based on user choice
        switch(choice) {
            case 1:
                addProduct(inventory, &count);
                break;
            case 2:
                removeProduct(inventory, &count);
                break;
            case 3:
                displayInventory(inventory, count);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Displays menu options
void displayMenu() {
    printf("\n1. Add Product\n");
    printf("2. Remove Product\n");
    printf("3. Display Inventory\n");
    printf("4. Exit\n");
}

// Adds a new product to the inventory
void addProduct(Product *products, int *count) {
    char name[50];
    float price;
    int quantity;

    // Get product info from user
    printf("\nEnter product name: ");
    scanf("%s", name);
    printf("Enter product price: ");
    scanf("%f", &price);
    printf("Enter product quantity: ");
    scanf("%d", &quantity);

    // Create new Product and add to inventory
    Product newProduct;
    strcpy(newProduct.name, name);
    newProduct.price = price;
    newProduct.quantity = quantity;
    products[*count] = newProduct;

    // Increment product count
    (*count)++;

    printf("\nProduct added successfully.\n");
}

// Removes a product from the inventory
void removeProduct(Product *products, int *count) {
    char name[50];

    // Get product name from user
    printf("\nEnter product name: ");
    scanf("%s", name);

    // Find product in inventory
    int foundIndex = -1;
    for(int i=0; i<*count; i++) {
        if(strcmp(products[i].name, name) == 0) {
            foundIndex = i;
            break;
        }
    }

    // Remove product if found
    if(foundIndex != -1) {
        // Shift products after found product left one spot
        for(int i = foundIndex; i < (*count)-1; i++) {
            products[i] = products[i+1];
        }
        // Decrement product count
        (*count)--;
        printf("\nProduct removed successfully.\n");
    } else {
        printf("\nProduct could not be found.\n");
    }
}

// Displays the current inventory
void displayInventory(Product *products, int count) {
    printf("\nCurrent Inventory\n-----------------\n");
    for(int i=0; i<count; i++) {
        printf("%s - $%.2f - %d\n", products[i].name, products[i].price, products[i].quantity);
    }
    printf("-----------------\n");
}