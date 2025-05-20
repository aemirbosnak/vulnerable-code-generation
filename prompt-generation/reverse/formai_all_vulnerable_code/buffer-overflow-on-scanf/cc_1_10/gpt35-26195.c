//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPENSES 100
#define MAX_DESCRIPTION 50

struct expense {
    int id;
    char description[MAX_DESCRIPTION];
    float amount;
};

void add_expense(struct expense *expenses, int *num_expenses);
void view_expenses(struct expense *expenses, int num_expenses);
void search_expenses(struct expense *expenses, int num_expenses);
void delete_expense(struct expense *expenses, int *num_expenses);

// Main menu function
int main() {
    struct expense expenses[MAX_EXPENSES];
    int num_expenses = 0;
    char choice;

    printf("Welcome to the Cyberpunk Expense Tracker!\n");

    while (1) {
        printf("\nMAIN MENU\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Search Expenses\n");
        printf("4. Delete Expense\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf(" %c", &choice);
        printf("\n");

        switch(choice) {
            case '1':
                add_expense(expenses, &num_expenses);
                break;
            case '2':
                view_expenses(expenses, num_expenses);
                break;
            case '3':
                search_expenses(expenses, num_expenses);
                break;
            case '4':
                delete_expense(expenses, &num_expenses);
                break;
            case '5':
                printf("Thank you for using the Cyberpunk Expense Tracker!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Adds an expense to the array of expenses
void add_expense(struct expense *expenses, int *num_expenses) {
    struct expense new_expense;

    printf("Adding new expense...\n");

    printf("Enter description (max %d characters): ", MAX_DESCRIPTION);
    scanf(" %[^\n]", new_expense.description);

    printf("Enter amount: ");
    scanf(" %f", &new_expense.amount);

    new_expense.id = *num_expenses + 1;
    expenses[*num_expenses] = new_expense;
    *num_expenses += 1;

    printf("Expense added!\n");
}

// Views all expenses in the array
void view_expenses(struct expense *expenses, int num_expenses) {
    if (num_expenses == 0) {
        printf("No expenses to view.\n");
        return;
    }

    printf("Expenses:\n");

    for (int i = 0; i < num_expenses; i++) {
        printf("ID: %d\n", expenses[i].id);
        printf("Description: %s\n", expenses[i].description);
        printf("Amount: %.2f\n", expenses[i].amount);
        printf("\n");
    }
}

// Searches expenses for a particular keyword
void search_expenses(struct expense *expenses, int num_expenses) {
    char search_term[MAX_DESCRIPTION];
    int num_results = 0;

    printf("Search for an expense...\n");

    printf("Enter search term: ");
    scanf(" %[^\n]", search_term);

    printf("Search results:\n");

    for (int i = 0; i < num_expenses; i++) {
        if (strstr(expenses[i].description, search_term)) {
            printf("ID: %d\n", expenses[i].id);
            printf("Description: %s\n", expenses[i].description);
            printf("Amount: %.2f\n", expenses[i].amount);
            printf("\n");
            num_results++;
        }
    }

    if (num_results == 0) {
        printf("No results found.\n");
    } else {
        printf("Found %d result(s).\n", num_results);
    }
}

// Deletes an expense from the array
void delete_expense(struct expense *expenses, int *num_expenses) {
    int id_to_delete, index_to_delete = -1;

    printf("Deleting an expense...\n");

    printf("Enter ID of expense to delete: ");
    scanf(" %d", &id_to_delete);

    for (int i = 0; i < *num_expenses; i++) {
        if (expenses[i].id == id_to_delete) {
            index_to_delete = i;
            break;
        }
    }

    if (index_to_delete == -1) {
        printf("ID %d not found. Nothing deleted.\n", id_to_delete);
        return;
    }

    for (int i = index_to_delete; i < *num_expenses - 1; i++) {
        expenses[i] = expenses[i+1];
    }

    *num_expenses -= 1;

    printf("Expense deleted!\n");
}