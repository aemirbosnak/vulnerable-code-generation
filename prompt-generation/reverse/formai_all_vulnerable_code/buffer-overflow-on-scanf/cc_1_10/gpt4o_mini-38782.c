//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void displayMenu();
float calculateTotal(int choice, int quantity);
void printBill(float total);

int main() {
    int choice = 0, quantity = 0;
    float total;

    printf("Welcome to the Cozy Cafe!\n");
    printf("Here's our menu:\n");

    // Display the menu
    displayMenu();

    // Take user input 
    do {
        printf("Please enter the item number you wish to order (1-5), or 0 to finish your order: ");
        scanf("%d", &choice);

        // Check if user wants to finish their order
        if (choice == 0) {
            printf("Finishing your order...\n");
            break; // Exit the loop if they want to finish
        }

        // Validate choice
        if (choice < 1 || choice > 5) {
            printf("Invalid choice. Please select a valid item number.\n");
            continue; // Ask again
        }

        printf("Enter quantity: ");
        scanf("%d", &quantity);

        // Validating quantity
        if (quantity < 1) {
            printf("Invalid quantity. Please enter a positive number.\n");
            continue; // Ask again
        }

        // Calculate total for the current item
        total += calculateTotal(choice, quantity);
        printf("Order added. Your current total is: $%.2f\n", total);

    } while(1);
    
    // Print the final bill
    printBill(total);

    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("1. Coffee - $2.00\n");
    printf("2. Tea - $1.50\n");
    printf("3. Sandwich - $3.00\n");
    printf("4. Salad - $4.50\n");
    printf("5. Cake - $2.50\n");
}

// Function to calculate the total for each item
float calculateTotal(int choice, int quantity) {
    float price;

    // Assigning prices based on user choice
    switch (choice) {
        case 1: price = 2.00; break; // Coffee
        case 2: price = 1.50; break; // Tea
        case 3: price = 3.00; break; // Sandwich
        case 4: price = 4.50; break; // Salad
        case 5: price = 2.50; break; // Cake
        default: price = 0.00; break;
    }

    return price * quantity; // Calculate and return total
}

// Function to print the final bill
void printBill(float total) {
    printf("\nThank you for visiting Cozy Cafe!\n");
    printf("Your total bill is: $%.2f\n", total);
    printf("Have a great day!\n");
}