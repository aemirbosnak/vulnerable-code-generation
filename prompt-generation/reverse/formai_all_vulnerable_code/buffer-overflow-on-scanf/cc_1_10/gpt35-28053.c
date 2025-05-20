//FormAI DATASET v1.0 Category: Banking Record System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ACCOUNT_MAX 10
#define NAME_MAX 20
#define PASSWORD_MAX 20

typedef struct {
    int id;
    char name[NAME_MAX];
    double balance;
    char password[PASSWORD_MAX];
} Account;

int accounts_count = 0;
Account accounts[ACCOUNT_MAX];

void clear_screen() {
    system("cls || clear");
}

void add_account() {
    clear_screen();

    if (accounts_count >= ACCOUNT_MAX) {
        printf("Sorry, you can't add more accounts!\n");
        return;
    }

    Account account;
    printf("Creating a new account...\n");
    printf("Enter your name: ");
    scanf("%s", account.name);
    printf("Enter your password: ");
    scanf("%s", account.password);
    account.balance = 0.0;
    account.id = accounts_count + 1;

    accounts[accounts_count++] = account;

    printf("\nAccount created successfully!\n");
    printf("Your account id is: %d\n", account.id);
}

void deposit() {
    clear_screen();

    if (accounts_count == 0) {
        printf("Sorry, there are no accounts available!\n");
        return;
    }

    int id;
    char password[PASSWORD_MAX];
    double amount;
    printf("Making a deposit...\n");
    printf("Enter your account id: ");
    scanf("%d", &id);
    printf("Enter your password: ");
    scanf("%s", password);

    Account *account = NULL;
    for (int i = 0; i < accounts_count; i++) {
        Account *acc = &accounts[i];
        if (acc->id == id && strcmp(acc->password, password) == 0) {
            account = acc;
            break;
        }
    }

    if (account == NULL) {
        printf("\nInvalid account id or password!\n");
        return;
    }

    printf("Enter the amount to deposit: ");
    scanf("%lf", &amount);
    account->balance += amount;

    printf("\nDeposit made successfully!\n");
    printf("New balance: %.2lf\n", account->balance);
}

void withdrawal() {
    clear_screen();

    if (accounts_count == 0) {
        printf("Sorry, there are no accounts available!\n");
        return;
    }

    int id;
    char password[PASSWORD_MAX];
    double amount;
    printf("Making a withdrawal...\n");
    printf("Enter your account id: ");
    scanf("%d", &id);
    printf("Enter your password: ");
    scanf("%s", password);

    Account *account = NULL;
    for (int i = 0; i < accounts_count; i++) {
        Account *acc = &accounts[i];
        if (acc->id == id && strcmp(acc->password, password) == 0) {
            account = acc;
            break;
        }
    }

    if (account == NULL) {
        printf("\nInvalid account id or password!\n");
        return;
    }

    printf("Enter the amount to withdraw: ");
    scanf("%lf", &amount);
    if (account->balance >= amount) {
        account->balance -= amount;
        printf("\nWithdrawal made successfully!\n");
        printf("New balance: %.2lf\n", account->balance);
    } else {
        printf("\nInsufficient funds!\n");
    }
}

void print_accounts() {
    clear_screen();

    if (accounts_count == 0) {
        printf("Sorry, there are no accounts available!\n");
        return;
    }

    printf("List of accounts:\n");
    printf("ID\tName\t\tBalance\n");

    for (int i = 0; i < accounts_count; i++) {
        Account *account = &accounts[i];
        printf("%d\t%s\t\t%.2lf\n", account->id, account->name, account->balance);
    }
}

int main() {
    int option = 0;
    do {
        clear_screen();

        printf("Welcome to the mind-bending banking record system!\n");
        printf("Choose an option below:\n");
        printf("1. Add account\n");
        printf("2. Make a deposit\n");
        printf("3. Make a withdrawal\n");
        printf("4. Print accounts\n");
        printf("5. Exit\n");
        printf("Option: ");
        scanf("%d", &option);

        switch (option) {
            case 1: add_account(); break;
            case 2: deposit(); break;
            case 3: withdrawal(); break;
            case 4: print_accounts(); break;
            case 5:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid option!\n");
                break;
        }

        printf("Press Enter key to continue...");
        getchar(); getchar();
    } while (option != 5);

    return 0;
}