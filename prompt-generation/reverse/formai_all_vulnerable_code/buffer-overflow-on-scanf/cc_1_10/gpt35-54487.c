//FormAI DATASET v1.0 Category: Expense Tracker ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORY_LEN 50
#define MAX_DESCRIPTION_LEN 100

typedef struct {
    char category[MAX_CATEGORY_LEN];
    char description[MAX_DESCRIPTION_LEN];
    double amount;
} Expense;

double total_expenses = 0;

void print_menu() {
    printf("\n1. Add expense\n");
    printf("2. View expenses\n");
    printf("3. Quit\n\n");
}

void add_expense(Expense expenses[], int *num_expenses) {
    Expense e;
    printf("\nEnter category: ");
    fgets(e.category, MAX_CATEGORY_LEN, stdin);
    e.category[strcspn(e.category, "\n")] = '\0'; // remove newline character
    printf("Enter description: ");
    fgets(e.description, MAX_DESCRIPTION_LEN, stdin);
    e.description[strcspn(e.description, "\n")] = '\0';
    printf("Enter amount: ");
    scanf("%lf", &e.amount);
    getchar(); // clear newline character from buffer
    expenses[*num_expenses] = e;
    (*num_expenses)++;
    total_expenses += e.amount;
    printf("\nExpense added successfully!\n");
}

void view_expenses(Expense expenses[], int num_expenses) {
    if (num_expenses == 0) {
        printf("\nNo expenses to show.\n");
    }
    else {
        printf("\n%-20s%-30s%10s\n", "Category", "Description", "Amount");
        printf("-------------------------------------------------------\n");
        for (int i = 0; i < num_expenses; i++) {
            printf("%-20s%-30s%10.2f\n", expenses[i].category, expenses[i].description, expenses[i].amount);
        }
        printf("-------------------------------------------------------\n");
        printf("%-50s%10.2f\n", "Total expenses:", total_expenses);
    }
}

int main() {
    Expense expenses[100];
    int num_expenses = 0;
    int choice;
    printf("Welcome to the Expense Tracker!\n");
    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline character from buffer
        switch (choice) {
            case 1:
                add_expense(expenses, &num_expenses);
                break;
            case 2:
                view_expenses(expenses, num_expenses);
                break;
            case 3:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 3);
    return 0;
}