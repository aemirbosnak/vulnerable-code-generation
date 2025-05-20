//FormAI DATASET v1.0 Category: Product Inventory System ; Style: peaceful
#include <stdio.h>

// Define the maximum number of products that can be stored in the inventory
#define MAX_PRODUCTS 100

// Define the structure for a product
typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

// Declare the inventory array
Product inventory[MAX_PRODUCTS];

// Declare the current number of products in the inventory
int numProducts = 0;

// Function to display the main menu
void displayMenu() {
    printf("\n=== Product Inventory System ===\n");
    printf("1. Add a product\n");
    printf("2. Display the inventory\n");
    printf("3. Search for a product\n");
    printf("4. Update a product\n");
    printf("5. Delete a product\n");
    printf("6. Exit\n");
}

// Function to add a product to the inventory
void addProduct() {
    // Check if the inventory is full
    if(numProducts >= MAX_PRODUCTS) {
        printf("Inventory is full. Cannot add more products.\n");
        return;
    }

    // Get the details of the product to be added
    printf("Enter the name of the product: ");
    scanf("%s", inventory[numProducts].name);
    printf("Enter the quantity of the product: ");
    scanf("%d", &inventory[numProducts].quantity);
    printf("Enter the price of the product: ");
    scanf("%f", &inventory[numProducts].price);

    // Increment the number of products in the inventory
    numProducts++;

    printf("Product added successfully.\n");
}

// Function to display the inventory
void displayInventory() {
    // Check if there are any products in the inventory
    if(numProducts == 0) {
        printf("Inventory is empty.\n");
        return;
    }

    printf("\n=== Inventory ===\n");
    printf("Name\t\tQuantity\tPrice\n");

    // Loop through all the products in the inventory
    for(int i = 0; i < numProducts; i++) {
        printf("%s\t\t%d\t\t%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

// Function to search for a product in the inventory
void searchProduct() {
    // Check if there are any products in the inventory
    if(numProducts == 0) {
        printf("Inventory is empty.\n");
        return;
    }

    // Get the name of the product to be searched
    char searchName[50];
    printf("Enter the name of the product to be searched: ");
    scanf("%s", searchName);

    // Loop through all the products in the inventory
    for(int i = 0; i < numProducts; i++) {
        // Check if the current product matches the search criteria
        if(strcmp(inventory[i].name, searchName) == 0) {
            printf("Product found: %s\t\t%d\t\t%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
            return;
        }
    }

    // If control reaches here, it means the product was not found
    printf("Product not found.\n");
}

// Function to update a product in the inventory
void updateProduct() {
    // Check if there are any products in the inventory
    if(numProducts == 0) {
        printf("Inventory is empty.\n");
        return;
    }

    // Get the name of the product to be updated
    char updateName[50];
    printf("Enter the name of the product to be updated: ");
    scanf("%s", updateName);

    // Loop through all the products in the inventory
    for(int i = 0; i < numProducts; i++) {
        // Check if the current product matches the search criteria
        if(strcmp(inventory[i].name, updateName) == 0) {
            // Get the updated details of the product
            printf("Enter the new quantity of the product: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter the new price of the product: ");
            scanf("%f", &inventory[i].price);

            printf("Product updated successfully.\n");
            return;
        }
    }

    // If control reaches here, it means the product was not found
    printf("Product not found.\n");
}

// Function to delete a product from the inventory
void deleteProduct() {
    // Check if there are any products in the inventory
    if(numProducts == 0) {
        printf("Inventory is empty.\n");
        return;
    }

    // Get the name of the product to be deleted
    char deleteName[50];
    printf("Enter the name of the product to be deleted: ");
    scanf("%s", deleteName);

    // Loop through all the products in the inventory
    for(int i = 0; i < numProducts; i++) {
        // Check if the current product matches the search criteria
        if(strcmp(inventory[i].name, deleteName) == 0) {
            // Shift all the products after the deleted product one position to the left
            for(int j = i; j < numProducts - 1; j++) {
                inventory[j] = inventory[j+1];
            }

            // Decrement the number of products in the inventory
            numProducts--;

            printf("Product deleted successfully.\n");
            return;
        }
    }

    // If control reaches here, it means the product was not found
    printf("Product not found.\n");
}

int main() {
    int choice;

    // Loop until the user chooses to exit
    while(1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addProduct();
                break;

            case 2:
                displayInventory();
                break;

            case 3:
                searchProduct();
                break;

            case 4:
                updateProduct();
                break;

            case 5:
                deleteProduct();
                break;

            case 6:
                printf("Exiting the program...\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}