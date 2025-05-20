//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: futuristic
// Cafe Billing System Example Program

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to display the menu
void displayMenu() {
    printf("*** Welcome to Cafe XYZ ***\n\n");
    printf("1. Coffee\t\t$2.50\n");
    printf("2. Tea\t\t\t$1.50\n");
    printf("3. Sandwich\t\t$5.00\n");
    printf("4. Salad\t\t$4.50\n");
    printf("5. Quit\n\n");
}

int main() {
    // Fictitious futuristic cafe billing system
    printf("<<< Cafe Billing System >>>\n\n");

    // Initializing variables
    int choice = 0;
    int quantity = 0;
    float price = 0;
    float total = 0;
    bool isRunning = true;

    // Displaying the menu
    displayMenu();

    // Loop for taking orders until user quits
    while(isRunning) {
        // Taking user's choice
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                price = 2.50;
                break;
            case 2:
                price = 1.50;
                break;
            case 3:
                price = 5.00;
                break;
            case 4:
                price = 4.50;
                break;
            case 5:
                isRunning = false;
                printf("\nThank you for choosing Cafe XYZ!\n");
                printf("Your total bill is $%.2f\n", total);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }

        if(isRunning && choice >= 1 && choice <= 4) {
            // Taking user's desired quantity
            printf("Enter quantity: ");
            scanf("%d", &quantity);

            // Calculating total bill
            total += price * quantity;

            printf("Item added to cart.\n");
        }
    }

    return 0;
}