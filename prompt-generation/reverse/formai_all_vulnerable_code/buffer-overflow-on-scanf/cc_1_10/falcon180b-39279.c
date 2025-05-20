//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_TRANSACTIONS 100

typedef struct {
    char name[50];
    double amount;
    int date;
} Transaction;

typedef struct {
    char name[50];
    double balance;
} Category;

void addTransaction(Transaction* transactions, int numTransactions, Category* categories, int numCategories) {
    printf("Enter transaction name: ");
    scanf("%s", transactions[numTransactions].name);
    printf("Enter transaction amount: $");
    scanf("%lf", &transactions[numTransactions].amount);
    printf("Enter transaction date: ");
    scanf("%d", &transactions[numTransactions].date);
    printf("Enter category name: ");
    scanf("%s", categories[numCategories].name);
    printf("Enter category balance: $");
    scanf("%lf", &categories[numCategories].balance);
    numTransactions++;
    numCategories++;
}

void displayTransactions(Transaction* transactions, int numTransactions) {
    printf("Transaction Name\tAmount\tDate\n");
    for(int i=0; i<numTransactions; i++) {
        printf("%s\t\t$%.2lf\t\t%d\n", transactions[i].name, transactions[i].amount, transactions[i].date);
    }
}

void displayCategories(Category* categories, int numCategories) {
    printf("Category Name\tBalance\n");
    for(int i=0; i<numCategories; i++) {
        printf("%s\t\t$%.2lf\n", categories[i].name, categories[i].balance);
    }
}

int main() {
    Transaction transactions[MAX_TRANSACTIONS];
    Category categories[MAX_CATEGORIES];
    int numTransactions = 0;
    int numCategories = 0;

    addTransaction(transactions, numTransactions, categories, numCategories);
    addTransaction(transactions, numTransactions, categories, numCategories);
    addTransaction(transactions, numTransactions, categories, numCategories);

    displayTransactions(transactions, numTransactions);
    displayCategories(categories, numCategories);

    return 0;
}