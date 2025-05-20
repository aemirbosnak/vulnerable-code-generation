//FormAI DATASET v1.0 Category: Banking Record System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for customer account information
struct Account {
    int accountNumber;
    char holderName[50];
    float balance;
};

// Function to display customer account information
void displayAccount(struct Account acc) {
    printf("Account Number: %d\n", acc.accountNumber);
    printf("Account Holder Name: %s\n", acc.holderName);
    printf("Account Balance: %.2f\n", acc.balance);
}

// Function to deposit amount
void deposit(struct Account *acc, float amount) {
    acc->balance += amount;
}

// Function to withdraw amount
void withdraw(struct Account *acc, float amount) {
    if (acc->balance >= amount) {
        acc->balance -= amount;
    }
    else {
        printf("Insufficient balance in account.\n");
    }
}

int main() {
    int choice;
    float amount;
    struct Account a1;
    
    // Initialize customer account information
    a1.accountNumber = 1001;
    strcpy(a1.holderName, "John Doe");
    a1.balance = 5000;
    
    // Display customer account information
    printf("Initial Account Information:\n");
    displayAccount(a1);
    
    // User menu to deposit or withdraw amount
    printf("\nEnter 1 for Deposit\nEnter 2 for Withdrawal\n");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            deposit(&a1, amount);
            printf("\nAccount Information after Deposit:\n");
            displayAccount(a1);
            break;
        case 2:
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            withdraw(&a1, amount);
            printf("\nAccount Information after Withdrawal:\n");
            displayAccount(a1);
            break;
        default:
            printf("Invalid choice entered.\n");
            break;
    }
    
    return 0;
}