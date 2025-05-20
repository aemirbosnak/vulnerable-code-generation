//FormAI DATASET v1.0 Category: Expense Tracker ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX_TRANSACTIONS 100

struct Transaction {
    char category[20];
    float amount;
};

void display_menu() {
    printf("Expense Tracker\n");
    printf("----------------\n");
    printf("1. Add Transaction\n");
    printf("2. Display Transactions\n");
    printf("3. Exit\n");
}

void add_transaction(struct Transaction transactions[], int *num_transactions) {
    if (*num_transactions == MAX_TRANSACTIONS) {
        printf("Maximum number of transactions reached.\n");
        return;
    }

    struct Transaction t;

    printf("Enter category: ");
    scanf("%s", t.category);

    printf("Enter amount: ");
    scanf("%f", &t.amount);

    transactions[*num_transactions] = t;

    printf("Transaction added.\n");

    (*num_transactions)++;
}

void display_transactions(struct Transaction transactions[], int num_transactions) {
    printf("Transactions:\n");

    for (int i = 0; i < num_transactions; i++) {
        printf("%s: %.2f\n", transactions[i].category, transactions[i].amount);
    }
}

int main() {
    struct Transaction transactions[MAX_TRANSACTIONS];
    int num_transactions = 0;
    int choice;

    do {
        display_menu();

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_transaction(transactions, &num_transactions);
                break;
            case 2:
                display_transactions(transactions, num_transactions);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

        printf("\n");

    } while (choice != 3);

    return 0;
}