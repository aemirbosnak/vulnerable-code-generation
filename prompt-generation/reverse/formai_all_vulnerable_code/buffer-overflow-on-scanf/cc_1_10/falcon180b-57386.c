//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float amount;
    time_t date;
} Expense;

Expense expenses[MAX_ITEMS];
int num_expenses = 0;

void add_expense() {
    if (num_expenses >= MAX_ITEMS) {
        printf("Maximum number of expenses reached.\n");
        return;
    }

    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);

    printf("Enter expense amount: ");
    scanf("%f", &expenses[num_expenses].amount);

    time_t now = time(NULL);
    expenses[num_expenses].date = now;

    num_expenses++;
    printf("Expense added.\n");
}

void view_expenses() {
    if (num_expenses == 0) {
        printf("No expenses to view.\n");
        return;
    }

    printf("Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s: $%.2f (%s)\n", expenses[i].name, expenses[i].amount, ctime(&expenses[i].date));
    }
}

void main() {
    printf("Welcome to the Expense Tracker 3000!\n");

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. Quit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_expense();
            break;
        case 2:
            view_expenses();
            break;
        case 3:
            printf("Goodbye!\n");
            exit(0);
        default:
            printf("Invalid option.\n");
        }
    }
}