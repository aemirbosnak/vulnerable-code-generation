//Falcon2-11B DATASET v1.0 Category: Personal Finance Planner ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

typedef struct {
    int id;
    int balance;
    int transactions[10];
} Account;

pthread_mutex_t lock;

void *transfer(void *arg) {
    Account *account = (Account *)arg;
    int amount = 100;
    int source_index = 3;
    int dest_index = 2;

    pthread_mutex_lock(&lock);
    account->balance -= amount;
    account->transactions[source_index] -= amount;
    account->transactions[dest_index] += amount;
    pthread_mutex_unlock(&lock);
}

int main() {
    Account accounts[3];
    for (int i = 0; i < 3; i++) {
        accounts[i].id = i;
        accounts[i].balance = 1000;
        accounts[i].transactions[i] = 500;
    }

    pthread_t threads[3];
    for (int i = 0; i < 3; i++) {
        Account *account = &accounts[i];
        pthread_create(&threads[i], NULL, transfer, account);
    }

    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < 3; i++) {
        printf("Account %d balance: %d\n", accounts[i].id, accounts[i].balance);
        for (int j = 0; j < 10; j++) {
            printf("Transaction %d: %d\n", j, accounts[i].transactions[j]);
        }
    }

    return 0;
}