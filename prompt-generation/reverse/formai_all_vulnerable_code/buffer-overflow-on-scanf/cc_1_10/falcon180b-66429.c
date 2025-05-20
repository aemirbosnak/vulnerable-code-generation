//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_EXPENSES 100

struct expense {
    char date[11];
    char category[51];
    double amount;
};

void add_expense(struct expense expenses[], int num_expenses) {
    char input[1024];
    printf("Enter expense date (YYYY-MM-DD): ");
    fgets(input, sizeof(input), stdin);
    strcpy(expenses[num_expenses].date, input);

    printf("Enter expense category: ");
    fgets(input, sizeof(input), stdin);
    strcpy(expenses[num_expenses].category, input);

    printf("Enter expense amount: ");
    scanf("%lf", &expenses[num_expenses].amount);

    num_expenses++;
}

void print_expenses(struct expense expenses[], int num_expenses) {
    printf("Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s - %s - %.2lf\n", expenses[i].date, expenses[i].category, expenses[i].amount);
    }
}

int main() {
    struct expense expenses[MAX_EXPENSES];
    int num_expenses = 0;

    while (1) {
        printf("\n1. Add expense\n2. Print expenses\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_expenses >= MAX_EXPENSES) {
                    printf("Maximum number of expenses reached.\n");
                } else {
                    add_expense(expenses, num_expenses);
                }
                break;
            case 2:
                print_expenses(expenses, num_expenses);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}