//FormAI DATASET v1.0 Category: Product Inventory System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

// Define a product structure
struct product {
    char name[50];
    int quantity;
    float price;
};

// Function prototypes
void add_product(struct product[], int);
void update_product(struct product[], int);
void display_products(struct product[], int);

int main() {
    struct product inventory[MAX_PRODUCTS];
    int num_products = 0, choice;
    
    // Display a menu for user to choose an operation
    printf("Welcome to the Product Inventory System!\n");
    do {
        printf("\nMenu:\n");
        printf("1. Add a new product\n");
        printf("2. Update an existing product\n");
        printf("3. Display all products\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                add_product(inventory, num_products);
                num_products++;
                break;
            case 2:
                update_product(inventory, num_products);
                break;
            case 3:
                display_products(inventory, num_products);
                break;
            case 4:
                printf("Thank you for using the Product Inventory System.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        
    } while(choice != 4);
    
    return 0;
}

// Function to add a new product to the inventory
void add_product(struct product inventory[], int index) {
    printf("Adding a new product:\n");
    
    printf("Enter the product name: ");
    scanf("%s", inventory[index].name);
    
    printf("Enter the product quantity: ");
    scanf("%d", &inventory[index].quantity);
    
    printf("Enter the product price: ");
    scanf("%f", &inventory[index].price);
    
    printf("Product added successfully!\n");
}

// Function to update an existing product in the inventory
void update_product(struct product inventory[], int num_products) {
    int i, found = 0;
    char name[50];
    
    printf("Updating an existing product:\n");
    
    printf("Enter the name of the product to update: ");
    scanf("%s", name);
    
    for(i = 0; i < num_products; i++) {
        if(strcmp(name, inventory[i].name) == 0) {
            found = 1;
            printf("Enter the new quantity for %s: ", name);
            scanf("%d", &inventory[i].quantity);
            
            printf("Enter the new price for %s: ", name);
            scanf("%f", &inventory[i].price);
            
            printf("Product %s updated successfully!\n", name);
            break;
        }
    }
    
    if(!found) {
        printf("Product %s not found. Please try again.\n", name);
    }
}

// Function to display all products in the inventory
void display_products(struct product inventory[], int num_products) {
    int i;
    
    printf("Product Inventory:\n");
    printf("Name\tQuantity\tPrice\n");
    
    for(i = 0; i < num_products; i++) {
        printf("%s\t%d\t\t%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}