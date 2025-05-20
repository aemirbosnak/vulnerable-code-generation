//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define MAX_TRANSACTIONS 100

typedef struct {
    char category[MAX_LENGTH];
    float amount;
    char description[MAX_LENGTH];
} Transaction;

void addTransaction(Transaction transactions[], int *count) {
    if (*count >= MAX_TRANSACTIONS) {
        printf("Transaction limit reached!\n");
        return;
    }
    
    printf("Enter category: ");
    scanf("%s", transactions[*count].category);
    printf("Enter amount: ");
    scanf("%f", &transactions[*count].amount);
    printf("Enter description: ");
    scanf(" %[^\n]", transactions[*count].description);

    (*count)++;
    printf("Transaction added successfully!\n");
}

void viewTransactions(Transaction transactions[], int count) {
    if (count == 0) {
        printf("No transactions to display.\n");
        return;
    }

    printf("\nYour Transactions:\n");
    for (int i = 0; i < count; i++) {
        printf("Category: %s, Amount: %.2f, Description: %s\n",
               transactions[i].category,
               transactions[i].amount,
               transactions[i].description);
    }
}

void saveTransactionsToFile(Transaction transactions[], int count) {
    FILE *file = fopen("transactions.txt", "w");
    if (file == NULL) {
        printf("Error saving transactions.\n");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %.2f %s\n", transactions[i].category, transactions[i].amount, transactions[i].description);
    }
    fclose(file);
    printf("Transactions saved to transactions.txt\n");
}

void loadTransactionsFromFile(Transaction transactions[], int *count) {
    FILE *file = fopen("transactions.txt", "r");
    if (file == NULL) {
        printf("No transaction file found. Starting fresh.\n");
        return;
    }

    while (fscanf(file, "%s %f %[^\n]", transactions[*count].category, &transactions[*count].amount, transactions[*count].description) != EOF) {
        (*count)++;
    }
    
    fclose(file);
    printf("Transactions loaded successfully!\n");
}

void showSummary(Transaction transactions[], int count) {
    float totalExpenses = 0;
    for (int i = 0; i < count; i++) {
        totalExpenses += transactions[i].amount;
    }
    printf("Total Expenses: %.2f\n", totalExpenses);
}

int main() {
    Transaction transactions[MAX_TRANSACTIONS];
    int transactionCount = 0;
    int choice;

    loadTransactionsFromFile(transactions, &transactionCount);

    while (1) {
        printf("\nPersonal Finance Planner\n");
        printf("1. Add Transaction\n");
        printf("2. View Transactions\n");
        printf("3. Save Transactions\n");
        printf("4. Show Summary\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTransaction(transactions, &transactionCount);
                break;
            case 2:
                viewTransactions(transactions, transactionCount);
                break;
            case 3:
                saveTransactionsToFile(transactions, transactionCount);
                break;
            case 4:
                showSummary(transactions, transactionCount);
                break;
            case 5:
                saveTransactionsToFile(transactions, transactionCount);
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}