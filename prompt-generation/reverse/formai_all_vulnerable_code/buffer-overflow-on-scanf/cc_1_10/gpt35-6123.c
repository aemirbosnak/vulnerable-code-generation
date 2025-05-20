//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char description[100];
    float amount;
} Expense;

int num_expenses = 0;
Expense expenses[MAX_EXPENSES];

void add_expense() {
    Expense expense;
    printf("Enter expense description: ");
    fgets(expense.description, 100, stdin);
    printf("Enter expense amount: ");
    scanf("%f", &expense.amount);
    getchar(); // clear newline from buffer
    expenses[num_expenses++] = expense;
}

void print_expenses() {
    printf("Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%d. %s - $%.2f\n", i+1, expenses[i].description, expenses[i].amount);
    }
}

float total_expenses() {
    float total = 0;
    for (int i = 0; i < num_expenses; i++) {
        total += expenses[i].amount;
    }
    return total;
}

int main() {
    int choice = 0;
    do {
        printf("Expense Tracker\n");
        printf("1. Add expense\n");
        printf("2. Print expenses\n");
        printf("3. Total expenses\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline from buffer
        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                print_expenses();
                break;
            case 3:
                printf("Total expenses: $%.2f\n", total_expenses());
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 4);
    return 0;
}