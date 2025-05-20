//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the account structure
typedef struct {
    char name[50];
    int balance;
} Account;

// Define the main function
int main() {
    // Create an array of account objects
    Account accounts[10];

    // Initialize the account array with dummy data
    memset(accounts, 0, sizeof(Account) * 10);

    // Prompt the user to create a new account
    printf("Create a new account:\n");
    printf("Enter your name:\n");
    fgets(accounts[0].name, sizeof(accounts[0].name), stdin);
    accounts[0].balance = 0;

    // Prompt the user to perform operations on the account
    while (1) {
        printf("\nAccount operations:\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Check balance\n");
        printf("4. Quit\n");
        printf("Enter your choice (1-4): ");
        char choice;
        scanf(" %c", &choice);

        // Process the user's choice
        switch (choice) {
            case '1':
                // Prompt the user to enter the deposit amount
                printf("Enter the deposit amount: ");
                int deposit;
                scanf("%d", &deposit);

                // Update the account balance
                accounts[0].balance += deposit;
                break;
            case '2':
                // Prompt the user to enter the withdrawal amount
                printf("Enter the withdrawal amount: ");
                int withdrawal;
                scanf("%d", &withdrawal);

                // Update the account balance
                accounts[0].balance -= withdrawal;
                break;
            case '3':
                // Display the account balance
                printf("Account balance: %d\n", accounts[0].balance);
                break;
            case '4':
                // Quit the program
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}