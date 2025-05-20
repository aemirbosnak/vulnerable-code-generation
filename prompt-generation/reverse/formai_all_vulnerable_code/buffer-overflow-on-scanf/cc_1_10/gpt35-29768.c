//FormAI DATASET v1.0 Category: Banking Record System ; Style: futuristic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Account {
    char name[50];
    int account_number;
    float balance;
};

typedef struct Account Account;

void addAccount(Account* accounts, int index);
void deposit(Account* account);
void withdraw(Account* account);
void display(Account* account);
void displayAll(Account* accounts, int num_accounts);

int main() {
    int num_accounts = 0;
    int max_accounts = 3;
    Account* accounts = malloc(max_accounts * sizeof(Account));

    int menu_choice;
    do {
        printf("\nWelcome to the C Banking Record System!");
        printf("\n1. Add an account");
        printf("\n2. Deposit to an account");
        printf("\n3. Withdraw from an account");
        printf("\n4. Display an account");
        printf("\n5. Display all accounts");
        printf("\n6. Exit");
        printf("\n\nEnter menu choice: ");
        scanf("%d", &menu_choice);

        switch (menu_choice) {
            case 1:
                addAccount(accounts, num_accounts);
                num_accounts++;
                if (num_accounts == max_accounts) {
                    max_accounts *= 2;
                    accounts = realloc(accounts, max_accounts * sizeof(Account));
                }
                break;
            case 2:
                if (num_accounts == 0) {
                    printf("\nThere are no accounts to deposit to.");
                } else {
                    printf("\nEnter account number to deposit to: ");
                    int deposit_account_number;
                    scanf("%d", &deposit_account_number);
                    int found_index = -1;
                    for (int i = 0; i < num_accounts; i++) {
                        if (accounts[i].account_number == deposit_account_number) {
                            found_index = i;
                            break;
                        }
                    }
                    if (found_index == -1) {
                        printf("\nAccount not found.");
                    } else {
                        deposit(&accounts[found_index]);
                    }
                }
                break;
            case 3:
                if (num_accounts == 0) {
                    printf("\nThere are no accounts to withdraw from.");
                } else {
                    printf("\nEnter account number to withdraw from: ");
                    int withdraw_account_number;
                    scanf("%d", &withdraw_account_number);
                    int found_index = -1;
                    for (int i = 0; i < num_accounts; i++) {
                        if (accounts[i].account_number == withdraw_account_number) {
                            found_index = i;
                            break;
                        }
                    }
                    if (found_index == -1) {
                        printf("\nAccount not found.");
                    } else {
                        withdraw(&accounts[found_index]);
                    }
                }
                break;
            case 4:
                if (num_accounts == 0) {
                    printf("\nThere are no accounts to display.");
                } else {
                    printf("\nEnter account number to display: ");
                    int display_account_number;
                    scanf("%d", &display_account_number);
                    int found_index = -1;
                    for (int i = 0; i < num_accounts; i++) {
                        if (accounts[i].account_number == display_account_number) {
                            found_index = i;
                            break;
                        }
                    }
                    if (found_index == -1) {
                        printf("\nAccount not found.");
                    } else {
                        display(&accounts[found_index]);
                    }
                }
                break;
            case 5:
                if (num_accounts == 0) {
                    printf("\nThere are no accounts to display.");
                } else {
                    displayAll(accounts, num_accounts);
                }
                break;
            case 6:
                printf("\nGoodbye!");
                break;
            default:
                printf("\nInvalid menu choice. Try again.");
        }
    } while (menu_choice != 6);

    free(accounts);

    return 0;
}

void addAccount(Account* accounts, int index) {
    printf("\nEnter name for account %d: ", index + 1);
    scanf("%s", accounts[index].name);
    printf("Enter account number for account %d: ", index + 1);
    scanf("%d", &accounts[index].account_number);
    printf("Enter balance for account %d: ", index + 1);
    scanf("%f", &accounts[index].balance);
}

void deposit(Account* account) {
    float deposit_amount;
    printf("\nEnter amount to deposit: ");
    scanf("%f", &deposit_amount);
    account->balance += deposit_amount;
    printf("\nDeposit successful. New balance: %.2f", account->balance);
}

void withdraw(Account* account) {
    float withdraw_amount;
    printf("\nEnter amount to withdraw: ");
    scanf("%f", &withdraw_amount);
    if (withdraw_amount > account->balance) {
        printf("\nCannot withdraw more than account balance.");
    } else {
        account->balance -= withdraw_amount;
        printf("\nWithdrawal successful. New balance: %.2f", account->balance);
    }
}

void display(Account* account) {
    printf("\nName: %s", account->name);
    printf("\nAccount number: %d", account->account_number);
    printf("\nBalance: %.2f", account->balance);
}

void displayAll(Account* accounts, int num_accounts) {
    printf("\nAll accounts:\n");
    for (int i = 0; i < num_accounts; i++) {
        printf("\nAccount %d:", i + 1);
        display(&accounts[i]);
    }
}