//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to define a menu item
typedef struct {
    char name[30];
    float price;
    int quantity;
} MenuItem;

// Function to display the menu
void displayMenu(MenuItem menu[], int size) {
    printf("Cafe Menu:\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
    printf("------------------------------------------------\n");
}

// Function to calculate total bill
float calculateTotal(MenuItem menu[], int size) {
    float total = 0.0;
    for (int i = 0; i < size; i++) {
        total += menu[i].price * menu[i].quantity;
    }
    return total;
}

// Function to print the bill
void printBill(MenuItem menu[], int size) {
    printf("\nBill Summary:\n");
    printf("------------------------------------------------\n");
    printf("Item Name\tQuantity\tPrice\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < size; i++) {
        if (menu[i].quantity > 0) {
            printf("%s\t\t%d\t\t$%.2f\n", menu[i].name, menu[i].quantity, menu[i].price * menu[i].quantity);
        }
    }
    printf("------------------------------------------------\n");
    float total = calculateTotal(menu, size);
    printf("Total Amount Due: $%.2f\n", total);
}

// Main function
int main() {
    // Menu items
    MenuItem menu[] = {
        {"Coffee", 2.50, 0},
        {"Tea", 1.50, 0},
        {"Sandwich", 5.00, 0},
        {"Burger", 7.00, 0},
        {"Pasta", 8.00, 0},
        {"Salad", 4.00, 0},
        {"Cake", 3.00, 0}
    };
    
    int menuSize = sizeof(menu) / sizeof(menu[0]);
    int choice;
    
    // User interface loop
    do {
        displayMenu(menu, menuSize);

        printf("Enter the item number to order (0 to finish): ");
        scanf("%d", &choice);

        if (choice > 0 && choice <= menuSize) {
            printf("Enter quantity for %s: ", menu[choice - 1].name);
            scanf("%d", &menu[choice - 1].quantity);
        } else if (choice != 0) {
            printf("Invalid choice, please try again.\n");
        }
        
    } while (choice != 0);

    // Print the bill
    printBill(menu, menuSize);
    
    return 0;
}