//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define DESCRIPTION_LENGTH 100
#define CATEGORY_LENGTH 50

typedef struct {
    char description[DESCRIPTION_LENGTH];
    char category[CATEGORY_LENGTH];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int expense_count = 0;

void addExpense(const char* description, const char* category, float amount);
void displayExpenses();
void saveToFile();
void loadFromFile();

int main() {
    int choice;
    loadFromFile();

    while (1) {
        printf("\n----- Expense Tracker -----\n");
        printf("1. Add Expense\n");
        printf("2. Display Expenses\n");
        printf("3. Save and Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        getchar(); // Clear newline character from input buffer

        switch (choice) {
            case 1: {
                char description[DESCRIPTION_LENGTH];
                char category[CATEGORY_LENGTH];
                float amount;

                printf("Enter Expense Description: ");
                fgets(description, DESCRIPTION_LENGTH, stdin);
                description[strcspn(description, "\n")] = 0; // Remove newline
                printf("Enter Expense Category: ");
                fgets(category, CATEGORY_LENGTH, stdin);
                category[strcspn(category, "\n")] = 0; // Remove newline
                printf("Enter Expense Amount: ");
                scanf("%f", &amount);

                addExpense(description, category, amount);
                break;
            }
            case 2:
                displayExpenses();
                break;
            case 3:
                saveToFile();
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}

void addExpense(const char* description, const char* category, float amount) {
    if (expense_count < MAX_EXPENSES) {
        strncpy(expenses[expense_count].description, description, DESCRIPTION_LENGTH);
        strncpy(expenses[expense_count].category, category, CATEGORY_LENGTH);
        expenses[expense_count].amount = amount;
        expense_count++;
        printf("Expense added successfully!\n");
    } else {
        printf("Expense limit reached. Cannot add more expenses.\n");
    }
}

void displayExpenses() {
    if (expense_count == 0) {
        printf("No expenses recorded yet.\n");
        return;
    }
    printf("\n----- Expense List -----\n");
    for (int i = 0; i < expense_count; i++) {
        printf("Expense %d: Description: %s | Category: %s | Amount: %.2f\n", 
               i + 1, expenses[i].description, expenses[i].category, expenses[i].amount);
    }
}

void saveToFile() {
    FILE *file = fopen("expenses.txt", "w");
    if (!file) {
        printf("Error saving file!\n");
        return;
    }
    for (int i = 0; i < expense_count; i++) {
        fprintf(file, "%s,%s,%.2f\n", expenses[i].description, expenses[i].category, expenses[i].amount);
    }
    fclose(file);
    printf("Expenses saved successfully!\n");
}

void loadFromFile() {
    FILE *file = fopen("expenses.txt", "r");
    if (!file) {
        printf("No expenses file found. Starting fresh.\n");
        return;
    }
    while (fscanf(file, "%99[^,],%49[^,],%f\n", 
                  expenses[expense_count].description, 
                  expenses[expense_count].category, 
                  &expenses[expense_count].amount) != EOF) {
        expense_count++;
    }
    fclose(file);
    printf("Expenses loaded successfully!\n");
}