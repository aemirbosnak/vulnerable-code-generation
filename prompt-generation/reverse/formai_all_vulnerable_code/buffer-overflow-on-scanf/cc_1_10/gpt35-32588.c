//FormAI DATASET v1.0 Category: Product Inventory System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    int id;
    char name[50];
    float price;
    int quantity;
};

// function to add a new product to inventory
void add_product(struct product inventory[], int *num_products) {
    printf("\nAdding new product...\n");
    printf("Enter product name: ");
    scanf("%s", inventory[*num_products].name);
    printf("Enter product price: ");
    scanf("%f", &inventory[*num_products].price);
    printf("Enter product quantity: ");
    scanf("%d", &inventory[*num_products].quantity);
    inventory[*num_products].id = *num_products + 1;
    (*num_products)++;
    printf("Product added successfully!\n\n");
}

// function to display all products in inventory
void display_inventory(struct product inventory[], int num_products) {
    printf("\nProduct Inventory:\n");
    printf("-------------------\n");
    printf("%-5s %-20s %-10s %-10s\n", "ID", "Name", "Price", "Quantity");
    for (int i = 0; i < num_products; i++) {
        printf("%-5d %-20s %-10.2f %-10d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
    printf("-------------------\n\n");
}

// function to search for a product by name
void search_product(struct product inventory[], int num_products) {
    char search_name[50];
    printf("\nEnter product name to search: ");
    scanf("%s", search_name);
    for (int i = 0; i < num_products; i++) {
        if (strcmp(search_name, inventory[i].name) == 0) {
            printf("%-5s %-20s %-10s %-10s\n", "ID", "Name", "Price", "Quantity");
            printf("%-5d %-20s %-10.2f %-10d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
            printf("\n");
            return;
        }
    }
    printf("Product not found!\n\n");
}

// function to update a product's information
void update_product(struct product inventory[], int num_products) {
    int update_id;
    printf("\nEnter product ID to update: ");
    scanf("%d", &update_id);
    for (int i = 0; i < num_products; i++) {
        if (inventory[i].id == update_id) {
            printf("Updating product %d...\n", update_id);
            printf("Enter new product name (press enter to keep current name): ");
            char new_name[50];
            scanf("\n%[^\n]", new_name);
            if (strlen(new_name) > 0) {
                strcpy(inventory[i].name, new_name);
            }
            printf("Enter new product price (press enter to keep current price): ");
            char new_price_str[50];
            char *ptr;
            scanf("\n%[^\n]", new_price_str);
            if (strlen(new_price_str) > 0) {
                inventory[i].price = strtof(new_price_str, &ptr);
            }
            printf("Enter new product quantity (press enter to keep current quantity): ");
            char new_quantity_str[50];
            scanf("\n%[^\n]", new_quantity_str);
            if (strlen(new_quantity_str) > 0) {
                inventory[i].quantity = strtol(new_quantity_str, NULL, 10);
            }
            printf("Product updated successfully!\n\n");
            return;
        }
    }
    printf("Product not found!\n\n");
}

int main() {
    struct product inventory[100];
    int num_products = 0;
    int choice;
    do {
        printf("Product Inventory System:\n");
        printf("1. Add product\n");
        printf("2. Display inventory\n");
        printf("3. Search for product\n");
        printf("4. Update product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_product(inventory, &num_products);
                break;
            case 2:
                display_inventory(inventory, num_products);
                break;
            case 3:
                search_product(inventory, num_products);
                break;
            case 4:
                update_product(inventory, num_products);
                break;
            case 5:
                printf("\nExiting... Thank you for using the Product Inventory System!\n\n");
                break;
            default:
                printf("\nInvalid choice! Please enter a valid choice (1-5).\n\n");
                break;
        }
    } while (choice != 5);
    return 0;
}