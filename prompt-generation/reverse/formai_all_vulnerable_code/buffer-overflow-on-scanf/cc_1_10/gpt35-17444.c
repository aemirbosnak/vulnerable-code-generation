//FormAI DATASET v1.0 Category: Expense Tracker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 100

struct Expense {
    int id;
    char description[100];
    float amount;
};

int totalExpenses = 0;
struct Expense expenses[MAX_EXPENSES];

void addExpense() {
    if (totalExpenses >= MAX_EXPENSES) {
        printf("Cannot add more expenses. Maximum limit reached!\n");
        return;
    }

    struct Expense newExpense;
    printf("Enter expense id: ");
    scanf("%d", &newExpense.id);
    fflush(stdin);

    printf("Enter expense description: ");
    scanf("%[^\n]s", newExpense.description);
    fflush(stdin);

    printf("Enter expense amount: ");
    scanf("%f", &newExpense.amount);

    expenses[totalExpenses++] = newExpense;
    printf("Expense added successfully!\n");
}

void viewExpenses() {
    if (totalExpenses == 0) {
        printf("No expenses found!\n");
        return;
    }

    printf("ID\tDescription\tAmount\n");
    for (int i = 0; i < totalExpenses; i++) {
        printf("%d\t%s\t%.2f\n", expenses[i].id, expenses[i].description, expenses[i].amount);
    }
}

void deleteExpense() {
    int idToDelete;
    printf("Enter expense ID to delete: ");
    scanf("%d", &idToDelete);

    for (int i = 0; i < totalExpenses; i++) {
        if (expenses[i].id == idToDelete) {
            for (int j = i; j < totalExpenses - 1; j++) {
                expenses[j] = expenses[j+1];
            }
            totalExpenses--;
            printf("Expense with id %d deleted successfully!\n", idToDelete);
            return;
        }
    }
    printf("Expense with id %d not found!\n", idToDelete);
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Delete Expense\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                viewExpenses();
                break;
            case 3:
                deleteExpense();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}