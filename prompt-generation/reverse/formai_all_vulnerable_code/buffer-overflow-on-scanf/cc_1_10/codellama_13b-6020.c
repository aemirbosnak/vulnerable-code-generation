//Code Llama-13B DATASET v1.0 Category: Warehouse Management System ; Style: random
// Warehouse Management System
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

// Structures
typedef struct {
    int id;
    char name[50];
    char location[50];
    char status[50];
} Product;

typedef struct {
    int id;
    char name[50];
    char location[50];
    char status[50];
    int quantity;
    float price;
} Order;

typedef struct {
    int id;
    char name[50];
    char location[50];
    char status[50];
    int quantity;
    float price;
} Inventory;

// Functions
void printMenu();
void createProduct(Product *product);
void createOrder(Order *order);
void createInventory(Inventory *inventory);
void updateInventory(Inventory *inventory);
void printInventory(Inventory *inventory);

// Main Function
int main() {
    // Variables
    Product product;
    Order order;
    Inventory inventory;
    int option;
    char input;
    bool running = true;

    // Print Menu
    printMenu();

    // Main Loop
    while (running) {
        // Get Option
        printf("Enter an option: ");
        scanf("%d", &option);

        // Create Product
        if (option == 1) {
            createProduct(&product);
        }

        // Create Order
        else if (option == 2) {
            createOrder(&order);
        }

        // Create Inventory
        else if (option == 3) {
            createInventory(&inventory);
        }

        // Update Inventory
        else if (option == 4) {
            updateInventory(&inventory);
        }

        // Print Inventory
        else if (option == 5) {
            printInventory(&inventory);
        }

        // Exit
        else if (option == 6) {
            running = false;
        }
    }

    return 0;
}

// Functions
void printMenu() {
    printf("Warehouse Management System\n");
    printf("--------------------------\n");
    printf("1. Create Product\n");
    printf("2. Create Order\n");
    printf("3. Create Inventory\n");
    printf("4. Update Inventory\n");
    printf("5. Print Inventory\n");
    printf("6. Exit\n");
}

void createProduct(Product *product) {
    printf("Enter product name: ");
    scanf("%s", product->name);
    printf("Enter product location: ");
    scanf("%s", product->location);
    printf("Enter product status: ");
    scanf("%s", product->status);
}

void createOrder(Order *order) {
    printf("Enter order name: ");
    scanf("%s", order->name);
    printf("Enter order location: ");
    scanf("%s", order->location);
    printf("Enter order status: ");
    scanf("%s", order->status);
    printf("Enter order quantity: ");
    scanf("%d", &order->quantity);
    printf("Enter order price: ");
    scanf("%f", &order->price);
}

void createInventory(Inventory *inventory) {
    printf("Enter inventory name: ");
    scanf("%s", inventory->name);
    printf("Enter inventory location: ");
    scanf("%s", inventory->location);
    printf("Enter inventory status: ");
    scanf("%s", inventory->status);
    printf("Enter inventory quantity: ");
    scanf("%d", &inventory->quantity);
    printf("Enter inventory price: ");
    scanf("%f", &inventory->price);
}

void updateInventory(Inventory *inventory) {
    printf("Enter inventory id: ");
    scanf("%d", &inventory->id);
    printf("Enter inventory quantity: ");
    scanf("%d", &inventory->quantity);
    printf("Enter inventory price: ");
    scanf("%f", &inventory->price);
}

void printInventory(Inventory *inventory) {
    printf("Inventory: %s\n", inventory->name);
    printf("Location: %s\n", inventory->location);
    printf("Status: %s\n", inventory->status);
    printf("Quantity: %d\n", inventory->quantity);
    printf("Price: %f\n", inventory->price);
}