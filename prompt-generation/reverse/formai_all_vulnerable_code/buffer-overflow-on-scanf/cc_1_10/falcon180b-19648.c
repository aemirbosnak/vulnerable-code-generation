//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    float amount;
    int date;
} Expense;

void add_expense(Expense expenses[], int num_expenses) {
    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[num_expenses].amount);
    printf("Enter expense date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &expenses[num_expenses].date);
    num_expenses++;
}

void display_expenses(Expense expenses[], int num_expenses) {
    printf("\nExpense Report\n");
    printf("Expense Name\tAmount\tDate\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s\t%.2f\t%d/%d/%d\n", expenses[i].name, expenses[i].amount, expenses[i].date/10000, (expenses[i].date/100)%100, expenses[i].date%100);
    }
}

void search_expense(Expense expenses[], int num_expenses) {
    char search_name[50];
    printf("Enter expense name to search: ");
    scanf("%s", search_name);
    int found = 0;
    for (int i = 0; i < num_expenses; i++) {
        if (strcmp(expenses[i].name, search_name) == 0) {
            printf("Found expense:\n");
            printf("Expense Name: %s\n", expenses[i].name);
            printf("Expense Amount: %.2f\n", expenses[i].amount);
            printf("Expense Date: %d/%d/%d\n", expenses[i].date/10000, (expenses[i].date/100)%100, expenses[i].date%100);
            found = 1;
            break;
        }
    }
    if (found == 0) {
        printf("Expense not found.\n");
    }
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int num_expenses = 0;

    while (num_expenses < MAX_EXPENSES) {
        int choice;
        printf("\nExpense Tracker\n");
        printf("1. Add expense\n2. Display expenses\n3. Search expense\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_expense(expenses, num_expenses);
                break;
            case 2:
                display_expenses(expenses, num_expenses);
                break;
            case 3:
                search_expense(expenses, num_expenses);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}