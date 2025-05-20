//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_TRANSACTIONS 100

typedef struct {
    char description[50];
    float amount;
} Transaction;

typedef struct {
    char name[50];
    Transaction transactions[MAX_TRANSACTIONS];
    int transaction_count;
} User;

User users[MAX_USERS];
int user_count = 0;

void add_user() {
    if (user_count >= MAX_USERS) {
        printf("Max user limit reached.\n");
        return;
    }
    printf("Enter user name: ");
    scanf("%s", users[user_count].name);
    users[user_count].transaction_count = 0;
    user_count++;
    printf("User added successfully.\n");
}

void add_transaction() {
    char user_name[50];
    printf("Enter user name for transaction: ");
    scanf("%s", user_name);
    
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].name, user_name) == 0) {
            if (users[i].transaction_count >= MAX_TRANSACTIONS) {
                printf("Max transaction limit reached for user %s.\n", user_name);
                return;
            }
            Transaction new_transaction;
            printf("Enter transaction description: ");
            scanf("%s", new_transaction.description);
            printf("Enter transaction amount: ");
            scanf("%f", &new_transaction.amount);
            users[i].transactions[users[i].transaction_count++] = new_transaction;
            printf("Transaction added successfully.\n");
            return;
        }
    }
    printf("User not found.\n");
}

void view_summary() {
    for (int i = 0; i < user_count; i++) {
        printf("User: %s\n", users[i].name);
        float total_income = 0.0;
        float total_expenses = 0.0;

        for (int j = 0; j < users[i].transaction_count; j++) {
            if (users[i].transactions[j].amount >= 0) {
                total_income += users[i].transactions[j].amount;
            } else {
                total_expenses += -users[i].transactions[j].amount; // Negative amount for expenses
            }
        }

        printf("Total Income: %.2f\n", total_income);
        printf("Total Expenses: %.2f\n", total_expenses);
        printf("Net Savings: %.2f\n\n", total_income - total_expenses);
    }
}

void menu() {
    int choice;

    do {
        printf("Welcome to the Personal Finance Planner\n");
        printf("1. Add User\n");
        printf("2. Add Transaction\n");
        printf("3. View Summary\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_user();
                break;
            case 2:
                add_transaction();
                break;
            case 3:
                view_summary();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}

int main() {
    menu();
    return 0;
}