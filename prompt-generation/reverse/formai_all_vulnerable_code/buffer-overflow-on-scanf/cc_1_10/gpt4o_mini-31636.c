//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define CATEGORY_LENGTH 30
#define DESC_LENGTH 100

typedef struct {
    char description[DESC_LENGTH];
    float amount;
    char category[CATEGORY_LENGTH];
} Expense;

void printWelcomeMessage() {
    printf("🎉 Welcome to the Incredible Expense Tracker! 🎉\n");
    printf("✨ Keep an eye on your spending, it might surprise you! ✨\n\n");
}

void addExpense(Expense expenses[], int *expense_count) {
    if (*expense_count >= MAX_EXPENSES) {
        printf("😱 Oops! Maximum expense limit reached! Can't add more expenses!\n");
        return;
    }
    
    Expense new_expense;
    
    printf("What did you spend money on? (Description): ");
    getchar(); // to consume leftover newline
    fgets(new_expense.description, DESC_LENGTH, stdin);
    new_expense.description[strcspn(new_expense.description, "\n")] = 0; // Remove newline

    printf("How much did you spend? (Amount): $");
    scanf("%f", &new_expense.amount);

    printf("What category does this expense belong to? (e.g., Food, Transport, etc.): ");
    getchar(); // consume leftover newline
    fgets(new_expense.category, CATEGORY_LENGTH, stdin);
    new_expense.category[strcspn(new_expense.category, "\n")] = 0; // Remove newline

    expenses[*expense_count] = new_expense;
    (*expense_count)++;
    printf("✅ Expense added successfully! You spent $%.2f on %s in the category of %s!\n\n", 
            new_expense.amount, new_expense.description, new_expense.category);
}

void viewExpenses(const Expense expenses[], int expense_count) {
    if (expense_count == 0) {
        printf("🤔 No expenses to show! Let's spend a little and track it!\n\n");
        return;
    }

    printf("📝 Here are your recorded expenses:\n");
    for (int i = 0; i < expense_count; i++) {
        printf("%d. %s | $%.2f | Category: %s\n", 
                i + 1, expenses[i].description, expenses[i].amount, expenses[i].category);
    }
    printf("\n");
}

void calculateTotal(const Expense expenses[], int expense_count) {
    if (expense_count == 0) {
        printf("🤷 No expenses tracked yet! Can't calculate total.\n\n");
        return;
    }

    float total = 0.0;
    for (int i = 0; i < expense_count; i++) {
        total += expenses[i].amount;
    }
    printf("💰 Your total expenses so far: $%.2f\n\n", total);
}

void menu() {
    printf("📋 What would you like to do?\n");
    printf("1. Add an Expense\n");
    printf("2. View Expenses\n");
    printf("3. Calculate Total Expenses\n");
    printf("4. Exit\n");
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int expense_count = 0; 
    int choice = 0; 

    printWelcomeMessage();

    while (1) {
        menu();
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addExpense(expenses, &expense_count);
                break;
            case 2:
                viewExpenses(expenses, expense_count);
                break;
            case 3:
                calculateTotal(expenses, expense_count);
                break;
            case 4:
                printf("🚪 Exiting the program. Goodbye! 💖\n");
                exit(0);
            default:
                printf("⚠️ Invalid choice! Please enter a number between 1 and 4.\n\n");
        }
    }

    return 0;
}