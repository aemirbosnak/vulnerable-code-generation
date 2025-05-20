//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ENTRIES 100

typedef struct expense {
    char description[50];
    float amount;
    char date[11];
    char category[20];
} expense_t;

expense_t expenses[MAX_ENTRIES];
int num_expenses = 0;

void add_expense(char *description, float amount, char *date, char *category) {
    if (num_expenses == MAX_ENTRIES) {
        printf("Error: Cannot add more expenses, maximum reached.\n");
        return;
    }

    strcpy(expenses[num_expenses].description, description);
    expenses[num_expenses].amount = amount;
    strcpy(expenses[num_expenses].date, date);
    strcpy(expenses[num_expenses].category, category);

    num_expenses++;
}

void print_expenses() {
    printf("Expense Tracker\n");
    printf("=================\n");

    for (int i = 0; i < num_expenses; i++) {
        printf("%s\t%.2f\t%s\t%s\n", expenses[i].description, expenses[i].amount, expenses[i].date, expenses[i].category);
    }
}

void sort_expenses(int sort_by) {
    expense_t temp;

    for (int i = 0; i < num_expenses - 1; i++) {
        for (int j = 0; j < num_expenses - i - 1; j++) {
            switch (sort_by) {
                case 0: // Sort by description
                    if (strcmp(expenses[j].description, expenses[j + 1].description) > 0) {
                        temp = expenses[j];
                        expenses[j] = expenses[j + 1];
                        expenses[j + 1] = temp;
                    }
                    break;
                case 1: // Sort by amount
                    if (expenses[j].amount > expenses[j + 1].amount) {
                        temp = expenses[j];
                        expenses[j] = expenses[j + 1];
                        expenses[j + 1] = temp;
                    }
                    break;
                case 2: // Sort by date
                    if (strcmp(expenses[j].date, expenses[j + 1].date) > 0) {
                        temp = expenses[j];
                        expenses[j] = expenses[j + 1];
                        expenses[j + 1] = temp;
                    }
                    break;
                case 3: // Sort by category
                    if (strcmp(expenses[j].category, expenses[j + 1].category) > 0) {
                        temp = expenses[j];
                        expenses[j] = expenses[j + 1];
                        expenses[j + 1] = temp;
                    }
                    break;
            }
        }
    }
}

void search_expenses(char *query) {
    int found = 0;

    printf("Search Results for '%s':\n", query);
    printf("=========================\n");

    for (int i = 0; i < num_expenses; i++) {
        if (strstr(expenses[i].description, query) || strstr(expenses[i].date, query) || strstr(expenses[i].category, query)) {
            printf("%s\t%.2f\t%s\t%s\n", expenses[i].description, expenses[i].amount, expenses[i].date, expenses[i].category);
            found = 1;
        }
    }

    if (!found) {
        printf("No matching expenses found.\n");
    }
}

int main() {
    int choice;
    char description[50];
    float amount;
    char date[11];
    char category[20];
    char query[50];

    while (1) {
        printf("\nExpense Tracker Menu\n");
        printf("=====================\n");
        printf("1. Add Expense\n");
        printf("2. Print Expenses\n");
        printf("3. Sort Expenses\n");
        printf("4. Search Expenses\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter description: ");
                scanf(" %[^\n]s", description);
                printf("Enter amount: ");
                scanf("%f", &amount);
                printf("Enter date (YYYY-MM-DD): ");
                scanf("%s", date);
                printf("Enter category: ");
                scanf(" %[^\n]s", category);
                add_expense(description, amount, date, category);
                break;
            case 2:
                print_expenses();
                break;
            case 3:
                printf("Sort by:\n");
                printf("1. Description\n");
                printf("2. Amount\n");
                printf("3. Date\n");
                printf("4. Category\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                sort_expenses(choice - 1);
                break;
            case 4:
                printf("Enter search query: ");
                scanf(" %[^\n]s", query);
                search_expenses(query);
                break;
            case 5:
                printf("Exiting Expense Tracker.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    }

    return 0;
}