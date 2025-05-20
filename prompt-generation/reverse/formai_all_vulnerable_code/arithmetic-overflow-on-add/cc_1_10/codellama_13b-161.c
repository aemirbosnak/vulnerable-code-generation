//Code Llama-13B DATASET v1.0 Category: Banking Record System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_CLIENTS 100
#define MAX_TRANSACTIONS 1000

typedef struct {
    int client_id;
    int account_id;
    int amount;
} Transaction;

typedef struct {
    int balance;
    int num_transactions;
    Transaction transactions[MAX_TRANSACTIONS];
} Account;

typedef struct {
    int client_id;
    int account_id;
    Account *account;
} Client;

typedef struct {
    Client clients[MAX_CLIENTS];
    int num_clients;
    pthread_mutex_t mutex;
} Bank;

void init_bank(Bank *bank) {
    bank->num_clients = 0;
    pthread_mutex_init(&bank->mutex, NULL);
}

void add_client(Bank *bank, int client_id, int account_id) {
    pthread_mutex_lock(&bank->mutex);
    bank->clients[bank->num_clients].client_id = client_id;
    bank->clients[bank->num_clients].account_id = account_id;
    bank->clients[bank->num_clients].account = NULL;
    bank->num_clients++;
    pthread_mutex_unlock(&bank->mutex);
}

void deposit(Bank *bank, int client_id, int account_id, int amount) {
    pthread_mutex_lock(&bank->mutex);
    int i;
    for (i = 0; i < bank->num_clients; i++) {
        if (bank->clients[i].client_id == client_id && bank->clients[i].account_id == account_id) {
            if (bank->clients[i].account == NULL) {
                bank->clients[i].account = malloc(sizeof(Account));
                bank->clients[i].account->balance = 0;
                bank->clients[i].account->num_transactions = 0;
            }
            bank->clients[i].account->balance += amount;
            bank->clients[i].account->num_transactions++;
            pthread_mutex_unlock(&bank->mutex);
            return;
        }
    }
    pthread_mutex_unlock(&bank->mutex);
    fprintf(stderr, "Error: Client %d and account %d not found.\n", client_id, account_id);
}

void withdraw(Bank *bank, int client_id, int account_id, int amount) {
    pthread_mutex_lock(&bank->mutex);
    int i;
    for (i = 0; i < bank->num_clients; i++) {
        if (bank->clients[i].client_id == client_id && bank->clients[i].account_id == account_id) {
            if (bank->clients[i].account == NULL) {
                pthread_mutex_unlock(&bank->mutex);
                fprintf(stderr, "Error: Account %d does not exist.\n", account_id);
                return;
            }
            if (bank->clients[i].account->balance < amount) {
                pthread_mutex_unlock(&bank->mutex);
                fprintf(stderr, "Error: Insufficient balance.\n");
                return;
            }
            bank->clients[i].account->balance -= amount;
            bank->clients[i].account->num_transactions++;
            pthread_mutex_unlock(&bank->mutex);
            return;
        }
    }
    pthread_mutex_unlock(&bank->mutex);
    fprintf(stderr, "Error: Client %d and account %d not found.\n", client_id, account_id);
}

void print_account_info(Bank *bank, int client_id, int account_id) {
    pthread_mutex_lock(&bank->mutex);
    int i;
    for (i = 0; i < bank->num_clients; i++) {
        if (bank->clients[i].client_id == client_id && bank->clients[i].account_id == account_id) {
            if (bank->clients[i].account == NULL) {
                pthread_mutex_unlock(&bank->mutex);
                fprintf(stderr, "Error: Account %d does not exist.\n", account_id);
                return;
            }
            printf("Account %d: Balance = %d, Num transactions = %d\n", account_id, bank->clients[i].account->balance, bank->clients[i].account->num_transactions);
            pthread_mutex_unlock(&bank->mutex);
            return;
        }
    }
    pthread_mutex_unlock(&bank->mutex);
    fprintf(stderr, "Error: Client %d and account %d not found.\n", client_id, account_id);
}

int main() {
    Bank bank;
    init_bank(&bank);
    add_client(&bank, 1, 100);
    deposit(&bank, 1, 100, 1000);
    deposit(&bank, 1, 100, 2000);
    withdraw(&bank, 1, 100, 500);
    print_account_info(&bank, 1, 100);
    return 0;
}