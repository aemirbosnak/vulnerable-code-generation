//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Claude Shannon
/* The following is an example of a Warehouse Management System written in C, based on the principles of Claude Shannon's information theory. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000 //maximum number of products allowed in the warehouse
#define MAX_NAME_LENGTH 50 //maximum length of a product name
#define MAX_LOCATION_LENGTH 20 //maximum length of a location ID

/* Define a struct for products in the warehouse */
typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
    char location[MAX_LOCATION_LENGTH];
} Product;

/* Define a struct for storing information about products in the warehouse */
typedef struct {
    Product *products[MAX_PRODUCTS];
    int num_products;
} Warehouse;

/* Function prototypes */
void add_product(Warehouse *warehouse);
void remove_product(Warehouse *warehouse);
void update_product(Warehouse *warehouse);
void search_product(Warehouse *warehouse);
void display_products(Warehouse *warehouse);

/* Main function */
int main() {
    int choice;
    Warehouse warehouse;
    warehouse.num_products = 0;
    do {
        /* Display menu and get user choice */
        printf("Warehouse Management System\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Update product\n");
        printf("4. Search product\n");
        printf("5. Display products\n");
        printf("6. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_product(&warehouse);
                break;
            case 2:
                remove_product(&warehouse);
                break;
            case 3:
                update_product(&warehouse);
                break;
            case 4:
                search_product(&warehouse);
                break;
            case 5:
                display_products(&warehouse);
                break;
            case 6: //quit program
                printf("Goodbye.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 6);
    return 0;
}

/* Function to add a product to the warehouse */
void add_product(Warehouse *warehouse) {
    /* Check if max number of products already reached */
    if (warehouse->num_products >= MAX_PRODUCTS) {
        printf("Warehouse is full.\n");
        return;
    }
    /* Allocate memory for a new product */
    Product *new_product = (Product *)malloc(sizeof(Product));
    /* Get info about new product */
    printf("Enter name of product: ");
    scanf("%s", new_product->name);
    printf("Enter quantity of product: ");
    scanf("%d", &new_product->quantity);
    printf("Enter price of product: ");
    scanf("%f", &new_product->price);
    printf("Enter location of product: ");
    scanf("%s", new_product->location);
    /* Add new product to warehouse */
    warehouse->products[warehouse->num_products] = new_product;
    warehouse->num_products++;
    printf("Product added to warehouse.\n");
}

/* Function to remove a product from the warehouse */
void remove_product(Warehouse *warehouse) {
    char name[MAX_NAME_LENGTH];
    int i, found = 0;
    /* Get name of product to remove */
    printf("Enter name of product to remove: ");
    scanf("%s", name);
    /* Search for product in warehouse */
    for (i = 0; i < warehouse->num_products; i++) {
        if (strcmp(name, warehouse->products[i]->name) == 0) {
            /* Remove product from warehouse */
            free(warehouse->products[i]);
            warehouse->products[i] = NULL;
            /* Shift remaining products down in array */
            for (; i < warehouse->num_products - 1; i++)
                warehouse->products[i] = warehouse->products[i + 1];
            warehouse->num_products--;
            found = 1;
            break;
        }
    }
    if (found)
        printf("Product removed from warehouse.\n");
    else
        printf("Product not found.\n");
}

/* Function to update a product in the warehouse */
void update_product(Warehouse *warehouse) {
    char name[MAX_NAME_LENGTH];
    int i, found = 0;
    /* Get name of product to update */
    printf("Enter name of product to update: ");
    scanf("%s", name);
    /* Find product in warehouse */
    for (i = 0; i < warehouse->num_products; i++) {
        if (strcmp(name, warehouse->products[i]->name) == 0) {
            /* Update product info */
            printf("Enter new quantity of product: ");
            scanf("%d", &warehouse->products[i]->quantity);
            printf("Enter new price of product: ");
            scanf("%f", &warehouse->products[i]->price);
            printf("Enter new location of product: ");
            scanf("%s", warehouse->products[i]->location);
            found = 1;
            break;
        }
    }
    if (found)
        printf("Product updated.\n");
    else
        printf("Product not found.\n");
}

/* Function to search for a product in the warehouse */
void search_product(Warehouse *warehouse) {
    char name[MAX_NAME_LENGTH];
    int i, found = 0;
    /* Get name of product to search for */
    printf("Enter name of product to search for: ");
    scanf("%s", name);
    /* Search for product in warehouse */
    for (i = 0; i < warehouse->num_products; i++) {
        if (strcmp(name, warehouse->products[i]->name) == 0) {
            /* Print out product info */
            printf("Name: %s\n", warehouse->products[i]->name);
            printf("Quantity: %d\n", warehouse->products[i]->quantity);
            printf("Price: $%.2f\n", warehouse->products[i]->price);
            printf("Location: %s\n", warehouse->products[i]->location);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("Product not found.\n");
}

/* Function to display all products in the warehouse */
void display_products(Warehouse *warehouse) {
    int i, j;
    /* Print out header */
    printf("%-20s %-10s %-10s %-20s\n", "Name", "Quantity", "Price", "Location");
    /* Print out each product */
    for (i = 0; i < warehouse->num_products; i++) {
        printf("%-20s %-10d $%.2f\t%-20s\n", warehouse->products[i]->name, warehouse->products[i]->quantity, warehouse->products[i]->price, warehouse->products[i]->location);
    }
}