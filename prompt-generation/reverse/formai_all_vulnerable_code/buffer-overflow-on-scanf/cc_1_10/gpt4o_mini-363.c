//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50
#define CATEGORY_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    char category[CATEGORY_LENGTH];
    float amount;
} Expense;

void add_expense(Expense expenses[], int *count);
void view_expenses(const Expense expenses[], int count);
void calculate_total(const Expense expenses[], int count);
void search_expenses(const Expense expenses[], int count);
void menu();

int main() {
    Expense expenses[MAX_ENTRIES];
    int count = 0;
    int choice;

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                add_expense(expenses, &count);
                break;
            case 2: 
                view_expenses(expenses, count);
                break;
            case 3: 
                calculate_total(expenses, count);
                break;
            case 4: 
                search_expenses(expenses, count);
                break;
            case 5:
                printf("Exiting the Personal Finance Planner. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a number between 1-5.\n");
        }
    }

    return 0;
}

void menu() {
    printf("\n--- Personal Finance Planner ---\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Calculate Total Expense\n");
    printf("4. Search Expenses by Category\n");
    printf("5. Exit\n");
}

void add_expense(Expense expenses[], int *count) {
    if (*count >= MAX_ENTRIES) {
        printf("Error: Maximum entries reached.\n");
        return;
    }

    printf("Enter expense name: ");
    getchar(); // To consume the newline character left by previous input
    fgets(expenses[*count].name, NAME_LENGTH, stdin);
    expenses[*count].name[strcspn(expenses[*count].name, "\n")] = 0; // Remove newline character

    printf("Enter expense category: ");
    fgets(expenses[*count].category, CATEGORY_LENGTH, stdin);
    expenses[*count].category[strcspn(expenses[*count].category, "\n")] = 0;

    printf("Enter expense amount: ");
    scanf("%f", &expenses[*count].amount);

    (*count)++;
    printf("Expense added successfully!\n");
}

void view_expenses(const Expense expenses[], int count) {
    if (count == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    printf("\n--- List of Expenses ---\n");
    for (int i = 0; i < count; i++) {
        printf("Expense %d: %s | Category: %s | Amount: %.2f\n", 
               i + 1, expenses[i].name, expenses[i].category, expenses[i].amount);
    }
}

void calculate_total(const Expense expenses[], int count) {
    float total = 0.0f;
    
    for (int i = 0; i < count; i++) {
        total += expenses[i].amount;
    }

    printf("Total Expense: %.2f\n", total);
}

void search_expenses(const Expense expenses[], int count) {
    if (count == 0) {
        printf("No expenses recorded. Cannot search.\n");
        return;
    }

    char searchCategory[CATEGORY_LENGTH];
    printf("Enter category to search for: ");
    getchar(); // To consume newline from previous inputs
    fgets(searchCategory, CATEGORY_LENGTH, stdin);
    searchCategory[strcspn(searchCategory, "\n")] = 0; // Remove newline character

    printf("\n--- Search Results for '%s' ---\n", searchCategory);
    int found = 0;

    for (int i = 0; i < count; i++) {
        if (strcmp(expenses[i].category, searchCategory) == 0) {
            printf("Expense %d: %s | Amount: %.2f\n", 
                   i + 1, expenses[i].name, expenses[i].amount);
            found = 1;
        }
    }

    if (!found) {
        printf("No expenses found for category '%s'.\n", searchCategory);
    }
}