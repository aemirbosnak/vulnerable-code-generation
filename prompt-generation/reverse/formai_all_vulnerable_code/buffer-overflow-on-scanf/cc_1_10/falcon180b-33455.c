//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EXPENSES 100

typedef struct {
    char description[50];
    float amount;
    time_t date;
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense() {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Error: Maximum number of expenses reached.\n");
        return;
    }

    printf("Enter expense description: ");
    scanf("%s", expenses[num_expenses].description);

    printf("Enter expense amount: ");
    scanf("%f", &expenses[num_expenses].amount);

    time_t now = time(NULL);
    expenses[num_expenses].date = now;

    num_expenses++;
}

void view_expenses() {
    printf("Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s - %.2f - %s\n", expenses[i].description, expenses[i].amount, ctime(&expenses[i].date));
    }
}

int main() {
    srand(time(NULL));

    printf("Welcome to the Cyberpunk Expense Tracker!\n");

    while (1) {
        printf("\nOptions:\n");
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. Exit\n");

        int choice = rand() % 3;
        printf("You choose option %d.\n", choice + 1);

        switch (choice) {
        case 1:
            add_expense();
            break;
        case 2:
            view_expenses();
            break;
        case 3:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid option.\n");
        }
    }

    return 0;
}