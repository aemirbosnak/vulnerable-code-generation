//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants for menu item count and maximum length of strings
#define ITEM_COUNT 5
#define MAX_LENGTH 100

// Structure to hold the details of menu items
typedef struct {
    char name[MAX_LENGTH];
    float price;
} MenuItem;

// Function to display the menu
void displayMenu(MenuItem menu[], int size) {
    printf("\n--- Welcome to the Cafe ---\n");
    printf("Here's our delicious menu:\n");
    printf("------------------------------------\n");
    for(int i = 0; i < size; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
    printf("------------------------------------\n");
}

// Function to get the user orders
void getOrder(MenuItem menu[], float *totalCost) {
    int choice, quantity;
    char moreChoice[MAX_LENGTH];

    do {
        printf("Enter the item number (1-%d): ", ITEM_COUNT);
        scanf("%d", &choice);
        if (choice < 1 || choice > ITEM_COUNT) {
            printf("Invalid choice! Please select a valid item number.\n");
            continue;
        }
        printf("How many would you like to order? ");
        scanf("%d", &quantity);

        // Adding to the total cost
        *totalCost += menu[choice - 1].price * quantity;
        
        printf("You have added %d x %s to your order. Total cost now: $%.2f\n", 
                quantity, menu[choice - 1].name, *totalCost);
        
        printf("Would you like to order anything else? (yes/no): ");
        scanf("%s", moreChoice);
    } while (strcmp(moreChoice, "yes") == 0);
}

// Function to print the final bill
void printBill(float totalCost) {
    printf("\n--- Your Order Summary ---\n");
    printf("Thank you for your order!\n");
    printf("Total Amount: $%.2f\n", totalCost);
    printf("We appreciate your business!\n");
    printf("---------------------------\n");
    printf("Have a great day!\n");
}

int main() {
    MenuItem menu[ITEM_COUNT] = {
        {"Espresso", 2.50},
        {"Cappuccino", 3.50},
        {"Latte", 4.00},
        {"Tea", 1.75},
        {"Pastry", 2.00}
    };

    float totalCost = 0.0;
    
    // Display the menu
    displayMenu(menu, ITEM_COUNT);
    
    // Take orders from the user
    getOrder(menu, &totalCost);
    
    // Print the final bill
    printBill(totalCost);
    
    return 0;
}