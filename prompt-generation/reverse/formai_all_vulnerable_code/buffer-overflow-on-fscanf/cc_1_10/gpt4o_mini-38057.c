//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 100
#define DESCRIPTION_LENGTH 100

typedef struct {
    float amount;
    char description[DESCRIPTION_LENGTH];
} Transaction;

void addTransaction(Transaction transactions[], int *count);
void viewTransactions(Transaction transactions[], int count);
void calculateTotalExpenses(Transaction transactions[], int count);
void saveTransactions(Transaction transactions[], int count);
void loadTransactions(Transaction transactions[], int *count);

int main() {
    Transaction transactions[MAX_TRANSACTIONS];
    int count = 0;
    int choice;

    loadTransactions(transactions, &count);

    do {
        printf("\n----- Expense Tracker -----\n");
        printf("1. Add Transaction\n");
        printf("2. View Transactions\n");
        printf("3. Calculate Total Expenses\n");
        printf("4. Save Transactions\n");
        printf("5. Load Transactions\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTransaction(transactions, &count);
                break;
            case 2:
                viewTransactions(transactions, count);
                break;
            case 3:
                calculateTotalExpenses(transactions, count);
                break;
            case 4:
                saveTransactions(transactions, count);
                break;
            case 5:
                loadTransactions(transactions, &count);
                break;
            case 6:
                printf("Exiting the Expense Tracker. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void addTransaction(Transaction transactions[], int *count) {
    if (*count >= MAX_TRANSACTIONS) {
        printf("Transaction limit reached. Cannot add more transactions.\n");
        return;
    }

    Transaction t;
    printf("Enter the amount: ");
    scanf("%f", &t.amount);
    printf("Enter a description: ");
    getchar(); // Consume the newline character left by scanf
    fgets(t.description, DESCRIPTION_LENGTH, stdin);
    t.description[strcspn(t.description, "\n")] = '\0'; // Remove newline character

    transactions[*count] = t;
    (*count)++;
    printf("Transaction added successfully!\n");
}

void viewTransactions(Transaction transactions[], int count) {
    if (count == 0) {
        printf("No transactions available.\n");
        return;
    }
    
    printf("\n----- Your Transactions -----\n");
    for (int i = 0; i < count; i++) {
        printf("Transaction %d: Amount: %.2f, Description: %s\n", i + 1, transactions[i].amount, transactions[i].description);
    }
}

void calculateTotalExpenses(Transaction transactions[], int count) {
    float total = 0.0;
    for (int i = 0; i < count; i++) {
        total += transactions[i].amount;
    }
    printf("Total Expenses: %.2f\n", total);
}

void saveTransactions(Transaction transactions[], int count) {
    FILE *file = fopen("transactions.txt", "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%.2f\n%s\n", transactions[i].amount, transactions[i].description);
    }
    fclose(file);
    printf("Transactions saved successfully!\n");
}

void loadTransactions(Transaction transactions[], int *count) {
    FILE *file = fopen("transactions.txt", "r");
    if (!file) {
        printf("No saved transactions found.\n");
        return;
    }

    while (*count < MAX_TRANSACTIONS && fscanf(file, "%f\n%[^\n]\n", &transactions[*count].amount, transactions[*count].description) == 2) {
        (*count)++;
    }

    fclose(file);
    printf("Transactions loaded successfully! Total transactions: %d\n", *count);
}