//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[50];
    float balance;
} Account;

int main() {
    // Initialize database with 5 accounts
    Account accounts[5] = {
        {1, "John Doe", 1000.00},
        {2, "Jane Smith", 5000.00},
        {3, "Bob Johnson", 750.00},
        {4, "Alice Brown", 2500.00},
        {5, "Charlie Green", 1500.00}
    };

    // Print initial database
    printf("\nInitial Database:\n");
    for(int i=0; i<5; i++) {
        printf("ID: %d\tName: %s\tBalance: $%.2f\n", accounts[i].id, accounts[i].name, accounts[i].balance);
    }

    // Deposit money into an account
    int depositId;
    printf("\nEnter ID of account to deposit into: ");
    scanf("%d", &depositId);
    float depositAmount;
    printf("Enter amount to deposit: $");
    scanf("%f", &depositAmount);

    for(int i=0; i<5; i++) {
        if(accounts[i].id == depositId) {
            accounts[i].balance += depositAmount;
            printf("\nDeposit successful! New balance: $%.2f\n", accounts[i].balance);
            break;
        }
    }

    // Withdraw money from an account
    int withdrawId;
    printf("\nEnter ID of account to withdraw from: ");
    scanf("%d", &withdrawId);
    float withdrawAmount;
    printf("Enter amount to withdraw: $");
    scanf("%f", &withdrawAmount);

    for(int i=0; i<5; i++) {
        if(accounts[i].id == withdrawId) {
            if(accounts[i].balance >= withdrawAmount) {
                accounts[i].balance -= withdrawAmount;
                printf("\nWithdrawal successful! New balance: $%.2f\n", accounts[i].balance);
            } else {
                printf("\nInsufficient funds!\n");
            }
            break;
        }
    }

    // Print updated database
    printf("\nUpdated Database:\n");
    for(int i=0; i<5; i++) {
        printf("ID: %d\tName: %s\tBalance: $%.2f\n", accounts[i].id, accounts[i].name, accounts[i].balance);
    }

    return 0;
}