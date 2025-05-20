//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bank {
    char name[50];
    int account_number;
    int balance;
} bank_t;

int main() {
    bank_t account[10]; // array to store 10 bank accounts
    int choice, i;

    // Display the menu
    printf("Banking Record System\n");
    printf("1. Create new account\n");
    printf("2. Deposit funds\n");
    printf("3. Withdraw funds\n");
    printf("4. Check balance\n");
    printf("5. Search account by name\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");

    // Loop until user chooses to exit
    while (1) {
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Create new account
                printf("Enter account name: ");
                scanf("%s", account[i].name);
                printf("Enter account number: ");
                scanf("%d", &account[i].account_number);
                account[i].balance = 0;
                printf("Account created successfully.\n");
                break;

            case 2: // Deposit funds
                printf("Enter account number: ");
                scanf("%d", &account[i].account_number);
                printf("Enter deposit amount: ");
                scanf("%d", &account[i].balance);
                printf("Funds deposited successfully.\n");
                break;

            case 3: // Withdraw funds
                printf("Enter account number: ");
                scanf("%d", &account[i].account_number);
                printf("Enter withdrawal amount: ");
                scanf("%d", &account[i].balance);
                if (account[i].balance >= 0) {
                    account[i].balance -= account[i].balance;
                    printf("Funds withdrawn successfully.\n");
                } else {
                    printf("Insufficient funds.\n");
                }
                break;

            case 4: // Check balance
                printf("Enter account number: ");
                scanf("%d", &account[i].account_number);
                printf("Account balance: %d\n", account[i].balance);
                break;

            case 5: // Search account by name
                printf("Enter account name: ");
                scanf("%s", account[i].name);
                for (i = 0; i < 10; i++) {
                    if (strcmp(account[i].name, account[i].name) == 0) {
                        printf("Account found.\n");
                        break;
                    }
                }
                break;

            case 6: // Exit
                printf("Exiting the system...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}