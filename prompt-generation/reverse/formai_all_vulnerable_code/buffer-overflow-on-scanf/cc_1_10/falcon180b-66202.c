//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char category[50];
    float amount;
    int date;
} expense;

void add_expense(expense *expenses) {
    int i = 0;
    while (i < MAX_EXPENSES && expenses[i].category[0]!= '\0') {
        i++;
    }
    if (i == MAX_EXPENSES) {
        printf("Cannot add more expenses.\n");
        return;
    }
    printf("Enter expense category: ");
    scanf("%s", expenses[i].category);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[i].amount);
    printf("Enter expense date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &expenses[i].date);
    expenses[i].category[strcspn(expenses[i].category, "\n")] = '\0';
}

void view_expenses(expense *expenses) {
    int i = 0;
    while (i < MAX_EXPENSES && expenses[i].category[0]!= '\0') {
        printf("%s - %.2f - %d/%.2f/%d\n", expenses[i].category, expenses[i].amount, expenses[i].date / 10000, expenses[i].date / 100 % 100, expenses[i].date % 100);
        i++;
    }
}

int main() {
    expense expenses[MAX_EXPENSES];
    int choice;
    do {
        printf("1. Add expense\n2. View expenses\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_expense(expenses);
                break;
            case 2:
                view_expenses(expenses);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);
    return 0;
}