//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50

typedef struct {
    int accountNumber;
    char name[NAME_LENGTH];
    float balance;
} Account;

Account bankAccounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount();
void deposit();
void withdraw();
void viewAccount();
void showMenu();

int main() {
    int option;
    printf("\n🌟 Welcome to Cheerful Banking Record System! 🌟\n");
    
    do {
        showMenu();
        printf("Please enter your choice (1-5): ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                createAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                viewAccount();
                break;
            case 5:
                printf("Exiting... Thank you for using the Cheerful Banking System! 🎉\n");
                break;
            default:
                printf("Oops! That's not a valid option. Please try again. 😊\n");
        }
    } while (option != 5);
    
    return 0;
}

void showMenu() {
    printf("\n*** Menu ***\n");
    printf("1. Create Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. View Account Details\n");
    printf("5. Exit\n");
}

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Sorry, we can't create any more accounts right now. 🌧️\n");
        return;
    }
    
    Account newAccount;
    printf("Enter your name: ");
    scanf(" %[^\n]", newAccount.name);
    newAccount.accountNumber = accountCount + 1;
    newAccount.balance = 0.0;

    bankAccounts[accountCount] = newAccount;
    accountCount++;

    printf("🎉 Congratulations %s! Your account has been created with Account Number: %d\n", newAccount.name, newAccount.accountNumber);
}

void deposit() {
    int accountNumber;
    float amount;

    printf("Enter your Account Number: ");
    scanf("%d", &accountNumber);
    
    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Account not found! Please check the number and try again. 😞\n");
        return;
    }

    printf("Enter deposit amount: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Deposit amount must be positive! Please try again. 😅\n");
        return;
    }

    bankAccounts[accountNumber - 1].balance += amount;
    printf("💰 Success! You've deposited $%.2f into your account. Current balance: $%.2f\n", amount, bankAccounts[accountNumber - 1].balance);
}

void withdraw() {
    int accountNumber;
    float amount;

    printf("Enter your Account Number: ");
    scanf("%d", &accountNumber);
    
    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Account not found! Please check the number and try again. 😞\n");
        return;
    }

    printf("Enter withdrawal amount: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Withdrawal amount must be positive! Please try again. 😅\n");
        return;
    }

    if (amount > bankAccounts[accountNumber - 1].balance) {
        printf("Insufficient funds! You currently have $%.2f in your account. 😥\n", bankAccounts[accountNumber - 1].balance);
        return;
    }

    bankAccounts[accountNumber - 1].balance -= amount;
    printf("🎈 Hooray! You've withdrawn $%.2f from your account. Remaining balance: $%.2f\n", amount, bankAccounts[accountNumber - 1].balance);
}

void viewAccount() {
    int accountNumber;

    printf("Enter your Account Number: ");
    scanf("%d", &accountNumber);
    
    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Account not found! Please check the number and try again. 😞\n");
        return;
    }

    Account acc = bankAccounts[accountNumber - 1];
    printf("🎊 Account Details 🎊\n");
    printf("Account Number: %d\n", acc.accountNumber);
    printf("Account Holder: %s\n", acc.name);
    printf("Current Balance: $%.2f\n", acc.balance);
}