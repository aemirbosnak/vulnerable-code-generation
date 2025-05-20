//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_NAME_LENGTH 50
#define MAX_CATEGORY_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    float amount;
    int date;
} expense;

void add_expense(expense* expenses, int num_expenses) {
    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);
    printf("Enter expense category: ");
    scanf("%s", expenses[num_expenses].category);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[num_expenses].amount);
    printf("Enter expense date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &expenses[num_expenses].date);
}

void print_expenses(expense* expenses, int num_expenses) {
    printf("Expense Name\tExpense Category\tExpense Amount\tExpense Date\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s\t%s\t%.2f\t%d/%d/%d\n", expenses[i].name, expenses[i].category, expenses[i].amount, expenses[i].date%100, (expenses[i].date/100)%100, expenses[i].date/10000);
    }
}

int main() {
    expense expenses[MAX_EXPENSES];
    int num_expenses = 0;
    char choice;

    do {
        printf("\nExpense Tracker\n");
        printf("1. Add expense\n");
        printf("2. Print expenses\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                if (num_expenses >= MAX_EXPENSES) {
                    printf("Maximum number of expenses reached!\n");
                } else {
                    add_expense(expenses, num_expenses);
                    num_expenses++;
                }
                break;
            case '2':
                if (num_expenses == 0) {
                    printf("No expenses added yet!\n");
                } else {
                    print_expenses(expenses, num_expenses);
                }
                break;
            case '3':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= '3');

    return 0;
}