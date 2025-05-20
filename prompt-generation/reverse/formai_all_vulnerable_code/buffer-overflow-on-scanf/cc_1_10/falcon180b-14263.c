//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    float amount;
    time_t date;
} Expense;

void addExpense(Expense expenses[], int count) {
    printf("Enter expense name: ");
    scanf("%s", expenses[count].name);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[count].amount);
    time_t now = time(NULL);
    expenses[count].date = now;
    printf("Expense added successfully!\n");
}

void viewExpenses(Expense expenses[], int count) {
    printf("Expenses:\n");
    for (int i = 0; i < count; i++) {
        printf("%s - $%.2f - %s\n", expenses[i].name, expenses[i].amount, ctime(&expenses[i].date));
    }
}

void deleteExpense(Expense expenses[], int count) {
    printf("Enter expense name to delete: ");
    scanf("%s", expenses[count].name);
    printf("Expense deleted successfully!\n");
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int count = 0;

    while (count < MAX_EXPENSES) {
        printf("1. Add expense\n2. View expenses\n3. Delete expense\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(expenses, count);
                break;
            case 2:
                viewExpenses(expenses, count);
                break;
            case 3:
                deleteExpense(expenses, count);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
        count++;
    }

    return 0;
}