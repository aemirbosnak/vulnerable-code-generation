//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

#define MAX_TRANSACTIONS 100
#define MAX_LENGTH 100

typedef struct {
    char description[MAX_LENGTH];
    double amount;
    char category[MAX_LENGTH];
    time_t date;
} Transaction;

typedef struct {
    Transaction transactions[MAX_TRANSACTIONS];
    int count;
} FinanceData;

FinanceData financeData;
pthread_mutex_t lock;

void *addTransaction(void *param) {
    Transaction transaction;
    
    printf("Enter transaction description: ");
    scanf(" %[^\n]", transaction.description);
    printf("Enter transaction amount: ");
    scanf("%lf", &transaction.amount);
    printf("Enter transaction category: ");
    scanf(" %[^\n]", transaction.category);
    transaction.date = time(NULL);
    
    pthread_mutex_lock(&lock);
    if (financeData.count < MAX_TRANSACTIONS) {
        financeData.transactions[financeData.count] = transaction;
        financeData.count++;
        printf("Transaction added!\n");
    } else {
        printf("Transaction limit reached!\n");
    }
    pthread_mutex_unlock(&lock);
    
    return NULL;
}

void *viewTransactions(void *param) {
    pthread_mutex_lock(&lock);
    if (financeData.count == 0) {
        printf("No transactions to display.\n");
    } else {
        printf("\nTransactions:\n");
        for (int i = 0; i < financeData.count; i++) {
            printf("Description: %s, Amount: %.2f, Category: %s, Date: %s", 
                financeData.transactions[i].description, 
                financeData.transactions[i].amount,
                financeData.transactions[i].category,
                ctime(&financeData.transactions[i].date));
        }
    }
    pthread_mutex_unlock(&lock);
    
    return NULL;
}

void *calculateBalance(void *param) {
    double balance = 0.0;
    
    pthread_mutex_lock(&lock);
    for (int i = 0; i < financeData.count; i++) {
        balance += financeData.transactions[i].amount;
    }
    pthread_mutex_unlock(&lock);
    
    printf("Current balance: %.2f\n", balance);
    
    return NULL;
}

void *menu(void *param) {
    int choice;
    pthread_t thread;

    while (1) {
        printf("\nPersonal Finance Planner\n");
        printf("1. Add a Transaction\n");
        printf("2. View Transactions\n");
        printf("3. Calculate Balance\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                pthread_create(&thread, NULL, addTransaction, NULL);
                pthread_detach(thread);
                break;
            case 2:
                pthread_create(&thread, NULL, viewTransactions, NULL);
                pthread_detach(thread);
                break;
            case 3:
                pthread_create(&thread, NULL, calculateBalance, NULL);
                pthread_detach(thread);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }
    
    return NULL;
}

int main() {
    financeData.count = 0;
    pthread_mutex_init(&lock, NULL);

    pthread_t menuThread;
    pthread_create(&menuThread, NULL, menu, NULL);
    pthread_join(menuThread, NULL);

    pthread_mutex_destroy(&lock);
    return 0;
}