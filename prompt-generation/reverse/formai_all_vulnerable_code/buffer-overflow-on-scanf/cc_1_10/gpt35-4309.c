//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Expense structure to hold each transaction
struct Expense {
    char date[15];
    char category[20];
    float amount;
};

int main() {
    int input, i, count = 0;
    float total = 0;
    char date[15], category[20];
    float amount;

    // Define an array of Expenses with 10 slots
    struct Expense expenses[10];

    while (1) {
        // Print Menu
        printf("\nExpense Tracker\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &input);

        switch (input) {
            case 1: {
                // Add Expense
                printf("\nEnter Date (dd/mm/yyyy): ");
                scanf("%s", &date);
                printf("Enter Category: ");
                scanf("%s", &category);
                printf("Enter Amount: ");
                scanf("%f", &amount);

                // Create new Expense object and add it to the array
                struct Expense newExpense;
                strcpy(newExpense.date, date);
                strcpy(newExpense.category, category);
                newExpense.amount = amount;
                expenses[count] = newExpense;

                // Increment count and update total amount
                count++;
                total += amount;

                printf("\nExpense added successfully!\n");
                break;
            }
            case 2: {
                // View Expenses
                printf("\nDate\tCategory\tAmount\n");
                for (i = 0; i < count; i++) {
                    printf("%s\t%s\t%.2f\n", expenses[i].date, expenses[i].category, expenses[i].amount);
                }
                printf("Total\t\t%.2f\n", total);
                break;
            }
            case 3: {
                // Exit Program
                printf("\nThank you for using Expense Tracker!\n");
                return 0;
            }
            default: {
                // Handle Invalid Input
                printf("\nInvalid Input! Please try again.\n");
                break;
            }
        }
    }
}