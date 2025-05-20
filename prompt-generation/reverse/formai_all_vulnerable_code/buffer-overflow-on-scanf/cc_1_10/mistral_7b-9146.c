//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EXPENSES 100
#define EXPENSE_NAME_SIZE 50
#define EXPENSE_AMOUNT_SIZE 10

struct Expense {
    char name[EXPENSE_NAME_SIZE];
    float amount;
    time_t timestamp;
};

void print_header() {
    printf("_______________________________________________________________\n");
    printf("|                  Galactic Expense Tracker                |\n");
    printf("|____________________________________________________________||\n");
    printf("| Date             | Name                        | Amount | \n");
    printf("|------------------|-----------------------------|--------| \n");
    printf("|__________________|_______________________________|________| \n");
}

void add_expense(struct Expense expenses[], int *num_expenses, char name[], float amount) {
    if (*num_expenses >= MAX_EXPENSES) {
        printf("Error: Maximum number of expenses reached.\n");
        return;
    }

    strcpy(expenses[*num_expenses].name, name);
    expenses[*num_expenses].amount = amount;
    time(&(expenses[*num_expenses].timestamp));
    (*num_expenses)++;
}

void print_expenses(struct Expense expenses[], int num_expenses) {
    for (int i = 0; i < num_expenses; i++) {
        char timestamp_str[20];
        strftime(timestamp_str, sizeof(timestamp_str), "%Y-%m-%d %H:%M:%S", localtime(&(expenses[i].timestamp)));

        printf("| %s     | %s           | %.2f   |\n", timestamp_str, expenses[i].name, expenses[i].amount);
    }
}

int main() {
    int num_expenses = 0;
    struct Expense expenses[MAX_EXPENSES];

    print_header();

    while (1) {
        char action;
        printf("Enter A to Add an expense, P to Print expenses, or Q to Quit: ");
        scanf("%c", &action);

        switch (action) {
            case 'A': {
                char name[EXPENSE_NAME_SIZE];
                float amount;
                printf("Enter expense name: ");
                scanf("%s", name);
                printf("Enter expense amount: ");
                scanf("%f", &amount);

                add_expense(expenses, &num_expenses, name, amount);
                break;
            }
            case 'P': {
                if (num_expenses == 0) {
                    printf("No expenses to display.\n");
                    break;
                }

                print_expenses(expenses, num_expenses);
                break;
            }
            case 'Q':
                exit(0);
            default:
                printf("Invalid action.\n");
        }
    }

    return 0;
}