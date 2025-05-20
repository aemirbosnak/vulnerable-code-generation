//MISTRAL-7B DATASET v1.0 Category: Personal Finance Planner ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_ITEMS 100
#define FILE_NAME "finance.dat"

typedef struct {
    char name[50];
    float amount;
    int type; // 0 for expense, 1 for income
} Transaction;

void add_transaction(Transaction transactions[], int *num_items, char *name, float amount, int type) {
    if (*num_items < MAX_ITEMS) {
        strcpy(transactions[*num_items].name, name);
        transactions[*num_items].amount = amount;
        transactions[*num_items].type = type;
        (*num_items)++;
    } else {
        printf("Error: Maximum number of transactions reached.\n");
    }
}

void display_transactions(Transaction transactions[], int num_items) {
    float total = 0.0;
    int i;

    printf("\nCurrent Transactions:\n");
    for (i = 0; i < num_items; i++) {
        printf("%s %s: %s %.2f\n", (transactions[i].type == 0) ? "Expense" : "Income", i + 1, transactions[i].name, transactions[i].amount);
        total += transactions[i].amount * (transactions[i].type == 1 ? 1 : -1);
    }

    printf("\nCurrent Balance: %.2f\n", total);
}

void save_data(Transaction transactions[], int num_items) {
    FILE *file;

    file = fopen(FILE_NAME, "wb");
    if (file != NULL) {
        fwrite(&num_items, sizeof(int), 1, file);
        fwrite(transactions, sizeof(Transaction), num_items, file);
        fclose(file);
        printf("Data saved successfully.\n");
    } else {
        printf("Error: Unable to save data.\n");
    }
}

int main() {
    Transaction transactions[MAX_ITEMS];
    int num_items = 0;
    char name[50];
    float amount;
    int choice, type;

    while (1) {
        printf("\n1. Add transaction\n2. Display transactions\n3. Save and exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter transaction name: ");
                scanf("%s", name);
                printf("Enter transaction amount: ");
                scanf("%f", &amount);
                printf("Enter transaction type (0 for expense, 1 for income): ");
                scanf("%d", &type);
                add_transaction(transactions, &num_items, name, amount, type);
                break;
            case 2:
                display_transactions(transactions, num_items);
                break;
            case 3:
                save_data(transactions, num_items);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}