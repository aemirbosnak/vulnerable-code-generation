//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define MAX_TRANSACTIONS 100
#define MAX_CATEGORIES 10

typedef struct {
    char description[50];
    float amount;
    char category[20];
} Transaction;

typedef struct {
    char name[20];
    float budget;
    float expenditure;
} Category;

Transaction transactions[MAX_TRANSACTIONS];
int transactionCount = 0;

Category categories[MAX_CATEGORIES];
int categoryCount = 0;

void addCategory() {
    if (categoryCount < MAX_CATEGORIES) {
        printf("Enter category name: ");
        scanf("%s", categories[categoryCount].name);
        categories[categoryCount].budget = 0.0;
        categories[categoryCount].expenditure = 0.0;
        categoryCount++;
        printf("Category added successfully!\n");
    } else {
        printf("Category limit reached.\n");
    }
}

void setBudget() {
    char categoryName[20];
    float budget;
    printf("Enter category name to set budget: ");
    scanf("%s", categoryName);
    for (int i = 0; i < categoryCount; i++) {
        if (strcmp(categories[i].name, categoryName) == 0) {
            printf("Enter budget for %s: ", categoryName);
            scanf("%f", &budget);
            categories[i].budget = budget;
            printf("Budget set successfully!\n");
            return;
        }
    }
    printf("Category not found.\n");
}

void addTransaction() {
    if (transactionCount < MAX_TRANSACTIONS) {
        printf("Enter transaction description: ");
        scanf("%s", transactions[transactionCount].description);
        printf("Enter transaction amount: ");
        scanf("%f", &transactions[transactionCount].amount);
        printf("Enter transaction category: ");
        scanf("%s", transactions[transactionCount].category);

        for (int i = 0; i < categoryCount; i++) {
            if (strcmp(categories[i].name, transactions[transactionCount].category) == 0) {
                categories[i].expenditure += transactions[transactionCount].amount;
            }
        }

        transactionCount++;
        printf("Transaction added successfully!\n");
    } else {
        printf("Transaction limit reached.\n");
    }
}

void displayReport() {
    printf("\nPersonal Finance Report:\n");
    printf("-------------------------\n");
    for (int i = 0; i < categoryCount; i++) {
        printf("Category: %s\n", categories[i].name);
        printf("Budget: %.2f\n", categories[i].budget);
        printf("Expenditure: %.2f\n\n", categories[i].expenditure);
    }
}

void viewTransactions() {
    printf("\nTransaction List:\n");
    printf("---------------------\n");
    for (int i = 0; i < transactionCount; i++) {
        printf("Description: %s, Amount: %.2f, Category: %s\n",
                transactions[i].description,
                transactions[i].amount,
                transactions[i].category);
    }
}

void menu() {
    int choice;
    do {
        printf("\nPersonal Finance Planner Menu\n");
        printf("1. Add Category\n");
        printf("2. Set Budget\n");
        printf("3. Add Transaction\n");
        printf("4. Display Report\n");
        printf("5. View Transactions\n");
        printf("6. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCategory();
                break;
            case 2:
                setBudget();
                break;
            case 3:
                addTransaction();
                break;
            case 4:
                displayReport();
                break;
            case 5:
                viewTransactions();
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
}

int main() {
    printf("Welcome to the Personal Finance Planner!\n");
    menu();
    return 0;
}