//FormAI DATASET v1.0 Category: Product Inventory System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining a struct to hold inventory item information
struct product {
    int product_id;
    char product_name[50];
    int quantity;
    float price;
};

// Function to add a product to the inventory
void add_product(struct product *catalogue, int *product_count) {
    printf("\n=== ADD PRODUCT ===\n");

    // Taking input for new product details
    printf("Enter Product ID: ");
    scanf("%d", &catalogue[*product_count].product_id);

    printf("Enter Product Name: ");
    scanf(" %[^\n]s", catalogue[*product_count].product_name);

    printf("Enter Quantity: ");
    scanf("%d", &catalogue[*product_count].quantity);

    printf("Enter Price: ");
    scanf("%f", &catalogue[*product_count].price);

    // Incrementing product count
    (*product_count)++;

    printf("\nProduct Added Successfully!\n");
}

// Function to display all products in the inventory
void display_all_products(struct product *catalogue, int product_count) {
    printf("\n=== CATALOGUE ===\n");
    printf("Product ID\tProduct Name\tQuantity\tPrice\n");

    for (int i = 0; i < product_count; i++) {
        printf("%d\t\t%s\t\t%d\t\t%.2f\n", catalogue[i].product_id, catalogue[i].product_name, catalogue[i].quantity, catalogue[i].price);
    }
}

// Function to search for a product in the inventory
void search_product(struct product *catalogue, int product_count) {
    int product_id;
    int found = 0;

    printf("\n=== SEARCH PRODUCT ===\n");
    printf("Enter Product ID: ");
    scanf("%d", &product_id);

    for (int i = 0; i < product_count; i++) {
        if (catalogue[i].product_id == product_id) {
            printf("\nProduct Found!\n");
            printf("Product ID: %d\n", catalogue[i].product_id);
            printf("Product Name: %s\n", catalogue[i].product_name);
            printf("Quantity: %d\n", catalogue[i].quantity);
            printf("Price: %.2f\n", catalogue[i].price);

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nProduct Not Found!\n");
    }
}

// Main function
int main() {
    struct product catalogue[50]; // array of 50 products, can be changed as needed
    int product_count = 0;
    int choice;

    printf("=== C PRODUCT INVENTORY SYSTEM ===\n");

    do {
        // Displaying menu
        printf("\n1. Add Product");
        printf("\n2. Display All Products");
        printf("\n3. Search Product");
        printf("\n4. Exit");
        printf("\n\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product(catalogue, &product_count);
                break;
            case 2:
                display_all_products(catalogue, product_count);
                break;
            case 3:
                search_product(catalogue, product_count);
                break;
            case 4:
                printf("\nClosing Product Inventory System...\n");
                break;
            default:
                printf("\nInvalid Choice! Please Try Again.\n");
        }
    } while (choice != 4);

    return 0;
}