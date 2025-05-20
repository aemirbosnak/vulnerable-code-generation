//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TRANSACTIONS 100
#define MAX_NAME_LEN 50

typedef enum {
    INCOME,
    EXPENSE
} TransactionType;

typedef struct {
    char name[MAX_NAME_LEN];
    float amount;
    TransactionType type;
    time_t timestamp;
} Transaction;

typedef struct {
    Transaction transactions[MAX_TRANSACTIONS];
    int count;
    float balance;
} PersonalFinance;

void display_current_state(PersonalFinance *pf) {
    printf("\n--- Cyberpunk Finance Dashboard ---\n");
    printf("Current Balance: $%.2f\n", pf->balance);
    printf("Recent Transactions:\n");
    for (int i = 0; i < pf->count; i++) {
        char *type_str = (pf->transactions[i].type == INCOME) ? "Income" : "Expense";
        char time_buf[26];
        struct tm* tm_info;

        tm_info = localtime(&pf->transactions[i].timestamp);
        strftime(time_buf, sizeof(time_buf), "%Y-%m-%d %H:%M:%S", tm_info);
        printf("%s: $%.2f on %s - %s\n", type_str, pf->transactions[i].amount, time_buf, pf->transactions[i].name);
    }
}

void add_transaction(PersonalFinance *pf) {
    if (pf->count >= MAX_TRANSACTIONS) {
        printf("Transaction limit reached. Cannot add more transactions.\n");
        return;
    }

    Transaction new_transaction;
    char type_input[10];

    printf("Enter transaction name: ");
    scanf("%s", new_transaction.name);
    
    printf("Enter amount: $");
    scanf("%f", &new_transaction.amount);
    
    printf("Is this an Income or Expense? (i/e): ");
    scanf("%s", type_input);

    new_transaction.type = (strcmp(type_input, "i") == 0) ? INCOME : EXPENSE;
    new_transaction.timestamp = time(NULL);

    pf->transactions[pf->count++] = new_transaction;

    // Update the balance
    pf->balance += (new_transaction.type == INCOME) ? new_transaction.amount : -new_transaction.amount;
    printf("Transaction added successfully!\n");
}

void list_transactions(PersonalFinance *pf) {
    printf("\n--- Transaction History ---\n");
    for (int i = 0; i < pf->count; i++) {
        printf("%d. %s: $%.2f\n", i + 1,
               (pf->transactions[i].type == INCOME) ? "Income" : "Expense",
               pf->transactions[i].amount);
    }
}

void delete_transaction(PersonalFinance *pf) {
    int index;
    printf("Enter the transaction number to delete: ");
    scanf("%d", &index);
    index--;

    if (index < 0 || index >= pf->count) {
        printf("Invalid transaction number.\n");
        return;
    }

    float amount = pf->transactions[index].amount;
    TransactionType type = pf->transactions[index].type;

    // Shift transactions down
    for (int i = index; i < pf->count - 1; i++) {
        pf->transactions[i] = pf->transactions[i + 1];
    }
    pf->count--;

    // Update the balance
    pf->balance -= (type == INCOME) ? amount : -amount;

    printf("Transaction deleted successfully!\n");
}

void welcome() {
    printf("Welcome to the Cyberpunk Personal Finance Planner.\n");
    printf("Manage your finances in the neon-lit dystopian world!\n");
}

int main() {
    PersonalFinance pf;
    pf.count = 0;
    pf.balance = 0;
    welcome();

    int choice;
    do {
        printf("\n1. Add Transaction\n2. List Transactions\n3. Delete Transaction\n4. Show Current State\n5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_transaction(&pf);
                break;
            case 2:
                list_transactions(&pf);
                break;
            case 3:
                delete_transaction(&pf);
                break;
            case 4:
                display_current_state(&pf);
                break;
            case 5:
                printf("Exiting the Cyberpunk finance world...\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}