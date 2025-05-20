//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define MAX_TRANSACTIONS 100
#define NAME_LENGTH 50

typedef struct {
    char category[NAME_LENGTH];
    double amount;
} Transaction;

typedef struct {
    Transaction transactions[MAX_TRANSACTIONS];
    int count;
    double total_income;
    double total_expense;
    double balance;
    pthread_mutex_t lock;
} PersonalFinance;

PersonalFinance finance;

void* addTransaction(void* arg) {
    char* type = (char*) arg;
    Transaction new_transaction;

    printf("Enter %s category: ", type);
    scanf("%s", new_transaction.category);
    printf("Enter %s amount: ", type);
    scanf("%lf", &new_transaction.amount);

    pthread_mutex_lock(&finance.lock);
    if (finance.count < MAX_TRANSACTIONS) {
        finance.transactions[finance.count] = new_transaction;
        finance.count++;
        if (strcmp(type, "Income") == 0) {
            finance.total_income += new_transaction.amount;
        } else {
            finance.total_expense += new_transaction.amount;
        }
        finance.balance = finance.total_income - finance.total_expense;
    } else {
        printf("Transaction limit reached!\n");
    }
    pthread_mutex_unlock(&finance.lock);

    printf("Added %s of %.2f in category %s\n", type, new_transaction.amount, new_transaction.category);
    return NULL;
}

void* viewSummary(void* arg) {
    pthread_mutex_lock(&finance.lock);
    printf("\n===== Personal Finance Summary =====\n");
    printf("Total Income: %.2f\n", finance.total_income);
    printf("Total Expense: %.2f\n", finance.total_expense);
    printf("Current Balance: %.2f\n", finance.balance);
    printf("====================================\n\n");
    pthread_mutex_unlock(&finance.lock);
    return NULL;
}

void initializeFinance() {
    finance.count = 0;
    finance.total_income = 0;
    finance.total_expense = 0;
    finance.balance = 0;
    pthread_mutex_init(&finance.lock, NULL);
}

int main() {
    pthread_t thread_income, thread_expense, thread_summary;
    char input[10];
    int running = 1;

    initializeFinance();

    while (running) {
        printf("Choose an option:\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. View Summary\n");
        printf("4. Exit\n");
        scanf("%s", input);

        switch(input[0]) {
            case '1':
                pthread_create(&thread_income, NULL, addTransaction, "Income");
                pthread_join(thread_income, NULL);
                break;
            case '2':
                pthread_create(&thread_expense, NULL, addTransaction, "Expense");
                pthread_join(thread_expense, NULL);
                break;
            case '3':
                pthread_create(&thread_summary, NULL, viewSummary, NULL);
                pthread_join(thread_summary, NULL);
                break;
            case '4':
                running = 0;
                break;
            default:
                printf("Invalid option, please try again.\n");
                break;
        }
    }

    pthread_mutex_destroy(&finance.lock);
    printf("Thank you for using the Personal Finance Planner. Goodbye!\n");
    return 0;
}