//FormAI DATASET v1.0 Category: Product Inventory System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define product struct
typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} product;

// Define function to add a product to inventory
void addProduct(product *p, int *count) {
    // Get input from user
    printf("Enter product name: ");
    scanf("%s", p[*count].name);
    printf("Enter product quantity: ");
    scanf("%d", &p[*count].quantity);
    printf("Enter product price: ");
    scanf("%f", &p[*count].price);
    // Assign product ID
    p[*count].id = (*count) + 1;
    // Increment product count
    (*count)++;
    // Print success message
    printf("Product added successfully.\n");
}

// Define function to search for product by name
void searchProduct(product *p, int count) {
    // Get input from user
    char searchName[50];
    printf("Enter product name to search for: ");
    scanf("%s", searchName);
    // Search for product
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(p[i].name, searchName) == 0) {
            printf("Product found:\nID: %d\nName: %s\nQuantity: %d\nPrice: %f\n", 
                   p[i].id, p[i].name, p[i].quantity, p[i].price);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Product not found.\n");
    }
}

// Define function to display all products in inventory
void displayInventory(product *p, int count) {
    // Check if inventory is empty
    if (count == 0) {
        printf("Inventory is empty.\n");
    } else {
        // Print header
        printf("Product ID\tProduct Name\tProduct Quantity\tProduct Price\n");
        // Print inventory
        for (int i = 0; i < count; i++) {
            printf("%d\t\t%s\t\t%d\t\t%0.2f\n", p[i].id, p[i].name, p[i].quantity, p[i].price);
        }
    }
}

int main() {
    // Define variables
    product inventory[50];
    int productCount = 0;
    int choice;
    // Loop through until user selects option 4 to exit
    do {
        // Display options menu
        printf("\nSelect an option:\n1. Add product to inventory\n2. Search for product by name\n3. Display inventory\n4. Exit\n");
        // Get input from user
        scanf("%d", &choice);
        // Process user choice
        switch (choice) {
            case 1:
                addProduct(inventory, &productCount);
                break;
            case 2:
                searchProduct(inventory, productCount);
                break;
            case 3:
                displayInventory(inventory, productCount);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);
    // Exit program
    return 0;
}