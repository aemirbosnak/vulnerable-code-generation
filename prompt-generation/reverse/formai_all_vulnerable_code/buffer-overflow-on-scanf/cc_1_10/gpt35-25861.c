//FormAI DATASET v1.0 Category: Product Inventory System ; Style: satisfied
#include <stdio.h>
#include <string.h>

// Create a product struct to hold information about a product
typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

// Function to add a product to inventory
void add_product(Product inventory[], int* num_products) {
    printf("Enter the product name: ");
    scanf("%s", inventory[*num_products].name);
    printf("Enter the quantity: ");
    scanf("%d", &inventory[*num_products].quantity);
    printf("Enter the price per unit: ");
    scanf("%f", &inventory[*num_products].price);
    inventory[*num_products].id = *num_products + 1;
    (*num_products)++;
    printf("Product added to inventory.\n");
}

// Function to display the inventory
void display_inventory(Product inventory[], int num_products) {
    printf("%-5s%-20s%-10s%-10s\n", "ID", "NAME", "QUANTITY", "PRICE");
    for(int i = 0; i < num_products; i++) {
        printf("%-5d%-20s%-10d%-10.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

// Function to search for a product in inventory
void search_product(Product inventory[], int num_products) {
    char product_name[50];
    printf("Enter the product name: ");
    scanf("%s", product_name);
    for(int i = 0; i < num_products; i++) {
        if(strcmp(inventory[i].name, product_name) == 0) {
            printf("%-5s%-20s%-10s%-10s\n", "ID", "NAME", "QUANTITY", "PRICE");
            printf("%-5d%-20s%-10d%-10.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    printf("Product not found in inventory.\n");
}

// Main function to run the program
int main() {
    // Initialize inventory array and number of products
    Product inventory[100];
    int num_products = 0;

    // Display menu for user to choose from
    int choice;
    do {
        printf("\n===== PRODUCT INVENTORY SYSTEM =====\n");
        printf("1. Add a product\n");
        printf("2. Display inventory\n");
        printf("3. Search for a product\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Call appropriate function based on user's choice
        switch(choice) {
            case 1:
                add_product(inventory, &num_products);
                break;
            case 2:
                display_inventory(inventory, num_products);
                break;
            case 3:
                search_product(inventory, num_products);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while(choice != 4);

    return 0;
}