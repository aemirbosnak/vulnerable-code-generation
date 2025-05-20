//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
    char category[MAX_NAME_LENGTH]; // e.g., Income, Expense
} Transaction;

int transaction_count = 0;
Transaction transactions[MAX_ENTRIES];

void add_transaction() {
    if (transaction_count >= MAX_ENTRIES) {
        printf("Transaction list is full!\n");
        return;
    }

    Transaction new_transaction;
    printf("Enter transaction name: ");
    scanf("%s", new_transaction.name);
    
    printf("Enter transaction amount: ");
    scanf("%f", &new_transaction.amount);

    printf("Enter transaction category (Income/Expense): ");
    scanf("%s", new_transaction.category);

    transactions[transaction_count++] = new_transaction;
    printf("Transaction added successfully!\n");
}

void view_transactions() {
    if (transaction_count == 0) {
        printf("No transactions to display.\n");
        return;
    }

    printf("\nTransactions:\n");
    for (int i = 0; i < transaction_count; i++) {
        printf("Name: %s, Amount: %.2f, Category: %s\n", 
               transactions[i].name, 
               transactions[i].amount, 
               transactions[i].category);
    }
}

void calculate_balance() {
    float total_income = 0.0, total_expense = 0.0;

    for (int i = 0; i < transaction_count; i++) {
        if (strcmp(transactions[i].category, "Income") == 0) {
            total_income += transactions[i].amount;
        } else if (strcmp(transactions[i].category, "Expense") == 0) {
            total_expense += transactions[i].amount;
        }
    }
    
    printf("\nTotal Income: %.2f\n", total_income);
    printf("Total Expense: %.2f\n", total_expense);
    printf("Net Balance: %.2f\n", total_income - total_expense);
}

void save_transactions() {
    FILE *file = fopen("transactions.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }

    for (int i = 0; i < transaction_count; i++) {
        fprintf(file, "%s %.2f %s\n", 
                transactions[i].name, 
                transactions[i].amount, 
                transactions[i].category);
    }
    fclose(file);
    printf("Transactions saved to transactions.txt\n");
}

void load_transactions() {
    FILE *file = fopen("transactions.txt", "r");
    if (file == NULL) {
        printf("No saved transactions found!\n");
        return;
    }

    while (fscanf(file, "%s %f %s", transactions[transaction_count].name, 
                  &transactions[transaction_count].amount, 
                  transactions[transaction_count].category) == 3) {
        transaction_count++;
        if (transaction_count >= MAX_ENTRIES) {
            break;
        }
    }
    fclose(file);
    printf("Transactions loaded successfully!\n");
}

void display_menu() {
    printf("\nPersonal Finance Planner\n");
    printf("1. Add transaction\n");
    printf("2. View transactions\n");
    printf("3. Calculate balance\n");
    printf("4. Save transactions\n");
    printf("5. Load transactions\n");
    printf("6. Exit\n");
    printf("Select an option: ");
}

int main() {
    int choice;
    load_transactions();

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_transaction();
                break;
            case 2:
                view_transactions();
                break;
            case 3:
                calculate_balance();
                break;
            case 4:
                save_transactions();
                break;
            case 5:
                load_transactions();
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}