//FormAI DATASET v1.0 Category: Expense Tracker ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense {
    char name[100];
    float amount;
    char date[11];
    char category[100];
};

void addExpense(struct Expense expenses[], int *n);
void viewExpenses(struct Expense expenses[], int n);
void viewCategoryExpenses(struct Expense expenses[], int n);
void viewExpenseByDate(struct Expense expenses[], int n);

int main() {
    struct Expense expenses[100];
    int n = 0, choice;
    while(1) {
        printf("\n\n");
        printf("1. Add expense\n");
        printf("2. View all expenses\n");
        printf("3. View expenses by category\n");
        printf("4. View expenses by date\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addExpense(expenses, &n);
                break;
            case 2:
                viewExpenses(expenses, n);
                break;
            case 3:
                viewCategoryExpenses(expenses, n);
                break;
            case 4:
                viewExpenseByDate(expenses, n);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

void addExpense(struct Expense expenses[], int *n) {
    printf("\nEnter expense details:\n");
    printf("Name: ");
    getchar();
    fgets(expenses[*n].name, 100, stdin);
    expenses[*n].name[strlen(expenses[*n].name) - 1] = '\0';
    printf("Amount: ");
    scanf("%f", &expenses[*n].amount);
    printf("Date (in DD/MM/YYYY format): ");
    getchar();
    fgets(expenses[*n].date, 11, stdin);
    expenses[*n].date[strlen(expenses[*n].date) - 1] = '\0';
    printf("Category: ");
    fgets(expenses[*n].category, 100, stdin);
    expenses[*n].category[strlen(expenses[*n].category) - 1] = '\0';
    (*n)++;
    printf("\nExpense added successfully!\n");
}

void viewExpenses(struct Expense expenses[], int n) {
    if(n == 0) {
        printf("No expenses found\n");
        return;
    }
    printf("\nAll expenses:\n");
    printf("%-20s %-10s %-15s %-20s\n", "Name", "Amount", "Date", "Category");
    for(int i = 0; i < n; i++) {
        printf("%-20s %-10.2f %-15s %-20s\n", expenses[i].name, expenses[i].amount,
                expenses[i].date, expenses[i].category);
    }
}

void viewCategoryExpenses(struct Expense expenses[], int n) {
    if(n == 0) {
        printf("No expenses found\n");
        return;
    }
    char category[100];
    printf("\nEnter category name: ");
    getchar();
    fgets(category, 100, stdin);
    category[strlen(category) - 1] = '\0';
    printf("\nExpenses in category '%s':\n", category);
    printf("%-20s %-10s %-15s %-20s\n", "Name", "Amount", "Date", "Category");
    for(int i = 0; i < n; i++) {
        if(strcmp(expenses[i].category, category) == 0) {
            printf("%-20s %-10.2f %-15s %-20s\n", expenses[i].name, expenses[i].amount,
                    expenses[i].date, expenses[i].category);
        }
    }
}

void viewExpenseByDate(struct Expense expenses[], int n) {
    if(n == 0) {
        printf("No expenses found\n");
        return;
    }
    char date[11];
    printf("\nEnter date (in DD/MM/YYYY format): ");
    getchar();
    fgets(date, 11, stdin);
    date[strlen(date) - 1] = '\0';
    printf("\nExpenses on '%s':\n", date);
    printf("%-20s %-10s %-15s %-20s\n", "Name", "Amount", "Date", "Category");
    for(int i = 0; i < n; i++) {
        if(strcmp(expenses[i].date, date) == 0) {
            printf("%-20s %-10.2f %-15s %-20s\n", expenses[i].name, expenses[i].amount,
                    expenses[i].date, expenses[i].category);
        }
    }
}