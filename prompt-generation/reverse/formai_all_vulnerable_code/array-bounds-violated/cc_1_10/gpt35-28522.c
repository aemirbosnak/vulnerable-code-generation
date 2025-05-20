//FormAI DATASET v1.0 Category: Product Inventory System ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

// Defining structures for products
typedef struct {
    int id;
    char name[50];
    float price;
} Product;

// Defining structures for inventory
typedef struct {
    int id;
    int quantity;
} Inventory;

// Initializing an array of products
Product products[MAX_SIZE];

// Initializing an array of inventory
Inventory inventory[MAX_SIZE];

// Function to add a new product
void addProduct(int id, char name[], float price) {
    products[id].id = id;
    strcpy(products[id].name, name);
    products[id].price = price;
}

// Function to add stock to an existing product
void addStock(int id, int quantity) {
    inventory[id].quantity += quantity;
}

// Function to remove stock from an existing product
void removeStock(int id, int quantity) {
    if(inventory[id].quantity - quantity >= 0) {
        inventory[id].quantity -= quantity;
    }
    else {
        printf("Not enough stock available!\n");
    }
}

// Function to display product stock
void displayStock(int id) {
    printf("Product ID: %d\n", products[id].id);
    printf("Product Name: %s\n", products[id].name);
    printf("Product Price: $%.2f\n", products[id].price);
    printf("Product Stock: %d\n", inventory[id].quantity);
}

int main() {
    int choice, id, quantity;
    float price;
    char name[50];

    do {
        printf("Enter your choice:\n");
        printf("1. Add a new product.\n");
        printf("2. Add stock to an existing product.\n");
        printf("3. Remove stock from an existing product.\n");
        printf("4. Display product stock.\n");
        printf("5. Exit.\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter product ID: ");
                scanf("%d", &id);
                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter product price: ");
                scanf("%f", &price);
                addProduct(id, name, price);
                printf("Product added successfully!\n");
                break;
            case 2:
                printf("Enter product ID: ");
                scanf("%d", &id);
                printf("Enter quantity to add: ");
                scanf("%d", &quantity);
                addStock(id, quantity);
                printf("Stock added successfully!\n");
                break;
            case 3:
                printf("Enter product ID: ");
                scanf("%d", &id);
                printf("Enter quantity to remove: ");
                scanf("%d", &quantity);
                removeStock(id, quantity);
                printf("Stock removed successfully!\n");
                break;
            case 4:
                printf("Enter product ID: ");
                scanf("%d", &id);
                displayStock(id);
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while(choice != 5);

    return 0;
}