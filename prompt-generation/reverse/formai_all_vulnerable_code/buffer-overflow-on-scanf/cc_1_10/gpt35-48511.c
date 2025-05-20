//FormAI DATASET v1.0 Category: Product Inventory System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

// Define our struct for the product inventory
typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

// Define our global array of products
Product inventory[MAX_PRODUCTS];

// Define our current index in the inventory
int currentIndex = 0;

// Declare our functions
void addProduct();
void removeProduct();
void showInventory();

int main()
{
    int choice;
    
    // Initial greeting
    printf("Welcome to the Product Inventory System.\n");
    
    // Loop through the menu until user chooses to exit
    do {
        printf("\nPlease choose an option:\n");
        printf("1. Add a product\n");
        printf("2. Remove a product\n");
        printf("3. Show inventory\n");
        printf("4. Exit\n");
        
        // Get user input
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                removeProduct();
                break;
            case 3:
                showInventory();
                break;
            case 4:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice.\n");
                break;
        }
    } while (choice != 4);
    
    return 0;
}

// Function to add a product to the inventory
void addProduct() {
    // Check if we've reached the maximum number of products
    if (currentIndex == MAX_PRODUCTS) {
        printf("\nSorry, the inventory is full.\n");
        return;
    }
    
    // Get the product details from the user
    printf("\nEnter the name of the product:\n");
    scanf("%s", inventory[currentIndex].name);
    
    printf("Enter the quantity of the product:\n");
    scanf("%d", &inventory[currentIndex].quantity);
    
    printf("Enter the price of the product:\n");
    scanf("%f", &inventory[currentIndex].price);
    
    currentIndex++;
    
    // Let the user know the product was added successfully
    printf("\nProduct added to inventory.\n");
}

// Function to remove a product from the inventory
void removeProduct() {
    // Check if the inventory is empty
    if (currentIndex == 0) {
        printf("\nSorry, the inventory is empty.\n");
        return;
    }
    
    // Get the name of the product to remove
    char nameToRemove[50];
    printf("\nEnter the name of the product to remove:\n");
    scanf("%s", nameToRemove);
    
    // Loop through the inventory to find the product
    int i;
    for (i = 0; i < currentIndex; i++) {
        if (strcmp(nameToRemove, inventory[i].name) == 0) {
            // Shift all products after the one to remove back one position
            int j;
            for (j = i; j < currentIndex - 1; j++) {
                strcpy(inventory[j].name, inventory[j+1].name);
                inventory[j].quantity = inventory[j+1].quantity;
                inventory[j].price = inventory[j+1].price;
            }
            
            // Decrement the current index and let the user know the product was removed successfully
            currentIndex--;
            printf("\nProduct removed from inventory.\n");
            return;
        }
    }
    
    // Let the user know the product wasn't found
    printf("\nProduct not found in inventory.\n");
}

// Function to show the entire inventory
void showInventory() {
    // Check if the inventory is empty
    if (currentIndex == 0) {
        printf("\nSorry, the inventory is empty.\n");
        return;
    }
    
    // Loop through the inventory and print the details of each product
    printf("\n%-20s | %-10s | %s\n", "Name", "Quantity", "Price");
    int i;
    for (i = 0; i < currentIndex; i++) {
        printf("%-20s | %-10d | $%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}