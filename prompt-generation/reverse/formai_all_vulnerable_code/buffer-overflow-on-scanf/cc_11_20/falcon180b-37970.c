//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    float amount;
    char category[50];
} Expense;

int main() {
    int numExpenses = 0;
    Expense expenses[MAX_EXPENSES];

    char choice;
    do {
        printf("\nExpense Tracker\n");
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. View expenses by category\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                if (numExpenses >= MAX_EXPENSES) {
                    printf("Maximum number of expenses reached.\n");
                } else {
                    printf("Enter expense name: ");
                    scanf("%s", expenses[numExpenses].name);
                    printf("Enter expense amount: $");
                    scanf("%f", &expenses[numExpenses].amount);
                    printf("Enter expense category: ");
                    scanf("%s", expenses[numExpenses].category);
                    numExpenses++;
                }
                break;
            case '2':
                if (numExpenses == 0) {
                    printf("No expenses entered.\n");
                } else {
                    printf("\nExpense List:\n");
                    for (int i = 0; i < numExpenses; i++) {
                        printf("%s - $%.2f - %s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
                    }
                }
                break;
            case '3':
                printf("\nEnter category to view expenses: ");
                scanf("%s", expenses[0].category); // assuming first expense is in the desired category
                for (int i = 0; i < numExpenses; i++) {
                    if (strcmp(expenses[i].category, expenses[0].category) == 0) {
                        printf("%s - $%.2f - %s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
                    }
                }
                break;
            case '4':
                printf("Thank you for using Expense Tracker.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= '4');

    return 0;
}