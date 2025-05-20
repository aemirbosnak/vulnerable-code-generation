//FormAI DATASET v1.0 Category: Password management ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LEN 20
#define MAX_USERNAME_LEN 20
#define MAX_ACCOUNTS 10

typedef struct {
    char username[MAX_USERNAME_LEN];
    char password[MAX_PASSWORD_LEN];
} Account;

typedef struct {
    int num_accounts;
    Account accounts[MAX_ACCOUNTS];
} AccountDatabase;

void add_account(AccountDatabase *db, char *username, char *password) {
    if (db->num_accounts < MAX_ACCOUNTS) {
        Account *account = &db->accounts[db->num_accounts++];
        strcpy(account->username, username);
        strcpy(account->password, password);
        printf("Account added successfully.\n");
    }
    else {
        printf("Account database full, unable to add account.\n");
    }
}

void list_accounts(AccountDatabase *db) {
    printf("Account database:\n");
    for (int i = 0; i < db->num_accounts; i++) {
        Account *account = &db->accounts[i];
        printf("%s\t%s\n", account->username, account->password);
    }
}

void save_database(AccountDatabase *db, FILE *file) {
    fwrite(&db->num_accounts, sizeof(db->num_accounts), 1, file);
    fwrite(&db->accounts, sizeof(db->accounts[0]), db->num_accounts, file);
    printf("Account database saved successfully.\n");
}

void load_database(AccountDatabase *db, FILE *file) {
    fread(&db->num_accounts, sizeof(db->num_accounts), 1, file);
    fread(&db->accounts, sizeof(db->accounts[0]), db->num_accounts, file);
    printf("Account database loaded successfully.\n");
}

int main() {
    AccountDatabase db = {0};
    
    // load database from file (if it exists)
    FILE *file = fopen("accounts.dat", "rb");
    if (file) {
        load_database(&db, file);
        fclose(file);
    }
    
    // main loop
    char command[10];
    while (1) {
        printf("\nCommands: add, list, save, exit\n");
        printf("> ");
        fflush(stdout);
        fgets(command, sizeof(command), stdin);
        command[strlen(command)-1] = '\0';  // remove newline
        
        if (strcmp(command, "add") == 0) {
            char username[MAX_USERNAME_LEN];
            char password[MAX_PASSWORD_LEN];
            printf("Enter username: ");
            fflush(stdout);
            fgets(username, sizeof(username), stdin);
            username[strlen(username)-1] = '\0';  // remove newline
            printf("Enter password: ");
            fflush(stdout);
            fgets(password, sizeof(password), stdin);
            password[strlen(password)-1] = '\0';  // remove newline
            add_account(&db, username, password);
        }
        else if (strcmp(command, "list") == 0) {
            list_accounts(&db);
        }
        else if (strcmp(command, "save") == 0) {
            file = fopen("accounts.dat", "wb");
            if (file) {
                save_database(&db, file);
                fclose(file);
            }
            else {
                printf("Error: could not open file for writing.\n");
            }
        }
        else if (strcmp(command, "exit") == 0) {
            break;
        }
        else {
            printf("Unknown command: %s\n", command);
        }
    }
    
    return 0;
}