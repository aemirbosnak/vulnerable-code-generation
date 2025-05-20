//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_PRODUCTS 100
#define MAX_GARAGE_SIZE 1000
#define MAX_WH_SIZE 2000

// Function to display menu and return user choice
int display_menu() {
    int choice;
    printf("Welcome to the Warehouse Management System\n");
    printf("1. Add product to warehouse\n");
    printf("2. Remove product from warehouse\n");
    printf("3. Display products in warehouse\n");
    printf("4. Check available space in warehouse\n");
    printf("5. Exit\n");
    printf("Enter your choice : ");
    scanf("%d", &choice);
    return choice;
}

// Struct to represent a product in warehouse
typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

// Global variables
Product products[MAX_PRODUCTS];
int num_products = 0;
int garage[MAX_GARAGE_SIZE];
int wh[MAX_WH_SIZE];

// Function to add a product to warehouse
void add_product() {
    Product new_product;
    printf("Enter name of product : ");
    scanf("%s", new_product.name);
    printf("Enter quantity of product : ");
    scanf("%d", &new_product.quantity);
    printf("Enter price of product : ");
    scanf("%f", &new_product.price);
    
    if (num_products == MAX_PRODUCTS) {
        printf("Maximum number of products reached!\n");
        return;
    }
    
    printf("Product added successfully!\n");
    products[num_products] = new_product;
    num_products++;
}

// Function to remove a product from warehouse
void remove_product() {
    int choice;
    printf("Select product to remove : \n");
    for (int i = 0; i < num_products; i++) {
        printf("%d. %s\n", i+1, products[i].name);
    }
    printf("Enter your choice : ");
    scanf("%d", &choice);
    if (choice < 1 || choice > num_products) {
        printf("Invalid choice!\n");
        return;
    }
    printf("Product %s removed successfully!\n", products[choice-1].name);
    for (int i = choice-1; i < num_products-1; i++) {
        products[i] = products[i+1];
    }
    num_products--;
}

// Function to display all products in warehouse
void display_products() {
    printf("Products in warehouse : \n");
    for (int i = 0; i < num_products; i++) {
        printf("%s x %d [$%.2f each]\n", products[i].name, products[i].quantity, products[i].price);
    }
}

// Function to check available space in warehouse
void check_space() {
    int used_space = 0;
    for (int i = 0; i < num_products; i++) {
        used_space += products[i].quantity;
    }
    printf("Available space in warehouse : %d/%d\n", MAX_WH_SIZE - used_space, MAX_WH_SIZE);
}

int main() {
    printf("Initializing warehouse...\n");
    memset(garage, 1, sizeof(garage));
    memset(wh, 0, sizeof(wh));
    printf("Warehouse initialized successfully!\n");
    
    int choice;
    while (1) {
        choice = display_menu();
        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                remove_product();
                break;
            case 3:
                display_products();
                break;
            case 4:
                check_space();
                break;
            case 5:
                printf("Exiting warehouse management system...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}