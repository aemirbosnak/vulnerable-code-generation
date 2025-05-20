//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int account_number;
    float balance;
    char status[10];
} account;

int main() {
    account accounts[5];
    int i;
    char choice;
    
    printf("Welcome to the Bank of Inquisitive!n");
    printf("What is your name? ");
    scanf("%s", accounts[0].name);
    
    for (i = 1; i < 5; i++) {
        accounts[i].name[0] = '\0';
        accounts[i].account_number = 0;
        accounts[i].balance = 0.0;
        accounts[i].status[0] = '\0';
    }
    
    while (1) {
        printf("1. Create Account\n2. Deposit Money\n3. Withdraw Money\n4. Transfer Money\n5. Check Balance\n6. Close Account\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);
        
        switch (choice) {
            case '1':
                printf("Enter account name: ");
                scanf("%s", accounts[i].name);
                printf("Enter account number: ");
                scanf("%d", &accounts[i].account_number);
                printf("Enter initial balance: ");
                scanf("%f", &accounts[i].balance);
                printf("Enter account status: ");
                scanf("%s", accounts[i].status);
                break;
            case '2':
                printf("Enter account name: ");
                scanf("%s", accounts[i].name);
                printf("Enter amount to deposit: ");
                scanf("%f", &accounts[i].balance);
                break;
            case '3':
                printf("Enter account name: ");
                scanf("%s", accounts[i].name);
                printf("Enter amount to withdraw: ");
                scanf("%f", &accounts[i].balance);
                break;
            case '4':
                printf("Enter account name: ");
                scanf("%s", accounts[i].name);
                printf("Enter account name to transfer money to: ");
                scanf("%s", accounts[i].name);
                printf("Enter amount to transfer: ");
                scanf("%f", &accounts[i].balance);
                break;
            case '5':
                printf("Enter account name: ");
                scanf("%s", accounts[i].name);
                printf("Current balance: %.2f\n", accounts[i].balance);
                break;
            case '6':
                printf("Enter account name: ");
                scanf("%s", accounts[i].name);
                printf("Are you sure you want to close this account? (y/n): ");
                scanf(" %c", &choice);
                if (choice == 'y') {
                    printf("Closing account...\n");
                    accounts[i].status[0] = 'C';
                }
                break;
            case '7':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}