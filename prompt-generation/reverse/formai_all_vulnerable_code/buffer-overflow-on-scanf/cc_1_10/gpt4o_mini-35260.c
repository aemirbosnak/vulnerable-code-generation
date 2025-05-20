//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define DESCRIPTION_LEN 50

typedef struct {
    char description[DESCRIPTION_LEN];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int expenseCount = 0;

void addExpense();
void displayExpenses();
void calculateTotal();
void saveToFile();
void loadFromFile();

int main() {
    int choice;

    // Load previous expenses from file
    loadFromFile();

    while (1) {
        printf("\n--- Expense Tracker ---\n");
        printf("1. Add Expense\n");
        printf("2. Display Expenses\n");
        printf("3. Calculate Total Expenses\n");
        printf("4. Save Expenses to File\n");
        printf("5. Load Expenses from File\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                displayExpenses();
                break;
            case 3:
                calculateTotal();
                break;
            case 4:
                saveToFile();
                break;
            case 5:
                loadFromFile();
                break;
            case 6:
                printf("Thank you for using the Expense Tracker! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}

void addExpense() {
    if (expenseCount >= MAX_EXPENSES) {
        printf("Expense limit reached. Cannot add more expenses.\n");
        return;
    }

    printf("Enter description of expense: ");
    scanf(" %[^\n]", expenses[expenseCount].description);
    printf("Enter amount of expense: ");
    scanf("%f", &expenses[expenseCount].amount);

    expenseCount++;
    printf("Expense added successfully!\n");
}

void displayExpenses() {
    if (expenseCount == 0) {
        printf("No expenses recorded yet.\n");
        return;
    }

    printf("\n--- Recorded Expenses ---\n");
    for (int i = 0; i < expenseCount; i++) {
        printf("%d. %s: $%.2f\n", i + 1, expenses[i].description, expenses[i].amount);
    }
}

void calculateTotal() {
    float total = 0;
    for (int i = 0; i < expenseCount; i++) {
        total += expenses[i].amount;
    }
    printf("Total expenses: $%.2f\n", total);
}

void saveToFile() {
    FILE *file = fopen("expenses.txt", "w");
    if (file == NULL) {
        printf("Failed to open file for writing.\n");
        return;
    }

    for (int i = 0; i < expenseCount; i++) {
        fprintf(file, "%s,%f\n", expenses[i].description, expenses[i].amount);
    }

    fclose(file);
    printf("Expenses saved to expenses.txt successfully!\n");
}

void loadFromFile() {
    FILE *file = fopen("expenses.txt", "r");
    if (file == NULL) {
        printf("No previous expenses found.\n");
        return;
    }

    while (fscanf(file, "%49[^,],%f\n", expenses[expenseCount].description, &expenses[expenseCount].amount) == 2) {
        expenseCount++;
        if (expenseCount >= MAX_EXPENSES) break; // Prevent overflow
    }

    fclose(file);
    printf("Loaded %d previous expenses successfully!\n", expenseCount);
}