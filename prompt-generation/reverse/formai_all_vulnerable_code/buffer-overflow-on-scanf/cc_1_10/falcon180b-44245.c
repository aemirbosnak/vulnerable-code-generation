//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPENSES 100

typedef struct {
    char category[50];
    char description[100];
    float amount;
} expense;

expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense() {
    printf("Enter expense category: ");
    scanf("%s", expenses[num_expenses].category);

    printf("Enter expense description: ");
    scanf("%s", expenses[num_expenses].description);

    printf("Enter expense amount: ");
    scanf("%f", &expenses[num_expenses].amount);

    num_expenses++;
}

void view_expenses() {
    printf("\nExpenses:\n");
    printf("Category\tDescription\tAmount\n");

    for (int i = 0; i < num_expenses; i++) {
        printf("%s\t%s\t$%.2f\n", expenses[i].category, expenses[i].description, expenses[i].amount);
    }
}

void remove_expense() {
    printf("\nEnter expense number to remove: ");
    int num;
    scanf("%d", &num);

    if (num >= 0 && num < num_expenses) {
        for (int i = num; i < num_expenses - 1; i++) {
            strcpy(expenses[i].category, expenses[i+1].category);
            strcpy(expenses[i].description, expenses[i+1].description);
            expenses[i].amount = expenses[i+1].amount;
        }
        num_expenses--;
    } else {
        printf("Invalid expense number.\n");
    }
}

int main() {
    printf("Welcome to the Expense Tracker!\n");

    while (1) {
        printf("\nOptions:\n1. Add expense\n2. View expenses\n3. Remove expense\n4. Exit\n");
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
                remove_expense();
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}