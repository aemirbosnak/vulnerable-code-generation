//FormAI DATASET v1.0 Category: Product Inventory System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold the product details
typedef struct {
    char name[50];
    int id;
    int quantity;
    float price;
} product;

// Declare a global array to hold the products
product inventory[50];

// Declare a global variable to hold the number of products in the inventory
int num_products_in_inventory = 0;

// Function to add a new product to the inventory
void add_product() {
    product new_product;
    printf("Enter the name of the product: ");
    scanf("%s", new_product.name);
    printf("Enter the product ID: ");
    scanf("%d", &new_product.id);
    printf("Enter the quantity: ");
    scanf("%d", &new_product.quantity);
    printf("Enter the price: ");
    scanf("%f", &new_product.price);
    inventory[num_products_in_inventory] = new_product;
    num_products_in_inventory++;
    printf("Product added to inventory successfully!\n");
}

// Function to display all the products in the inventory
void display_inventory() {
    printf("Product Name\tProduct ID\tQuantity\tPrice\n");
    for (int i = 0; i < num_products_in_inventory; i++) {
        printf("%s\t\t%d\t\t%d\t\t%f\n", inventory[i].name, inventory[i].id, inventory[i].quantity, inventory[i].price);
    }
}

// Function to search for a product in the inventory by its ID
void search_product_by_id() {
    int id;
    printf("Enter the product ID: ");
    scanf("%d", &id);
    for (int i = 0; i < num_products_in_inventory; i++) {
        if (inventory[i].id == id) {
            printf("Product Name: %s\nQuantity: %d\nPrice: %f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    printf("Product not found!\n");
}

// Function to remove a product from the inventory by its ID
void remove_product_by_id() {
    int id;
    printf("Enter the product ID: ");
    scanf("%d", &id);
    for (int i = 0; i < num_products_in_inventory; i++) {
        if (inventory[i].id == id) {
            for (int j = i; j < num_products_in_inventory - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            num_products_in_inventory--;
            printf("Product removed from inventory successfully!\n");
            return;
        }
    }
    printf("Product not found!\n");
}

// Main function to run the program
int main() {
    int choice;
    do {
        printf("\n\nProduct Inventory System\n\n");
        printf("1. Add a new product\n");
        printf("2. Display all products\n");
        printf("3. Search a product by ID\n");
        printf("4. Remove a product by ID\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                add_product();
                break;
            case 2:
                display_inventory();
                break;
            case 3:
                search_product_by_id();
                break;
            case 4:
                remove_product_by_id();
                break;
            case 5:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    return 0;
}