//FormAI DATASET v1.0 Category: Product Inventory System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODUCTS 50

// Define a structure for each product
typedef struct product {
    char name[20];
    int id, quantity;
    float price;
} Product;

int menu();
void add_product(Product products[], int count);
void remove_product(Product products[], int count);
void list_products(Product products[], int count);
void search_product(Product products[], int count);

int main() {
    Product products[MAX_PRODUCTS];
    int count = 0;
    int choice;

    do {
        // Display menu and get user choice
        choice = menu();

        switch (choice) {
            case 1:
                add_product(products, count);
                count++;
                break;
            case 2:
                remove_product(products, count);
                count--;
                break;
            case 3:
                list_products(products, count);
                break;
            case 4:
                search_product(products, count);
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Display menu and get user choice
int menu() {
    int choice;

    printf("Product Inventory System\n\n");
    printf("1. Add a product\n");
    printf("2. Remove a product\n");
    printf("3. List all products\n");
    printf("4. Search for a product\n");
    printf("5. Quit\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("\n");

    return choice;
}

// Function to add a product
void add_product(Product products[], int count) {
    Product new_product;

    printf("Enter product name: ");
    scanf("%s", new_product.name);
    printf("Enter product id: ");
    scanf("%d", &new_product.id);
    printf("Enter product quantity: ");
    scanf("%d", &new_product.quantity);
    printf("Enter product price: ");
    scanf("%f", &new_product.price);

    products[count] = new_product;

    printf("\nProduct added successfully.\n\n");
}

// Function to remove a product
void remove_product(Product products[], int count) {
    int id, i;

    printf("Enter product id: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (id == products[i].id) {
            products[i] = products[count-1];
            printf("\nProduct removed successfully.\n");
            return;
        }
    }

    printf("\nProduct not found.\n");

}

// Function to list all products
void list_products(Product products[], int count) {
    if (count == 0) {
        printf("\nNo products to list.\n\n");
        return;
    }

    int i;

    printf("Product Inventory:\n\n");

    printf("%-20s %-10s %-10s %-10s\n", "Name", "ID", "Quantity", "Price");
    printf("----------------------------------------------------\n");

    for (i = 0; i < count; i++) {
        printf("%-20s %-10d %-10d %-10.2f\n", products[i].name, products[i].id, products[i].quantity, products[i].price);
    }

    printf("\n");
}

// Function to search for a product
void search_product(Product products[], int count) {
    int id, i;

    printf("Enter product id: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (id == products[i].id) {
            printf("\nProduct found:\n\n");
            printf("Name: %s\n", products[i].name);
            printf("ID: %d\n", products[i].id);
            printf("Quantity: %d\n", products[i].quantity);
            printf("Price: $%.2f\n\n", products[i].price);
            return;
        }
    }

    printf("\nProduct not found.\n");
}