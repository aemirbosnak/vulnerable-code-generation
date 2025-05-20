//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

// Definitions
#define MAX_PRODUCTS 100
#define PRODUCT_NAME_SIZE 50
#define PRODUCT_QUANTITY_SIZE 10

// Product structure
typedef struct {
    char name[PRODUCT_NAME_SIZE];
    int quantity;
} Product;

// Global variables
Product inventory[MAX_PRODUCTS];
int num_products = 0;

// Surrealist functions
void generate_product_name(char* name) {
    int i;
    char elements[5][10] = {"apple", "tree", "dream", "cloud", "moon"};

    for (i = 0; i < 5; i++) {
        strcat(name, elements[rand() % 5]);
        strcat(name, " ");
    }

    name[strlen(name) - 1] = '\0';
}

void add_product_to_inventory() {
    Product new_product;
    char name[PRODUCT_NAME_SIZE];

    generate_product_name(name);
    new_product.quantity = rand() % 100 + 1;
    strcpy(new_product.name, name);

    inventory[num_products++] = new_product;
    printf("Added product: %s with quantity: %d\n", name, new_product.quantity);
}

void display_inventory() {
    int i;

    printf("-------------------------------\n");
    printf("| Product Inventory Report      |\n");
    printf("-------------------------------\n");

    for (i = 0; i < num_products; i++) {
        printf("| %s \t| %d \t|\n", inventory[i].name, inventory[i].quantity);
    }

    printf("-------------------------------\n");
}

// Main function
int main() {
    int choice;

    srand(time(NULL)); // Seed random generator

    do {
        printf("1. Add Product\n");
        printf("2. Display Inventory\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product_to_inventory();
                break;
            case 2:
                display_inventory();
                break;
            case 3:
                printf("Quitting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}