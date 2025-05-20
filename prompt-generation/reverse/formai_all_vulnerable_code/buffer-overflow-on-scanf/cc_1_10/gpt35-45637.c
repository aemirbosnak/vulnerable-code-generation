//FormAI DATASET v1.0 Category: Banking Record System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int accountNumber;
    float balance;
} Account;

void displayMenu();
void addAccount(Account *accounts, int *numberOfAccounts);
void displayAccounts(Account *accounts, int numberOfAccounts);
void deposit(Account *accounts, int numberOfAccounts);
void withdraw(Account *accounts, int numberOfAccounts);

int main() {
    int choice, numberOfAccounts = 0;
    Account *accounts = malloc(sizeof(Account));
    
    do {
        displayMenu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addAccount(accounts, &numberOfAccounts);
                break;
            case 2:
                deposit(accounts, numberOfAccounts);
                break;
            case 3:
                withdraw(accounts, numberOfAccounts);
                break;
            case 4:
                displayAccounts(accounts, numberOfAccounts);
                break;
            case 5:
                printf("Goodbye!");
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    } while(choice != 5);
    
    free(accounts);
    
    return 0;
}

void displayMenu() {
    printf("Welcome to the Banking Record System!\n\n");
    printf("1. Add account\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Display accounts\n");
    printf("5. Exit\n\n");
    printf("Please select an option: ");
}

void addAccount(Account *accounts, int *numberOfAccounts) {
    printf("\n\nAdd Account\n\n");
    printf("Please enter customer name: ");
    scanf("%s", accounts[*numberOfAccounts].name);
    printf("Please enter account number: ");
    scanf("%d", &accounts[*numberOfAccounts].accountNumber);
    printf("Please enter initial balance: ");
    scanf("%f", &accounts[*numberOfAccounts].balance);
    printf("Account added successfully!\n\n");
    *numberOfAccounts = *numberOfAccounts + 1;
}

void displayAccounts(Account *accounts, int numberOfAccounts) {
    printf("\n\nDisplay Accounts\n\n");
    
    if(numberOfAccounts == 0) {
        printf("No accounts found!\n\n");
    } else {
        for(int i=0; i<numberOfAccounts; i++) {
            printf("Name: %s\n", accounts[i].name);
            printf("Account Number: %d\n", accounts[i].accountNumber);
            printf("Balance: $%.2f\n\n", accounts[i].balance);
        }
    }
}

void deposit(Account *accounts, int numberOfAccounts) {
    printf("\n\nDeposit\n\n");
    int accountNumber;
    float amount;
    
    printf("Please enter account number: ");
    scanf("%d", &accountNumber);
    printf("Enter amount to deposit: $");
    scanf("%f", &amount);
    
    for(int i=0; i<numberOfAccounts; i++) {
        if(accounts[i].accountNumber == accountNumber) {
            accounts[i].balance += amount;
            printf("Deposit successful! Balance is now $%.2f\n\n", accounts[i].balance);
            return;
        }
    }
    
    printf("Account not found. Please check account number and try again.\n\n");
}

void withdraw(Account *accounts, int numberOfAccounts) {
    printf("\n\nWithdraw\n\n");
    int accountNumber;
    float amount;
    
    printf("Please enter account number: ");
    scanf("%d", &accountNumber);
    printf("Enter amount to withdraw: $");
    scanf("%f", &amount);
    
    for(int i=0; i<numberOfAccounts; i++) {
        if(accounts[i].accountNumber == accountNumber) {
            if(amount > accounts[i].balance) {
                printf("Insufficient funds. Please try again.\n\n");
                return;
            }
            
            accounts[i].balance -= amount;
            printf("Withdrawal successful! Balance is now $%.2f\n\n", accounts[i].balance);
            return;
        }
    }
    
    printf("Account not found. Please check account number and try again.\n\n");
}