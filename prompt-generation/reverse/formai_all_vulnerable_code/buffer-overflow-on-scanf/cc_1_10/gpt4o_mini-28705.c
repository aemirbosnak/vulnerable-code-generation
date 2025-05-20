//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 100
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
    int type; // 0 for income, 1 for expense
} Transaction;

typedef struct {
    Transaction transactions[MAX_TRANSACTIONS];
    int count;
} FinanceTracker;

void add_transaction(FinanceTracker *tracker, const char *name, float amount, int type) {
    if (tracker->count >= MAX_TRANSACTIONS) {
        printf("Transaction limit reached! Cannot add more transactions.\n");
        return;
    }
    strcpy(tracker->transactions[tracker->count].name, name);
    tracker->transactions[tracker->count].amount = amount;
    tracker->transactions[tracker->count].type = type;
    tracker->count++;
    printf("Transaction added successfully.\n");
}

void view_transactions(const FinanceTracker *tracker) {
    printf("Transactions:\n");
    printf("%-20s %-10s %-10s\n", "Name", "Amount", "Type");
    printf("--------------------------------------------\n");
    
    for (int i = 0; i < tracker->count; i++) {
        const char *type_str = tracker->transactions[i].type == 0 ? "Income" : "Expense";
        printf("%-20s %-10.2f %-10s\n", tracker->transactions[i].name, tracker->transactions[i].amount, type_str);
    }
}

float calculate_balance(const FinanceTracker *tracker) {
    float income = 0.0, expense = 0.0;
    
    for (int i = 0; i < tracker->count; i++) {
        if (tracker->transactions[i].type == 0) {
            income += tracker->transactions[i].amount;
        } else {
            expense += tracker->transactions[i].amount;
        }
    }
    
    return income - expense;
}

void display_menu() {
    printf("\nPersonal Finance Planner\n");
    printf("1. Add Transaction\n");
    printf("2. View Transactions\n");
    printf("3. Calculate Balance\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

int main() {
    FinanceTracker tracker = {{0}, 0};
    int choice = 0;
    char name[MAX_NAME_LENGTH];
    float amount;

    while (1) {
        display_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter transaction name: ");
                scanf("%s", name);
                printf("Enter transaction amount: ");
                scanf("%f", &amount);
                printf("Enter transaction type (0 for income, 1 for expense): ");
                int type;
                scanf("%d", &type);
                add_transaction(&tracker, name, amount, type);
                break;
            case 2:
                view_transactions(&tracker);
                break;
            case 3:
                printf("Current Balance: %.2f\n", calculate_balance(&tracker));
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}