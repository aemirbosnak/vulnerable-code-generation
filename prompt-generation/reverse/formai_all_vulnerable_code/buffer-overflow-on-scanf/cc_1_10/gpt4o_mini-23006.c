//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct {
    int accountNumber;
    char name[50];
    double balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int count = 0;

void createAccount() {
    if(count >= MAX_ACCOUNTS) {
        printf("Account limit reached! Cannot create more accounts.\n");
        return;
    }
    
    Account newAccount;
    printf("Enter account number: ");
    scanf("%d", &newAccount.accountNumber);
    printf("Enter account holder name: ");
    scanf("%s", newAccount.name);
    newAccount.balance = 0;
    
    accounts[count++] = newAccount;
    printf("Account created successfully!\n");
}

void deposit() {
    int accountNumber;
    double amount;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    
    for(int i = 0; i < count; i++) {
        if(accounts[i].accountNumber == accountNumber) {
            printf("Enter amount to deposit: ");
            scanf("%lf", &amount);
            accounts[i].balance += amount;
            printf("Amount deposited successfully! New balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

void withdraw() {
    int accountNumber;
    double amount;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    
    for(int i = 0; i < count; i++) {
        if(accounts[i].accountNumber == accountNumber) {
            printf("Enter amount to withdraw: ");
            scanf("%lf", &amount);
            if(amount > accounts[i].balance) {
                printf("Insufficient balance!\n");
            } else {
                accounts[i].balance -= amount;
                printf("Amount withdrawn successfully! New balance: %.2f\n", accounts[i].balance);
            }
            return;
        }
    }
    printf("Account not found!\n");
}

void displayAllAccounts() {
    if(count == 0) {
        printf("No accounts to display!\n");
        return;
    }
    
    printf("\nAccount List:\n");
    for(int i = 0; i < count; i++) {
        printf("Account Number: %d, Name: %s, Balance: %.2f\n", accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
    }
}

void accountSummary() {
    int accountNumber;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    
    for(int i = 0; i < count; i++) {
        if(accounts[i].accountNumber == accountNumber) {
            printf("Account Summary:\n");
            printf("Account Number: %d\n", accounts[i].accountNumber);
            printf("Name: %s\n", accounts[i].name);
            printf("Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

void menu() {
    int choice;
    do {
        printf("\n--- Banking Record System Menu ---\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Display All Accounts\n");
        printf("5. Account Summary\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: createAccount(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: displayAllAccounts(); break;
            case 5: accountSummary(); break;
            case 6: printf("Exiting the program. Goodbye!\n"); break;
            default: printf("Invalid choice! Please enter again.\n");
        }
    } while(choice != 6);
}

int main() {
    printf("Welcome to the Banking Record System!\n");
    menu();
    return 0;
}