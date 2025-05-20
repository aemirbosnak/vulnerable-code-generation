//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100 // Maximum number of products allowed in inventory

struct product {
    int id;
    char name[50];
    int quantity;
    float price;
};

typedef struct product product; // Giving the struct product a typedef name

// Initializing the inventory
product inventory[MAX_PRODUCTS];

// Function to add a product to inventory
int add_product(int id, char name[], int quantity, float price) {
    for(int i=0; i<MAX_PRODUCTS; i++) {
        if(inventory[i].id == 0) {
            inventory[i].id = id;
            strcpy(inventory[i].name, name);
            inventory[i].quantity = quantity;
            inventory[i].price = price;
            return 1; // Return 1 if product is added successfully
        }
    }
    return 0; // Return 0 if maximum number of products is already reached
}

// Function to remove a product from inventory
int remove_product(int id) {
    for(int i=0; i<MAX_PRODUCTS; i++) {
        if(inventory[i].id == id) {
            inventory[i].id = 0;
            inventory[i].name[0] = '\0';
            inventory[i].quantity = 0;
            inventory[i].price = 0.0;
            return 1; // Return 1 if product is removed successfully
        }
    }
    return 0; // Return 0 if product is not found in inventory
}

// Function to display all products in inventory
void display_products() {
    printf("\nID\tName\t\tQuantity\tPrice\n");
    for(int i=0; i<MAX_PRODUCTS; i++) {
        if(inventory[i].id != 0) {
            printf("%d\t%s\t\t%d\t\t$%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
        }
    }
    printf("\n");
}

// Main function to test the inventory system
int main() {
    int choice, id, quantity;
    char name[50];
    float price;
    printf("Welcome to the Product Inventory System\n\n");

    while(1) {
        printf("1. Add Product\t2. Remove Product\t3. Display Products\t4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter Product ID: ");
                scanf("%d", &id);
                printf("Enter Product Name: ");
                scanf("%s", name);
                printf("Enter Product Quantity: ");
                scanf("%d", &quantity);
                printf("Enter Product Price: ");
                scanf("%f", &price);
                if(add_product(id, name, quantity, price)) {
                    printf("\nProduct added to inventory successfully!\n");
                } else {
                    printf("\nMaximum number of products reached!\n");
                }
                break;
            case 2:
                printf("\nEnter Product ID to remove: ");
                scanf("%d", &id);
                if(remove_product(id)) {
                    printf("\nProduct removed from inventory successfully!\n");
                } else {
                    printf("\nProduct not found in inventory!\n");
                }
                break;
            case 3:
                display_products();
                break;
            case 4:
                printf("\nThank you for using the Product Inventory System!\n");
                return 0;
            default:
                printf("\nInvalid choice!\n");
                break;
        }
    }

    return 0;
}