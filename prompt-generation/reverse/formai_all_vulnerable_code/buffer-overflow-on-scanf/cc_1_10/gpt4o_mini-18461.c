//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50
#define PASSWORD_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    char password[PASSWORD_LENGTH];
    double balance;
    int account_number;
    int is_active;
} Account;

Account accounts[MAX_ACCOUNTS];
int account_count = 0;

void create_account() {
    if (account_count >= MAX_ACCOUNTS) {
        printf("Maximum account limit reached.\n");
        return;
    }

    Account new_account;
    printf("Enter your name: ");
    getchar(); // Clear the newline character left by the previous input
    fgets(new_account.name, NAME_LENGTH, stdin);
    new_account.name[strcspn(new_account.name, "\n")] = '\0'; // Remove newline

    printf("Set a password: ");
    fgets(new_account.password, PASSWORD_LENGTH, stdin);
    new_account.password[strcspn(new_account.password, "\n")] = '\0'; // Remove newline

    new_account.balance = 0.0;
    new_account.account_number = account_count + 1; // Simple account number generation
    new_account.is_active = 1; // Activate the account

    accounts[account_count] = new_account;
    account_count++;

    printf("Account created successfully! Your account number is: %d\n", new_account.account_number);
}

int authenticate(int account_number, char *password) {
    if (account_number < 1 || account_number > account_count) {
        return 0; // Account does not exist
    }
    if (strcmp(accounts[account_number - 1].password, password) == 0) {
        return 1; // Authentication successful
    }
    return 0; // Authentication failed
}

void deposit(int account_number) {
    double amount;
    printf("Enter amount to deposit: ");
    scanf("%lf", &amount);
    if (amount <= 0) {
        printf("Invalid deposit amount.\n");
        return;
    }
    accounts[account_number - 1].balance += amount;
    printf("Successfully deposited $%.2lf. New balance: $%.2lf\n", amount, accounts[account_number - 1].balance);
}

void withdraw(int account_number) {
    double amount;
    printf("Enter amount to withdraw: ");
    scanf("%lf", &amount);
    if (amount <= 0 || amount > accounts[account_number - 1].balance) {
        printf("Invalid withdrawal amount.\n");
        return;
    }
    accounts[account_number - 1].balance -= amount;
    printf("Successfully withdrew $%.2lf. New balance: $%.2lf\n", amount, accounts[account_number - 1].balance);
}

void display_balance(int account_number) {
    printf("Current balance: $%.2lf\n", accounts[account_number - 1].balance);
}

void menu() {
    printf("********* Banking System *********\n");
    printf("1. Create Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Check Balance\n");
    printf("5. Exit\n");
    printf("**********************************\n");
}

int main() {
    int choice;
    while (1) {
        menu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_account();
                break;
            case 2: {
                int account_number;
                char password[PASSWORD_LENGTH];
                printf("Enter account number: ");
                scanf("%d", &account_number);
                printf("Enter password: ");
                getchar(); // Clear the newline character left by the previous input
                fgets(password, PASSWORD_LENGTH, stdin);
                password[strcspn(password, "\n")] = '\0'; // Remove newline

                if (authenticate(account_number, password)) {
                    deposit(account_number);
                } else {
                    printf("Authentication failed.\n");
                }
                break;
            }
            case 3: {
                int account_number;
                char password[PASSWORD_LENGTH];
                printf("Enter account number: ");
                scanf("%d", &account_number);
                printf("Enter password: ");
                getchar(); // Clear the newline character left by the previous input
                fgets(password, PASSWORD_LENGTH, stdin);
                password[strcspn(password, "\n")] = '\0'; // Remove newline

                if (authenticate(account_number, password)) {
                    withdraw(account_number);
                } else {
                    printf("Authentication failed.\n");
                }
                break;
            }
            case 4: {
                int account_number;
                char password[PASSWORD_LENGTH];
                printf("Enter account number: ");
                scanf("%d", &account_number);
                printf("Enter password: ");
                getchar(); // Clear the newline character left by the previous input
                fgets(password, PASSWORD_LENGTH, stdin);
                password[strcspn(password, "\n")] = '\0'; // Remove newline

                if (authenticate(account_number, password)) {
                    display_balance(account_number);
                } else {
                    printf("Authentication failed.\n");
                }
                break;
            }
            case 5:
                printf("Thank you for using the Banking System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}