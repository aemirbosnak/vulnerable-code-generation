//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR_LEN 50
#define MAX_TRANS 100

typedef struct Transaction {
    char date[MAX_STR_LEN];
    float amount;
    char category[MAX_STR_LEN];
} Transaction;

void addTrans(Transaction *trans, int *numTrans);
void viewTrans(Transaction *trans, int numTrans);
void deleteTrans(Transaction *trans, int *numTrans);
void saveTransToFile(Transaction *trans, int numTrans, char fileName[]);
void loadTransFromFile(Transaction *trans, int *numTrans, char fileName[]);

int main() {
    Transaction transactionList[MAX_TRANS];
    int numTransactions = 0;
    int option;

    printf("Welcome to Expense Tracker!\n");

    do {
        printf("\nMenu:\n");
        printf("1. Add Transaction\n");
        printf("2. View Transactions\n");
        printf("3. Delete Transaction\n");
        printf("4. Save Transactions to File\n");
        printf("5. Load Transactions from File\n");
        printf("0. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                addTrans(transactionList, &numTransactions);
                break;
            case 2:
                viewTrans(transactionList, numTransactions);
                break;
            case 3:
                deleteTrans(transactionList, &numTransactions);
                break;
            case 4:
                saveTransToFile(transactionList, numTransactions, "transactions.txt");
                break;
            case 5:
                loadTransFromFile(transactionList, &numTransactions, "transactions.txt");
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }

    } while (option != 0);

    return 0;
}

void addTrans(Transaction *trans, int *numTrans) {
    // Prompt user for transaction information
    printf("--- Add Transaction ---\n");
    printf("Enter date (dd/mm/yyyy): ");
    scanf("%s", trans[*numTrans].date);

    printf("Enter amount: ");
    scanf("%f", &trans[*numTrans].amount);

    printf("Enter category: ");
    scanf("%s", trans[*numTrans].category);

    // Increment transaction counter
    *numTrans += 1;

    printf("Transaction added successfully!\n");
}

void viewTrans(Transaction *trans, int numTrans) {
    // Print header
    printf("Date\t\tAmount\tCategory\n");

    // Loop through transactions and print each one
    for (int i = 0; i < numTrans; i++) {
        printf("%s\t%.2f\t%s\n", trans[i].date, trans[i].amount, trans[i].category);
    }
}

void deleteTrans(Transaction *trans, int *numTrans) {
    int transIndex;

    // Prompt user for transaction index to delete
    printf("--- Delete Transaction ---\n");
    printf("Enter transaction index: ");
    scanf("%d", &transIndex);

    // Shift array elements left to remove deleted transaction
    for (int i = transIndex; i < *numTrans - 1; i++) {
        trans[i] = trans[i+1];
    }

    // Decrement transaction counter
    *numTrans -= 1;

    printf("Transaction deleted successfully!\n");
}

void saveTransToFile(Transaction *trans, int numTrans, char fileName[]) {
    FILE *fp;

    // Open file for writing
    fp = fopen(fileName, "w");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Write transaction data to file
    for (int i = 0; i < numTrans; i++) {
        fprintf(fp, "%s,%.2f,%s\n", trans[i].date, trans[i].amount, trans[i].category);
    }

    fclose(fp);
    printf("Transactions saved to file successfully!\n");
}

void loadTransFromFile(Transaction *trans, int *numTrans, char fileName[]) {
    FILE *fp;
    char line[MAX_STR_LEN];
    char *token;

    // Open file for reading
    fp = fopen(fileName, "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Read file line by line and parse transaction data
    while (fgets(line, MAX_STR_LEN, fp) != NULL) {
        token = strtok(line, ",");
        strcpy(trans[*numTrans].date, token);

        token = strtok(NULL, ",");
        trans[*numTrans].amount = atof(token);

        token = strtok(NULL, ",");
        sscanf(token, "%s", trans[*numTrans].category);

        // Increment transaction counter
        *numTrans += 1;
    }

    fclose(fp);
    printf("Transactions loaded from file successfully!\n");
}