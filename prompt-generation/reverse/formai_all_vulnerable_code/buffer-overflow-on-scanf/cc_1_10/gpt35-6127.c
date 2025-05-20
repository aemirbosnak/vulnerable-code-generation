//FormAI DATASET v1.0 Category: Product Inventory System ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure to represent a product
struct Product {
    int id; // The unique identifier of the product
    char name[50]; // The name of the product
    char description[100]; // The description of the product
    float price; // The price of the product
    int quantity; // The quantity of the product in stock
};

// Function to add a new product to the inventory
void addProduct(struct Product *inventory, int *counter) {
    printf("Enter the name of the product: ");
    scanf("%s", inventory[*counter].name);
    printf("Enter the description of the product: ");
    scanf("%s", inventory[*counter].description);
    printf("Enter the price of the product: ");
    scanf("%f", &inventory[*counter].price);
    printf("Enter the quantity of the product: ");
    scanf("%d", &inventory[*counter].quantity);
    inventory[*counter].id = *counter + 1; // Assigning a unique ID to each product
    *counter = *counter + 1; // Increasing the counter of the inventory
}

// Function to display all the products in the inventory
void displayInventory(struct Product *inventory, int counter) {
    printf("Product ID\tProduct Name\tDescription\tPrice\tQuantity\n");
    for(int i=0; i<counter; i++) {
        printf("%d\t\t%s\t%s\t%f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].description, inventory[i].price, inventory[i].quantity);
    }
}

// Function to search for a product by ID
void searchProductByID(struct Product *inventory, int counter) {
    int id;
    printf("Enter the ID of the product to search: ");
    scanf("%d", &id);
    for(int i=0; i<counter; i++) {
        if(inventory[i].id == id) {
            printf("Product found!\n");
            printf("Product Name: %s\n", inventory[i].name);
            printf("Product Description: %s\n", inventory[i].description);
            printf("Product Price: %f\n", inventory[i].price);
            printf("Product Quantity: %d\n", inventory[i].quantity);
            return;
        }
    }
    printf("Product not found!\n");
}

// Function to search for a product by name
void searchProductByName(struct Product *inventory, int counter) {
    char name[50];
    printf("Enter the name of the product to search: ");
    scanf("%s", name);
    for(int i=0; i<counter; i++) {
        if(strcmp(inventory[i].name, name) == 0) {
            printf("Product found!\n");
            printf("Product ID: %d\n", inventory[i].id);
            printf("Product Description: %s\n", inventory[i].description);
            printf("Product Price: %f\n", inventory[i].price);
            printf("Product Quantity: %d\n", inventory[i].quantity);
            return;
        }
    }
    printf("Product not found!\n");
}

// Function to update the details of a product
void updateProduct(struct Product *inventory, int counter) {
    int id, choice;
    printf("Enter the ID of the product to update: ");
    scanf("%d", &id);
    for(int i=0; i<counter; i++) {
        if(inventory[i].id == id) {
            printf("\nCurrent Details:\n");
            printf("Product Name: %s\n", inventory[i].name);
            printf("Product Description: %s\n", inventory[i].description);
            printf("Product Price: %f\n", inventory[i].price);
            printf("Product Quantity: %d\n", inventory[i].quantity);
            printf("\nWhat information do you want to update? Select an option:\n");
            printf("1. Product Name\n");
            printf("2. Product Description\n");
            printf("3. Product Price\n");
            printf("4. Product Quantity\n");
            printf("Your choice: ");
            scanf("%d", &choice);
            switch(choice) {
                case 1:
                    printf("Enter the new name: ");
                    scanf("%s", inventory[i].name);
                    break;
                case 2:
                    printf("Enter the new description: ");
                    scanf("%s", inventory[i].description);
                    break;
                case 3:
                    printf("Enter the new price: ");
                    scanf("%f", &inventory[i].price);
                    break;
                case 4:
                    printf("Enter the new quantity: ");
                    scanf("%d", &inventory[i].quantity);
                    break;
                default:
                    printf("Invalid choice!\n");
                    return;
            }
            printf("Product updated successfully!\n");
            return;
        }
    }
    printf("Product not found!\n");
}

int main() {
    struct Product inventory[100]; // The array to store the inventory of products
    int counter = 0; // The counter to keep track of the number of products in the inventory
    int choice;
    do {
        printf("\nWelcome to the Product Inventory System!\n");
        printf("1. Add a new product\n");
        printf("2. Display all products\n");
        printf("3. Search for a product by ID\n");
        printf("4. Search for a product by name\n");
        printf("5. Update the details of a product\n");
        printf("6. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addProduct(inventory, &counter);
                break;
            case 2:
                displayInventory(inventory, counter);
                break;
            case 3:
                searchProductByID(inventory, counter);
                break;
            case 4:
                searchProductByName(inventory, counter);
                break;
            case 5:
                updateProduct(inventory, counter);
                break;
            case 6:
                printf("Exiting the program...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 6);
    return 0;
}