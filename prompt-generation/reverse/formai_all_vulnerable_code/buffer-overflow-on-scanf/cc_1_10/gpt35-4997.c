//FormAI DATASET v1.0 Category: Product Inventory System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50

// Product structure
typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    float price;
    int quantity;
} Product;

// Function prototypes
void add_product(Product all_products[], int *num_products);
void edit_product(Product all_products[], int num_products);
void delete_product(Product all_products[], int *num_products);
void search_product(Product all_products[], int num_products);
void print_product(Product p);
void print_inventory(Product all_products[], int num_products);

int main() {
    Product all_products[MAX_PRODUCTS];  // Array to hold all products
    int num_products = 0;  // Number of products in the array

    int choice;
    do {
        // Print menu options
        printf("\nProduct Inventory System");
        printf("\n------------------------");
        printf("\n1. Add product");
        printf("\n2. Edit product");
        printf("\n3. Delete product");
        printf("\n4. Search product");
        printf("\n5. Print inventory");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");

        // Get user choice
        scanf("%d", &choice);

        // Perform action based on user choice
        switch (choice) {
            case 1:
                add_product(all_products, &num_products);
                break;
            case 2:
                edit_product(all_products, num_products);
                break;
            case 3:
                delete_product(all_products, &num_products);
                break;
            case 4:
                search_product(all_products, num_products);
                break;
            case 5:
                print_inventory(all_products, num_products);
                break;
            case 6:
                printf("\nExiting program. Goodbye.\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }

    } while (choice != 6);

    return 0;
}

// Function to add a new product to the array
void add_product(Product all_products[], int *num_products) {
    if (*num_products >= MAX_PRODUCTS) {
        printf("\nError: Maximum number of products reached.\n");
        return;
    }

    Product new_product;

    // Get product details from user
    printf("\nAdding Product");
    printf("\n--------------");
    printf("\nEnter product name: ");
    scanf("%s", new_product.name);
    printf("Enter product price: ");
    scanf("%f", &new_product.price);
    printf("Enter product quantity: ");
    scanf("%d", &new_product.quantity);

    // Generate ID for new product
    if (*num_products == 0) {
        new_product.id = 1;
    } else {
        new_product.id = all_products[*num_products - 1].id + 1;
    }

    all_products[*num_products] = new_product;
    (*num_products)++;

    printf("\nNew product added successfully.\n");
}

// Function to edit an existing product in the array
void edit_product(Product all_products[], int num_products) {
    if (num_products == 0) {
        printf("\nError: No products in inventory.\n");
        return;
    }

    int id;
    int product_found = 0;
    int i;

    // Get ID of product to edit
    printf("\nEditing Product");
    printf("\n---------------");
    printf("\nEnter ID of product to edit: ");
    scanf("%d", &id);

    // Find product in array
    for (i = 0; i < num_products; i++) {
        if (all_products[i].id == id) {
            product_found = 1;

            // Get new product details from user
            printf("\nEditing Product %d", id);
            printf("\n------------------");
            printf("\nEnter new product name: ");
            scanf("%s", all_products[i].name);
            printf("Enter new product price: ");
            scanf("%f", &all_products[i].price);
            printf("Enter new product quantity: ");
            scanf("%d", &all_products[i].quantity);

            printf("\nProduct %d edited successfully.\n", id);

            break;
        }
    }

    if (!product_found) {
        printf("\nError: Product not found.\n");
    }
}

// Function to delete an existing product from the array
void delete_product(Product all_products[], int *num_products) {
    if (*num_products == 0) {
        printf("\nError: No products in inventory.\n");
        return;
    }

    int id;
    int product_found = 0;
    int i;

    // Get ID of product to delete
    printf("\nDeleting Product");
    printf("\n----------------");
    printf("\nEnter ID of product to delete: ");
    scanf("%d", &id);

    // Find product in array
    for (i = 0; i < *num_products; i++) {
        if (all_products[i].id == id) {
            product_found = 1;

            // Shift all products after the deleted one back one position in the array
            for (int j = i; j < *num_products - 1; j++) {
                all_products[j] = all_products[j+1];
            }

            (*num_products)--;

            printf("\nProduct %d deleted successfully.\n", id);

            break;
        }
    }

    if (!product_found) {
        printf("\nError: Product not found.\n");
    }
}

// Function to search for a product in the array and print its details
void search_product(Product all_products[], int num_products) {
    if (num_products == 0) {
        printf("\nError: No products in inventory.\n");
        return;
    }

    int id;
    int product_found = 0;
    int i;

    // Get ID of product to search for
    printf("\nSearching for Product");
    printf("\n---------------------");
    printf("\nEnter ID of product to search for: ");
    scanf("%d", &id);

    // Find product in array
    for (i = 0; i < num_products; i++) {
        if (all_products[i].id == id) {
            product_found = 1;
            print_product(all_products[i]);
            break;
        }
    }

    if (!product_found) {
        printf("\nProduct not found.\n");
    }
}

// Function to print the details of a single product
void print_product(Product p) {
    printf("\nProduct ID: %d", p.id);
    printf("\nName: %s", p.name);
    printf("\nPrice: $%.2f", p.price);
    printf("\nQuantity: %d\n", p.quantity);
}

// Function to print the details of all products in the inventory
void print_inventory(Product all_products[], int num_products) {
    if (num_products == 0) {
        printf("\nNo products in inventory.\n");
        return;
    }

    printf("\nProduct Inventory");
    printf("\n-----------------");

    for (int i = 0; i < num_products; i++) {
        print_product(all_products[i]);
        printf("\n");
    }
}