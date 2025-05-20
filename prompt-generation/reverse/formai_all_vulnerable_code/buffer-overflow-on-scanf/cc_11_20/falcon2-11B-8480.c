//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

int main() {
    int deposit = 0, withdrawal = 0, balance = 0, amount;
    char operation[10];

    // Get user input for operation
    printf("Enter operation (deposit, withdrawal, or check balance): ");
    scanf("%s", operation);

    // Check for valid input
    switch(operation[0]) {
        case 'd':
        case 'D':
            printf("Enter deposit amount: ");
            scanf("%d", &deposit);
            break;
        case 'w':
        case 'W':
            printf("Enter withdrawal amount: ");
            scanf("%d", &withdrawal);
            break;
        case 'c':
        case 'C':
            printf("Account balance: %d\n", balance);
            break;
        default:
            printf("Invalid operation!\n");
            exit(1);
    }

    // Perform operation
    switch(operation[0]) {
        case 'd':
        case 'D':
            if(deposit > 0) {
                balance += deposit;
                printf("Deposit successful!\n");
            } else {
                printf("Insufficient funds!\n");
            }
            break;
        case 'w':
        case 'W':
            if(withdrawal > 0) {
                if(withdrawal <= balance) {
                    balance -= withdrawal;
                    printf("Withdrawal successful!\n");
                } else {
                    printf("Insufficient funds!\n");
                }
            } else {
                printf("Invalid withdrawal amount!\n");
            }
            break;
        case 'c':
        case 'C':
            printf("Account balance: %d\n", balance);
            break;
        default:
            printf("Invalid operation!\n");
    }

    return 0;
}