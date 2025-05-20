//FormAI DATASET v1.0 Category: Banking Record System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account { // structure to hold account information
    int account_number;
    char holder_name[50];
    float balance;
};

int main() {
    int choice, num_accounts = 0;
    struct account accounts[100]; // assuming maximum 100 accounts can be created

    do {
        printf("Welcome to the C Banking Record System!\n");
        printf("1. Create Account\n");
        printf("2. View Account Details\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // creating a new account
                printf("\nAccount Creation\n");
                printf("Enter account number: ");
                scanf("%d", &accounts[num_accounts].account_number);
                printf("Enter account holder name: ");
                scanf("%s", accounts[num_accounts].holder_name);
                printf("Enter starting balance: ");
                scanf("%f", &accounts[num_accounts].balance);
                num_accounts++;
                printf("\nAccount successfully created!\n");
                break;

            case 2: // viewing account details
                printf("\nAccount Details\n");
                printf("Enter account number: ");
                int account_num_search;
                scanf("%d", &account_num_search);
                for(int i=0; i<num_accounts; i++) {
                    if(accounts[i].account_number == account_num_search) {
                        printf("Account Number: %d\n", accounts[i].account_number);
                        printf("Account Holder Name: %s\n", accounts[i].holder_name);
                        printf("Account Balance: %.2f\n", accounts[i].balance);
                        break;
                    }
                    if(i == num_accounts-1) {
                        printf("Account not found!\n");
                    }
                }
                break;

            case 3: // depositing money
                printf("\nDeposit Money\n");
                printf("Enter account number: ");
                int account_num_deposit;
                scanf("%d", &account_num_deposit);
                for(int i=0; i<num_accounts; i++) {
                    if(accounts[i].account_number == account_num_deposit) {
                        printf("Enter amount to deposit: ");
                        float deposit;
                        scanf("%f", &deposit);
                        accounts[i].balance += deposit;
                        printf("Deposit successful! Current balance: %.2f\n", accounts[i].balance);
                        break;
                    }
                    if(i == num_accounts-1) {
                        printf("Account not found!\n");
                    }
                }
                break;

            case 4: // withdrawing money
                printf("\nWithdraw Money\n");
                printf("Enter account number: ");
                int account_num_withdraw;
                scanf("%d", &account_num_withdraw);
                for(int i=0; i<num_accounts; i++) {
                    if(accounts[i].account_number == account_num_withdraw) {
                        printf("Enter amount to withdraw: ");
                        float withdraw;
                        scanf("%f", &withdraw);
                        if(withdraw > accounts[i].balance) {
                            printf("Insufficient funds!\n");
                        } else {
                            accounts[i].balance -= withdraw;
                            printf("Withdrawal successful! Current balance: %.2f\n", accounts[i].balance);
                        }
                        break;
                    }
                    if(i == num_accounts-1) {
                        printf("Account not found!\n");
                    }
                }
                break;

            case 5: // exiting program
                printf("Thank you for using the C Banking Record System!\n");
                exit(0);

            default: // invalid user input
                printf("Invalid choice!\n");
        }

    } while(choice != 5);

    return 0;
}