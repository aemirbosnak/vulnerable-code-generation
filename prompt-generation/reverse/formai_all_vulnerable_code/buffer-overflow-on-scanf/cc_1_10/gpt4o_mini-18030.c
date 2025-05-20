//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 100

typedef struct {
    char description[MAX_LENGTH];
    float amount;
    char category[MAX_LENGTH];
} Expense;

void addExpense(Expense expenses[], int *count) {
    if (*count >= MAX_ENTRIES) {
        printf("Expense limit reached. Cannot add more expenses.\n");
        return;
    }
    
    printf("Enter expense description: ");
    fflush(stdin);
    fgets(expenses[*count].description, MAX_LENGTH, stdin);
    expenses[*count].description[strcspn(expenses[*count].description, "\n")] = '\0'; // Remove newline

    printf("Enter expense amount: ");
    scanf("%f", &expenses[*count].amount);
    fflush(stdin); // Clear input buffer

    printf("Enter expense category: ");
    fgets(expenses[*count].category, MAX_LENGTH, stdin);
    expenses[*count].category[strcspn(expenses[*count].category, "\n")] = '\0'; // Remove newline

    printf("Expense added successfully!\n");
    (*count)++;
}

void displayExpenses(Expense expenses[], int count) {
    if (count == 0) {
        printf("No expenses to display.\n");
        return;
    }
    
    printf("Your expenses:\n");
    printf("------------------------------------\n");
    printf("%-30s %-10s %-20s\n", "Description", "Amount", "Category");
    printf("------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        printf("%-30s $%-9.2f %-20s\n", expenses[i].description, expenses[i].amount, expenses[i].category);
    }
    printf("------------------------------------\n");
}

void saveExpenses(Expense expenses[], int count) {
    FILE *file = fopen("expenses.csv", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    
    fprintf(file, "Description,Amount,Category\n");
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s,%.2f,%s\n", expenses[i].description, expenses[i].amount, expenses[i].category);
    }
    
    fclose(file);
    printf("Expenses saved to expenses.csv\n");
}

void loadExpenses(Expense expenses[], int *count) {
    FILE *file = fopen("expenses.csv", "r");
    if (file == NULL) {
        printf("Error opening file for reading. Creating a new one.\n");
        return;
    }
    
    char line[MAX_LENGTH * 3];
    fgets(line, sizeof(line), file); // Skip header
    
    while (fgets(line, sizeof(line), file) && *count < MAX_ENTRIES) {
        sscanf(line, "%[^,],%f,%[^,\n]", expenses[*count].description, &expenses[*count].amount, expenses[*count].category);
        (*count)++;
    }
    
    fclose(file);
    printf("Expenses loaded successfully!\n");
}

int main() {
    Expense expenses[MAX_ENTRIES];
    int count = 0;
    int choice;
    
    loadExpenses(expenses, &count);
    
    do {
        printf("\nExpense Tracker Menu:\n");
        printf("1. Add Expense\n");
        printf("2. Display Expenses\n");
        printf("3. Save Expenses\n");
        printf("4. Load Expenses\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        fflush(stdin); // Clear input buffer

        switch (choice) {
            case 1:
                addExpense(expenses, &count);
                break;
            case 2:
                displayExpenses(expenses, count);
                break;
            case 3:
                saveExpenses(expenses, count);
                break;
            case 4:
                loadExpenses(expenses, &count);
                break;
            case 5:
                printf("Exiting Expense Tracker. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}