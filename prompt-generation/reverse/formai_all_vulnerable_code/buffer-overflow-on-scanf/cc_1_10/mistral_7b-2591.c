//MISTRAL-7B DATASET v1.0 Category: Personal Finance Planner ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 50

typedef struct Transaction {
    char description[50];
    float amount;
    int date;
} Transaction;

int mainMenu() {
    int choice;
    printf("\n1. Add Transaction\n2. Display Balance\n3. Display Transactions\n4. Delete Transaction\n5. Quit\n");
    scanf("%d", &choice);
    return choice;
}

void addTransaction(Transaction transactions[], int* numTransactions, char description[], float amount, int date) {
    if (*numTransactions < MAX_TRANSACTIONS) {
        strcpy(transactions[*numTransactions].description, description);
        transactions[*numTransactions].amount = amount;
        transactions[*numTransactions].date = date;
        (*numTransactions)++;
    } else {
        printf("Maximum number of transactions reached.\n");
    }
}

void displayBalance(Transaction transactions[], int numTransactions) {
    float balance = 0;
    for (int i = 0; i < numTransactions; i++) {
        balance += transactions[i].amount;
    }
    printf("Current Balance: $%.2f\n", balance);
}

void displayTransactions(Transaction transactions[], int numTransactions) {
    if (numTransactions == 0) {
        printf("No transactions found.\n");
        return;
    }

    printf("\nTransaction History:\n");
    for (int i = 0; i < numTransactions; i++) {
        printf("%d. %s: $%.2f (%d)\n", i+1, transactions[i].description, transactions[i].amount, transactions[i].date);
    }
}

void deleteTransaction(Transaction transactions[], int* numTransactions, int index) {
    if (index < 1 || index > *numTransactions || *numTransactions == 0) {
        printf("Invalid transaction index.\n");
        return;
    }

    for (int i = index; i < *numTransactions-1; i++) {
        transactions[i] = transactions[i+1];
    }

    (*numTransactions)--;
    printf("Transaction deleted successfully.\n");
}

int main() {
    Transaction transactions[MAX_TRANSACTIONS];
    int numTransactions = 0;
    int choice;

    while (1) {
        choice = mainMenu();

        switch (choice) {
            case 1: {
                char description[50];
                float amount;
                int date;

                printf("Enter Transaction Description: ");
                scanf("%s", description);
                printf("Enter Transaction Amount: $");
                scanf("%f", &amount);
                printf("Enter Transaction Date (YYYYMMDD): ");
                scanf("%d", &date);

                addTransaction(transactions, &numTransactions, description, amount, date);
                break;
            }
            case 2: {
                displayBalance(transactions, numTransactions);
                break;
            }
            case 3: {
                displayTransactions(transactions, numTransactions);
                break;
            }
            case 4: {
                int index;
                printf("Enter Transaction Index to Delete: ");
                scanf("%d", &index);

                deleteTransaction(transactions, &numTransactions, index);
                break;
            }
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}