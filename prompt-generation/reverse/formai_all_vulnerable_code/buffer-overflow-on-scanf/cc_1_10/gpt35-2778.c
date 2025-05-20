//FormAI DATASET v1.0 Category: Password management ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 1000
#define MAX_LEN 50

typedef struct Account {
    char username[MAX_LEN];
    char password[MAX_LEN];
} Account;

// Function prototypes
void addAccount(Account accounts[], int *numAccounts);
void searchAccount(Account accounts[], int numAccounts, char *username);
void printAccounts(Account accounts[], int numAccounts);
void saveToFile(Account accounts[], int numAccounts);

int main() {
    Account accounts[MAX_ACCOUNTS];
    int numAccounts = 0;
    char choice;

    do {
        printf("\nPassword management system\n");
        printf("----------------------------\n");
        printf("1. Add account\n");
        printf("2. Search account\n");
        printf("3. Print all accounts\n");
        printf("4. Save to file\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                addAccount(accounts, &numAccounts);
                break;
            case '2':
                printf("\nEnter username to search: ");
                char searchUsername[MAX_LEN];
                scanf("%s", searchUsername);
                searchAccount(accounts, numAccounts, searchUsername);
                break;
            case '3':
                printAccounts(accounts, numAccounts);
                break;
            case '4':
                saveToFile(accounts, numAccounts);
                break;
            case '5':
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nPlease enter a valid choice.\n");
        }
    } while (choice != '5');

    return 0;
}

void addAccount(Account accounts[], int *numAccounts) {
    if (*numAccounts == MAX_ACCOUNTS) {
        printf("\nMaximum number of accounts exceeded.\n");
        return;
    }

    Account newAccount;
    printf("\nEnter username: ");
    scanf("%s", newAccount.username);
    printf("Enter password: ");
    scanf("%s", newAccount.password);

    accounts[*numAccounts] = newAccount;
    (*numAccounts)++;

    printf("\nAccount added successfully.\n");
}

void searchAccount(Account accounts[], int numAccounts, char *username) {
    for (int i = 0; i < numAccounts; i++) {
        if (strcmp(accounts[i].username, username) == 0) {
            printf("\nUsername: %s\nPassword: %s\n", accounts[i].username, accounts[i].password);
            return;
        }
    }

    printf("\nAccount not found.\n");
}

void printAccounts(Account accounts[], int numAccounts) {
    if (numAccounts == 0) {
        printf("\nNo accounts to print.\n");
        return;
    }

    printf("\nAccounts:\n");
    for (int i = 0; i < numAccounts; i++) {
        printf("%d. Username: %s  Password: %s\n", i+1, accounts[i].username, accounts[i].password);
    }
}

void saveToFile(Account accounts[], int numAccounts) {
    if (numAccounts == 0) {
        printf("\nNo accounts to save.\n");
        return;
    }

    FILE *file = fopen("passwords.txt", "w");
    if (file == NULL) {
        printf("\nError opening file.\n");
        return;
    }

    for (int i = 0; i < numAccounts; i++) {
        fprintf(file, "%s,%s\n", accounts[i].username, accounts[i].password);
    }

    fclose(file);
    printf("\nAccounts saved to file.\n");
}