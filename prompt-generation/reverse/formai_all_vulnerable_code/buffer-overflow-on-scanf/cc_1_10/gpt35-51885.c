//FormAI DATASET v1.0 Category: Product Inventory System ; Style: accurate
#include <stdio.h>
#include <string.h>

// Define the maximum size of our inventory
#define MAX_SIZE 100

// Define a structure to store the product information
struct product {
    char name[50];
    int id;
    float price;
};

// Declare an array of products to store the inventory
struct product inventory[MAX_SIZE];

// Declare a variable to keep track of the current number of products in the inventory
int num_products = 0;

// Function prototypes
void add_product();
void display_all_products();
void search_product_by_id();
void search_product_by_name();
void update_product_price();
void delete_product();

// Main function
int main() {
    int choice;
    // Display the menu and get user input until they choose to exit
    do {
        printf("\n\nProduct Inventory System\n\n");
        printf("1. Add a new product\n");
        printf("2. Display all products\n");
        printf("3. Search for a product by ID\n");
        printf("4. Search for a product by name\n");
        printf("5. Update product price\n");
        printf("6. Delete a product\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        // Branch based on the user's input
        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                display_all_products();
                break;
            case 3:
                search_product_by_id();
                break;
            case 4:
                search_product_by_name();
                break;
            case 5:
                update_product_price();
                break;
            case 6:
                delete_product();
                break;
            case 7:
                // Exit the program
                printf("Exiting program...\n\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 7);

    return 0;
}

void add_product() {
    // Check if the inventory is full
    if (num_products == MAX_SIZE) {
        printf("Inventory is full, cannot add a new product.\n");
        return;
    }

    // Get input from the user
    printf("Enter product name: ");
    scanf("%s", inventory[num_products].name);
    printf("Enter product ID: ");
    scanf("%d", &inventory[num_products].id);
    printf("Enter product price: ");
    scanf("%f", &inventory[num_products].price);

    // Increment the number of products in the inventory
    num_products++;

    // Print a success message
    printf("Product added successfully!\n");
}

void display_all_products() {
    // Check if there are no products in the inventory
    if (num_products == 0) {
        printf("Inventory is empty, no products to display.\n");
        return;
    }
    // Print the header for the table
    printf("\nID\t\tName\t\t\tPrice\n");
    printf("---------------------------------------\n");
    // Loop through the products in the inventory and print them
    for (int i = 0; i < num_products; i++) {
        printf("%d\t\t%s\t\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].price);
    }
}

void search_product_by_id() {
    int id;
    // Get the ID to search for from the user
    printf("Enter product ID to search for: ");
    scanf("%d", &id);
    // Loop through the products in the inventory and search for a product with the given ID
    for (int i = 0; i < num_products; i++) {
        if (inventory[i].id == id) {
            printf("Product found:\n");
            printf("Name: %s\n", inventory[i].name);
            printf("Price: %.2f\n", inventory[i].price);
            return;
        }
    }
    // If no product was found with the given ID, print a message to the user
    printf("No product found with the given ID.\n");
}

void search_product_by_name() {
    char name[50];
    // Get the name to search for from the user
    printf("Enter product name to search for: ");
    scanf("%s", name);
    // Loop through the products in the inventory and search for a product with the given name
    for (int i = 0; i < num_products; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Product found:\n");
            printf("ID: %d\n", inventory[i].id);
            printf("Price: %.2f\n", inventory[i].price);
            return;
        }
    }
    // If no product was found with the given name, print a message to the user
    printf("No product found with the given name.\n");
}

void update_product_price() {
    int id;
    float price;
    // Get the ID of the product to update and the new price from the user
    printf("Enter product ID to update: ");
    scanf("%d", &id);
    printf("Enter new product price: ");
    scanf("%f", &price);
    // Loop through the products in the inventory and update the price of the product with the given ID
    for (int i = 0; i < num_products; i++) {
        if (inventory[i].id == id) {
            inventory[i].price = price;
            printf("Price updated successfully!\n");
            return;
        }
    }
    // If no product was found with the given ID, print a message to the user
    printf("No product found with the given ID.\n");
}

void delete_product() {
    int id;
    // Get the ID of the product to delete from the user
    printf("Enter product ID to delete: ");
    scanf("%d", &id);
    // Loop through the products in the inventory and delete the product with the given ID
    for (int i = 0; i < num_products; i++) {
        if (inventory[i].id == id) {
            // Shift all the products after the deleted product one position to the left
            for (int j = i; j < num_products - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            // Decrement the number of products in the inventory
            num_products--;
            printf("Product deleted successfully!\n");
            return;
        }
    }
    // If no product was found with the given ID, print a message to the user
    printf("No product found with the given ID.\n");
}