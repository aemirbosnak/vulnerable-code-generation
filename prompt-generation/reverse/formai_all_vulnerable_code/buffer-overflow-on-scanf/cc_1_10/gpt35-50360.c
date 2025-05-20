//FormAI DATASET v1.0 Category: Password management ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 10
#define MAX_PASSWORD_LENGTH 20

struct Account {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

void encrypt(char *password) {
    // implementation of encryption algorithm goes here
}

void decrypt(char *password) {
    // implementation of decryption algorithm goes here
}

void add_account(struct Account *accounts, int *count) {
    if (*count == MAX_ACCOUNTS) {
        printf("Maximum number of accounts reached.\n");
        return;
    }
    struct Account account;
    printf("Enter username: ");
    fgets(account.username, MAX_PASSWORD_LENGTH, stdin);
    printf("Enter password: ");
    fgets(account.password, MAX_PASSWORD_LENGTH, stdin);
    // encrypt password before storing it
    encrypt(account.password);
    accounts[*count] = account;
    (*count)++;
}

void remove_account(struct Account *accounts, int *count) {
    if (*count == 0) {
        printf("There are no accounts to remove.\n");
        return;
    }
    int index;
    printf("Enter the index of the account to remove: ");
    scanf("%d", &index);
    getchar(); // clear extra newline
    if (index >= *count || index < 0) {
        printf("Invalid index.\n");
        return;
    }
    struct Account account = accounts[index];
    memset(account.username, 0, MAX_PASSWORD_LENGTH);
    memset(account.password, 0, MAX_PASSWORD_LENGTH);
    // decrement count and shift all elements down
    (*count)--;
    for (int i = index; i < *count; i++) {
        accounts[i] = accounts[i+1];
    }
    printf("Removed account: %s\n", account.username);
}

void print_accounts(struct Account *accounts, int count) {
    printf("Accounts:\n");
    for (int i = 0; i < count; i++) {
        struct Account account = accounts[i];
        // decrypt password before printing it
        decrypt(account.password);
        printf("%d. %s | %s", i, account.username, account.password);
        // encrypt password after printing it
        encrypt(account.password);
    }
}

int main() {
    struct Account accounts[MAX_ACCOUNTS];
    int count = 0;
    int running = 1;
    while (running) {
        printf("\nOptions:\n1. Add account\n2. Remove account\n3. Print accounts\n4. Quit\n");
        char input[MAX_PASSWORD_LENGTH];
        fgets(input, MAX_PASSWORD_LENGTH, stdin);
        int option = atoi(input);
        switch (option) {
        case 1:
            add_account(accounts, &count);
            break;
        case 2:
            remove_account(accounts, &count);
            break;
        case 3:
            print_accounts(accounts, count);
            break;
        case 4:
            running = 0;
            break;
        default:
            printf("Invalid option.\n");
            break;
        }
    }
    return 0;
}