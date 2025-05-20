//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNT_NUM 10000
#define MAX_ACCOUNT_HOLDER_NAME 50
#define MAX_ACCOUNT_TYPE 20
#define MAX_ACCOUNT_BALANCE 10000000

typedef struct {
    int account_number;
    char account_holder_name[MAX_ACCOUNT_HOLDER_NAME];
    char account_type[MAX_ACCOUNT_TYPE];
    float account_balance;
} Account;

int main() {
    int choice;
    char ch;
    FILE *fp;
    Account account;

    // Open the file in read mode
    fp = fopen("bank.txt", "r");

    // Check if the file is opened successfully
    if (fp == NULL) {
        printf("Error in opening the file.\n");
        exit(0);
    }

    // Read the first record
    fscanf(fp, "%d %s %s %f", &account.account_number, account.account_holder_name, account.account_type, &account.account_balance);

    // Display the first record
    printf("Account Number: %d\n", account.account_number);
    printf("Account Holder Name: %s\n", account.account_holder_name);
    printf("Account Type: %s\n", account.account_type);
    printf("Account Balance: %.2f\n", account.account_balance);

    // Ask the user for the choice
    printf("\nEnter your choice:\n");
    printf("1. Deposit\n");
    printf("2. Withdraw\n");
    printf("3. Check Balance\n");
    printf("4. Exit\n");
    scanf("%d", &choice);

    // Perform the required operation
    switch (choice) {
        case 1: {
            printf("Enter the amount to deposit: ");
            scanf("%f", &account.account_balance);
            break;
        }
        case 2: {
            printf("Enter the amount to withdraw: ");
            scanf("%f", &account.account_balance);
            break;
        }
        case 3: {
            printf("Account Balance: %.2f\n", account.account_balance);
            break;
        }
        case 4: {
            exit(0);
        }
        default: {
            printf("Invalid choice.\n");
            exit(0);
        }
    }

    // Write the updated record to the file
    rewind(fp);
    fseek(fp, 0, SEEK_SET);
    fwrite(&account, sizeof(Account), 1, fp);

    // Close the file
    fclose(fp);

    return 0;
}