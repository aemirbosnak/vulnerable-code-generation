//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_LENGTH 50

typedef struct {
    char account[MAX_LENGTH];
    char password[MAX_LENGTH];
} Account;

void add_password(Account accounts[], int *num_accounts) {
    if (*num_accounts >= MAX_ACCOUNTS) {
        printf("Maximum account limit reached!\n");
        return;
    }

    char account[MAX_LENGTH];
    char password[MAX_LENGTH];

    printf("Enter account name: ");
    scanf("%s", account);
    printf("Enter password: ");
    scanf("%s", password);

    strcpy(accounts[*num_accounts].account, account);
    strcpy(accounts[*num_accounts].password, password);
    (*num_accounts)++;
    printf("Password added successfully!\n");
}

void view_passwords(Account accounts[], int num_accounts) {
    if (num_accounts == 0) {
        printf("No passwords stored.\n");
        return;
    }
    printf("\nStored Passwords:\n");
    for (int i = 0; i < num_accounts; i++) {
        printf("Account: %s, Password: %s\n", accounts[i].account, accounts[i].password);
    }
    printf("\n");
}

void delete_password(Account accounts[], int *num_accounts) {
    if (*num_accounts == 0) {
        printf("No passwords to delete.\n");
        return;
    }

    char account[MAX_LENGTH];
    printf("Enter account name to delete: ");
    scanf("%s", account);

    for (int i = 0; i < *num_accounts; i++) {
        if (strcmp(accounts[i].account, account) == 0) {
            for (int j = i; j < *num_accounts - 1; j++) {
                accounts[j] = accounts[j + 1];
            }
            (*num_accounts)--;
            printf("Password for %s deleted successfully!\n", account);
            return;
        }
    }
    printf("Account not found!\n");
}

void save_passwords(Account accounts[], int num_accounts) {
    FILE *file = fopen("passwords.txt", "w");
    if (!file) {
        printf("Could not open file for writing!\n");
        return;
    }
    
    for (int i = 0; i < num_accounts; i++) {
        fprintf(file, "%s %s\n", accounts[i].account, accounts[i].password);
    }
    
    fclose(file);
    printf("Passwords saved to passwords.txt\n");
}

void load_passwords(Account accounts[], int *num_accounts) {
    FILE *file = fopen("passwords.txt", "r");
    if (!file) {
        printf("No saved passwords found.\n");
        return;
    }
    
    while (fscanf(file, "%s %s", accounts[*num_accounts].account, accounts[*num_accounts].password) == 2) {
        (*num_accounts)++;
        if (*num_accounts >= MAX_ACCOUNTS) break;
    }

    fclose(file);
    printf("Passwords loaded successfully!\n");
}

int main() {
    Account accounts[MAX_ACCOUNTS];
    int num_accounts = 0;
    int choice;

    load_passwords(accounts, &num_accounts);

    while (1) {
        printf("\nPassword Manager\n");
        printf("1. Add Account\n");
        printf("2. View Accounts\n");
        printf("3. Delete Account\n");
        printf("4. Save Passwords\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_password(accounts, &num_accounts);
                break;
            case 2:
                view_passwords(accounts, num_accounts);
                break;
            case 3:
                delete_password(accounts, &num_accounts);
                break;
            case 4:
                save_passwords(accounts, num_accounts);
                break;
            case 5:
                save_passwords(accounts, num_accounts); // Save on exit
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}