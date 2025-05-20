//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_EXPENSES 100
#define MAX_CATEGORIES 20
#define MAX_DESCRIPTION_SIZE 100
#define MAX_AMOUNT_SIZE 20

typedef struct {
    char category[MAX_CATEGORIES];
    char description[MAX_DESCRIPTION_SIZE];
    char amount[MAX_AMOUNT_SIZE];
    time_t date;
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense() {
    if (num_expenses == MAX_EXPENSES) {
        printf("Error: Maximum number of expenses reached.\n");
        return;
    }

    printf("Category: ");
    scanf("%s", expenses[num_expenses].category);

    printf("Description: ");
    scanf("%s", expenses[num_expenses].description);

    printf("Amount: ");
    scanf("%s", expenses[num_expenses].amount);

    time(&expenses[num_expenses].date);

    num_expenses++;
}

void view_expenses() {
    if (num_expenses == 0) {
        printf("No expenses added yet.\n");
        return;
    }

    printf("Category\tDescription\tAmount\tDate\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s\t%s\t%s\t%s\n", expenses[i].category, expenses[i].description, expenses[i].amount, ctime(&expenses[i].date));
    }
}

void main() {
    int choice;

    do {
        printf("1. Add expense\n2. View expenses\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                view_expenses();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);
}