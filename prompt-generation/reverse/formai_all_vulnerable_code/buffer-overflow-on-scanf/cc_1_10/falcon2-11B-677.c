//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int account_number;
    char account_holder[20];
    float balance;
} Account;

int main(void) {
    Account accounts[100]; // Create an array to hold 100 accounts
    int account_count = 0; // Initialize account counter
    int choice; // Initialize choice variable

    // Loop until the user chooses to quit
    while (1) {
        // Display the menu options
        printf("1. Create new account\n2. Deposit money\n3. Withdraw money\n4. Display account balance\n5. Close account\n6. Quit\n\n");

        // Get user's choice
        scanf("%d", &choice);

        // Process the user's choice
        switch (choice) {
            case 1: // Create new account
                printf("Enter account number: ");
                scanf("%d", &accounts[account_count].account_number);
                printf("Enter account holder name: ");
                scanf("%s", accounts[account_count].account_holder);
                accounts[account_count].balance = 0.0;
                printf("New account created!\n");
                account_count++;
                break;
            case 2: // Deposit money
                printf("Enter account number: ");
                scanf("%d", &accounts[choice-1].account_number);
                printf("Enter deposit amount: ");
                scanf("%f", &accounts[choice-1].balance);
                printf("Deposit successful!\n");
                break;
            case 3: // Withdraw money
                printf("Enter account number: ");
                scanf("%d", &accounts[choice-1].account_number);
                printf("Enter withdrawal amount: ");
                scanf("%f", &accounts[choice-1].balance);
                if (accounts[choice-1].balance >= 0) {
                    accounts[choice-1].balance -= accounts[choice-1].balance;
                    printf("Withdrawal successful!\n");
                } else {
                    printf("Insufficient funds!\n");
                }
                break;
            case 4: // Display account balance
                printf("Enter account number: ");
                scanf("%d", &accounts[choice-1].account_number);
                printf("Account balance: %.2f\n", accounts[choice-1].balance);
                break;
            case 5: // Close account
                printf("Enter account number: ");
                scanf("%d", &accounts[choice-1].account_number);
                printf("Are you sure you want to close account %d? (y/n): ", accounts[choice-1].account_number);
                char choice_str[2];
                scanf("%s", choice_str);
                if (strcmp(choice_str, "y") == 0) {
                    accounts[choice-1].balance = 0.0;
                    printf("Account closed!\n");
                } else {
                    printf("Aborting close operation!\n");
                }
                break;
            case 6: // Quit
                printf("Bye!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}