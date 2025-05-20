//FormAI DATASET v1.0 Category: Product Inventory System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
    int code;
    char name[50];
    float price;
    int quantity;
};

int main() {
    int n = 4;  // number of products
    struct Product products[n];
    
    // Initialize the products
    products[0].code = 101;
    strcpy(products[0].name, "Chips");
    products[0].price = 1.25;
    products[0].quantity = 100;
    
    products[1].code = 102;
    strcpy(products[1].name, "Soda");
    products[1].price = 2.50;
    products[1].quantity = 50;
    
    products[2].code = 103;
    strcpy(products[2].name, "Chocolate");
    products[2].price = 1.00;
    products[2].quantity = 75;
    
    products[3].code = 104;
    strcpy(products[3].name, "Cookie");
    products[3].price = 0.75;
    products[3].quantity = 200;
    
    // Display the current inventory
    printf("Current Inventory:\n");
    printf("%-10s %-20s %-10s %-10s\n", "Code", "Name", "Price", "Quantity");
    for (int i = 0; i < n; i++) {
        printf("%-10d %-20s $%-9.2f %-10d\n", products[i].code, products[i].name, products[i].price, products[i].quantity);
    }
    printf("\n");
    
    // Update the inventory
    int choice = 0;
    while (choice != 3) {
        printf("What would you like to do?\n");
        printf("1. Add to inventory\n");
        printf("2. Remove from inventory\n");
        printf("3. Quit\n");
        scanf("%d", &choice);
        printf("\n");
        
        switch (choice) {
            case 1:
            {
                int code = 0;
                int quantity = 0;
                printf("Enter product code: ");
                scanf("%d", &code);
                printf("Enter quantity to add: ");
                scanf("%d", &quantity);
                
                for (int i = 0; i < n; i++) {
                    if (products[i].code == code) {
                        products[i].quantity += quantity;
                        printf("Added %d %s to inventory.\n", quantity, products[i].name);
                        break;
                    }
                    else if (i == n-1) {
                        printf("Invalid product code.\n");
                    }
                }
                break;
            }
            case 2:
            {
                int code = 0;
                int quantity = 0;
                printf("Enter product code: ");
                scanf("%d", &code);
                printf("Enter quantity to remove: ");
                scanf("%d", &quantity);
                
                for (int i = 0; i < n; i++) {
                    if (products[i].code == code && products[i].quantity >= quantity) {
                        products[i].quantity -= quantity;
                        printf("Removed %d %s from inventory.\n", quantity, products[i].name);
                        break;
                    }
                    else if (products[i].code == code && products[i].quantity < quantity) {
                        printf("Not enough %s in inventory.\n", products[i].name);
                        break;
                    }
                    else if (i == n-1) {
                        printf("Invalid product code.\n");
                    }
                }
                break;
            }
            case 3:
            {
                printf("Goodbye!\n");
                break;
            }
            default:
            {
                printf("Invalid choice.\n");
                break;
            }
        }
        
        printf("\n");
    }
    
    // Display the updated inventory
    printf("Updated Inventory:\n");
    printf("%-10s %-20s %-10s %-10s\n", "Code", "Name", "Price", "Quantity");
    for (int i = 0; i < n; i++) {
        printf("%-10d %-20s $%-9.2f %-10d\n", products[i].code, products[i].name, products[i].price, products[i].quantity);
    }
    
    return 0;
}