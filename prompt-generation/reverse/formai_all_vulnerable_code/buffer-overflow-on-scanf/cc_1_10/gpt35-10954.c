//FormAI DATASET v1.0 Category: Banking Record System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct {
    int accNo;
    char owner[50];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int numAccounts = 0;

void createAccount(int accNo, char* owner, float balance) {
    if (numAccounts < MAX_ACCOUNTS) {
        accounts[numAccounts].accNo = accNo;
        strcpy(accounts[numAccounts].owner, owner);
        accounts[numAccounts].balance = balance;
        numAccounts++;
        printf("Account created successfully!\n");
    } else {
        printf("Maximum number of accounts reached.\n");
    }
}

void deposit(int accNo, float amount) {
    int i;
    for (i = 0; i < numAccounts; i++) {
        if (accounts[i].accNo == accNo) {
            accounts[i].balance += amount;
            printf("Deposit successful. New balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void withdraw(int accNo, float amount) {
    int i;
    for (i = 0; i < numAccounts; i++) {
        if (accounts[i].accNo == accNo) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                printf("Withdrawal successful. New balance: %.2f\n", accounts[i].balance);
            } else {
                printf("Insufficient funds.\n");
            }
            return;
        }
    }
    printf("Account not found.\n");
}

void transfer(int senderAccNo, int receiverAccNo, float amount) {
    int i;
    Account* sender = NULL;
    Account* receiver = NULL;
    for (i = 0; i < numAccounts; i++) {
        if (accounts[i].accNo == senderAccNo) {
            sender = &accounts[i];
        } else if (accounts[i].accNo == receiverAccNo) {
            receiver = &accounts[i];
        }
    }
    if (sender == NULL) {
        printf("Sender account not found.\n");
    } else if (receiver == NULL) {
        printf("Receiver account not found.\n");
    } else if (sender->balance < amount) {
        printf("Insufficient funds.\n");
    } else {
        sender->balance -= amount;
        receiver->balance += amount;
        printf("Transfer successful. New balance for sender: %.2f. New balance for receiver: %.2f\n", sender->balance, receiver->balance);
    }
}

void printAccount(int accNo) {
    int i;
    for (i = 0; i < numAccounts; i++) {
        if (accounts[i].accNo == accNo) {
            printf("Account number: %d\n", accounts[i].accNo);
            printf("Account owner: %s\n", accounts[i].owner);
            printf("Account balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void printAllAccounts() {
    int i;
    for (i = 0; i < numAccounts; i++) {
        printf("Account number: %d\n", accounts[i].accNo);
        printf("Account owner: %s\n", accounts[i].owner);
        printf("Account balance: %.2f\n", accounts[i].balance);
        printf("\n");
    }
}

int main() {
    int choice;
    int accNo, senderAccNo, receiverAccNo;
    char owner[50];
    float balance, amount;
    do {
        printf("\n1. Create account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Transfer\n");
        printf("5. Print account\n");
        printf("6. Print all accounts\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter account number: ");
                scanf("%d", &accNo);
                printf("Enter account owner: ");
                scanf("%s", owner);
                printf("Enter account balance: ");
                scanf("%f", &balance);
                createAccount(accNo, owner, balance);
                break;
            case 2:
                printf("Enter account number: ");
                scanf("%d", &accNo);
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                deposit(accNo, amount);
                break;
            case 3:
                printf("Enter account number: ");
                scanf("%d", &accNo);
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                withdraw(accNo, amount);
                break;
            case 4:
                printf("Enter sender account number: ");
                scanf("%d", &senderAccNo);
                printf("Enter receiver account number: ");
                scanf("%d", &receiverAccNo);
                printf("Enter amount to transfer: ");
                scanf("%f", &amount);
                transfer(senderAccNo, receiverAccNo, amount);
                break;
            case 5:
                printf("Enter account number: ");
                scanf("%d", &accNo);
                printAccount(accNo);
                break;
            case 6:
                printAllAccounts();
                break;
            case 7:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 7);
    return 0;
}