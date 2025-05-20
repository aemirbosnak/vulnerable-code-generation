//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
    char category[MAX_NAME_LENGTH];
} Transaction;

typedef struct {
    Transaction transactions[MAX_TRANSACTIONS];
    int transaction_count;
} FinancePlanner;

// Function declarations
void addTransaction(FinancePlanner *fp);
void displayTransactions(const FinancePlanner *fp);
void displaySummary(const FinancePlanner *fp);
void saveToFile(const FinancePlanner *fp);
void loadFromFile(FinancePlanner *fp);
void clearTransactions(FinancePlanner *fp);

int main() {
    FinancePlanner myFinance;
    myFinance.transaction_count = 0;

    loadFromFile(&myFinance);

    int choice;
    do {
        printf("\nPersonal Finance Planner Menu:\n");
        printf("1. Add Transaction\n");
        printf("2. Display Transactions\n");
        printf("3. Display Summary\n");
        printf("4. Save to File\n");
        printf("5. Clear All Transactions\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTransaction(&myFinance);
                break;
            case 2:
                displayTransactions(&myFinance);
                break;
            case 3:
                displaySummary(&myFinance);
                break;
            case 4:
                saveToFile(&myFinance);
                break;
            case 5:
                clearTransactions(&myFinance);
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    saveToFile(&myFinance);
    return 0;
}

void addTransaction(FinancePlanner *fp) {
    if (fp->transaction_count >= MAX_TRANSACTIONS) {
        printf("Transaction limit reached. Cannot add more transactions.\n");
        return;
    }
    
    Transaction new_transaction;
    printf("Enter transaction name: ");
    scanf("%s", new_transaction.name);
    
    printf("Enter transaction amount: ");
    scanf("%f", &new_transaction.amount);
    
    printf("Enter transaction category: ");
    scanf("%s", new_transaction.category);

    fp->transactions[fp->transaction_count] = new_transaction;
    fp->transaction_count++;
    printf("Transaction added successfully!\n");
}

void displayTransactions(const FinancePlanner *fp) {
    if (fp->transaction_count == 0) {
        printf("No transactions to display.\n");
        return;
    }

    printf("\nTransactions:\n");
    for (int i = 0; i < fp->transaction_count; i++) {
        printf("Transaction %d: Name: %s, Amount: %.2f, Category: %s\n",
               i + 1, fp->transactions[i].name, fp->transactions[i].amount, fp->transactions[i].category);
    }
}

void displaySummary(const FinancePlanner *fp) {
    float total_income = 0.0, total_expenses = 0.0;

    for (int i = 0; i < fp->transaction_count; i++) {
        if (fp->transactions[i].amount > 0) {
            total_income += fp->transactions[i].amount;
        } else {
            total_expenses += -fp->transactions[i].amount;  // Make it positive for summation
        }
    }

    printf("\nFinancial Summary:\n");
    printf("Total Income: %.2f\n", total_income);
    printf("Total Expenses: %.2f\n", total_expenses);
    printf("Net Income: %.2f\n", total_income - total_expenses);
}

void saveToFile(const FinancePlanner *fp) {
    FILE *file = fopen("transactions.txt", "w");
    if (!file) {
        printf("Error saving data to file.\n");
        return;
    }
    fprintf(file, "%d\n", fp->transaction_count);
    for (int i = 0; i < fp->transaction_count; i++) {
        fprintf(file, "%s %.2f %s\n", fp->transactions[i].name, fp->transactions[i].amount, fp->transactions[i].category);
    }
    fclose(file);
    printf("Data saved successfully!\n");
}

void loadFromFile(FinancePlanner *fp) {
    FILE *file = fopen("transactions.txt", "r");
    if (!file) {
        printf("No previous transactions found. Starting fresh.\n");
        return;
    }

    fscanf(file, "%d", &fp->transaction_count);
    for (int i = 0; i < fp->transaction_count; i++) {
        fscanf(file, "%s %f %s", fp->transactions[i].name,
               &fp->transactions[i].amount, fp->transactions[i].category);
    }
    fclose(file);
    printf("Transactions loaded successfully!\n");
}

void clearTransactions(FinancePlanner *fp) {
    fp->transaction_count = 0;
    printf("All transactions cleared.\n");
}