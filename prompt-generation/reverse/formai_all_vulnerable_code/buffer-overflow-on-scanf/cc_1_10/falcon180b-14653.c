//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

struct Expense {
    char description[100];
    float amount;
    int date;
};

void addExpense(struct Expense expenses[], int count, char *description, float amount, int date) {
    if (count >= MAX_EXPENSES) {
        printf("Maximum expenses reached. Cannot add more.\n");
        return;
    }
    strcpy(expenses[count].description, description);
    expenses[count].amount = amount;
    expenses[count].date = date;
    count++;
}

void displayExpenses(struct Expense expenses[], int count) {
    printf("Expenses:\n");
    for (int i = 0; i < count; i++) {
        printf("%s - %.2f - %d\n", expenses[i].description, expenses[i].amount, expenses[i].date);
    }
}

int main() {
    struct Expense expenses[MAX_EXPENSES];
    int count = 0;
    char choice;
    do {
        printf("Expense tracker\n");
        printf("1. Add expense\n2. Display expenses\n3. Quit\n");
        scanf("%c", &choice);
        switch (choice) {
            case '1':
                printf("Enter expense description: ");
                char description[100];
                scanf("%s", description);
                printf("Enter amount: ");
                float amount;
                scanf("%f", &amount);
                printf("Enter date (YYYY-MM-DD): ");
                int date;
                scanf("%d", &date);
                addExpense(expenses, count, description, amount, date);
                break;
            case '2':
                displayExpenses(expenses, count);
                break;
            case '3':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= '3');
    return 0;
}