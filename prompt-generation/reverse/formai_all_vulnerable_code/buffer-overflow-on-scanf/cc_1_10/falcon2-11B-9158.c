//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_ACCOUNT 1000

typedef struct {
    char name[20];
    int balance;
} Account;

int main() {
    // Initialize the account data structure
    Account accounts[MAX_ACCOUNT] = {{"John Doe", 1000}, {"Jane Smith", 2000}};

    // Get user input
    char name[20];
    int amount;
    printf("Enter account name: ");
    scanf("%s", name);
    printf("Enter deposit amount: ");
    scanf("%d", &amount);

    // Deposit money
    int index = 0;
    while (name[0]!= '\0') {
        if (strcmp(name, accounts[index].name) == 0) {
            accounts[index].balance += amount;
            break;
        }
        index++;
        if (index == MAX_ACCOUNT) {
            printf("Account not found.\n");
            return 1;
        }
    }

    // Withdraw money
    index = 0;
    while (name[0]!= '\0') {
        if (strcmp(name, accounts[index].name) == 0) {
            accounts[index].balance -= amount;
            break;
        }
        index++;
        if (index == MAX_ACCOUNT) {
            printf("Account not found.\n");
            return 1;
        }
    }

    // Print account information
    printf("Account name: %s\n", name);
    printf("Balance: %d\n", accounts[index].balance);

    // Return success
    return 0;
}