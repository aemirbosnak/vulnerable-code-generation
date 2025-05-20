//FormAI DATASET v1.0 Category: Product Inventory System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODS 100 // Maximum number of products in the inventory

typedef struct {
    int id; // Product ID
    char name[50]; // Product name
    float price; // Product price
    int quantity; // Quantity in stock
} product;

product inventory[MAX_PRODS]; // Define the inventory array
int num_prods = 0; // Number of products currently in the inventory

// Function prototypes
void add_prod();
void remove_prod();
void display_prod();
void update_prod();

int main() {
    int choice;
    do {
        printf("\n\nMY PRODUCT INVENTORY SYSTEM\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Display all products\n");
        printf("4. Update product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_prod();
                break;
            case 2:
                remove_prod();
                break;
            case 3:
                display_prod();
                break;
            case 4:
                update_prod();
                break;
            case 5:
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while(choice != 5);

    return 0;
}

// Function to add a new product
void add_prod() {
    if(num_prods == MAX_PRODS) {
        printf("\nInventory is full. Cannot add more products.\n");
        return;
    }

    printf("\nEnter product ID: ");
    scanf("%d", &inventory[num_prods].id);

    printf("Enter product name: ");
    scanf("%s", inventory[num_prods].name);

    printf("Enter product price: ");
    scanf("%f", &inventory[num_prods].price);

    printf("Enter product quantity: ");
    scanf("%d", &inventory[num_prods].quantity);

    num_prods++;
    printf("\nProduct added successfully.\n");
}

// Function to remove a product
void remove_prod() {
    int prod_id, i, found = 0;
    printf("\nEnter product ID to remove: ");
    scanf("%d", &prod_id);

    for(i = 0; i < num_prods; i++) {
        if(inventory[i].id == prod_id) {
            found = 1;
            break;
        }
    }

    if(found) {
        for(; i < num_prods; i++) {
            inventory[i] = inventory[i+1];
        }

        num_prods--;
        printf("\nProduct removed successfully.\n");
    } else {
        printf("\nProduct not found.\n");
    }
}

// Function to display all products
void display_prod() {
    int i;
    if(num_prods == 0) {
        printf("\nInventory is empty.\n");
        return;
    }

    printf("\nProduct ID\tProduct Name\tProduct Price\tProduct Quantity\n");
    for(i = 0; i < num_prods; i++) {
        printf("%d\t\t%s\t\t%.2f\t\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

// Function to update a product
void update_prod() {
    int prod_id, i, found = 0;
    printf("\nEnter product ID to update: ");
    scanf("%d", &prod_id);

    for(i = 0; i < num_prods; i++) {
        if(inventory[i].id == prod_id) {
            found = 1;
            break;
        }
    }

    if(found) {
        printf("\nEnter new product name: ");
        scanf("%s", inventory[i].name);

        printf("Enter new product price: ");
        scanf("%f", &inventory[i].price);

        printf("Enter new product quantity: ");
        scanf("%d", &inventory[i].quantity);

        printf("\nProduct updated successfully.\n");
    } else {
        printf("\nProduct not found.\n");
    }
}