//Code Llama-13B DATASET v1.0 Category: Warehouse Management System ; Style: energetic
// Warehouse Management System
// A unique program written in an energetic style

#include <stdio.h>
#include <stdlib.h>

// Structures for products and inventory
struct product {
    char name[50];
    int price;
    int quantity;
};

struct inventory {
    struct product *products;
    int num_products;
};

// Function to display the menu
void display_menu() {
    printf("Warehouse Management System\n");
    printf("-------------------------\n");
    printf("1. Add product\n");
    printf("2. Remove product\n");
    printf("3. Update product quantity\n");
    printf("4. Print inventory\n");
    printf("5. Quit\n");
    printf("-------------------------\n");
    printf("Enter your choice: ");
}

// Function to add a product
void add_product(struct inventory *inventory) {
    // Prompt user for product details
    printf("Enter product name: ");
    scanf("%s", &inventory->products[inventory->num_products].name);
    printf("Enter product price: ");
    scanf("%d", &inventory->products[inventory->num_products].price);
    printf("Enter product quantity: ");
    scanf("%d", &inventory->products[inventory->num_products].quantity);

    // Increment the number of products
    inventory->num_products++;
}

// Function to remove a product
void remove_product(struct inventory *inventory) {
    // Prompt user for product name
    printf("Enter product name: ");
    scanf("%s", &inventory->products[inventory->num_products].name);

    // Find the index of the product
    int index = 0;
    for (int i = 0; i < inventory->num_products; i++) {
        if (strcmp(inventory->products[i].name, inventory->products[inventory->num_products].name) == 0) {
            index = i;
            break;
        }
    }

    // Remove the product
    for (int i = index; i < inventory->num_products - 1; i++) {
        inventory->products[i] = inventory->products[i + 1];
    }
    inventory->num_products--;
}

// Function to update product quantity
void update_quantity(struct inventory *inventory) {
    // Prompt user for product name
    printf("Enter product name: ");
    scanf("%s", &inventory->products[inventory->num_products].name);

    // Find the index of the product
    int index = 0;
    for (int i = 0; i < inventory->num_products; i++) {
        if (strcmp(inventory->products[i].name, inventory->products[inventory->num_products].name) == 0) {
            index = i;
            break;
        }
    }

    // Update the product quantity
    printf("Enter the new quantity: ");
    scanf("%d", &inventory->products[index].quantity);
}

// Function to print the inventory
void print_inventory(struct inventory *inventory) {
    printf("Inventory\n");
    for (int i = 0; i < inventory->num_products; i++) {
        printf("%s\t%d\t%d\n", inventory->products[i].name, inventory->products[i].price, inventory->products[i].quantity);
    }
}

int main() {
    // Create an inventory structure
    struct inventory inventory = {NULL, 0};

    // Loop until the user quits
    int choice = 0;
    while (choice != 5) {
        // Display the menu
        display_menu();

        // Get the user's choice
        scanf("%d", &choice);

        // Perform the selected action
        switch (choice) {
            case 1:
                add_product(&inventory);
                break;
            case 2:
                remove_product(&inventory);
                break;
            case 3:
                update_quantity(&inventory);
                break;
            case 4:
                print_inventory(&inventory);
                break;
            case 5:
                // Quit the program
                return 0;
                break;
            default:
                // Invalid choice
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}