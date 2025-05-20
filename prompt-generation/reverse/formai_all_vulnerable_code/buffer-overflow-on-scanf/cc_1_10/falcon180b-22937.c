//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_AMOUNT_LEN 10

typedef struct expense {
    char name[MAX_NAME_LEN];
    char amount[MAX_AMOUNT_LEN];
} Expense;

Expense expenses[MAX_ITEMS];
int num_expenses = 0;

void surrealist_expense_tracker() {
    int choice;
    char input[100];

    do {
        printf("Welcome to the Surrealist Expense Tracker!\n");
        printf("Please choose an option:\n");
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. Exit\n");
        scanf("%s", input);

        switch (atoi(input)) {
            case 1:
                printf("Enter expense name (max %d characters): ", MAX_NAME_LEN - 1);
                scanf("%s", expenses[num_expenses].name);
                printf("Enter expense amount (max %d characters): ", MAX_AMOUNT_LEN - 1);
                scanf("%s", expenses[num_expenses].amount);
                num_expenses++;
                break;
            case 2:
                printf("Expenses:\n");
                for (int i = 0; i < num_expenses; i++) {
                    printf("%s: %s\n", expenses[i].name, expenses[i].amount);
                }
                break;
            case 3:
                printf("Thank you for using the Surrealist Expense Tracker!\n");
                break;
            default:
                printf("Invalid option.\n");
        }
    } while (atoi(input)!= 3);
}

int main() {
    surrealist_expense_tracker();
    return 0;
}