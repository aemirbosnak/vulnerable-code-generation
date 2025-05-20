//FormAI DATASET v1.0 Category: Password management ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 10
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 30

struct Account {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

void clear_console() {
    #ifdef WINDOWS
        system("cls");
    #else
        system("clear");
    #endif
}

void input_username(char* username) {
    printf("Enter username: ");
    scanf("%s", username);
}

void input_password(char* password) {
    printf("Enter password: ");
    scanf("%s", password);
}

int find_account(struct Account accounts[], int num_accounts, char* username) {
    int i;
    for (i = 0; i < num_accounts; i++) {
        if (strcmp(accounts[i].username, username) == 0) {
            return i;
        }
    }
    return -1;
}

void add_account(struct Account accounts[], int* num_accounts, char* username, char* password) {
    if (*num_accounts >= MAX_ACCOUNTS) {
        printf("Cannot add account: maximum number of accounts reached\n");
        return;
    }
    strcpy(accounts[*num_accounts].username, username);
    strcpy(accounts[*num_accounts].password, password);
    *num_accounts += 1;
    printf("Account added successfully\n");
}

void change_password(struct Account accounts[], int num_accounts, char* username, char* password) {
    int index = find_account(accounts, num_accounts, username);
    if (index == -1) {
        printf("Could not find account with username %s\n", username);
        return;
    }
    strcpy(accounts[index].password, password);
    printf("Password changed successfully\n");
}

void authenticate(struct Account accounts[], int num_accounts) {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    input_username(username);
    input_password(password);
    int index = find_account(accounts, num_accounts, username);
    if (index == -1) {
        printf("Authentication failed: username or password incorrect\n");
        return;
    }
    if (strcmp(accounts[index].password, password) == 0) {
        printf("Authentication successful\n");
    } else {
        printf("Authentication failed: username or password incorrect\n");
    }
}

int main() {
    struct Account accounts[MAX_ACCOUNTS];
    int num_accounts = 0;
    char command;
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    clear_console();
    while (1) {
        printf("Enter command:\n");
        printf("a: add account\n");
        printf("c: change password\n");
        printf("g: authenticate\n");
        printf("q: quit\n");
        scanf(" %c", &command);
        switch (command) {
            case 'a':
                input_username(username);
                input_password(password);
                add_account(accounts, &num_accounts, username, password);
                break;
            case 'c':
                input_username(username);
                input_password(password);
                change_password(accounts, num_accounts, username, password);
                break;
            case 'g':
                authenticate(accounts, num_accounts);
                break;
            case 'q':
                exit(0);
            default:
                printf("Invalid command\n");
                break;
        }
        clear_console();
    }

    return 0;
}