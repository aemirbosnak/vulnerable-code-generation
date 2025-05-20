//FormAI DATASET v1.0 Category: Product Inventory System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100 // Maximum products that can be stored
#define MAX_NAME_LEN 50 // Maximum length of product name

// Struct for a product
typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    int quantity;
    float price;
} Product;

// Array of products
Product products[MAX_PRODUCTS];

// Index of next available product slot
int next_slot = 0;

// Function to add a product
void add_product() {
    // Check if the product inventory is full
    if(next_slot >= MAX_PRODUCTS) {
        printf("Product inventory is full. Cannot add any more products.\n");
        return;
    }

    // Create a new product with ID as the next available slot
    Product new_product;
    new_product.id = next_slot;

    // Get product details from user
    printf("Enter name of product: ");
    scanf("%s", new_product.name);

    printf("Enter quantity of product: ");
    scanf("%d", &new_product.quantity);

    printf("Enter price of product: ");
    scanf("%f", &new_product.price);

    // Add the new product to the products array
    products[next_slot] = new_product;
    next_slot++;

    printf("Product added successfully.\n");
}

// Function to display all products
void display_products() {
    printf("ID\tName\t\tQuantity\tPrice\n");
    for(int i=0; i<next_slot; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
    }
}

// Function to find a product by ID
Product* find_product(int id) {
    for(int i=0; i<next_slot; i++) {
        if(products[i].id == id) {
            return &products[i];
        }
    }
    return NULL; // Product not found
}

// Function to update a product
void update_product() {
    int id;
    printf("Enter ID of product to update: ");
    scanf("%d", &id);

    Product* product = find_product(id);
    if(product == NULL) {
        printf("Product not found.\n");
        return;
    }

    // Update product details
    printf("Enter new name of product: ");
    scanf("%s", product->name);

    printf("Enter new quantity of product: ");
    scanf("%d", &product->quantity);

    printf("Enter new price of product: ");
    scanf("%f", &product->price);

    printf("Product updated successfully.\n");
}

// Function to delete a product
void delete_product() {
    int id;
    printf("Enter ID of product to delete: ");
    scanf("%d", &id);

    Product* product = find_product(id);
    if(product == NULL) {
        printf("Product not found.\n");
        return;
    }

    // Shift products after the deleted product one position left
    for(int i=product->id+1; i<next_slot; i++) {
        products[i-1] = products[i];
        products[i-1].id--; // Update ID of shifted product
    }
    next_slot--;

    printf("Product deleted successfully.\n");
}

int main() {
    while(1) {
        printf("\nChoose an option:\n");
        printf("1. Add a product\n");
        printf("2. Display all products\n");
        printf("3. Update a product\n");
        printf("4. Delete a product\n");
        printf("5. Exit\n");
        printf("Option: ");

        int option;
        scanf("%d", &option);

        switch(option) {
            case 1:
                add_product();
                break;
            case 2:
                display_products();
                break;
            case 3:
                update_product();
                break;
            case 4:
                delete_product();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option.\n");
                break;
        }
    }
}