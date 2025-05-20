//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Function to calculate total cost for a single item
float calculate_cost(int quantity, float price_per_item) {
    return quantity * price_per_item;
}

// Function to display options
void display_menu() {
    printf("\nCafe Billing System\n");
    printf("1. Coffee - $2.50\n");
    printf("2. Tea - $2.00\n");
    printf("3. Sandwich - $5.00\n");
    printf("4. Cake - $3.50\n");
    printf("5. Exit\n");
    printf("Please select an item (1-5): ");
}

// Function to process the order
void process_order() {
    int choice, quantity;
    float total_cost = 0.0f, price = 0.0f;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        // Exit condition
        if (choice == 5) {
            printf("Exiting the cafe billing system.\n");
            break;
        }

        // Validate choice
        if (choice < 1 || choice > 5) {
            printf("Invalid choice! Please select a valid item.\n");
            continue;
        }

        printf("Enter quantity: ");
        scanf("%d", &quantity);
        
        // Validate quantity
        if (quantity <= 0) {
            printf("Invalid quantity! Please enter a positive number.\n");
            continue;
        }

        // Assign price based on the menu selection
        switch (choice) {
            case 1: 
                price = 2.50f; 
                break;
            case 2: 
                price = 2.00f; 
                break;
            case 3: 
                price = 5.00f; 
                break;
            case 4: 
                price = 3.50f; 
                break;
        }

        // Calculate total cost for this item
        total_cost += calculate_cost(quantity, price);
        printf("Added %d item(s) to the bill. Price per item: $%.2f\n", quantity, price);
        printf("Current total cost: $%.2f\n", total_cost);
    }

    printf("Total amount to pay: $%.2f\n", total_cost);
}

// Function to collect payment
void collect_payment(float total_amount) {
    float amount_paid;

    printf("Total amount to pay: $%.2f\n", total_amount);
    printf("Enter amount paid: $");
    scanf("%f", &amount_paid);

    // Validate payment
    while (amount_paid < total_amount) {
        printf("Insufficient amount! Please enter a valid amount: $");
        scanf("%f", &amount_paid);
    }

    if (amount_paid > total_amount) {
        printf("Thank you for your payment! Change to return: $%.2f\n", amount_paid - total_amount);
    } else {
        printf("Thank you for your exact payment of $%.2f!\n", total_amount);
    }
}

// Function to print a thank you message
void print_receipt(float total_amount) {
    printf("\n--- Receipt ---\n");
    printf("Thank you for visiting our cafe!\n");
    printf("Your total amount is: $%.2f\n", total_amount);
    printf("----------------\n");
}

int main() {
    float total_amount = 0.0f;

    // Start processing orders
    process_order();
    // After processing, print the receipt
    print_receipt(total_amount);

    // Collect payment
    collect_payment(total_amount);

    return 0;
}