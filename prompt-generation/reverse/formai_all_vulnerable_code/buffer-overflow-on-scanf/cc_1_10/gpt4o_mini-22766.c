//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TRANSACTIONS 100
#define MAX_CATEGORIES 10
#define NAME_LENGTH 50

typedef struct {
    time_t date;
    char category[NAME_LENGTH];
    float amount;
    char description[NAME_LENGTH];
} Transaction;

typedef struct {
    char categoryName[NAME_LENGTH];
    float budgetLimit;
    float spent;
} Category;

Transaction transactions[MAX_TRANSACTIONS];
Category categories[MAX_CATEGORIES];
int transactionCount = 0;
int categoryCount = 0;

void addTransaction() {
    if (transactionCount >= MAX_TRANSACTIONS) {
        printf("Transaction limit reached. Cannot add more transactions.\n");
        return;
    }
    Transaction newTransaction;
    newTransaction.date = time(NULL);

    printf("Enter transaction category: ");
    scanf(" %[^\n]s", newTransaction.category);
    
    printf("Enter transaction amount: ");
    scanf("%f", &newTransaction.amount);
    
    printf("Enter transaction description: ");
    scanf(" %[^\n]s", newTransaction.description);
    
    transactions[transactionCount++] = newTransaction;
    printf("Transaction added successfully!\n");
}

void viewTransactions() {
    if (transactionCount == 0) {
        printf("No transactions recorded.\n");
        return;
    }
    
    printf("Transactions:\n");
    for (int i = 0; i < transactionCount; i++) {
        char date[26];
        ctime_r(&transactions[i].date, date);
        printf("Date: %sCategory: %s, Amount: %.2f, Description: %s\n",
            date, transactions[i].category, transactions[i].amount, transactions[i].description);
    }
}

void addCategory() {
    if (categoryCount >= MAX_CATEGORIES) {
        printf("Category limit reached. Cannot add more categories.\n");
        return;
    }
    Category newCategory;
    
    printf("Enter category name: ");
    scanf(" %[^\n]s", newCategory.categoryName);

    printf("Enter budget limit for %s: ", newCategory.categoryName);
    scanf("%f", &newCategory.budgetLimit);
    newCategory.spent = 0.0;

    categories[categoryCount++] = newCategory;
    printf("Category added successfully!\n");
}

void viewCategories() {
    if (categoryCount == 0) {
        printf("No categories recorded.\n");
        return;
    }
    
    printf("Categories:\n");
    for (int i = 0; i < categoryCount; i++) {
        printf("Category: %s, Budget Limit: %.2f, Spent: %.2f\n",
            categories[i].categoryName, categories[i].budgetLimit, categories[i].spent);
    }
}

void recordTransactionToCategory() {
    char categoryName[NAME_LENGTH];
    printf("Enter the category name to record transaction: ");
    scanf(" %[^\n]s", categoryName);

    for (int i = 0; i < categoryCount; i++) {
        if (strcmp(categories[i].categoryName, categoryName) == 0) {
            float transactionAmount;
            printf("Enter the amount spent on %s: ", categoryName);
            scanf("%f", &transactionAmount);
            categories[i].spent += transactionAmount;
            printf("Recorded %.2f against category \"%s\".\n", transactionAmount, categoryName);
            return;
        }
    }
    printf("Category not found.\n");
}

void budgetAssessment() {
    printf("Budget Assessment:\n");
    for (int i = 0; i < categoryCount; i++) {
        float remaining = categories[i].budgetLimit - categories[i].spent;
        if (remaining < 0) {
            printf("Category: %s, OVER BUDGET by %.2f\n", categories[i].categoryName, -remaining);
        } else {
            printf("Category: %s, Remaining Budget: %.2f\n", categories[i].categoryName, remaining);
        }
    }
}

int main() {
    int choice;
    do {
        printf("\n--- Personal Finance Planner ---\n");
        printf("1. Add Transaction\n");
        printf("2. View Transactions\n");
        printf("3. Add Category\n");
        printf("4. View Categories\n");
        printf("5. Record Transaction to Category\n");
        printf("6. Budget Assessment\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTransaction();
                break;
            case 2:
                viewTransactions();
                break;
            case 3:
                addCategory();
                break;
            case 4:
                viewCategories();
                break;
            case 5:
                recordTransactionToCategory();
                break;
            case 6:
                budgetAssessment();
                break;
            case 0:
                printf("Exiting the planner. Live long and prosper!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}