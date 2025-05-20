//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_TRANSACTIONS 100
#define MAX_CATEGORY_NAME_LENGTH 20
#define MAX_TRANSACTION_NAME_LENGTH 40

typedef struct {
    char name[MAX_CATEGORY_NAME_LENGTH];
    int transactions[MAX_TRANSACTIONS];
} category;

typedef struct {
    char name[MAX_TRANSACTION_NAME_LENGTH];
    int amount;
    char category[MAX_CATEGORY_NAME_LENGTH];
} transaction;

category categories[MAX_CATEGORIES];
transaction transactions[MAX_TRANSACTIONS];
int num_categories;
int num_transactions;

void add_category() {
    printf("Enter category name: ");
    scanf("%s", categories[num_categories].name);
    num_categories++;
}

void add_transaction() {
    printf("Enter transaction name: ");
    scanf("%s", transactions[num_transactions].name);
    printf("Enter amount: ");
    scanf("%d", &transactions[num_transactions].amount);
    printf("Enter category: ");
    scanf("%s", transactions[num_transactions].category);
    num_transactions++;
}

void view_transactions() {
    printf("Transactions:\n");
    for (int i = 0; i < num_transactions; i++) {
        printf("%s - $%d - %s\n", transactions[i].name, transactions[i].amount, transactions[i].category);
    }
}

void view_categories() {
    printf("Categories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s\n", categories[i].name);
    }
}

int main() {
    num_categories = 0;
    num_transactions = 0;

    while (1) {
        printf("\nPersonal Finance Planner\n");
        printf("1. Add category\n2. Add transaction\n3. View transactions\n4. View categories\n5. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_category();
            break;
        case 2:
            add_transaction();
            break;
        case 3:
            view_transactions();
            break;
        case 4:
            view_categories();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}