//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Product structure
typedef struct product {
    char name[50];
    int quantity;
    float price;
} product;

// Function to create a new product
product* create_product(char* name, int quantity, float price) {
    product* p = malloc(sizeof(product));
    strcpy(p->name, name);
    p->quantity = quantity;
    p->price = price;
    return p;
}

// Function to add a product to the inventory
void add_product(product** inventory, int* size, product* p) {
    *inventory = realloc(*inventory, (*size + 1) * sizeof(product));
    (*inventory)[*size] = *p;
    *size = *size + 1;
}

// Function to remove a product from the inventory
void remove_product(product** inventory, int* size, char* name) {
    int i;
    for (i = 0; i < *size; i++) {
        if (strcmp((*inventory)[i].name, name) == 0) {
            break;
        }
    }
    if (i == *size) {
        printf("Product not found.\n");
    } else {
        for (i; i < *size - 1; i++) {
            (*inventory)[i] = (*inventory)[i + 1];
        }
        *size = *size - 1;
    }
}

// Function to update the quantity of a product
void update_quantity(product** inventory, int* size, char* name, int quantity) {
    int i;
    for (i = 0; i < *size; i++) {
        if (strcmp((*inventory)[i].name, name) == 0) {
            break;
        }
    }
    if (i == *size) {
        printf("Product not found.\n");
    } else {
        (*inventory)[i].quantity = quantity;
    }
}

// Function to print the inventory
void print_inventory(product** inventory, int* size) {
    int i;
    printf("Inventory:\n");
    printf("----------------------------------------------------------------------------------------------------------------------\n");
    printf("| %-5s | %-20s | %-10s | %-10s | %-10s | %-10s |\n", "ID", "Name", "Quantity", "Price", "Total Price", "Status");
    printf("----------------------------------------------------------------------------------------------------------------------\n");
    for (i = 0; i < *size; i++) {
        printf("| %-5d | %-20s | %-10d | %-10.2f | %-10.2f | %-10s |\n", i, (*inventory)[i].name, (*inventory)[i].quantity, (*inventory)[i].price, (*inventory)[i].quantity * (*inventory)[i].price, (*inventory)[i].quantity <= 0 ? "Out of Stock" : "In Stock");
    }
    printf("----------------------------------------------------------------------------------------------------------------------\n");
}

int main() {
    int choice, size = 0;
    char name[50];
    int quantity;
    float price;
    product* inventory = NULL;

    while (1) {
        printf("1. Add a product\n");
        printf("2. Remove a product\n");
        printf("3. Update the quantity of a product\n");
        printf("4. Print the inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the product: ");
                scanf("%s", name);
                printf("Enter the quantity of the product: ");
                scanf("%d", &quantity);
                printf("Enter the price of the product: ");
                scanf("%f", &price);
                add_product(&inventory, &size, create_product(name, quantity, price));
                break;
            case 2:
                printf("Enter the name of the product to remove: ");
                scanf("%s", name);
                remove_product(&inventory, &size, name);
                break;
            case 3:
                printf("Enter the name of the product to update: ");
                scanf("%s", name);
                printf("Enter the new quantity of the product: ");
                scanf("%d", &quantity);
                update_quantity(&inventory, &size, name, quantity);
                break;
            case 4:
                print_inventory(&inventory, &size);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}