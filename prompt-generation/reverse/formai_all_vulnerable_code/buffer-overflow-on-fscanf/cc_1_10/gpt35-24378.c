//FormAI DATASET v1.0 Category: Password management ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char account[20];
    char username[20];
    char password[20];
} Account;

void saveAccount(Account accounts[], int index) {
    FILE *file = fopen("passwords.txt", "a+");
    fprintf(file, "%s %s %s\n", accounts[index].account, accounts[index].username, accounts[index].password);
    fclose(file);
}

void retrieveAccounts() {
    FILE *file = fopen("passwords.txt", "r");
    char account[20];
    char username[20];
    char password[20];
    while (fscanf(file, "%s %s %s", account, username, password) != EOF) {
        printf("Account: %s\nUsername: %s\nPassword: %s\n\n", account, username, password);
    }
    fclose(file);
}

int main() {
    Account accounts[10];
    char input[20];
    int accountIndex = 0;
    printf("My love, what would you like to do today?\n1. Store a new password\n2. Retrieve a stored password\n");

    while (1) {
        printf("Enter your choice, my love: ");
        fgets(input, 20, stdin);
        input[strcspn(input, "\n")] = 0;
        if (strcmp(input, "1") == 0) {
            printf("For which account would you like to store a password, my love?\n");
            fgets(accounts[accountIndex].account, 20, stdin);
            accounts[accountIndex].account[strcspn(accounts[accountIndex].account, "\n")] = 0;
            
            printf("What is the username for this account, my dear?\n");
            fgets(accounts[accountIndex].username, 20, stdin);
            accounts[accountIndex].username[strcspn(accounts[accountIndex].username, "\n")] = 0;
            
            printf("And what is the password for this account, my heart?\n");
            fgets(accounts[accountIndex].password, 20, stdin);
            accounts[accountIndex].password[strcspn(accounts[accountIndex].password, "\n")] = 0;

            saveAccount(accounts, accountIndex);
            printf("The password has been stored, my love.\n\n");
            accountIndex++;
        }
        else if (strcmp(input, "2") == 0) {
            printf("Which account's password would you like to retrieve, my love?\n");
            retrieveAccounts();
        }
        else {
            printf("You have entered an invalid choice, my love.\n");
        }
    }
    return 0;
}