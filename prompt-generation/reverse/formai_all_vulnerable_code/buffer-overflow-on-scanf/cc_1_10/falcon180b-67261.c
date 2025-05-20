//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    double amount;
    char category[50];
    char date[20];
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense() {
    char name[50];
    double amount;
    char category[50];
    char date[20];

    printf("Enter expense name: ");
    scanf("%s", name);

    printf("Enter expense amount: ");
    scanf("%lf", &amount);

    printf("Enter expense category: ");
    scanf("%s", category);

    printf("Enter expense date (YYYY-MM-DD): ");
    scanf("%s", date);

    strcpy(expenses[num_expenses].name, name);
    expenses[num_expenses].amount = amount;
    strcpy(expenses[num_expenses].category, category);
    strcpy(expenses[num_expenses].date, date);

    num_expenses++;
}

void display_expenses() {
    printf("\nExpense Report\n");
    printf("=====================\n");
    printf("Name\tAmount\tCategory\tDate\n");

    for (int i = 0; i < num_expenses; i++) {
        printf("%s\t%.2lf\t%s\t%s\n", expenses[i].name, expenses[i].amount, expenses[i].category, expenses[i].date);
    }
}

int main() {
    int choice;

    do {
        printf("\n");
        printf("1. Add expense\n");
        printf("2. Display expenses\n");
        printf("3. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                display_expenses();
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice!= 3);

    return 0;
}