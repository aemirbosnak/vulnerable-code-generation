//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 100
#define MAX_CATEGORIES 10

typedef struct {
    char name[50];
    float amount;
    char category[50];
} transaction;

transaction transactions[MAX_TRANSACTIONS];
char categories[MAX_CATEGORIES][50];
int num_transactions = 0;
int num_categories = 0;

void add_transaction() {
    if (num_transactions >= MAX_TRANSACTIONS) {
        printf("Error: Maximum number of transactions reached.\n");
        return;
    }

    printf("Enter transaction name: ");
    scanf("%s", transactions[num_transactions].name);

    printf("Enter transaction amount: ");
    scanf("%f", &transactions[num_transactions].amount);

    printf("Enter transaction category (or 'new' to create a new category): ");
    scanf("%s", transactions[num_transactions].category);

    if (strcmp(transactions[num_transactions].category, "new") == 0) {
        printf("Enter new category name: ");
        scanf("%s", categories[num_categories]);
        strcpy(transactions[num_transactions].category, categories[num_categories]);
        num_categories++;
    }

    num_transactions++;
}

void display_transactions() {
    printf("\nTransactions:\n");
    for (int i = 0; i < num_transactions; i++) {
        printf("%s - $%.2f - %s\n", transactions[i].name, transactions[i].amount, transactions[i].category);
    }
}

void display_categories() {
    printf("\nCategories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s\n", categories[i]);
    }
}

int main() {
    printf("Welcome to the Personal Finance Planner!\n");

    while (1) {
        printf("\nOptions:\n1. Add transaction\n2. Display transactions\n3. Display categories\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_transaction();
                break;
            case 2:
                display_transactions();
                break;
            case 3:
                display_categories();
                break;
            case 4:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}