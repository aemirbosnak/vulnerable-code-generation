//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_EXPENSE_LENGTH 100

typedef struct {
    char name[MAX_EXPENSE_LENGTH];
    double amount;
} Expense;

int num_expenses;
Expense expenses[MAX_EXPENSES];

void add_expense() {
    num_expenses++;
    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses-1].name);
    printf("Enter expense amount: ");
    scanf("%lf", &expenses[num_expenses-1].amount);
}

void remove_expense() {
    num_expenses--;
    for(int i=0; i<num_expenses; i++) {
        expenses[i] = expenses[i+1];
    }
}

void print_expenses() {
    printf("Expenses:\n");
    for(int i=0; i<num_expenses; i++) {
        printf("%s: $%.2lf\n", expenses[i].name, expenses[i].amount);
    }
}

int main() {
    printf("Welcome to the Expense Tracker!\n");
    num_expenses = 0;
    while(1) {
        printf("\n1. Add expense\n2. Remove expense\n3. Print expenses\n4. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_expense();
                break;
            case 2:
                remove_expense();
                break;
            case 3:
                print_expenses();
                break;
            case 4:
                printf("Thank you for using the Expense Tracker!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}