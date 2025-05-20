//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense {
    char description[50];
    double amount;
};

struct Expense expenses[100];
int num_expenses = 0;

double total_expenses() {
    double total = 0;
    for(int i = 0; i < num_expenses; i++) {
        total += expenses[i].amount;
    }
    return total;
}

void add_expense() {
    struct Expense expense;
    printf("Enter expense description: ");
    fflush(stdin);
    fgets(expense.description, 50, stdin);
    printf("Enter expense amount: ");
    scanf("%lf", &expense.amount);
    expenses[num_expenses] = expense;
    num_expenses++;
}

void print_expenses() {
    printf("Expenses:\n");
    for(int i = 0; i < num_expenses; i++) {
        printf("%s: $%.2f\n", expenses[i].description, expenses[i].amount);
    }
    printf("Total: $%.2f\n", total_expenses());
}

void menu() {
    printf("\n");
    printf("1. Add Expense\n");
    printf("2. Print Expenses\n");
    printf("3. Exit\n");
    printf("\n");
}

int main() {
    int choice = 0;
    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_expense();
                break;
            case 2:
                print_expenses();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 3);
    return 0;
}