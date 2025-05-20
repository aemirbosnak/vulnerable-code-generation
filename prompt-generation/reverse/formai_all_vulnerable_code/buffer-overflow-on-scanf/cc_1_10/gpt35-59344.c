//FormAI DATASET v1.0 Category: Password management ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_PASSWORD_LENGTH 256

typedef struct Account {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Account;

// Function prototypes
void load_accounts(Account accounts[], int *num_accounts);
void save_accounts(Account accounts[], int num_accounts);
void add_account(Account accounts[], int *num_accounts);
void delete_account(Account accounts[], int *num_accounts);
void list_accounts(Account accounts[], int num_accounts);
void change_password(Account accounts[], int num_accounts);
void login(Account accounts[], int num_accounts);

int main() {
    Account accounts[MAX_ACCOUNTS];
    int num_accounts = 0;
    int choice;
    load_accounts(accounts, &num_accounts);
    while (1) {
        printf("Password Manager Menu\n");
        printf("1. Add account\n");
        printf("2. Delete account\n");
        printf("3. List accounts\n");
        printf("4. Change password\n");
        printf("5. Login\n");
        printf("6. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_account(accounts, &num_accounts);
                break;
            case 2:
                delete_account(accounts, &num_accounts);
                break;
            case 3:
                list_accounts(accounts, num_accounts);
                break;
            case 4:
                change_password(accounts, num_accounts);
                break;
            case 5:
                login(accounts, num_accounts);
                break;
            case 6:
                save_accounts(accounts, num_accounts);
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

void load_accounts(Account accounts[], int *num_accounts) {
    FILE *file = fopen("accounts.txt", "r");
    if (file == NULL) {
        printf("Could not open file\n");
        return;
    }
    char buffer[MAX_PASSWORD_LENGTH * 2];
    char *username, *password;
    while (fgets(buffer, MAX_PASSWORD_LENGTH * 2, file) != NULL) {
        if (buffer[0] != '\n') {
            username = strtok(buffer, ":");
            password = strtok(NULL, ":");
            strcpy(accounts[*num_accounts].username, username);
            strcpy(accounts[*num_accounts].password, password);
            *num_accounts += 1;
        }
    }
    fclose(file);
}

void save_accounts(Account accounts[], int num_accounts) {
    FILE *file = fopen("accounts.txt", "w");
    if (file == NULL) {
        printf("Could not open file\n");
        return;
    }
    for (int i = 0; i < num_accounts; i++) {
        fprintf(file, "%s:%s\n", accounts[i].username, accounts[i].password);
    }
    fclose(file);
}

void add_account(Account accounts[], int *num_accounts) {
    printf("Enter username: ");
    scanf("%s", accounts[*num_accounts].username);
    printf("Enter password: ");
    scanf("%s", accounts[*num_accounts].password);
    *num_accounts += 1;
}

void delete_account(Account accounts[], int *num_accounts) {
    char username[MAX_PASSWORD_LENGTH];
    printf("Enter username to delete: ");
    scanf("%s", username);
    for (int i = 0; i < *num_accounts; i++) {
        if (strcmp(accounts[i].username, username) == 0) {
            for (int j = i; j < *num_accounts - 1; j++) {
                accounts[j] = accounts[j + 1];
            }
            *num_accounts -= 1;
            return;
        }
    }
    printf("Username not found\n");
}

void list_accounts(Account accounts[], int num_accounts) {
    for (int i = 0; i < num_accounts; i++) {
        printf("%s\n", accounts[i].username);
    }
}

void change_password(Account accounts[], int num_accounts) {
    char username[MAX_PASSWORD_LENGTH], current_password[MAX_PASSWORD_LENGTH], new_password[MAX_PASSWORD_LENGTH];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter current password: ");
    scanf("%s", current_password);
    printf("Enter new password: ");
    scanf("%s", new_password);
    for (int i = 0; i < num_accounts; i++) {
        if (strcmp(accounts[i].username, username) == 0) {
            if (strcmp(accounts[i].password, current_password) == 0) {
                strcpy(accounts[i].password, new_password);
                printf("Password changed successfully\n");
                return;
            } else {
                printf("Incorrect password\n");
                return;
            }
        }
    }
    printf("Username not found\n");
}

void login(Account accounts[], int num_accounts) {
    char username[MAX_PASSWORD_LENGTH], password[MAX_PASSWORD_LENGTH];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    for (int i = 0; i < num_accounts; i++) {
        if (strcmp(accounts[i].username, username) == 0) {
            if (strcmp(accounts[i].password, password) == 0) {
                printf("Login successful\n");
                return;
            } else {
                printf("Incorrect password\n");
                return;
            }
        }
    }
    printf("Username not found\n");
}