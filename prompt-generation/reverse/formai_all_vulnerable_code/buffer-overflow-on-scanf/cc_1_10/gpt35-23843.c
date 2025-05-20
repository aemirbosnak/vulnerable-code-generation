//FormAI DATASET v1.0 Category: Database simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

// Function prototype declarations
void display_menu();
void add_product(Product *products, int *count);
void display_products(Product *products, int count);
void search_product(Product *products, int count);

int main() {
    // Variable declarations
    Product products[100];  // Maximum 100 products can be stored
    int count = 0;  // Current number of products stored
    int choice;

    // Display the menu and get user's choice
    do {
        display_menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product(products, &count);
                break;
            case 2:
                display_products(products, count);
                break;
            case 3:
                search_product(products, count);
                break;
            case 4:
                printf("\nThank you for using the program. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to display the menu options
void display_menu() {
    printf("\n=====================");
    printf("\nC Database Simulation");
    printf("\n=====================");
    printf("\n1. Add new product");
    printf("\n2. Display all products");
    printf("\n3. Search for a product");
    printf("\n4. Exit");
}

// Function to add a new product to the database
void add_product(Product *products, int *count) {
    Product new_product;

    // Get input from user
    printf("\nEnter product id: ");
    scanf("%d", &new_product.id);
    printf("Enter product name: ");
    scanf("%s", new_product.name);
    printf("Enter product quantity: ");
    scanf("%d", &new_product.quantity);
    printf("Enter product price: ");
    scanf("%f", &new_product.price);

    // Add the new product to the database
    products[*count] = new_product;
    (*count)++;  // Increment the count of products
    printf("\nProduct added successfully!\n");
}

// Function to display all the products in the database
void display_products(Product *products, int count) {
    if (count == 0) {
        printf("\nNo products found.\n");
        return;
    }

    printf("\nID\tName\tQuantity\tPrice\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", products[i].id, products[i].name,
               products[i].quantity, products[i].price);
    }
}

// Function to search for a product in the database
void search_product(Product *products, int count) {
    int id;
    printf("\nEnter product id: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (products[i].id == id) {
            printf("\nProduct found!\n");
            printf("\nID\tName\tQuantity\tPrice\n");
            printf("%d\t%s\t%d\t\t%.2f\n", products[i].id, products[i].name,
                   products[i].quantity, products[i].price);
            return;
        }
    }

    printf("\nProduct not found.\n");
}