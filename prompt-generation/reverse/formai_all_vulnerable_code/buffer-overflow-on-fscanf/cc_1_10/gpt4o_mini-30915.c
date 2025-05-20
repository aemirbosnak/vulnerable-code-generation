//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 100
#define MAX_CATEGORIES 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
    char category[MAX_NAME_LENGTH];
} Transaction;

typedef struct {
    Transaction transactions[MAX_TRANSACTIONS];
    int count;
} FinanceTracker;

void add_transaction(FinanceTracker* tracker) {
    if (tracker->count >= MAX_TRANSACTIONS) {
        printf("Transaction limit reached!\n");
        return;
    }
    
    Transaction t;
    printf("Enter transaction name: ");
    scanf("%s", t.name);
    printf("Enter transaction amount: ");
    scanf("%f", &t.amount);
    printf("Enter transaction category: ");
    scanf("%s", t.category);
    
    tracker->transactions[tracker->count] = t;
    tracker->count++;
    printf("Transaction added successfully!\n");
}

void view_transactions(FinanceTracker tracker) {
    if (tracker.count == 0) {
        printf("No transactions to display.\n");
        return;
    }
    
    printf("\n--- Transactions ---\n");
    for (int i = 0; i < tracker.count; i++) {
        printf("Transaction %d: %s | Amount: %.2f | Category: %s\n", 
                i + 1, tracker.transactions[i].name, 
                tracker.transactions[i].amount, 
                tracker.transactions[i].category);
    }
    printf("-------------------\n");
}

void calculate_totals(FinanceTracker tracker) {
    float income = 0.0, expenses = 0.0;
    
    for (int i = 0; i < tracker.count; i++) {
        if (tracker.transactions[i].amount > 0) {
            income += tracker.transactions[i].amount;
        } else {
            expenses += tracker.transactions[i].amount;
        }
    }
    
    printf("\n--- Financial Summary ---\n");
    printf("Total Income: %.2f\n", income);
    printf("Total Expenses: %.2f\n", expenses);
    printf("Net Amount: %.2f\n", income + expenses);
    printf("------------------------\n");
}

void save_to_file(FinanceTracker tracker) {
    FILE* file = fopen("transactions.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }
    
    for (int i = 0; i < tracker.count; i++) {
        fprintf(file, "Transaction: %s | Amount: %.2f | Category: %s\n", 
                tracker.transactions[i].name, 
                tracker.transactions[i].amount, 
                tracker.transactions[i].category);
    }
    
    fclose(file);
    printf("Transactions saved to transactions.txt successfully!\n");
}

void load_from_file(FinanceTracker* tracker) {
    FILE* file = fopen("transactions.txt", "r");
    if (file == NULL) {
        printf("No saved data found!\n");
        return;
    }
    
    while (fscanf(file, "Transaction: %s | Amount: %f | Category: %s\n", 
                  tracker->transactions[tracker->count].name, 
                  &tracker->transactions[tracker->count].amount, 
                  tracker->transactions[tracker->count].category) != EOF) {
        tracker->count++;
        if (tracker->count >= MAX_TRANSACTIONS) {
            break;
        }
    }
    fclose(file);
    printf("Transactions loaded from transactions.txt successfully!\n");
}

void display_menu() {
    printf("\n--- Personal Finance Planner Menu ---\n");
    printf("1. Add Transaction\n");
    printf("2. View Transactions\n");
    printf("3. Calculate Totals\n");
    printf("4. Save Transactions\n");
    printf("5. Load Transactions\n");
    printf("6. Exit\n");
    printf("--------------------------------------\n");
}

int main() {
    FinanceTracker tracker = { .count = 0 };
    int choice;

    do {
        display_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_transaction(&tracker);
                break;
            case 2:
                view_transactions(tracker);
                break;
            case 3:
                calculate_totals(tracker);
                break;
            case 4:
                save_to_file(tracker);
                break;
            case 5:
                load_from_file(&tracker);
                break;
            case 6:
                printf("Exiting the program. Happy budgeting!\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}