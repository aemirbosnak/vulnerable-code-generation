//FormAI DATASET v1.0 Category: Expense Tracker ; Style: beginner-friendly
#include <stdio.h>

// Define a structure to store the details of an expense
struct Expense {
    char name[20];
    float amount;
    char category[20];
};

int main(void) {
    // Declare an array to store expenses
    struct Expense expenses[100];
    int numExpenses = 0;

    // Declare variables to store input
    char choice;
    float amount;
    char name[20];
    char category[20];

    // Display menu options
    printf("Expense Tracker\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Exit\n");

    // Loop until user chooses to exit
    do {
        // Prompt user for choice
        printf("Enter choice: ");
        scanf(" %c", &choice);

        // Execute chosen option
        switch (choice) {
            case '1':
                // Prompt user for expense details
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter amount: ");
                scanf("%f", &amount);
                printf("Enter category: ");
                scanf("%s", category);

                // Add expense to array
                struct Expense expense = {name, amount, category};
                expenses[numExpenses] = expense;
                numExpenses++;

                printf("Expense added successfully!\n");
                break;
            case '2':
                // Display all expenses in array
                if (numExpenses > 0) {
                    printf("Expenses:\n");
                    for (int i = 0; i < numExpenses; i++) {
                        struct Expense expense = expenses[i];
                        printf("%s - $%.2f - %s\n", expense.name, expense.amount, expense.category);
                    }
                } else {
                    printf("No expenses added yet!\n");
                }
                break;
            case '3':
                // Exit program
                printf("Goodbye!\n");
                break;
            default:
                // Invalid input
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != '3');

    return 0;
}