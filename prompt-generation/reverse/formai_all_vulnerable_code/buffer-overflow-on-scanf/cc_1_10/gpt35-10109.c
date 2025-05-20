//FormAI DATASET v1.0 Category: Expense Tracker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

typedef struct Expense {
    float amount;
    char category[100];
    char date[20];
} Expense;

void addExpense(Expense *expenses, int *numExpenses) {
    float amount;
    char category[100], date[20];
    printf("Enter expense amount: ");
    scanf("%f", &amount);
    printf("Enter expense category: ");
    scanf("%s", category);
    printf("Enter expense date (dd/mm/yyyy): ");
    scanf("%s", date);

    Expense newExpense;
    newExpense.amount = amount;
    strcpy(newExpense.category, category);
    strcpy(newExpense.date, date);

    expenses[*numExpenses] = newExpense;
    *numExpenses += 1;
}

void printExpenses(Expense *expenses, int numExpenses) {
    printf("-----------------------------------------\n");
    printf("   DATE    |    CATEGORY    |    AMOUNT   \n");
    printf("-----------------------------------------\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%-10s | %-14s | $%-7.2f\n", expenses[i].date, expenses[i].category, expenses[i].amount);
    }
    printf("-----------------------------------------\n");
}

void searchExpenses(Expense *expenses, int numExpenses) {
    char searchTerm[100];
    printf("Enter search term: ");
    scanf("%s", searchTerm);

    printf("-----------------------------------------\n");
    printf("   DATE    |    CATEGORY    |    AMOUNT   \n");
    printf("-----------------------------------------\n");
    for (int i = 0; i < numExpenses; i++) {
        if (strstr(expenses[i].category, searchTerm) != NULL || strstr(expenses[i].date, searchTerm) != NULL) {
            printf("%-10s | %-14s | $%-7.2f\n", expenses[i].date, expenses[i].category, expenses[i].amount);
        }
    }
    printf("-----------------------------------------\n");
}

int main() {
    int option = 0;
    int maxExpenses = 1000;
    int numExpenses = 0;
    Expense expenses[maxExpenses];

    while (option != 4) {
        printf("\n1. Add expense\n2. Print all expenses\n3. Search expenses\n4. Quit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                addExpense(expenses, &numExpenses);
                break;
            case 2:
                printExpenses(expenses, numExpenses);
                break;
            case 3:
                searchExpenses(expenses, numExpenses);
                break;
            case 4:
                printf("Goodbye!");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}