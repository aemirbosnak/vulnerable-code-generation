//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_ACCOUNTS 10
#define MAX_THREADS 20

typedef struct {
    int account_number;
    char account_name[50];
    double balance;
} Account;

typedef struct {
    int thread_id;
    Account accounts[MAX_ACCOUNTS];
    int num_accounts;
} ThreadData;

void *thread_function(void *data) {
    ThreadData *thread_data = (ThreadData *) data;
    int i;

    for (i = 0; i < thread_data->num_accounts; i++) {
        Account *account = &thread_data->accounts[i];
        account->balance += 0.01; // simulate interest earned
    }

    return NULL;
}

int main() {
    int i, num_threads;
    pthread_t threads[MAX_THREADS];
    ThreadData thread_data[MAX_THREADS];

    printf("Enter number of accounts: ");
    scanf("%d", &num_threads);

    printf("Enter account details:\n");
    for (i = 0; i < num_threads; i++) {
        Account account;
        printf("Account number: ");
        scanf("%d", &account.account_number);
        printf("Account name: ");
        scanf("%s", account.account_name);
        printf("Initial balance: ");
        scanf("%lf", &account.balance);

        thread_data[i].accounts[i] = account;
        thread_data[i].num_accounts++;
    }

    for (i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, thread_function, (void *) &thread_data[i]);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Final account balances:\n");
    for (i = 0; i < num_threads; i++) {
        Account *account = &thread_data[i].accounts[0];
        printf("Account %d: $%.2lf\n", account->account_number, account->balance);
    }

    return 0;
}