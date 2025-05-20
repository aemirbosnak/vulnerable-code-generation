//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

int account_balance = 1000;

void *withdraw_money(void *arg) {
    int amount;
    printf("Enter the amount you want to withdraw: ");
    scanf("%d", &amount);

    if (amount > account_balance) {
        printf("Insufficient funds.\n");
    } else {
        account_balance -= amount;
        printf("Withdrawal successful.\n");
    }

    return NULL;
}

void *deposit_money(void *arg) {
    int amount;
    printf("Enter the amount you want to deposit: ");
    scanf("%d", &amount);

    account_balance += amount;
    printf("Deposit successful.\n");

    return NULL;
}

void *check_balance(void *arg) {
    printf("Current account balance: $%d\n", account_balance);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        int rc;

        if (i % 2 == 0) {
            rc = pthread_create(&threads[i], NULL, withdraw_money, NULL);
        } else {
            rc = pthread_create(&threads[i], NULL, deposit_money, NULL);
        }

        if (rc) {
            printf("Error: unable to create thread, %d\n", rc);
            exit(-1);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}