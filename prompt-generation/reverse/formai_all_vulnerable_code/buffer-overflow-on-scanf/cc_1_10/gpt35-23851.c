//FormAI DATASET v1.0 Category: Product Inventory System ; Style: artistic
#include<stdio.h>
#include<string.h>

// Structure for inventory
struct product {
    int product_id;
    char product_name[50];
    int quantity;
    float price;
};

// Function to add new product in inventory
void add_new_product(struct product *inventory, int *inventory_count) {
    struct product new_product;

    // Getting inputs about new product
    printf("\n---------Add new Product---------\n");
    printf("Product ID: ");
    scanf("%d", &new_product.product_id);
    printf("Product Name: ");
    scanf("%s", new_product.product_name);
    printf("Quantity: ");
    scanf("%d", &new_product.quantity);
    printf("Price per unit: ");
    scanf("%f", &new_product.price);

    // Adding new product to inventory
    inventory[*inventory_count] = new_product;
    (*inventory_count)++;

    printf("\nProduct added to inventory successfully.\n");
}

// Function to display all products in inventory
void display_all_products(struct product *inventory, int inventory_count) {
    printf("\n---------All Products in Inventory---------\n");

    // Displaying all products in inventory
    if (inventory_count == 0) {
        printf("Inventory is empty.\n");
    } else {
        printf("%-15s%-30s%-20s%-20s\n", "Product ID", "Product Name", "Quantity", "Price per unit");
        for(int i=0; i<inventory_count; i++) {
            printf("%-15d%-30s%-20d%-20.2f\n", inventory[i].product_id, inventory[i].product_name, inventory[i].quantity, inventory[i].price);
        }
    }
}

// Function to search a product in inventory by ID
void search_product_by_id(struct product *inventory, int inventory_count) {
    int product_id;
    printf("\n---------Search Product---------\n");
    printf("Enter product ID to search: ");
    scanf("%d", &product_id);

    // Searching for product by ID
    int found = 0;
    for(int i=0; i<inventory_count; i++) {
        if (inventory[i].product_id == product_id) {
            printf("%-15s%-30s%-20s%-20s\n", "Product ID", "Product Name", "Quantity", "Price per unit");
            printf("%-15d%-30s%-20d%-20.2f\n", inventory[i].product_id, inventory[i].product_name, inventory[i].quantity, inventory[i].price);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Product not found in inventory.\n");
    }
}

// Function to update quantity of a product by ID
void update_product_quantity(struct product *inventory, int inventory_count) {
    int product_id, new_quantity;
    printf("\n---------Update Product Quantity---------\n");
    printf("Enter product ID to update quantity: ");
    scanf("%d", &product_id);

    // Searching for product by ID
    int found = 0;
    for(int i=0; i<inventory_count; i++) {
        if (inventory[i].product_id == product_id) {
            printf("%-15s%-30s%-20s%-20s\n", "Product ID", "Product Name", "Quantity", "Price per unit");
            printf("%-15d%-30s%-20d%-20.2f\n", inventory[i].product_id, inventory[i].product_name, inventory[i].quantity, inventory[i].price);

            // Updating quantity
            printf("Enter new quantity: ");
            scanf("%d", &new_quantity);
            inventory[i].quantity = new_quantity;

            printf("\nQuantity updated successfully.\n");

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Product not found in inventory.\n");
    }
}

// Function to calculate total value of inventory
void calculate_total_value(struct product *inventory, int inventory_count) {
    double total_value = 0;
    for(int i=0; i<inventory_count; i++) {
        total_value += inventory[i].quantity * inventory[i].price;
    }
    printf("\nTotal value of inventory is: $%.2lf\n", total_value);
}

// Main function
int main() {
    struct product inventory[50];
    int inventory_count = 0;
    int choice;

    do {
        // Printing inventory menu
        printf("\n---------Inventory Menu---------\n");
        printf("1. Add new product to inventory\n");
        printf("2. Display all products in inventory\n");
        printf("3. Search a product by ID\n");
        printf("4. Update quantity of a product by ID\n");
        printf("5. Calculate total value of inventory\n");
        printf("6. Exit \n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        // Executing selected choice
        switch (choice) {
            case 1:
                add_new_product(inventory, &inventory_count);
                break;
            case 2:
                display_all_products(inventory, inventory_count);
                break;
            case 3:
                search_product_by_id(inventory, inventory_count);
                break;
            case 4:
                update_product_quantity(inventory, inventory_count);
                break;
            case 5:
                calculate_total_value(inventory, inventory_count);
                break;
            case 6:
                printf("\nExiting program...");
                break;
            default:
                printf("\nInvalid choice. Please select a valid option from menu.");
                break;
        }
    } while (choice != 6);

    return 0;
}