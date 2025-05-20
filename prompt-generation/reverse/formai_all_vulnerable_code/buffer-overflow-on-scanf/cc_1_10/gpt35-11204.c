//FormAI DATASET v1.0 Category: Banking Record System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for account information
struct Account {
    char name[50];
    float balance;
    int account_number;
};

// Function to display account details
void displayAccountDetails(struct Account account) {
    printf("Account Name: %s\n", account.name);
    printf("Account Number: %d\n", account.account_number);
    printf("Account Balance: %.2f\n", account.balance);
}

int main() {
    struct Account accounts[10]; // max number of accounts is 10
    int num_accounts = 0; // number of accounts entered so far

    int choice;
    do {
        printf("Menu\n");
        printf("1. Add new account\n");
        printf("2. Display account details\n");
        printf("3. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(num_accounts == 10) { // check if max number of accounts has been reached
                    printf("Max number of accounts reached.\n");
                    break;
                }

                // Prompt user for account information
                printf("\nEnter account name: ");
                scanf("%s", accounts[num_accounts].name);
                printf("Enter account number: ");
                scanf("%d", &accounts[num_accounts].account_number);
                printf("Enter account balance: ");
                scanf("%f", &accounts[num_accounts].balance);

                num_accounts++; // increment number of accounts entered
                printf("Account added successfully!\n");
                break;

            case 2:
                if(num_accounts == 0) { // check if there are any accounts to display
                    printf("No accounts entered yet.\n");
                    break;
                }

                // Prompt user for account number and display account details if found
                int search_account_number;
                printf("\nEnter account number to search: ");
                scanf("%d", &search_account_number);

                int i;
                for(i = 0; i < num_accounts; i++) {
                    if(accounts[i].account_number == search_account_number) {
                        displayAccountDetails(accounts[i]);
                        break;
                    }
                }

                if(i == num_accounts) {
                    printf("Account not found.\n");
                }
                break;

            case 3:
                printf("Exiting program. Bye!\n");
                exit(0); // exit program

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 3);

    return 0; // successful program termination
}