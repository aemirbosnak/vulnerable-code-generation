//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CATEGORIES 10
#define MAX_DESCRIPTION_LENGTH 50
#define MAX_EXPENSES_PER_CATEGORY 10

// Category structure
typedef struct {
    char name[MAX_CATEGORIES][MAX_DESCRIPTION_LENGTH];
    double total_expenses[MAX_EXPENSES_PER_CATEGORY];
    int num_expenses;
} Category;

// Global variables
Category categories[MAX_CATEGORIES];
int num_categories = 0;

// Function to categorize expense based on description
void categorize_expense(double amount, const char* description) {
    int i;
    for (i = 0; i < num_categories; i++) {
        if (strstr(description, categories[i].name) != NULL) {
            categories[i].total_expenses[categories[i].num_expenses++] += amount;
            return;
        }
    }

    // If no category is found, add a new one
    strcpy(categories[num_categories].name, description);
    categories[num_categories].total_expenses[0] = amount;
    categories[num_categories].num_expenses = 1;
    num_categories++;
}

// Function to display total expenses in each category
void display_expenses() {
    int i;
    for (i = 0; i < num_categories; i++) {
        printf("\nCategory: %s\nTotal Expenses: %.2f", categories[i].name, categories[i].total_expenses[0]);
        if (categories[i].num_expenses > 1) {
            int j;
            printf("\nExpenses:\n");
            for (j = 1; j < categories[i].num_expenses; j++) {
                printf("  %d. %.2f\n", j+1, categories[i].total_expenses[j]);
            }
        }
    }
}

int main() {
    char description[MAX_DESCRIPTION_LENGTH];
    double amount;

    while (1) {
        printf("\nEnter description of expense: ");
        scanf("%s", description);
        description[strcspn(description, "\n")] = '\0';

        if (strcmp(description, "quit") == 0) {
            break;
        }

        printf("Enter amount of expense: ");
        scanf("%lf", &amount);

        categorize_expense(amount, description);
    }

    display_expenses();

    return 0;
}