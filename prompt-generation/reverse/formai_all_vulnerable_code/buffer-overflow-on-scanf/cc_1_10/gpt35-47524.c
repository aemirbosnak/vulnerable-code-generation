//FormAI DATASET v1.0 Category: Expense Tracker ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Expense {
    int expenseId;
    char name[20];
    float amount;
};

void createExpense(struct Expense **expenses, int *size) {
    //code to add new expense
    (*size)++;
    *expenses = (struct Expense*)realloc(*expenses, *size * sizeof(struct Expense));
    
    (*expenses)[*size - 1].expenseId = *size;
    printf("Enter the name of expense: ");
    scanf("%s", (*expenses)[*size - 1].name);
    printf("Enter the amount: ");
    scanf("%f", &(*expenses)[*size - 1].amount);
}

void viewExpenses(struct Expense *expenses, int size) {
    //code to view all expenses
    if (size <= 0) {
        printf("No expenses recorded yet!\n");
        return;
    }

    printf("Expenses:\n");
    printf("ID\tName\tAmount\n");
    printf("---------------------------------------\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%s\t%.2f\n", expenses[i].expenseId, expenses[i].name, expenses[i].amount);
    }
    printf("---------------------------------------\n");
}

void viewTotalExpense(struct Expense *expenses, int size) {
    //code to view total expenses
    float total = 0;
    for (int i = 0; i < size; i++) {
        total += expenses[i].amount;
    }
    printf("Total Expenses: %.2f\n", total);
}

int main() {
    struct Expense *expenses;
    int size = 0, ch;

    do {
        printf("\nExpense Tracker\n");
        printf("-----------------\n");
        printf("1. Add new Expense\n");
        printf("2. View all Expenses\n");
        printf("3. View Total Expense\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                createExpense(&expenses, &size);
                break;
            case 2:
                viewExpenses(expenses, size);
                break;
            case 3:
                viewTotalExpense(expenses, size);
                break;
            case 4:
                printf("Exiting..");
                break;
            default:
                printf("Invalid Choice!");
        }
    } while(ch != 4);

    free(expenses);
    return 0;
}