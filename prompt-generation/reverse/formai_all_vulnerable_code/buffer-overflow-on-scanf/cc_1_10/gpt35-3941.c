//FormAI DATASET v1.0 Category: Banking Record System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

//define structure to hold account information
typedef struct account {
    int accNum;
    char name[50];
    float balance;
} Account;

//function to display account details
void displayAccount(Account acc) {
    printf("Account Number: %d\n", acc.accNum);
    printf("Name: %s\n", acc.name);
    printf("Balance: $%.2f\n", acc.balance);
}

//function to add funds to account
void addFunds(Account *acc, float amount) {
    acc->balance += amount;
    printf("Funds added successfully.\n");
}

//function to withdraw funds from account
void withdrawFunds(Account *acc, float amount) {
    if (acc->balance - amount < 0) {
        printf("Insufficient funds.\n");
    } else {
        acc->balance -= amount;
        printf("$%.2f withdrawn successfully.\n", amount);
    }
}

int main() {
    //seed random number generator
    srand(time(NULL));
    
    //initialize empty account array
    Account accounts[10];
    int numAccounts = 0;
    
    printf("Welcome to the Post-Apocalyptic Banking System!\n");
    printf("You are one of the lucky few who still has access to a bank account.\n");
    printf("Let's create an account for you.\n");
    
    char name[50];
    printf("Enter your name: ");
    scanf("%s", name);
    
    //generate unique account number for new account
    int accNum = rand() % 10000;
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accNum == accNum) {
            accNum = rand() % 10000; //generate a new account number if the first one is already taken
        }
    }
    
    //initialize new account with user information and $100 starting balance
    Account newAcc = {accNum, name, 100.00};
    accounts[numAccounts] = newAcc;
    numAccounts++;
    
    printf("Account created successfully.\n");
    
    //display account details and options for adding or withdrawing funds
    printf("Here are your account details:\n");
    displayAccount(newAcc);
    
    printf("\nWhat would you like to do?\n");
    printf("1. Add funds\n");
    printf("2. Withdraw funds\n");
    int choice;
    scanf("%d", &choice);
    
    switch (choice) {
        case 1: {
            float amount;
            printf("Enter amount to add: $");
            scanf("%f", &amount);
            addFunds(&newAcc, amount);
            break;
        }
        case 2: {
            float amount;
            printf("Enter amount to withdraw: $");
            scanf("%f", &amount);
            withdrawFunds(&newAcc, amount);
            break;
        }
        default: {
            printf("Invalid choice.\n");
            break;
        }
    }
    
    printf("Thank you for banking with us.\n");

    return 0;
}