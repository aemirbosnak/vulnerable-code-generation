//FormAI DATASET v1.0 Category: Banking Record System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* A Banking Record System program with a romantic flair */

struct account {
    int acc_num;
    char holder[20];
    double balance;
};

int main() {

    /* Declare variables for record-keeping */

    struct account customers[10];
    int i, choice, search_index, account_num;
    char search_name[20];

    /* Greet the user with a romantic opening */

    printf("My dearest love,\n\n");
    printf("I have created a special banking record system just for you.\n");
    printf("I know how much you value organization and order, so I wanted to make sure that your finances were in good hands.\n");
    printf("Please enjoy this program I have written just for you.\n\n");

    /* Populate the initial account records */

    printf("To start, let's add some initial account records.\n");

    for(i=0;i<2;i++) {
        printf("\nEnter account number for customer %d: ", i+1);
        scanf("%d", &customers[i].acc_num);
        printf("Enter name for customer %d: ", i+1);
        scanf("%s", customers[i].holder);
        printf("Enter balance for customer %d: ", i+1);
        scanf("%lf", &customers[i].balance);
    }

    /* Main menu for program functionality */

    while(1) {

        printf("\n\nWhat would you like to do next?\n");
        printf("--------------------------------\n");
        printf("1. Search for an account by name\n");
        printf("2. Search for an account by account number\n");
        printf("3. Add a new account\n");
        printf("4. View all accounts\n");
        printf("5. Exit\n\n");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("\nEnter the name to search for: ");
                scanf("%s", search_name);
                for(i=0;i<2;i++) {
                    if(strcmp(customers[i].holder, search_name) == 0) {
                        printf("Account number: %d\n", customers[i].acc_num);
                        printf("Account holder: %s\n", customers[i].holder);
                        printf("Balance: $%.2lf\n", customers[i].balance);
                        break;
                    }
                }
                if(i == 2) {
                    printf("I am sorry, my love, but there is no account under that name.\n");
                }
                break;

            case 2:
                printf("\nEnter the account number to search for: ");
                scanf("%d", &account_num);
                for(i=0;i<2;i++) {
                    if(customers[i].acc_num == account_num) {
                        printf("Account number: %d\n", customers[i].acc_num);
                        printf("Account holder: %s\n", customers[i].holder);
                        printf("Balance: $%.2lf\n", customers[i].balance);
                        break;
                    }
                }
                if(i == 2) {
                    printf("I am sorry, my love, but there is no account under that account number.\n");
                }
                break;

            case 3:
                printf("\nEnter account number for new customer: ");
                scanf("%d", &customers[i].acc_num);
                printf("Enter name for new customer: ");
                scanf("%s", customers[i].holder);
                printf("Enter balance for new customer: ");
                scanf("%lf", &customers[i].balance);
                i++;
                printf("\nNew account successfully added!\n");
                break;

            case 4:
                printf("\n\n---All Accounts---\n\n");
                for(i=0;i<2;i++) {
                    printf("Account number: %d\n", customers[i].acc_num);
                    printf("Account holder: %s\n", customers[i].holder);
                    printf("Balance: $%.2lf\n", customers[i].balance);
                }
                break;

            case 5:
                printf("\n\nThank you for trusting me to handle your finances, my love.\n");
                printf("I hope this program serves you well.\n");
                exit(0);

            default:
                printf("\nInvalid choice, please try again.\n");
        }
    }
    return 0;    
}