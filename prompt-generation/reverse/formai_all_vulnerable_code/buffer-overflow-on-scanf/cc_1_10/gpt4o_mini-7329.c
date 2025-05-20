//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: scalable
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

Expense expenses[MAX_EXPENSES];
int expense_count = 0;

void addExpense();
void viewExpenses();
void totalExpenses();
void saveToFile();
void loadFromFile();

int main() {
    loadFromFile();
    int choice;
    do {
        printf("\nExpense Tracker Menu:\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Total Expenses\n");
        printf("4. Save Expenses\n");
        printf("5. Load Expenses\n");
        printf("6. Exit\n");
        printf("Choose an option (1-6): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addExpense(); break;
            case 2: viewExpenses(); break;
            case 3: totalExpenses(); break;
            case 4: saveToFile(); break;
            case 5: loadFromFile(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid option, please try again.\n");
        }
    } while (choice != 6);
    return 0;
}

void addExpense() {
    if (expense_count >= MAX_EXPENSES) {
        printf("Can't add more expenses. Limit reached.\n");
        return;
    }
    
    Expense new_expense;
    printf("Enter category: ");
    scanf("%s", new_expense.category);
    printf("Enter description: ");
    scanf(" %[^\n]%*c", new_expense.description);
    printf("Enter amount: ");
    scanf("%f", &new_expense.amount);
    
    expenses[expense_count] = new_expense;
    expense_count++;
    printf("Expense added successfully!\n");
}

void viewExpenses() {
    if (expense_count == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    printf("\nRecorded Expenses:\n");
    for (int i = 0; i < expense_count; i++) {
        printf("%d. Category: %s, Description: %s, Amount: $%.2f\n", 
               i + 1, expenses[i].category, expenses[i].description, expenses[i].amount);
    }
}

void totalExpenses() {
    float total = 0;
    for (int i = 0; i < expense_count; i++) {
        total += expenses[i].amount;
    }
    printf("Total Expenses: $%.2f\n", total);
}

void saveToFile() {
    FILE *file = fopen("expenses.dat", "wb");
    if (!file) {
        printf("Error saving to file.\n");
        return;
    }
    fwrite(expenses, sizeof(Expense), expense_count, file);
    fclose(file);
    printf("Expenses saved to file successfully!\n");
}

void loadFromFile() {
    FILE *file = fopen("expenses.dat", "rb");
    if (!file) {
        printf("No previous expenses found, starting fresh.\n");
        return;
    }
    expense_count = fread(expenses, sizeof(Expense), MAX_EXPENSES, file);
    fclose(file);
    printf("Expenses loaded from file successfully!\n");
}