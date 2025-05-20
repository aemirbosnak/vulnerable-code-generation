//MISTRAL-7B DATASET v1.0 Category: Personal Finance Planner ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float amount;
    int type; // 1 for income, -1 for expense
} Transaction;

Transaction transactions[MAX_ITEMS];
int current_item = 0;
float balance = 0.0;

void save_data(const char *filename) {
    FILE *file = fopen(filename, "wb");

    if (file == NULL) {
        printf("Error: Unable to save data.\n");
        return;
    }

    fwrite(&current_item, sizeof(int), 1, file);
    for (int i = 0; i < current_item; i++) {
        fwrite(&transactions[i], sizeof(Transaction), 1, file);
    }

    fclose(file);
}

void load_data(const char *filename) {
    FILE *file = fopen(filename, "rb");

    if (file == NULL) {
        printf("Error: Unable to load data.\n");
        return;
    }

    fread(&current_item, sizeof(int), 1, file);

    for (int i = 0; i < current_item; i++) {
        fread(&transactions[i], sizeof(Transaction), 1, file);
        balance += transactions[i].amount * transactions[i].type;
    }

    fclose(file);
}

void add_transaction(const char *name, float amount, int is_income) {
    if (current_item >= MAX_ITEMS) {
        printf("Error: Not enough space to add a new transaction.\n");
        return;
    }

    strcpy(transactions[current_item].name, name);
    transactions[current_item].amount = amount;
    transactions[current_item].type = is_income ? 1 : -1;
    current_item++;

    balance += amount * is_income;
}

void view_transactions() {
    printf("\nCurrent transactions:\n");

    for (int i = 0; i < current_item; i++) {
        printf("%s: %.2f%s\n", transactions[i].name, transactions[i].amount,
            transactions[i].type > 0 ? " (income)" : " (expense)");
    }

    printf("\nCurrent balance: %.2f\n", balance);
}

int main() {
    const char *filename = "transactions.dat";

    load_data(filename);

    while (1) {
        int choice;
        printf("\nPersonal Finance Planner\n");
        printf("1. Add transaction\n");
        printf("2. View transactions\n");
        printf("3. Save and quit\n");
        printf("> ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            char name[50];
            float amount;
            int is_income;

            printf("Name: ");
            scanf("%s", name);
            printf("Amount: ");
            scanf("%f", &amount);
            printf("Is income (1) or expense (-1)? ");
            scanf("%d", &is_income);

            add_transaction(name, amount, is_income);
            break;
        }
        case 2:
            view_transactions();
            break;
        case 3:
            save_data(filename);
            printf("Goodbye!\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}