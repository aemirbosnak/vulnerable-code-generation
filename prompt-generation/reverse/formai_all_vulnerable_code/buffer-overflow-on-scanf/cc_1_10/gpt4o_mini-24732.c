//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 100
#define MAX_DESCRIPTION_LENGTH 50

typedef struct {
    char description[MAX_DESCRIPTION_LENGTH];
    float amount;
    char type; // 'i' for income, 'e' for expense
} Transaction;

typedef struct {
    Transaction transactions[MAX_TRANSACTIONS];
    int count;
    float balance;
} PersonalFinance;

// Function prototypes
void initFinance(PersonalFinance *pf);
void addTransaction(PersonalFinance *pf, char *description, float amount, char type);
void displayTransactions(PersonalFinance *pf);
void calculateBalance(PersonalFinance *pf);
void showMenu();

int main() {
    PersonalFinance myFinance;
    initFinance(&myFinance);
    char description[MAX_DESCRIPTION_LENGTH];
    float amount;
    char type;
    int choice;

    do {
        showMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter transaction description: ");
                scanf(" %[^\n]", description);
                printf("Enter transaction amount: ");
                scanf("%f", &amount);
                printf("Enter transaction type (i for income, e for expense): ");
                scanf(" %c", &type);
                addTransaction(&myFinance, description, amount, type);
                break;
            case 2:
                displayTransactions(&myFinance);
                calculateBalance(&myFinance);
                break;
            case 3:
                calculateBalance(&myFinance);
                break;
            case 4:
                printf("Exiting the Personal Finance Planner. Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void initFinance(PersonalFinance *pf) {
    pf->count = 0;
    pf->balance = 0.0f;
}

void addTransaction(PersonalFinance *pf, char *description, float amount, char type) {
    if (pf->count < MAX_TRANSACTIONS) {
        strcpy(pf->transactions[pf->count].description, description);
        pf->transactions[pf->count].amount = amount;
        pf->transactions[pf->count].type = type;
        pf->count++;
        printf("Transaction added successfully.\n");
    } else {
        printf("Transaction limit reached. Cannot add more!\n");
    }
}

void displayTransactions(PersonalFinance *pf) {
    printf("\nTransaction History:\n");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < pf->count; i++) {
        printf("Description: %s | Amount: %.2f | Type: %s\n", 
                pf->transactions[i].description, 
                pf->transactions[i].amount, 
                pf->transactions[i].type == 'i' ? "Income" : "Expense");
    }
    printf("---------------------------------------------------\n");
}

void calculateBalance(PersonalFinance *pf) {
    pf->balance = 0.0f;
    for (int i = 0; i < pf->count; i++) {
        if (pf->transactions[i].type == 'i') {
            pf->balance += pf->transactions[i].amount;
        } else {
            pf->balance -= pf->transactions[i].amount;
        }
    }
    printf("Current Balance: %.2f\n", pf->balance);
}

void showMenu() {
    printf("\n--- Personal Finance Planner ---\n");
    printf("1. Add Transaction\n");
    printf("2. Show Transactions\n");
    printf("3. Show Balance\n");
    printf("4. Exit\n");
}