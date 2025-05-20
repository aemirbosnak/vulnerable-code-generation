//FormAI DATASET v1.0 Category: Product Inventory System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold information about each product
typedef struct product {
    char name[50];
    int id;
    int quantity;
    float price;
} Product;

// Function to add new product to inventory
void add_product(Product* inventory, int *num_products) {
    printf("Enter name of new product: ");
    fflush(stdin);
    fgets((inventory+*num_products)->name, 50, stdin);
    printf("Enter id of new product: ");
    scanf("%d", &(inventory+*num_products)->id);
    printf("Enter price of new product: ");
    scanf("%f", &(inventory+*num_products)->price);
    printf("Enter quantity of new product: ");
    scanf("%d", &(inventory+*num_products)->quantity);
    (*num_products)++;
    printf("\nProduct added successfully!\n");
}

// Function to remove product from inventory
void remove_product(Product* inventory, int *num_products, int id) {
    int index = -1;
    for (int i=0; i<*num_products; i++) {
        if ((inventory+i)->id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Product not found in inventory!\n");
    } else {
        memmove(inventory+index, inventory+index+1, (*num_products-index-1)*sizeof(Product));
        (*num_products)--;
        printf("\nProduct removed successfully!\n");
    }
}

// Function to print entire inventory
void print_inventory(Product* inventory, int num_products) {
    printf("\nInventory:\n");
    printf("%-50s %-10s %-10s %-10s\n", "Name", "ID", "Price", "Quantity");
    for (int i=0; i<num_products; i++) {
        printf("%-50s %-10d %-10.2f %-10d\n", (inventory+i)->name, (inventory+i)->id, (inventory+i)->price, (inventory+i)->quantity);
    }
}

int main() {
    Product inventory[100]; // Define array to hold products
    int num_products = 0; // Number of products in inventory
    int choice, id;
    do {
        printf("\nProduct Inventory System\n");
        printf("1. Add new product\n");
        printf("2. Remove product by ID\n");
        printf("3. Print entire inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_product(inventory, &num_products);
                break;
            case 2:
                printf("\nEnter ID of product to remove: ");
                scanf("%d", &id);
                remove_product(inventory, &num_products, id);
                break;
            case 3:
                print_inventory(inventory, num_products);
                break;
            case 4:
                printf("\nExiting program.\n");
                break;
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    } while (choice != 4);
    return 0; // Return success
}