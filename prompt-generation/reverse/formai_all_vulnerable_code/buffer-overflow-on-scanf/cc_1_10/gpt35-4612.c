//FormAI DATASET v1.0 Category: Expense Tracker ; Style: complex
#include <stdio.h>

// Structure to store an expense
struct Expense {
    int day;
    int month;
    int year;
    char category[20];
    float amount;
};

// Function to print expenses for a specific month
void printExpenses(struct Expense expenses[], int size, int month) {
    printf("----------------------\n");
    printf("Expenses for Month %d:\n", month);
    printf("----------------------\n");

    // Loop through expenses and print those that match the month
    for (int i = 0; i < size; i++) {
        if (expenses[i].month == month) {
            printf("Date: %d/%d/%d\n", expenses[i].day, expenses[i].month, expenses[i].year);
            printf("Category: %s\n", expenses[i].category);
            printf("Amount: $%.2f\n\n", expenses[i].amount);
        }
    }
}

int main() {
    // Initialize an array of expenses
    struct Expense expenses[100];
    int size = 0;

    // User menu
    int choice = 0;

    // Loop until user chooses to exit
    while (choice != 4) {
        printf("Expense Tracker Menu\n");
        printf("----------------------\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses for Month\n");
        printf("3. View All Expenses\n");
        printf("4. Exit Program\n");

        // Get user choice
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Get expense details from user
                printf("\nEnter Expense Details:\n");
                printf("Day: ");
                scanf("%d", &expenses[size].day);
                printf("Month: ");
                scanf("%d", &expenses[size].month);
                printf("Year: ");
                scanf("%d", &expenses[size].year);
                printf("Category: ");
                scanf("%s", &expenses[size].category);
                printf("Amount: ");
                scanf("%f", &expenses[size].amount);

                // Increase size of expense array
                size++;

                printf("\nExpense Added!\n");
                break;
            case 2:
                // Get month from user
                printf("\nEnter Month (1-12): ");
                int month;
                scanf("%d", &month);

                // Print expenses for specified month
                printExpenses(expenses, size, month);
                break;
            case 3:
                // Print all expenses
                printf("\nAll Expenses:\n");
                printf("----------------------\n");

                for (int i = 0; i < size; i++) {
                    printf("Date: %d/%d/%d\n", expenses[i].day, expenses[i].month, expenses[i].year);
                    printf("Category: %s\n", expenses[i].category);
                    printf("Amount: $%.2f\n\n", expenses[i].amount);
                }
                break;
            case 4:
                // Exit program
                printf("\nExiting Program...\n");
                break;
            default:
                printf("\nInvalid Choice! Please choose a valid option.\n");
                break;
        }
    }

    return 0;
}