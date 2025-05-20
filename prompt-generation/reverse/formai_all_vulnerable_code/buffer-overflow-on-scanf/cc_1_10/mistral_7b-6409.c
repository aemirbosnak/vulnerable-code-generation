//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: Cryptic
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EXPENSES 100
#define EXPENSE_NAME_LENGTH 50
#define EXPENSE_AMOUNT_LENGTH 10

typedef struct Expense {
    char name[EXPENSE_NAME_LENGTH];
    float amount;
    time_t timestamp;
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void save_expense(const char* name, float amount) {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Error: Maximum number of expenses reached.\n");
        return;
    }

    strcpy(expenses[num_expenses].name, name);
    expenses[num_expenses].amount = amount;
    expenses[num_expenses].timestamp = time(NULL);
    num_expenses++;
}

void print_expenses() {
    if (num_expenses == 0) {
        printf("Error: No expenses recorded.\n");
        return;
    }

    printf("%-10s %-50s %-15s\n", "ID", "Name", "Amount");

    for (int i = 0; i < num_expenses; i++) {
        printf("%-10d %-50s %-15.2f\n", i + 1, expenses[i].name, expenses[i].amount);
    }
}

int main(void) {
    char input_name[EXPENSE_NAME_LENGTH];
    float input_amount;
    char command;

    while (1) {
        printf("\nExpense Tracker > ");
        scanf("%c", &command);
        getchar();

        switch (command) {
            case 'a':
                printf("Enter expense name: ");
                scanf("%s", input_name);
                printf("Enter expense amount: ");
                scanf("%f", &input_amount);
                save_expense(input_name, input_amount);
                break;
            case 'p':
                print_expenses();
                break;
            case 'e':
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid command.\n");
                break;
        }
    }

    return 0;
}