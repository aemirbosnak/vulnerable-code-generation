//FormAI DATASET v1.0 Category: Banking Record System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store banking records
struct bankRecord {
    int accountNumber;
    char name[50];
    float balance;
};

int main() {

    // Creating an array of bank records with default values
    struct bankRecord accounts[10];
    for(int i=0; i<10; i++) {
        accounts[i].accountNumber = 1000 + i;
        strcpy(accounts[i].name, "John Doe");
        accounts[i].balance = 1000.0;
    }

    // Printing the current state of all the accounts
    printf("Current state of all the accounts:\n");
    printf("%-10s%-20s%-10s\n", "Account", "Name", "Balance");
    for(int i=0; i<10; i++) {
        printf("%-10d%-20s%-10.2f\n", accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
    }

    // Asking user for account number and amount to deposit
    int accountNumber;
    float amount;
    printf("\nEnter account number and amount to deposit: ");
    scanf("%d %f",&accountNumber, &amount);

    // Validating the account number
    int index = -1;
    for(int i=0; i<10; i++) {
        if(accounts[i].accountNumber == accountNumber) {
            index = i;
            break;
        }
    }

    // Depositing the amount and updating the balance
    if(index >= 0) {
        accounts[index].balance += amount;
        printf("\nDeposited %.2f in account %d\n", amount, accounts[index].accountNumber);
        printf("New balance in account %d is %.2f\n", accounts[index].accountNumber, accounts[index].balance);
    } else {
        printf("\nAccount not found\n");
    }

    return 0;
}