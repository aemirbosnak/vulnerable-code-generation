//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int amount;
    char date[20];
    char category[20];
} Expense;

void addExpense(Expense* expenses, int n) {
    printf("Enter the amount: ");
    scanf("%d", &expenses[n].amount);
    printf("Enter the date: ");
    scanf("%s", expenses[n].date);
    printf("Enter the category: ");
    scanf("%s", expenses[n].category);
}

void displayExpenses(Expense* expenses, int n) {
    for (int i = 0; i < n; i++) {
        printf("Expense: %d - %s - %s\n", expenses[i].amount, expenses[i].date, expenses[i].category);
    }
}

void deleteExpense(Expense* expenses, int n) {
    int choice, index;
    printf("Enter the index of the expense to delete: ");
    scanf("%d", &index);

    for (int i = 0; i < n; i++) {
        if (i == index) {
            printf("Deleted expense %d\n", index);
            break;
        }
    }
}

int main() {
    Expense expenses[5];
    int n = 0;

    while (1) {
        int choice;
        printf("1. Add Expense\n2. Display Expenses\n3. Delete Expense\n4. Quit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(expenses, n);
                break;
            case 2:
                displayExpenses(expenses, n);
                break;
            case 3:
                deleteExpense(expenses, n);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}