//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: energetic
// Welcome to our C Warehouse Management System! Get ready for an adventure in inventory management!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our warehouse, a haven for goods and treasures!
typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

// Our trusty inventory, keeping track of what we've got
Product inventory[100];
int inventory_count = 0;

// Welcome to the show, let's dive right in!
void start() {
    printf("Welcome to the C Warehouse Management System! Prepare for an inventory adventure!\n");
}

// Adding a new product to our warehouse, expanding our horizons!
void addProduct() {
    printf("Product Name: ");
    char name[50];
    scanf("%s", name);
    
    printf("Quantity: ");
    int quantity;
    scanf("%d", &quantity);
    
    printf("Price: ");
    float price;
    scanf("%f", &price);
    
    inventory[inventory_count].id = inventory_count + 1;
    strcpy(inventory[inventory_count].name, name);
    inventory[inventory_count].quantity = quantity;
    inventory[inventory_count].price = price;
    
    inventory_count++;
    
    printf("Product added successfully!\n");
}

// Selling a product, sending it off to a new home!
void sellProduct() {
    printf("Product ID: ");
    int id;
    scanf("%d", &id);
    
    int index = findProductIndex(id);
    if (index == -1) {
        printf("Product not found!\n");
        return;
    }
    
    printf("Quantity: ");
    int quantity;
    scanf("%d", &quantity);
    
    if (inventory[index].quantity < quantity) {
        printf("Insufficient stock!\n");
        return;
    }
    
    inventory[index].quantity -= quantity;
    printf("Product sold successfully!\n");
}

// Restock our shelves, bringing in more goods!
void restockProduct() {
    printf("Product ID: ");
    int id;
    scanf("%d", &id);
    
    int index = findProductIndex(id);
    if (index == -1) {
        printf("Product not found!\n");
        return;
    }
    
    printf("Quantity: ");
    int quantity;
    scanf("%d", &quantity);
    
    inventory[index].quantity += quantity;
    printf("Product restocked successfully!\n");
}

// Displaying our inventory, a treasure trove of information!
void displayInventory() {
    printf("ID\tName\t\tQuantity\tPrice\n");
    for (int i = 0; i < inventory_count; i++) {
        printf("%d\t%-20s\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

// Our trusty search function, finding products in a flash!
int findProductIndex(int id) {
    for (int i = 0; i < inventory_count; i++) {
        if (inventory[i].id == id) {
            return i;
        }
    }
    return -1;
}

// Let the adventure begin, what choice will you make?
void showMenu() {
    printf("\nMenu:\n");
    printf("1. Add Product\n");
    printf("2. Sell Product\n");
    printf("3. Restock Product\n");
    printf("4. Display Inventory\n");
    printf("5. Exit\n");
    printf("Choice: ");
    int choice;
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            addProduct();
            break;
        case 2:
            sellProduct();
            break;
        case 3:
            restockProduct();
            break;
        case 4:
            displayInventory();
            break;
        case 5:
            printf("Thank you for using our Warehouse Management System. Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice!\n");
            break;
    }
    
    showMenu();
}

int main() {
    start();
    showMenu();
    return 0;
}