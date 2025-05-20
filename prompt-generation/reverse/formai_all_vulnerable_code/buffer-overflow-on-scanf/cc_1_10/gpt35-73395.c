//FormAI DATASET v1.0 Category: Product Inventory System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ITEMS 100

// Defining a Product structure
struct Product {
    char name[20];
    float price;
    int quantity;
};

// Function to add a product to the inventory
void addProduct(struct Product* p, int* itemCount) {
    if(*itemCount == MAX_ITEMS) {
        printf("Inventory is full! Cannot add more products.\n");
        return;
    }
    printf("Enter name of product: ");
    scanf("%s", p[*itemCount].name);
    printf("Enter price of product: ");
    scanf("%f", &p[*itemCount].price);
    printf("Enter quantity of product: ");
    scanf("%d", &p[*itemCount].quantity);
    printf("Product added successfully!\n");
    *itemCount += 1;
}

// Function to display the list of products in the inventory
void displayInventory(struct Product* p, int itemCount) {
    printf("Inventory: \n");
    printf("Name\t\tPrice\t\tQuantity\n");
    for(int i=0; i<itemCount; i++) {
        printf("%s\t\t%.2f\t\t%d\n", p[i].name, p[i].price, p[i].quantity);
    }
}

// Main function to drive the program
int main() {
    struct Product inventory[MAX_ITEMS];
    int itemCount = 0;
    int option;
    while(1) {
        printf("\nChoose an option:\n");
        printf("1. Add a new product\n");
        printf("2. Display inventory\n");
        printf("3. Exit\n");
        scanf("%d", &option);
        if(option == 1) {
            addProduct(inventory, &itemCount);
        }
        else if(option == 2) {
            displayInventory(inventory, itemCount);
        }
        else if(option == 3) {
            printf("Exiting program. Thank you!\n");
            break;
        }
        else {
            printf("Invalid option. Please choose again.\n");
        }
    }
    return 0;
}