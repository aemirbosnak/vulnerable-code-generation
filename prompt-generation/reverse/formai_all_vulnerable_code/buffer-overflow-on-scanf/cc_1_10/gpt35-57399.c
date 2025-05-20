//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
} Product;

Product inventory[MAX_PRODUCTS];
int total_products = 0;

void add_product(char* name, int quantity) {
    if (total_products == MAX_PRODUCTS) {
        printf("Maximum capacity reached. Cannot add more products.\n");
        exit(1);
    }
    for (int i = 0; i < total_products; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Product already exists in inventory.\n");
            exit(1);
        }
    }
    Product new_product;
    strncpy(new_product.name, name, MAX_NAME_LEN);
    new_product.quantity = quantity;
    inventory[total_products++] = new_product;
    printf("Product added successfully.\n");
}

void remove_product(char* name) {
    int index = -1;
    for (int i = 0; i < total_products; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Product does not exist in inventory.\n");
        exit(1);
    }
    for (int i = index; i < total_products-1; i++) {
        inventory[i] = inventory[i+1];
    }
    total_products--;
    printf("Product removed successfully.\n");
}

void update_quantity(char* name, int quantity) {
    for (int i = 0; i < total_products; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            inventory[i].quantity = quantity;
            printf("Quantity updated successfully.\n");
            return;
        }
    }
    printf("Product does not exist in inventory.\n");
    exit(1);
}

void display_inventory() {
    printf("CURRENT INVENTORY:\n");
    printf("NAME\tQUANTITY\n");
    for (int i = 0; i < total_products; i++) {
        printf("%s\t%d\n", inventory[i].name, inventory[i].quantity);
    }
}

int main() {
    printf("Welcome to the paranoid Warehouse Management System!\n");
    printf("Please select an option:\n");
    printf("1. Add product\n");
    printf("2. Remove product\n");
    printf("3. Update quantity of product\n");
    printf("4. Display inventory\n");
    printf("5. Exit program\n");
    while (1) {
        int option;
        printf("Enter option number: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("Please enter product name: ");
                char name[MAX_NAME_LEN];
                scanf("%s", name);
                printf("Please enter product quantity: ");
                int quantity;
                scanf("%d", &quantity);
                add_product(name, quantity);
                break;
            case 2:
                printf("Please enter product name: ");
                char name2[MAX_NAME_LEN];
                scanf("%s", name2);
                remove_product(name2);
                break;
            case 3:
                printf("Please enter product name: ");
                char name3[MAX_NAME_LEN];
                scanf("%s", name3);
                printf("Please enter new product quantity: ");
                int quantity2;
                scanf("%d", &quantity2);
                update_quantity(name3, quantity2);
                break;
            case 4:
                display_inventory();
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
    return 0;
}