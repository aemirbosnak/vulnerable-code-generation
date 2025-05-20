//MISTRAL-7B DATASET v1.0 Category: Personal Finance Planner ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
    int type; // 0 for income, 1 for expense
} Transaction;

Transaction transactions[MAX_ITEMS];
int transactionIndex = 0;

void saveData() {
    FILE *fp;
    fp = fopen("transactions.dat", "wb");
    if (fp == NULL) {
        printf("Error saving data!\n");
        exit(1);
    }

    fwrite(transactions, sizeof(Transaction), transactionIndex, fp);
    fclose(fp);
}

void loadData() {
    FILE *fp;
    Transaction tempTransaction;

    fp = fopen("transactions.dat", "rb");
    if (fp != NULL) {
        while (fread(&tempTransaction, sizeof(Transaction), 1, fp) > 0) {
            transactions[transactionIndex++] = tempTransaction;
        }
        fclose(fp);
    }
}

void addTransaction(char *name, float amount, int type) {
    if (transactionIndex == MAX_ITEMS) {
        printf("Max transactions reached! Delete some transactions to add new ones.\n");
        return;
    }

    strcpy(transactions[transactionIndex].name, name);
    transactions[transactionIndex].amount = amount;
    transactions[transactionIndex].type = type;
    transactionIndex++;
}

void viewBalance() {
    float balance = 0;
    int i;

    for (i = 0; i < transactionIndex; i++) {
        if (transactions[i].type == 0) {
            balance += transactions[i].amount;
        } else {
            balance -= transactions[i].amount;
        }
    }

    printf("Current balance: %.2f\n", balance);
}

int main() {
    int choice;
    char name[MAX_NAME_LENGTH];
    float amount;

    loadData();

    while (1) {
        printf("\n1. Add transaction\n");
        printf("2. View balance\n");
        printf("3. Save and exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter transaction name: ");
                scanf("%s", name);
                printf("Enter transaction amount: ");
                scanf("%f", &amount);
                printf("Enter transaction type (0 for income, 1 for expense): ");
                scanf("%d", &choice);
                addTransaction(name, amount, choice);
                break;
            case 2:
                viewBalance();
                break;
            case 3:
                saveData();
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}