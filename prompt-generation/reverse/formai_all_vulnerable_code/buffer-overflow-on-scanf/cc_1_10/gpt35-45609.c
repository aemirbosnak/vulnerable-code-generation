//FormAI DATASET v1.0 Category: Expense Tracker ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    float amount;
    char description[50];
} Expense;

float getTotalExpense(Expense expenses[], int n) {
    float total = 0;
    for (int i = 0; i < n; i++) {
        total += expenses[i].amount;
    }
    return total;
}

void printExpenses(Expense expenses[], int n) {
    printf("No.   Amount    Description\n");
    for (int i = 0; i < n; i++) {
        printf("%-5d $%-8.2f %s\n", i+1, expenses[i].amount, expenses[i].description);
    }
}

void addExpense(Expense expenses[], int *n) {
    Expense e;
    printf("Enter amount: $");
    scanf("%f", &e.amount);
    printf("Enter description: ");
    getchar(); // consume newline left in buffer
    fgets(e.description, 50, stdin);
    e.description[strcspn(e.description, "\n")] = 0; // remove trailing newline
    expenses[*n] = e;
    (*n)++;
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int n = 0;
    char choice;

    do {
        printf("\nExpense Tracker Menu\n");
        printf("---------------------\n");
        printf("1. View Total Expenses\n");
        printf("2. View All Expenses\n");
        printf("3. Add an Expense\n");
        printf("4. Quit\n");
        printf("Enter choice (1-4): ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("\nTotal expenses: $%.2f\n", getTotalExpense(expenses, n));
                break;
            case '2':
                printExpenses(expenses, n);
                break;
            case '3':
                if (n == MAX_EXPENSES) {
                    printf("\nMaximum number of expenses reached. Cannot add more.\n");
                } else {
                    addExpense(expenses, &n);
                    printf("\nExpense added successfully.\n");
                }
                break;
            case '4':
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
        }
    } while (choice != '4');

    return 0;
}