//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define USERNAME_LEN 32
#define PASSWORD_LEN 32
#define NAME_LEN 64

typedef struct {
    char username[USERNAME_LEN];
    char password[PASSWORD_LEN];
    char name[NAME_LEN];
    double balance;
    int active;
} Account;

Account accounts[MAX_ACCOUNTS];
int account_count = 0;

void displayMenu() {
    printf("\n--- Cyber Bank ---\n");
    printf("1. Create Account\n");
    printf("2. Login\n");
    printf("3. Exit\n");
    printf("Select an option: ");
}

void createAccount() {
    if (account_count >= MAX_ACCOUNTS) {
        printf("Max account limit reached!\n");
        return;
    }
    Account new_account;
    printf("Enter Username: ");
    scanf("%s", new_account.username);
    printf("Enter Password: ");
    scanf("%s", new_account.password);
    printf("Enter Name: ");
    scanf(" %[^\n]", new_account.name);
    new_account.balance = 0.0;
    new_account.active = 1; // Account active by default

    accounts[account_count] = new_account;
    account_count++;
    printf("Account created successfully!\n");
}

int login(char* username, char* password) {
    for (int i = 0; i < account_count; i++) {
        if (strcmp(accounts[i].username, username) == 0 &&
            strcmp(accounts[i].password, password) == 0 &&
            accounts[i].active) {
            return i; // Return index of the account
        }
    }
    return -1; // Login failed
}

void accountMenu(int idx) {
    int choice;
    double amount;

    do {
        printf("\n--- User Account Menu for %s ---\n", accounts[idx].name);
        printf("1. Check Balance\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Logout\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Current Balance: %.2f\n", accounts[idx].balance);
                break;
            case 2:
                printf("Enter Deposit Amount: ");
                scanf("%lf", &amount);
                if (amount < 0) {
                    printf("Invalid deposit amount!\n");
                } else {
                    accounts[idx].balance += amount;
                    printf("Successfully deposited %.2f. New Balance: %.2f\n", amount, accounts[idx].balance);
                }
                break;
            case 3:
                printf("Enter Withdraw Amount: ");
                scanf("%lf", &amount);
                if (amount < 0 || amount > accounts[idx].balance) {
                    printf("Invalid withdraw amount!\n");
                } else {
                    accounts[idx].balance -= amount;
                    printf("Successfully withdrew %.2f. New Balance: %.2f\n", amount, accounts[idx].balance);
                }
                break;
            case 4:
                printf("Logging out...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 4);
}

int main() {
    int choice;
    char username[USERNAME_LEN], password[PASSWORD_LEN];
    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                printf("Enter Username: ");
                scanf("%s", username);
                printf("Enter Password: ");
                scanf("%s", password);
                int idx = login(username, password);
                if (idx != -1) {
                    accountMenu(idx);
                } else {
                    printf("Login failed! Invalid credentials.\n");
                }
                break;
            case 3:
                printf("Exiting Cyber Bank. Stay safe in Neo-Tokyo!\n");
                return 0;
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    }
    return 0;
}