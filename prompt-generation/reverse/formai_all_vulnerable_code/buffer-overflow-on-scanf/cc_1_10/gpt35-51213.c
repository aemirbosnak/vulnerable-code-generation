//FormAI DATASET v1.0 Category: Product Inventory System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum capacity of the inventory
#define MAX_CAPACITY 100

// Define the structure for each product in the inventory
struct product {
    char name[50];
    int quantity;
    float price;
};

//Global variables

int count = 0; // Counter for number of products
struct product inventory[MAX_CAPACITY]; // The product inventory

//Function declarations

void add_product();
void remove_product();
void display_inventory();

/* The main function takes input from the user to either add, remove or display products in the inventory*/

int main() {
    int choice;
    while(1) {
        printf("\n1 - Add product\n");
        printf("2 - Remove product\n");
        printf("3 - Display inventory\n");
        printf("4 - Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_product();
                break;
            case 2:
                remove_product();
                break;
            case 3:
                display_inventory();
                break;
            case 4:
                printf("Exiting inventory system\n");
                exit(0);
                break;
            default:
                printf("Invalid Choice\n");
                break;
        }
    }
    return 0;
}

/* This function allows the user to add a new product to the inventory. It takes the name, quantity and price of the product as input*/

void add_product() {
    if (count == MAX_CAPACITY) {
        printf("Inventory is full\n");
        return;
    }
    struct product new_product;
    printf("\nEnter product name: ");
    scanf("%s", new_product.name);
    printf("Enter product quantity: ");
    scanf("%d", &new_product.quantity);
    printf("Enter product price: ");
    scanf("%f", &new_product.price);

    // Add the new product to the inventory array
    inventory[count] = new_product;
    count++;

    printf("\nProduct added successfully\n");
}

/* This function allows the user to remove a product from the inventory based on name.*/

void remove_product() {
    char name[50];
    int i, flag = 0;

    if (count == 0) {
        printf("The inventory is empty\n");
        return;
    }

    printf("\nEnter the name of the product to remove: ");
    scanf("%s", name);

    // Search for the product in the inventory
    for (i = 0; i < count; i++) {
        if (strcmp(name, inventory[i].name) == 0) {
            flag = 1;
            break;
        }
    }
    if (flag == 1) {
        // Shift all the products one place left to remove the product
        for (; i < count; i++) {
            inventory[i] = inventory[i + 1];
        }
        count--;
        printf("\nProduct removed successfully\n");
    } else {
        printf("\nProduct not found\n");
    }
}

/* This function displays the entire inventory */

void display_inventory() {
    int i;
    if (count == 0) {
        printf("The inventory is empty\n");
        return;
    }
    printf("\n%-20s%-20s%-20s\n", "Product", "Quantity", "Price");
    for (i = 0; i < count; i++) {
        printf("%-20s%-20d%-.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}