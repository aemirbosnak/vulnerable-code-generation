//FormAI DATASET v1.0 Category: Product Inventory System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODUCTS 100

// Define a product struct
typedef struct {
    int product_id;
    char *product_name;
    int product_quantity;
    float product_price;
} product;

// Declare functions
void addProduct(product[], int*);
void removeProduct(product[], int*);
void displayInventory(product[], int);

int main() {
    product inventory[MAX_PRODUCTS]; // Create an array of products
    int num_products = 0; // Keep track of number of products in inventory

    int choice;
    do {
        printf("\n\nPRODUCT INVENTORY SYSTEM\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. Display Inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(inventory, &num_products);
                break;
            case 2:
                removeProduct(inventory, &num_products);
                break;
            case 3:
                displayInventory(inventory, num_products);
                break;
            case 4:
                printf("Exiting program...");
                break;
            default:
                printf("Invalid choice. Please try again.");
        }
    } while (choice != 4);

    return 0;
}

void addProduct(product inventory[], int *num_products) {
    if (*num_products == MAX_PRODUCTS) {
        printf("Inventory is full. Cannot add more products.");
        return;
    }

    product new_product;

    printf("\nEnter Product ID: ");
    scanf("%d", &new_product.product_id);
    printf("Enter Product Name: ");
    getchar(); // Clear input buffer
    new_product.product_name = malloc(100 * sizeof(char)); // Allocate memory for product name
    scanf("%[^\n]", new_product.product_name);
    printf("Enter Product Quantity: ");
    scanf("%d", &new_product.product_quantity);
    printf("Enter Product Price: ");
    scanf("%f", &new_product.product_price);

    inventory[*num_products] = new_product;

    printf("\nProduct added successfully.");
    (*num_products)++;
}

void removeProduct(product inventory[], int *num_products) {
    if (*num_products == 0) {
        printf("Inventory is empty. Cannot remove any product.");
        return;
    }

    int remove_id;
    printf("\nEnter the product ID to remove: ");
    scanf("%d", &remove_id);

    int found = 0;
    for (int i = 0; i < *num_products; i++) {
        if (inventory[i].product_id == remove_id) {
            found = 1;
            for (int j = i; j < *num_products - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            (*num_products)--;
            printf("\nProduct removed successfully.");
            break;
        }
    }

    if (!found) {
        printf("\nProduct with ID %d not found in inventory.", remove_id);
    } 
}

void displayInventory(product inventory[], int num_products) {
    if (num_products == 0) {
        printf("\nInventory is empty.");
        return;
    }

    printf("\nPRODUCT ID\tPRODUCT NAME\t\tQUANTITY\tPRICE");
    for (int i = 0; i < num_products; i++) {
        printf("\n%d\t\t%s\t\t\t%d\t\t%.2f", inventory[i].product_id, inventory[i].product_name,
               inventory[i].product_quantity, inventory[i].product_price);
    }
}