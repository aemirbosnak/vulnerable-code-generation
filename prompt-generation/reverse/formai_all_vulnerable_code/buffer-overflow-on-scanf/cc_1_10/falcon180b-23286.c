//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_TRANSACTIONS 100
#define MAX_CATEGORY_SIZE 50

typedef struct {
    char name[MAX_CATEGORY_SIZE];
    float balance;
} Category;

typedef struct {
    char description[MAX_CATEGORY_SIZE];
    float amount;
    int category_index;
} Transaction;

int main() {
    int num_categories, num_transactions;
    Category categories[MAX_CATEGORIES];
    Transaction transactions[MAX_TRANSACTIONS];

    printf("Welcome to the Personal Finance Planner!\n");

    // Initialize categories
    for (int i = 0; i < MAX_CATEGORIES; i++) {
        categories[i].balance = 0.0;
        strcpy(categories[i].name, "");
    }

    printf("How many categories do you want to create? (Max %d)\n", MAX_CATEGORIES);
    scanf("%d", &num_categories);

    for (int i = 0; i < num_categories; i++) {
        printf("Enter category %d name: ", i+1);
        scanf("%s", categories[i].name);
        printf("Enter category %d initial balance: ", i+1);
        scanf("%f", &categories[i].balance);
    }

    // Initialize transactions
    for (int i = 0; i < MAX_TRANSACTIONS; i++) {
        transactions[i].amount = 0.0;
        strcpy(transactions[i].description, "");
        transactions[i].category_index = -1;
    }

    printf("How many transactions do you want to create? (Max %d)\n", MAX_TRANSACTIONS);
    scanf("%d", &num_transactions);

    for (int i = 0; i < num_transactions; i++) {
        printf("Enter transaction %d description: ", i+1);
        scanf("%s", transactions[i].description);
        printf("Enter transaction %d amount: ", i+1);
        scanf("%f", &transactions[i].amount);
        printf("Enter transaction %d category index (0-%d): ", i+1, num_categories-1);
        scanf("%d", &transactions[i].category_index);
    }

    // Print initial balance
    printf("\nInitial Balance:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("Category %d: $%.2f\n", i+1, categories[i].balance);
    }

    // Print transactions
    printf("\nTransactions:\n");
    for (int i = 0; i < num_transactions; i++) {
        printf("Transaction %d: %s - $%.2f (Category: ", i+1, transactions[i].description, transactions[i].amount);
        if (transactions[i].category_index >= 0) {
            printf("%s)\n", categories[transactions[i].category_index].name);
        } else {
            printf("None)\n");
        }
    }

    return 0;
}