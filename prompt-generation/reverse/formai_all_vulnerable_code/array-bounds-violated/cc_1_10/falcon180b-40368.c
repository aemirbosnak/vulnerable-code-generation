//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

#define MAX_CATEGORIES 10
#define MAX_TRANSACTIONS 100
#define MAX_NAME_LENGTH 50

// Struct to hold category information
typedef struct {
    char name[MAX_NAME_LENGTH];
    int id;
} Category;

// Struct to hold transaction information
typedef struct {
    char name[MAX_NAME_LENGTH];
    Category category;
    double amount;
    time_t date;
} Transaction;

int main() {
    // Initialize categories
    Category categories[MAX_CATEGORIES];
    int numCategories = 0;

    // Initialize transactions
    Transaction transactions[MAX_TRANSACTIONS];
    int numTransactions = 0;

    // Read categories from file
    FILE* categoriesFile = fopen("categories.txt", "r");
    if (categoriesFile!= NULL) {
        char line[MAX_NAME_LENGTH];
        while (fgets(line, MAX_NAME_LENGTH, categoriesFile)!= NULL) {
            Category category;
            strcpy(category.name, line);
            category.id = numCategories;
            categories[numCategories++] = category;
        }
        fclose(categoriesFile);
    }

    // Read transactions from file
    FILE* transactionsFile = fopen("transactions.txt", "r");
    if (transactionsFile!= NULL) {
        char line[MAX_NAME_LENGTH];
        while (fgets(line, MAX_NAME_LENGTH, transactionsFile)!= NULL) {
            Transaction transaction;
            strcpy(transaction.name, line);
            int categoryId = atoi(fgets(line, MAX_NAME_LENGTH, transactionsFile));
            transaction.category = categories[categoryId];
            transaction.amount = atof(fgets(line, MAX_NAME_LENGTH, transactionsFile));
            strptime(fgets(line, MAX_NAME_LENGTH, transactionsFile), "%Y-%m-%d", &transaction.date);
            transactions[numTransactions++] = transaction;
        }
        fclose(transactionsFile);
    }

    // Display categories
    printf("Categories:\n");
    for (int i = 0; i < numCategories; i++) {
        printf("%d. %s\n", i + 1, categories[i].name);
    }

    // Display transactions
    printf("\nTransactions:\n");
    for (int i = 0; i < numTransactions; i++) {
        printf("%s - %.2f - %s\n", transactions[i].name, transactions[i].amount, ctime(&transactions[i].date));
    }

    return 0;
}