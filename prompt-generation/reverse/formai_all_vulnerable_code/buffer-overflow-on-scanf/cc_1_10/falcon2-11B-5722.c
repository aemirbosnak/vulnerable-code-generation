//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void displayMenu();
void trackExpense();
void calculateTotalExpenses();

int main() {

    // Display the menu
    displayMenu();

    // Get user input and track expenses
    int choice;
    do {
        choice = getchar();
        switch (choice) {
            case '1':
                trackExpense();
                break;
            case '2':
                calculateTotalExpenses();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= '3');

    return 0;
}

void displayMenu() {
    printf("Welcome to the Expense Tracker!\n");
    printf("Please select an option:\n");
    printf("1. Track Expenses\n");
    printf("2. Calculate Total Expenses\n");
    printf("3. Exit\n");
}

void trackExpense() {
    char name[100];
    int amount;

    printf("Enter name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove newline character from input

    printf("Enter amount: ");
    scanf("%d", &amount);

    // Print tracked expense
    printf("Expense tracked successfully!\n");
    printf("Name: %s\n", name);
    printf("Amount: $%d\n", amount);
}

void calculateTotalExpenses() {
    int totalExpenses = 0;

    // Get total expenses from user input
    printf("Enter total expenses: ");
    scanf("%d", &totalExpenses);

    // Print total expenses
    printf("Total Expenses: $%d\n", totalExpenses);
}