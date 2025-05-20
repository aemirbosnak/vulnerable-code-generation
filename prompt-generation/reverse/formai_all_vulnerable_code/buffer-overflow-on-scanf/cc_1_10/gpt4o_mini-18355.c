//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_TRANSACTIONS 100
#define MAX_CATEGORIES 10

struct Transaction {
    char description[100];
    float amount;
    char category[50];
};

struct BudgetCategory {
    char name[50];
    float budgetedAmount;
    float spentAmount;
};

struct FinancePlanner {
    struct Transaction transactions[MAX_TRANSACTIONS];
    int transactionCount;
    struct BudgetCategory categories[MAX_CATEGORIES];
    int categoryCount;
};

// Function declarations
void addTransaction(struct FinancePlanner *planner);
void viewTransactions(struct FinancePlanner *planner);
void addBudgetCategory(struct FinancePlanner *planner);
void viewBudget(struct FinancePlanner *planner);
void viewSummary(struct FinancePlanner *planner);
void initializePlanner(struct FinancePlanner *planner);

int main() {
    struct FinancePlanner planner;
    initializePlanner(&planner);

    int choice;
    do {
        printf("\nPersonal Finance Planner Menu:\n");
        printf("1. Add Transaction\n");
        printf("2. View Transactions\n");
        printf("3. Add Budget Category\n");
        printf("4. View Budget\n");
        printf("5. View Summary\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTransaction(&planner);
                break;
            case 2:
                viewTransactions(&planner);
                break;
            case 3:
                addBudgetCategory(&planner);
                break;
            case 4:
                viewBudget(&planner);
                break;
            case 5:
                viewSummary(&planner);
                break;
            case 6:
                printf("Exiting the program. Have a good day!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void initializePlanner(struct FinancePlanner *planner) {
    planner->transactionCount = 0;
    planner->categoryCount = 0;
}

void addTransaction(struct FinancePlanner *planner) {
    if (planner->transactionCount >= MAX_TRANSACTIONS) {
        printf("Transaction limit reached. Can't add more transactions.\n");
        return;
    }

    struct Transaction newTransaction;
    printf("Enter transaction description: ");
    getchar(); // clear buffer
    fgets(newTransaction.description, sizeof(newTransaction.description), stdin);
    printf("Enter transaction amount: ");
    scanf("%f", &newTransaction.amount);
    printf("Enter transaction category: ");
    getchar(); // clear buffer
    fgets(newTransaction.category, sizeof(newTransaction.category), stdin);
    
    // Remove newline character from string
    newTransaction.description[strcspn(newTransaction.description, "\n")] = 0;
    newTransaction.category[strcspn(newTransaction.category, "\n")] = 0;

    planner->transactions[planner->transactionCount++] = newTransaction;
    printf("Transaction added successfully.\n");
}

void viewTransactions(struct FinancePlanner *planner) {
    if (planner->transactionCount == 0) {
        printf("No transactions found.\n");
        return;
    }

    printf("\nTransactions:\n");
    for (int i = 0; i < planner->transactionCount; i++) {
        printf("%d. %s - $%.2f (%s)\n", i + 1, planner->transactions[i].description,
               planner->transactions[i].amount, planner->transactions[i].category);
    }
}

void addBudgetCategory(struct FinancePlanner *planner) {
    if (planner->categoryCount >= MAX_CATEGORIES) {
        printf("Category limit reached. Can't add more budget categories.\n");
        return;
    }

    struct BudgetCategory newCategory;
    printf("Enter budget category name: ");
    getchar(); // clear buffer
    fgets(newCategory.name, sizeof(newCategory.name), stdin);
    newCategory.name[strcspn(newCategory.name, "\n")] = 0;  // remove newline
    printf("Enter budgeted amount for this category: ");
    scanf("%f", &newCategory.budgetedAmount);
    
    newCategory.spentAmount = 0.0; // Initialize spent amount to zero
    planner->categories[planner->categoryCount++] = newCategory;
    printf("Budget category added successfully.\n");
}

void viewBudget(struct FinancePlanner *planner) {
    if (planner->categoryCount == 0) {
        printf("No budget categories found.\n");
        return;
    }

    printf("\nBudget Categories:\n");
    for (int i = 0; i < planner->categoryCount; i++) {
        printf("%d. %s - Budgeted: $%.2f, Spent: $%.2f\n",
               i + 1, planner->categories[i].name,
               planner->categories[i].budgetedAmount,
               planner->categories[i].spentAmount);
    }
}

void viewSummary(struct FinancePlanner *planner) {
    float totalSpent = 0.0;
    for (int i = 0; i < planner->transactionCount; i++) {
        totalSpent += planner->transactions[i].amount;
    }

    printf("\nFinance Summary:\n");
    printf("Total Transactions: %d\n", planner->transactionCount);
    printf("Total Spent: $%.2f\n", totalSpent);
  
    for (int i = 0; i < planner->categoryCount; i++) {
        planner->categories[i].spentAmount = 0.0; // reset spent amount for calculations
        for (int j = 0; j < planner->transactionCount; j++) {
            if (strcmp(planner->transactions[j].category, planner->categories[i].name) == 0) {
                planner->categories[i].spentAmount += planner->transactions[j].amount;
            }
        }
        printf("%s -> Budgeted: $%.2f, Spent: $%.2f\n",
               planner->categories[i].name,
               planner->categories[i].budgetedAmount,
               planner->categories[i].spentAmount);
    }
}