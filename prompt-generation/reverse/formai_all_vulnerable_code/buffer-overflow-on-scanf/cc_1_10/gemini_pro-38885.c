//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The table to store expenses
typedef struct {
    char *item;
    double amount;
    char *category;
    char *date;
} expense;

// Function to print the expenses
void print_expenses(expense *expenses, int num_expenses) {
    printf("--------------------------------------------------------------------------------\n");
    printf("| %-20s | %-10s | %-15s | %-10s |\n", "Item", "Amount", "Category", "Date");
    printf("--------------------------------------------------------------------------------\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("| %-20s | %-10.2f | %-15s | %-10s |\n", expenses[i].item, expenses[i].amount, expenses[i].category, expenses[i].date);
    }
    printf("--------------------------------------------------------------------------------\n");
}

// Function to add an expense
void add_expense(expense *expenses, int *num_expenses) {
    char *item = malloc(50 * sizeof(char));
    printf("Item: ");
    scanf("%s", item);

    double amount;
    printf("Amount: ");
    scanf("%lf", &amount);

    char *category = malloc(20 * sizeof(char));
    printf("Category: ");
    scanf("%s", category);

    char *date = malloc(11 * sizeof(char));
    printf("Date (YYYY-MM-DD): ");
    scanf("%s", date);

    expenses[*num_expenses].item = item;
    expenses[*num_expenses].amount = amount;
    expenses[*num_expenses].category = category;
    expenses[*num_expenses].date = date;

    (*num_expenses)++;
}

// Function to search for an expense
void search_expense(expense *expenses, int num_expenses) {
    char *search_term = malloc(50 * sizeof(char));
    printf("Search term: ");
    scanf("%s", search_term);

    int found = 0;
    for (int i = 0; i < num_expenses; i++) {
        if (strstr(expenses[i].item, search_term) != NULL) {
            printf("Found expense:\n");
            printf("| %-20s | %-10.2f | %-15s | %-10s |\n", expenses[i].item, expenses[i].amount, expenses[i].category, expenses[i].date);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No expense found.\n");
    }
    free(search_term);
}

// Function to delete an expense
void delete_expense(expense *expenses, int *num_expenses) {
    char *delete_term = malloc(50 * sizeof(char));
    printf("Delete term: ");
    scanf("%s", delete_term);

    int found = 0;
    for (int i = 0; i < *num_expenses; i++) {
        if (strstr(expenses[i].item, delete_term) != NULL) {
            for (int j = i; j < *num_expenses - 1; j++) {
                expenses[j] = expenses[j + 1];
            }
            (*num_expenses)--;
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No expense found.\n");
    }
    free(delete_term);
}

int main() {
    // Sherlock Holmes' expense tracker
    printf("Welcome to Sherlock Holmes' Expense Tracker, my dear Watson!\n");

    int num_expenses = 0;
    expense expenses[100];

    int choice;
    do {
        printf("\n");
        printf("1. Add an expense\n");
        printf("2. Print expenses\n");
        printf("3. Search for an expense\n");
        printf("4. Delete an expense\n");
        printf("5. Quit\n");
        printf("\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense(expenses, &num_expenses);
                break;
            case 2:
                print_expenses(expenses, num_expenses);
                break;
            case 3:
                search_expense(expenses, num_expenses);
                break;
            case 4:
                delete_expense(expenses, &num_expenses);
                break;
            case 5:
                printf("Thank you, my dear Watson!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    // Free the memory allocated for the expenses
    for (int i = 0; i < num_expenses; i++) {
        free(expenses[i].item);
        free(expenses[i].category);
        free(expenses[i].date);
    }

    return 0;
}