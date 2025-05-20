//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the product details
typedef struct product {
    int id;
    char name[50];
    float price;
    int quantity;
} product;

// Function to add a product to the inventory
void add_product(product *inventory, int *size) {
    printf("Enter product ID: ");
    scanf("%d", &inventory[*size].id);
    printf("Enter product name: ");
    scanf("%s", inventory[*size].name);
    printf("Enter product price: ");
    scanf("%f", &inventory[*size].price);
    printf("Enter product quantity: ");
    scanf("%d", &inventory[*size].quantity);
    (*size)++;
}

// Function to delete a product from the inventory
void delete_product(product *inventory, int *size) {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < *size; i++) {
        if (inventory[i].id == id) {
            for (int j = i; j < *size - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            (*size)--;
            printf("Product deleted successfully\n");
            return;
        }
    }
    printf("Product not found\n");
}

// Function to search for a product in the inventory
void search_product(product *inventory, int size) {
    int id;
    printf("Enter product ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < size; i++) {
        if (inventory[i].id == id) {
            printf("Product found:\n");
            printf("ID: %d\n", inventory[i].id);
            printf("Name: %s\n", inventory[i].name);
            printf("Price: %f\n", inventory[i].price);
            printf("Quantity: %d\n", inventory[i].quantity);
            return;
        }
    }
    printf("Product not found\n");
}

// Function to update the quantity of a product in the inventory
void update_product_quantity(product *inventory, int size) {
    int id, quantity;
    printf("Enter product ID to update quantity: ");
    scanf("%d", &id);
    for (int i = 0; i < size; i++) {
        if (inventory[i].id == id) {
            printf("Enter new quantity: ");
            scanf("%d", &quantity);
            inventory[i].quantity = quantity;
            printf("Product quantity updated successfully\n");
            return;
        }
    }
    printf("Product not found\n");
}

// Function to display the inventory
void display_inventory(product *inventory, int size) {
    printf("Inventory:\n");
    for (int i = 0; i < size; i++) {
        printf("ID: %d\n", inventory[i].id);
        printf("Name: %s\n", inventory[i].name);
        printf("Price: %f\n", inventory[i].price);
        printf("Quantity: %d\n\n");
    }
}

// Main function
int main() {
    int size = 0;
    product *inventory = malloc(sizeof(product));

    while (1) {
        int choice;
        printf("1. Add product\n");
        printf("2. Delete product\n");
        printf("3. Search product\n");
        printf("4. Update product quantity\n");
        printf("5. Display inventory\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product(inventory, &size);
                break;
            case 2:
                delete_product(inventory, &size);
                break;
            case 3:
                search_product(inventory, size);
                break;
            case 4:
                update_product_quantity(inventory, size);
                break;
            case 5:
                display_inventory(inventory, size);
                break;
            case 6:
                free(inventory);
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}