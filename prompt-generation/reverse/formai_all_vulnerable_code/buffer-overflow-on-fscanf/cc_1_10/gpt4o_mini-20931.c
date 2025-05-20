//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define CATEGORY_LENGTH 30
#define DESCRIPTION_LENGTH 50

typedef struct {
    char category[CATEGORY_LENGTH];
    char description[DESCRIPTION_LENGTH];
    float amount;
} Expense;

void add_expense(Expense expenses[], int *count) {
    if (*count >= MAX_EXPENSES) {
        printf("Expense limit reached! Can't add more expenses.\n");
        return;
    }

    Expense new_expense;
    printf("Enter category (e.g. Food, Transport): ");
    scanf("%s", new_expense.category);
    
    printf("Enter description: ");
    getchar(); // Consume the newline character left by previous input
    fgets(new_expense.description, DESCRIPTION_LENGTH, stdin);
    new_expense.description[strcspn(new_expense.description, "\n")] = '\0'; // Remove newline

    printf("Enter amount: ");
    scanf("%f", &new_expense.amount);

    expenses[*count] = new_expense;
    (*count)++;
    printf("Expense added!\n");
}

void show_expenses(Expense expenses[], int count) {
    if (count == 0) {
        printf("No expenses recorded.\n");
        return;
    }
    
    printf("\nExpense List:\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("Category: %s | Description: %s | Amount: %.2f\n", 
               expenses[i].category, expenses[i].description, expenses[i].amount);
    }
    printf("------------------------------------------------\n");
}

void save_expenses(Expense expenses[], int count) {
    FILE *file = fopen("expenses.txt", "w");
    if (!file) {
        printf("Could not open file for writing.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s,%s,%.2f\n", expenses[i].category, expenses[i].description, expenses[i].amount);
    }
    
    fclose(file);
    printf("Expenses saved to expenses.txt\n");
}

void load_expenses(Expense expenses[], int *count) {
    FILE *file = fopen("expenses.txt", "r");
    if (!file) {
        printf("No previous expenses found. Starting fresh.\n");
        return;
    }

    while (fscanf(file, "%[^,],%[^,],%f\n", 
                  expenses[*count].category, 
                  expenses[*count].description, 
                  &expenses[*count].amount) != EOF) {
        (*count)++;
        if (*count >= MAX_EXPENSES) break; // Prevent overflowing the array
    }

    fclose(file);
    printf("Expenses loaded successfully!\n");
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int count = 0;
    int choice;

    load_expenses(expenses, &count);

    do {
        printf("\nExpense Tracker Menu:\n");
        printf("1. Add Expense\n");
        printf("2. Show Expenses\n");
        printf("3. Save Expenses\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_expense(expenses, &count);
                break;
            case 2:
                show_expenses(expenses, count);
                break;
            case 3:
                save_expenses(expenses, count);
                break;
            case 4:
                printf("Exiting the Expense Tracker. Bye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}