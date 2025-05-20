//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account {
    char name[50];
    char account_number[20];
    float balance;
};

int main() {
    // Initialize the array of accounts
    struct account accounts[100];
    
    // Get the number of accounts
    int num_accounts;
    printf("How many accounts do you want to create? ");
    scanf("%d", &num_accounts);

    // Get the details of each account
    for (int i = 0; i < num_accounts; i++) {
        printf("Enter the name of account holder %d: ", i + 1);
        scanf("%s", accounts[i].name);

        printf("Enter the account number for %s: ", accounts[i].name);
        scanf("%s", accounts[i].account_number);

        printf("Enter the balance for %s: ", accounts[i].name);
        scanf("%f", &accounts[i].balance);
    }

    // Display the details of each account
    printf("\nAccount Details:\n");
    for (int i = 0; i < num_accounts; i++) {
        printf("Name: %s\n", accounts[i].name);
        printf("Account Number: %s\n", accounts[i].account_number);
        printf("Balance: %.2f\n\n", accounts[i].balance);
    }
    
    //Add a new account
    char add_account;
    printf("\nDo you want to add a new account? (Y/N): ");
    scanf(" %c", &add_account);
    
    if (add_account == 'Y' || add_account == 'y') {
        printf("\nEnter the name of account holder: ");
        scanf("%s", accounts[num_accounts].name);
        
        printf("Enter the account number for %s: ", accounts[num_accounts].name);
        scanf("%s", accounts[num_accounts].account_number);
        
        printf("Enter the balance for %s: ", accounts[num_accounts].name);
        scanf("%f", &accounts[num_accounts].balance);
        
        num_accounts++;
        
        printf("\nNew account added!\n");
    }
    
    //Deposit money into an account
    char deposit_money;
    printf("\nDo you want to deposit money into an account? (Y/N): ");
    scanf(" %c", &deposit_money);
    
    if (deposit_money == 'Y' || deposit_money == 'y') {
        char account_number[20];
        float amount;
        
        printf("\nEnter the account number: ");
        scanf("%s", account_number);
        
        printf("Enter the amount to deposit: ");
        scanf("%f", &amount);
        
        for (int i = 0; i < num_accounts; i++) {
            if (strcmp(accounts[i].account_number, account_number) == 0) {
                accounts[i].balance += amount;
                
                printf("\n%.2f deposited into account %s!\n", amount, accounts[i].name);
                break;
            }
        }
    }
    
    //Withdraw money from an account
    char withdraw_money;
    printf("\nDo you want to withdraw money from an account? (Y/N): ");
    scanf(" %c", &withdraw_money);
    
    if (withdraw_money == 'Y' || withdraw_money == 'y') {
        char account_number[20];
        float amount;
        
        printf("\nEnter the account number: ");
        scanf("%s", account_number);
        
        printf("Enter the amount to withdraw: ");
        scanf("%f", &amount);
        
        for (int i = 0; i < num_accounts; i++) {
            if (strcmp(accounts[i].account_number, account_number) == 0) {
                if (accounts[i].balance >= amount) {
                    accounts[i].balance -= amount;
                    
                    printf("\n%.2f withdrawn from account %s!\n", amount, accounts[i].name);
                } else {
                    printf("\nInsufficient balance!\n");
                }
                break;
            }
        }
    }
    
    //Delete an account
    char delete_account;
    printf("\nDo you want to delete an account? (Y/N): ");
    scanf(" %c", &delete_account);
    
    if (delete_account == 'Y' || delete_account == 'y') {
        char account_number[20];
        
        printf("\nEnter the account number: ");
        scanf("%s", account_number);
        
        for (int i = 0; i < num_accounts; i++) {
            if (strcmp(accounts[i].account_number, account_number) == 0) {
                for (int j = i; j < num_accounts - 1; j++) {
                    accounts[j] = accounts[j + 1];
                }
                num_accounts--;
                
                printf("\nAccount %s deleted!\n", account_number);
                break;
            }
        }
    }

    return 0;
}