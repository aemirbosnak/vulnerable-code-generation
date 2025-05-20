//FormAI DATASET v1.0 Category: Product Inventory System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100 // Maximum number of products that can be stored

// Product structure
typedef struct {
    int id;
    char name[50];
    float price;
    int quantity;
} Product;

// Global variables
Product inventory[MAX_PRODUCTS]; // Array to store inventory
int numProducts = 0; // Number of products in inventory

// Function to display menu and get user's choice
int menu() {
    printf("*****************************************\n");
    printf("***            INVENTORY SYSTEM         *\n");
    printf("*****************************************\n");
    printf("1. Add a product\n");
    printf("2. Display inventory\n");
    printf("3. Update product\n");
    printf("4. Delete product\n");
    printf("5. Search product by name\n");
    printf("6. Exit\n");
    printf("*****************************************\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);
    return choice;
}

// Function to add a new product
void addProduct() {
    printf("\nEnter product details:\n");
    printf("Product ID: ");
    int id;
    scanf("%d", &id);
    // Check if product with same ID already exists
    for(int i=0; i<numProducts; i++) {
        if(inventory[i].id == id) {
            printf("Product with same ID already exists\n");
            return;
        }
    }
    inventory[numProducts].id = id;
    printf("Product name: ");
    scanf("%s", inventory[numProducts].name);
    printf("Price: ");
    scanf("%f", &inventory[numProducts].price);
    printf("Quantity: ");
    scanf("%d", &inventory[numProducts].quantity);
    numProducts++; // Increment number of products
    printf("Product added successfully!\n");
}

// Function to display all products in the inventory
void displayInventory() {
    printf("\nInventory:\n");
    printf("ID\tName\tPrice\tQuantity\n");
    for(int i=0; i<numProducts; i++) {
        printf("%d\t%s\t%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

// Function to update a product
void updateProduct() {
    printf("\nEnter product ID to update: ");
    int id;
    scanf("%d", &id);
    // Find the product in inventory
    int found = 0;
    for(int i=0; i<numProducts; i++) {
        if(inventory[i].id == id) {
            found = 1;
            printf("Enter new details:\n");
            printf("Product name: ");
            scanf("%s", inventory[i].name);
            printf("Price: ");
            scanf("%f", &inventory[i].price);
            printf("Quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Product updated successfully!\n");
            break;
        }
    }
    if(!found) {
        printf("Product not found\n");
    }
}

// Function to delete a product
void deleteProduct() {
    printf("\nEnter product ID to delete: ");
    int id;
    scanf("%d", &id);
    // Find the product in inventory
    int found = 0;
    for(int i=0; i<numProducts; i++) {
        if(inventory[i].id == id) {
            found = 1;
            // Shift all products after this one to the left
            for(int j=i; j<numProducts-1; j++) {
                inventory[j] = inventory[j+1];
            }
            numProducts--; // Decrement number of products
            printf("Product deleted successfully!\n");
            break;
        }
    }
    if(!found) {
        printf("Product not found\n");
    }
}

// Function to search product by name
void searchProduct() {
    printf("\nEnter product name to search: ");
    char name[50];
    scanf("%s", name);
    // Find products with matching name
    int found = 0;
    printf("Search results:\n");
    printf("ID\tName\tPrice\tQuantity\n");
    for(int i=0; i<numProducts; i++) {
        if(strcmp(inventory[i].name, name) == 0) {
            printf("%d\t%s\t%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
            found = 1;
        }
    }
    if(!found) {
        printf("No products found with matching name\n");
    }
}

int main() {
    int choice;
    do {
        choice = menu();
        switch(choice) {
            case 1:
                addProduct();
                break;
            case 2:
                displayInventory();
                break;
            case 3:
                updateProduct();
                break;
            case 4:
                deleteProduct();
                break;
            case 5:
                searchProduct();
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option (1-6).\n");
        }
    } while(choice != 6);
    return 0;
}