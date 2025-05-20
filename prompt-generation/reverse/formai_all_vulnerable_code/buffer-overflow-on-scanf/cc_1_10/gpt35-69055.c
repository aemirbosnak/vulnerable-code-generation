//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: protected
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function declarations
void displayMenu();
bool validateOrder(int choice, int quantity, double* price);
void processOrder(int choice, int quantity, double* price, double* totalBill, char* itemName);

int main() {
    // Variable declarations
    int choice, quantity;
    double price, totalBill = 0;
    char itemName[100];

    // Welcome message
    printf("Welcome to C Cafe!\n");

    // Loop until user chooses to exit
    while(true) {
        // Display menu
        displayMenu();

        // Get user input
        printf("\nEnter your choice (1-3): ");
        scanf("%d", &choice);

        if(choice == 3) {
            // User chose to exit
            break;
        }

        printf("Enter quantity: ");
        scanf("%d", &quantity);

        // Validate user input
        if(!validateOrder(choice, quantity, &price)) {
            printf("Invalid input. Please try again.\n\n");
            continue;
        }

        // Process order
        processOrder(choice, quantity, &price, &totalBill, itemName);

        // Display order details
        printf("\nItem: %s\nPrice per unit: %.2f\nQuantity: %d\nTotal price: %.2f\n\n", itemName, price, quantity, price * quantity);
    }

    // Display total bill
    printf("Total bill: %.2f", totalBill);

    return 0;
}

// Function definitions
void displayMenu() {
    printf("\nMenu\n");
    printf("1. Coffee - $2.50\n");
    printf("2. Sandwich - $5.00\n");
    printf("3. Exit\n");
}

bool validateOrder(int choice, int quantity, double* price) {
    bool isValid = true;

    switch(choice) {
        case 1:
            *price = 2.50;
            break;
        case 2:
            *price = 5.00;
            break;
        default:
            isValid = false;
    }

    if(quantity < 1 || quantity > 10) {
        isValid = false;
    }

    return isValid;
}

void processOrder(int choice, int quantity, double* price, double* totalBill, char* itemName) {
    switch(choice) {
        case 1:
            strcpy(itemName, "Coffee");
            *totalBill += quantity * (*price);
            break;
        case 2:
            strcpy(itemName, "Sandwich");
            *totalBill += quantity * (*price);
            break;
    }
}