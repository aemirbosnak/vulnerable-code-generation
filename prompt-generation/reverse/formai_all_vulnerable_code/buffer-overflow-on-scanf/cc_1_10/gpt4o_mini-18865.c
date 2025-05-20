//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_TRANSACTIONS 100
#define NAME_LENGTH 30
#define DESC_LENGTH 50

typedef struct {
    char description[DESC_LENGTH];
    float amount;
} Transaction;

typedef struct {
    char name[NAME_LENGTH];
    float balance;
    Transaction transactions[MAX_TRANSACTIONS];
    int transaction_count;
} User;

User users[MAX_USERS];
int user_count = 0;

void add_user() {
    if (user_count >= MAX_USERS) {
        printf("Maximum users reached!\n");
        return;
    }
    printf("Enter the name of the new user: ");
    scanf("%s", users[user_count].name);
    users[user_count].balance = 0;
    users[user_count].transaction_count = 0;
    user_count++;
    printf("User %s added successfully!\n", users[user_count - 1].name);
}

void add_transaction(int user_index) {
    if (users[user_index].transaction_count >= MAX_TRANSACTIONS) {
        printf("Transaction limit reached for user %s!\n", users[user_index].name);
        return;
    }
    Transaction *transaction = &users[user_index].transactions[users[user_index].transaction_count];
    
    printf("Enter transaction description: ");
    scanf("%s", transaction->description);
    printf("Enter transaction amount: ");
    scanf("%f", &transaction->amount);
    
    users[user_index].balance += transaction->amount;
    users[user_index].transaction_count++;
    printf("Transaction added! New balance: %.2f\n", users[user_index].balance);
}

void view_balance(int user_index) {
    printf("Balance for %s: %.2f\n", users[user_index].name, users[user_index].balance);
}

void view_transactions(int user_index) {
    printf("Transactions for %s:\n", users[user_index].name);
    for (int i = 0; i < users[user_index].transaction_count; i++) {
        printf("%d: %s - %.2f\n", (i + 1), users[user_index].transactions[i].description, users[user_index].transactions[i].amount);
    }
}

void print_menu() {
    printf("1. Add User\n");
    printf("2. Add Transaction\n");
    printf("3. View Balance\n");
    printf("4. View Transactions\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    while (1) {
        print_menu();
        int choice;
        scanf("%d", &choice);
        
        if (choice == 5) {
            printf("Exiting Personal Finance Planner. Goodbye!\n");
            break;
        }
        
        int user_index;
        switch (choice) {
            case 1:
                add_user();
                break;
            case 2:
                printf("Select User (0 to %d): ", user_count - 1);
                scanf("%d", &user_index);
                if (user_index >= 0 && user_index < user_count) {
                    add_transaction(user_index);
                } else {
                    printf("Invalid user selected.\n");
                }
                break;
            case 3:
                printf("Select User (0 to %d): ", user_count - 1);
                scanf("%d", &user_index);
                if (user_index >= 0 && user_index < user_count) {
                    view_balance(user_index);
                } else {
                    printf("Invalid user selected.\n");
                }
                break;
            case 4:
                printf("Select User (0 to %d): ", user_count - 1);
                scanf("%d", &user_index);
                if (user_index >= 0 && user_index < user_count) {
                    view_transactions(user_index);
                } else {
                    printf("Invalid user selected.\n");
                }
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}