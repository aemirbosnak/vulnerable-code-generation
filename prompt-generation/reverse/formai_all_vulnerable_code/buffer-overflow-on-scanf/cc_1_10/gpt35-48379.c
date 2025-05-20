//FormAI DATASET v1.0 Category: Expense Tracker ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_EXPENSES 100

// Structure to hold expense information
struct Expense {
    char item[50];
    float price;
    int quantity;
};

// Function to calculate total expense
float totalExpense(struct Expense expenses[], int count) {
    float total = 0;
    for (int i = 0; i < count; i++) {
        total += (expenses[i].price * expenses[i].quantity);
    }
    return total;
}

int main() {
    struct Expense expenses[MAX_EXPENSES];
    int count = 0;
    float total;

    // Loop to add expenses until maximum limit reached
    while (count < MAX_EXPENSES) {
        char choice;
        printf("Add an expense? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'n') {
            break;
        }

        // Prompt for item, price and quantity
        printf("Enter item name: ");
        scanf("%s", expenses[count].item);
        printf("Enter price: ");
        scanf("%f", &expenses[count].price);
        printf("Enter quantity: ");
        scanf("%d", &expenses[count].quantity);

        // Increase count of expenses
        count++;
    }

    // Calculate total expense
    total = totalExpense(expenses, count);

    // Print all expenses and total
    printf("Expenses:\n");
    for (int i = 0; i < count; i++) {
        printf("Item: %s\tPrice: %.2f\tQuantity: %d\n", expenses[i].item, expenses[i].price, expenses[i].quantity);
    }
    printf("Total expense: %.2f\n", total);

    return 0;
}