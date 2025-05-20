//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: ephemeral
// Ephemeral style Warehouse Management System

#include <stdio.h>

#define MAX_PRODUCTS 100

// Product struct definition
typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

// Global variables
Product products[MAX_PRODUCTS];
int num_products = 0;

// Function prototypes
void display_menu();
void add_product();
void remove_product();
void display_products();
void update_product();

int main() {
    int selection;

    // Loop until user chooses to exit
    while (1) {
        display_menu();

        // Get user input
        printf("\nEnter selection: ");
        scanf("%d", &selection);

        switch (selection) {
            case 1:
                add_product();
                break;
            case 2:
                remove_product();
                break;
            case 3:
                update_product();
                break;
            case 4:
                display_products();
                break;
            case 5:
                printf("\nExiting program...");
                return 0;
            default:
                printf("\nInvalid selection. Try again.");
                break;
        }
    }

    return 0;
}

void display_menu() {
    printf("\nWarehouse Management System\n\n");
    printf("1. Add product\n");
    printf("2. Remove product\n");
    printf("3. Update product\n");
    printf("4. Display products\n");
    printf("5. Exit program\n");
}

void add_product() {
    Product new_product;
    int id, quantity;
    float price;

    // Get input for new product
    printf("\nEnter new product details:\n");
    printf("ID: ");
    scanf("%d", &id);
    printf("Name: ");
    scanf("%s", new_product.name);
    printf("Quantity: ");
    scanf("%d", &quantity);
    printf("Price: ");
    scanf("%f", &price);

    // Add new product to array
    new_product.id = id;
    new_product.quantity = quantity;
    new_product.price = price;
    products[num_products] = new_product;
    num_products++;

    printf("\nProduct added successfully.\n");
}

void remove_product() {
    int id, i, found = 0;

    // Get ID of product to remove
    printf("\nEnter ID of product to remove: ");
    scanf("%d", &id);

    // Search for product with given ID
    for (i = 0; i < num_products; i++) {
        if (products[i].id == id) {
            // Shift remaining products left to close gap
            for (int j = i; j < num_products - 1; j++) {
                products[j] = products[j + 1];
            }
            num_products--;
            found = 1;
            printf("\nProduct removed successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("\nProduct not found.\n");
    }
}

void update_product() {
    int id, i;

    // Get ID of product to update
    printf("\nEnter ID of product to update: ");
    scanf("%d", &id);

    // Search for product with given ID
    for (i = 0; i < num_products; i++) {
        if (products[i].id == id) {
            // Get new quantity and price for product
            printf("\nEnter new quantity for product: ");
            scanf("%d", &products[i].quantity);
            printf("Enter new price for product: ");
            scanf("%f", &products[i].price);
            printf("\nProduct updated successfully.\n");
            break;
        }
    }

    if (i == num_products) {
        printf("\nProduct not found.\n");
    }
}

void display_products() {
    printf("\nProducts list:\n");
    printf("ID      Name                      Quantity    Price\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < num_products; i++) {
        printf("%-7d %-25s %-11d $%.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
    }
    printf("-------------------------------------------------\n");
}