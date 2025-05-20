//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

struct MenuItem {
    int itemNumber;
    char name[50];
    float price;
};

// Function to display the menu
void displayMenu(struct MenuItem menu[], int size) {
    printf("Cafe Menu:\n");
    printf("---------------------------------------------------\n");
    printf("Item No\tItem Name\t\tPrice\n");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%s\t\t%.2f\n", menu[i].itemNumber, menu[i].name, menu[i].price);
    }
    printf("---------------------------------------------------\n");
}

// Function to calculate bill
float calculateBill(int order[], int quantities[], struct MenuItem menu[], int size) {
    float total = 0.0;
    printf("Ordered Items:\n");
    printf("---------------------------------------------------\n");
    printf("Item No\tItem Name\t\tQuantity\tTotal Price\n");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < size; i++) {
        if (quantities[i] > 0) {
            float itemTotal = quantities[i] * menu[order[i]].price;
            printf("%d\t%s\t\t%d\t\t%.2f\n", menu[order[i]].itemNumber, menu[order[i]].name, quantities[i], itemTotal);
            total += itemTotal;
        }
    }
    printf("---------------------------------------------------\n");
    return total;
}

int main() {
    // Create a menu
    struct MenuItem menu[] = {
        {1, "Coffee", 2.50},
        {2, "Tea", 2.00},
        {3, "Sandwich", 5.00},
        {4, "Salad", 4.50},
        {5, "Cake", 3.50}
    };
    
    int menuSize = sizeof(menu) / sizeof(menu[0]);
    
    // Display menu
    displayMenu(menu, menuSize);
    
    // Order items
    int order[menuSize];
    int quantities[menuSize];
    
    for (int i = 0; i < menuSize; i++) {
        order[i] = i;  // Set the order to be the corresponding index
        quantities[i] = 0;  // Initialize quantities to 0
    }

    // Taking user input for quantity
    printf("Enter quantities for each item (enter 0 if not ordered): \n");
    for (int i = 0; i < menuSize; i++) {
        printf("%s: ", menu[i].name);
        scanf("%d", &quantities[i]);
        while (quantities[i] < 0) {
            printf("Please enter a valid quantity for %s: ", menu[i].name);
            scanf("%d", &quantities[i]);
        }
    }
    
    // Calculate total bill
    float total = calculateBill(order, quantities, menu, menuSize);
    
    // Display total amount
    printf("---------------------------------------------------\n");
    printf("Total Amount Due: %.2f\n", total);
    printf("Thank you for visiting our cafe!\n");
    
    return 0;
}