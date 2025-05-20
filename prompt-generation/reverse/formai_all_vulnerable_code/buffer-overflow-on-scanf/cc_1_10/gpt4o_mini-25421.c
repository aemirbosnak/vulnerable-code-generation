//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

// Structure to represent a menu item
typedef struct {
    int id;
    char name[30];
    float price;
} MenuItem;

// Function declarations
void displayMenu(MenuItem menu[], int size);
float calculateBill(int quantities[], MenuItem menu[], int size);

int main() {
    MenuItem menu[MAX_ITEMS] = {
        {1, "Coffee", 2.50},
        {2, "Tea", 2.00},
        {3, "Sandwich", 5.00},
        {4, "Burger", 6.00},
        {5, "Salad", 4.00},
        {6, "Juice", 3.00},
        {7, "Cake", 3.50},
        {8, "Water", 1.00},
        {9, "Pasta", 7.00},
        {10, "Ice Cream", 2.50}
    };
    
    int quantities[MAX_ITEMS] = {0}; // Array to store quantities of each item
    int choice, i;

    printf("Welcome to the Cafe Billing System!\n");
    
    // Display the menu
    displayMenu(menu, MAX_ITEMS);

    // Start taking orders
    while(1) {
        printf("\nPlease enter the item number to order (0 to finish): ");
        scanf("%d", &choice);
        
        if (choice == 0) {
            break;
        } else if (choice < 1 || choice > MAX_ITEMS) {
            printf("Invalid choice! Please select a valid item number.\n");
            continue;
        }

        printf("Enter quantity for %s: ", menu[choice - 1].name);
        scanf("%d", &quantities[choice - 1]);
    }

    // Calculate and display the final bill
    float totalCost = calculateBill(quantities, menu, MAX_ITEMS);

    printf("\nYour total bill is: $%.2f\n", totalCost);
    printf("Thank you for visiting our cafe!\n");
    
    return 0;
}

// Function to display the menu
void displayMenu(MenuItem menu[], int size) {
    printf("\n--- Cafe Menu ---\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - $%.2f\n", menu[i].id, menu[i].name, menu[i].price);
    }
}

// Function to calculate the total bill
float calculateBill(int quantities[], MenuItem menu[], int size) {
    float total = 0.0;
    for (int i = 0; i < size; i++) {
        if (quantities[i] > 0) {
            total += quantities[i] * menu[i].price;
            printf("Item: %s, Quantity: %d, Price: $%.2f\n", menu[i].name, quantities[i], (quantities[i] * menu[i].price));
        }
    }
    return total;
}