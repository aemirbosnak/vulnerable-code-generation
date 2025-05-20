//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expense {
    char name[50];
    float amount;
    char date[20];
};

void addExpense(struct expense *expenses, int *numExpenses) {
    printf("Enter expense name: ");
    scanf(" %[^\n]", expenses[*numExpenses].name);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[*numExpenses].amount);
    printf("Enter expense date (MM/DD/YYYY): ");
    scanf(" %[^\n]", expenses[*numExpenses].date);
    (*numExpenses)++;
}

float totalExpenses(struct expense *expenses, int numExpenses) {
    float total = 0;
    for(int i = 0; i < numExpenses; i++) {
        total += expenses[i].amount;
    }
    return total;
}

void printExpenses(struct expense *expenses, int numExpenses) {
    printf("Expenses:\n");
    printf("Name\tAmount\tDate\n");
    for(int i = 0; i < numExpenses; i++) {
        printf("%s\t%.2f\t%s\n", expenses[i].name, expenses[i].amount, expenses[i].date);
    }
}

int main() {
    struct expense expenses[100];
    int numExpenses = 0;
    int choice = 0;

    while(choice != 4) {
        printf("\n=====Personal Finance Planner=====\n");
        printf("1. Add Expense\n");
        printf("2. View Total Expenses\n");
        printf("3. View All Expenses\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addExpense(expenses, &numExpenses);
                    break;
            case 2: printf("Total expenses: $%.2f\n", totalExpenses(expenses, numExpenses));
                    break;
            case 3: printExpenses(expenses, numExpenses);
                    break;
            case 4: printf("Quitting...\n");
                    break;
            default: printf("Invalid choice! Please try again.\n");
                    break;
        }
    }

    return 0;
}