//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <ctype.h>

typedef struct Expense {
    char description[100];
    float amount;
    time_t timestamp;
} Expense;

#define MAX_EXPENSES 100
Expense expenses[MAX_EXPENSES];
int current_expense = 0;

void print_expenses() {
    printf("\n*** SHOCKED EXPENSE TRACKER ***\n");
    for (int i = 0; i < current_expense; i++) {
        printf("\nExpense %d:\n", i + 1);
        printf("Description: %s\n", expenses[i].description);
        printf("Amount: $%.2f\n", expenses[i].amount);
        printf("Timestamp: %s", ctime(&expenses[i].timestamp));
    }
}

void add_expense() {
    if (current_expense >= MAX_EXPENSES) {
        printf("\n*** SHOCKED! MAXIMUM EXPENSES REACHED! ***\n");
        return;
    }

    printf("\nEnter expense description: ");
    fgets(expenses[current_expense].description, sizeof(expenses[current_expense].description), stdin);
    expenses[current_expense].description[strlen(expenses[current_expense].description) - 1] = '\0';

    printf("Enter expense amount: $");
    scanf("%f", &expenses[current_expense].amount);

    expenses[current_expense].timestamp = time(NULL);
    current_expense++;
}

int main() {
    int choice;

    while (1) {
        printf("\n*** SHOCKED EXPENSE TRACKER MENU ***\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                print_expenses();
                break;
            case 3:
                printf("\n*** SHOCKED! EXITING EXPENSE TRACKER! ***\n");
                exit(0);
            default:
                printf("\n*** SHOCKED! INVALID CHOICE! ***\n");
                break;
        }
    }

    return 0;
}