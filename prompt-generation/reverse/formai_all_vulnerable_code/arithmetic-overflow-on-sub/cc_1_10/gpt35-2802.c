//FormAI DATASET v1.0 Category: Product Inventory System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

// Define constant values for product codes
#define CODE_1 1000
#define CODE_2 1001
#define CODE_3 1002

// Define struct for product inventory
struct Inventory {
    int code;
    char name[50];
    int quantity;
    float price;
};

int main() {
    // Initialize inventory array with 3 products
    struct Inventory inventory[3] = {
        {CODE_1, "Product A", 10, 5.99},
        {CODE_2, "Product B", 5, 7.99},
        {CODE_3, "Product C", 3, 12.99}
    };

    printf("Welcome to our Product Inventory System!\n\n");

    // Display current inventory
    printf("Current Inventory:\n");
    printf("Code\tName\t\tQuantity\tPrice\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < 3; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", 
            inventory[i].code, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }

    // Prompt user to enter product code and quantity to purchase
    int productCode, qty;
    printf("\nEnter product code and quantity to purchase: ");
    scanf("%d %d", &productCode, &qty);

    // Iterate through inventory array to find matching product code
    int index = -1;
    for (int i = 0; i < 3; i++) {
        if (inventory[i].code == productCode) {
            index = i;
            break;
        }
    }

    // If product code is not found, display error message and exit program
    if (index == -1) {
        printf("\nError: Product code not found.\n");
        exit(0);
    }

    // If quantity to purchase exceeds available quantity, display error message and exit program
    if (qty > inventory[index].quantity) {
        printf("\nError: Not enough quantity available.\n");
        exit(0);
    }

    // Calculate total purchase amount
    float totalPrice = qty * inventory[index].price;

    // Update inventory quantity
    inventory[index].quantity -= qty;

    // Display purchase details and updated inventory
    printf("\nPurchase Details:\n");
    printf("Code\tName\t\tQuantity\tPrice\t\tTotal\n");
    printf("--------------------------------------------------------------\n");
    printf("%d\t%s\t\t%d\t\t%.2f\t\t%.2f\n", 
        inventory[index].code, inventory[index].name, qty, inventory[index].price, totalPrice);
    printf("\nUpdated Inventory:\n");
    printf("Code\tName\t\tQuantity\tPrice\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < 3; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", 
            inventory[i].code, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    printf("\nThank you for shopping with us!\n");

    return 0;
}