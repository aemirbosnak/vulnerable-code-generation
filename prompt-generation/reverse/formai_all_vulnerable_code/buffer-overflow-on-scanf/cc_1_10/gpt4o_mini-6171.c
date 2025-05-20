//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LEN 50
#define ACCOUNT_NOT_FOUND -1

typedef struct {
    int id;
    char name[NAME_LEN];
    double balance;
} Account;

Account bank[MAX_ACCOUNTS];
int account_count = 0;

void displayMenu() {
    printf("\n---------- Welcome to the Bank of Humor ----------\n");
    printf("1. Create a new account\n");
    printf("2. Deposit money\n");
    printf("3. Withdraw money\n");
    printf("4. Display account details\n");
    printf("5. Exit\n");
    printf("--------------------------------------------------\n");
    printf("What's your pick?  ");
}

void createAccount() {
    if (account_count >= MAX_ACCOUNTS) {
        printf("Oops! We can't accommodate more silly bank accounts. Try again later!\n");
        return;
    }

    Account new_account;
    new_account.id = account_count + 1; // Simple ID assignment
    printf("Enter your name: ");
    scanf("%s", new_account.name);
    new_account.balance = 0.0;

    bank[account_count] = new_account;
    account_count++;
    printf("Congratulations %s! Your account has been created with ID: %d\n", new_account.name, new_account.id);
}

int findAccount(int id) {
    for (int i = 0; i < account_count; i++) {
        if (bank[i].id == id) {
            return i;
        }
    }
    return ACCOUNT_NOT_FOUND;
}

void depositMoney() {
    int id;
    double amount;
    printf("What’s your account ID? ");
    scanf("%d", &id);

    int index = findAccount(id);
    if (index == ACCOUNT_NOT_FOUND) {
        printf("Account not found! Did you accidentally send your money to a unicorn?\n");
        return;
    }

    printf("How much money do you want to throw into this black hole? ");
    scanf("%lf", &amount);
    if (amount <= 0) {
        printf("Haha! You can't deposit negative or zero money. Seriously?\n");
        return;
    }

    bank[index].balance += amount;
    printf("You just deposited $%.2f, making your new balance $%.2f!\n", amount, bank[index].balance);
}

void withdrawMoney() {
    int id;
    double amount;
    printf("What’s your account ID? ");
    scanf("%d", &id);

    int index = findAccount(id);
    if (index == ACCOUNT_NOT_FOUND) {
        printf("Account not found! Are you trying to rob a bank with an imposter ID?\n");
        return;
    }

    printf("How much money do you want to extract from your mystical account? ");
    scanf("%lf", &amount);
    if (amount <= 0) {
        printf("Come on! You can't withdraw negative or zero money! Are you kidding me?\n");
        return;
    }

    if (amount > bank[index].balance) {
        printf("You can't withdraw that much! You don’t have a magic wand to make more money appear!\n");
        return;
    }

    bank[index].balance -= amount;
    printf("You just withdrew $%.2f. Now you have $%.2f left in your treasure chest!\n", amount, bank[index].balance);
}

void displayAccountDetails() {
    int id;
    printf("What’s your account ID? ");
    scanf("%d", &id);

    int index = findAccount(id);
    if (index == ACCOUNT_NOT_FOUND) {
        printf("Account not found! Did you feed the ID to a hungry dragon?\n");
        return;
    }

    printf("Account ID: %d\n", bank[index].id);
    printf("Account Holder: %s\n", bank[index].name);
    printf("Current Balance: $%.2f\n", bank[index].balance);
}

int main() {
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                displayAccountDetails();
                break;
            case 5:
                printf("Thanks for visiting the Bank of Humor! Remember, if you can't laugh about your finances, you're doing it wrong!\n");
                break;
            default:
                printf("Silly choice! Please pick a number between 1 and 5. Not counting your pet goldfish, of course!\n");
        }
    } while (choice != 5);

    return 0;
}