//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    float amount;
    int date;
} Expense;

void addExpense(Expense* expenses, int index) {
    printf("Enter expense name (up to %d characters): ", MAX_NAME_LENGTH);
    scanf("%s", expenses[index].name);

    printf("Enter expense description (up to %d characters): ", MAX_DESCRIPTION_LENGTH);
    scanf("%s", expenses[index].description);

    printf("Enter expense amount: ");
    scanf("%f", &expenses[index].amount);

    printf("Enter expense date (YYYY-MM-DD): ");
    scanf("%d", &expenses[index].date);
}

void printExpenses(Expense* expenses, int count) {
    printf("Expense Report\n");
    printf("================\n");

    for (int i = 0; i < count; i++) {
        printf("%s\t%s\t%.2f\t%d\n", expenses[i].name, expenses[i].description, expenses[i].amount, expenses[i].date);
    }
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int count = 0;

    while (count < MAX_EXPENSES) {
        printf("\nDo you want to add an expense? (y/n): ");
        char choice;
        scanf("%c", &choice);

        if (choice == 'y') {
            addExpense(expenses, count);
            count++;
        } else if (choice!= 'n') {
            printf("Invalid input. Please enter 'y' or 'n'.\n");
        }
    }

    printExpenses(expenses, count);

    return 0;
}