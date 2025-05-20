//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_DESC_LEN 50

typedef struct {
    char description[MAX_DESC_LEN];
    float amount;
    char category[MAX_DESC_LEN];
} Expense;

void addExpense(Expense expenses[], int *count);
void viewExpenses(const Expense expenses[], int count);
void saveExpenses(const Expense expenses[], int count);
void loadExpenses(Expense expenses[], int *count);

int main() {
    Expense expenses[MAX_EXPENSES];
    int count = 0;
    int choice;

    loadExpenses(expenses, &count);

    do {
        printf("\n--- Enchanted Expense Tracker ---\n");
        printf("1. Add an Expense\n");
        printf("2. View Expenses\n");
        printf("3. Exit\n");
        printf("Choose your quest (1-3): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addExpense(expenses, &count);
                break;
            case 2:
                viewExpenses(expenses, count);
                break;
            case 3:
                printf("Farewell, noble traveler!\n");
                saveExpenses(expenses, count);
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    } while (choice != 3);
    return 0;
}

void addExpense(Expense expenses[], int *count) {
    if (*count >= MAX_EXPENSES) {
        printf("Oh no! You have reached the maximum number of expenses.\n");
        return;
    }

    Expense newExpense;
    printf("Enter the expense description: ");
    scanf(" %[^\n]s", newExpense.description);
    printf("Enter the amount spent: ");
    scanf("%f", &newExpense.amount);
    printf("Enter the category (e.g., Food, Entertainment): ");
    scanf(" %[^\n]s", newExpense.category);

    expenses[*count] = newExpense;
    (*count)++;
    printf("Huzzah! Your expense has been recorded!\n");
}

void viewExpenses(const Expense expenses[], int count) {
    if (count == 0) {
        printf("No expenses found in the enchanted scrolls.\n");
        return;
    }

    printf("\n--- Your Recorded Expenses ---\n");
    for (int i = 0; i < count; i++) {
        printf("Description: %s, Amount: %.2f, Category: %s\n",
               expenses[i].description,
               expenses[i].amount,
               expenses[i].category);
    }
}

void saveExpenses(const Expense expenses[], int count) {
    FILE *file = fopen("expenses.txt", "w");
    if (file == NULL) {
        printf("Alas! The scrolls could not be saved.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s,%.2f,%s\n", 
                expenses[i].description, 
                expenses[i].amount, 
                expenses[i].category);
    }

    fclose(file);
    printf("Your scrolls have been safely inscribed!\n");
}

void loadExpenses(Expense expenses[], int *count) {
    FILE *file = fopen("expenses.txt", "r");
    if (file == NULL) {
        printf("No prior scrolls found, starting a new adventure!\n");
        return;
    }

    while (fscanf(file, " %[^\n],%f,%[^\n]\n", expenses[*count].description, &expenses[*count].amount, expenses[*count].category) != EOF) {
        (*count)++;
    }

    fclose(file);
    printf("Your past adventures have been unearthed!\n");
}