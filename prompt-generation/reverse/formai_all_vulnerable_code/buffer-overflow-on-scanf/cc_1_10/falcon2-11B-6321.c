//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense {
    char name[50];
    double amount;
    char category[50];
    int num_occurrences;
};

struct Expense expenses[100];
int num_expenses = 0;

void add_expense(char name[], double amount, char category[]) {
    struct Expense new_expense;
    strcpy(new_expense.name, name);
    new_expense.amount = amount;
    strcpy(new_expense.category, category);
    new_expense.num_occurrences = 1;
    expenses[num_expenses] = new_expense;
    num_expenses++;
}

void display_expenses() {
    int i;
    printf("Total expenses: %d\n", num_expenses);
    printf("Name\t\tAmount\t\tCategory\t\tOccurrences\n");
    for (i = 0; i < num_expenses; i++) {
        printf("%s\t\t%.2f\t\t%s\t\t%d\n", expenses[i].name, expenses[i].amount, expenses[i].category, expenses[i].num_occurrences);
    }
}

void update_expense(int index, char name[], double amount, char category[]) {
    if (index >= 0 && index < num_expenses) {
        struct Expense expense = expenses[index];
        strcpy(expense.name, name);
        expense.amount = amount;
        strcpy(expense.category, category);
        expense.num_occurrences++;
    }
}

void delete_expense(int index) {
    if (index >= 0 && index < num_expenses) {
        struct Expense expense = expenses[index];
        for (int i = index; i < num_expenses - 1; i++) {
            expenses[i] = expenses[i + 1];
        }
        num_expenses--;
    }
}

int main() {
    int choice, index, amount;
    char name[50], category[50];
    while (1) {
        printf("1. Add expense\n2. Display expenses\n3. Update expense\n4. Delete expense\n5. Quit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter expense name: ");
                scanf("%s", name);
                printf("Enter expense amount: ");
                scanf("%lf", &amount);
                printf("Enter expense category: ");
                scanf("%s", category);
                add_expense(name, amount, category);
                break;
            case 2:
                display_expenses();
                break;
            case 3:
                printf("Enter index of expense to update: ");
                scanf("%d", &index);
                if (index >= 0 && index < num_expenses) {
                    printf("Enter new expense name: ");
                    scanf("%s", name);
                    printf("Enter new expense amount: ");
                    scanf("%lf", &amount);
                    printf("Enter new expense category: ");
                    scanf("%s", category);
                    update_expense(index, name, amount, category);
                }
                break;
            case 4:
                printf("Enter index of expense to delete: ");
                scanf("%d", &index);
                if (index >= 0 && index < num_expenses) {
                    delete_expense(index);
                }
                break;
            case 5:
                printf("Quitting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}