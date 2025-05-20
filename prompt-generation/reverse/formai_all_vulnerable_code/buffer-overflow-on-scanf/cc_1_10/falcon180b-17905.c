//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

typedef struct {
    char name[50];
    float balance;
    float interest_rate;
    time_t created_at;
} account;

int main() {
    int choice;
    account my_account;

    printf("Welcome to the Personal Finance Planner!\n");
    printf("Please enter your name: ");
    scanf("%s", my_account.name);

    while(1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Deposit money\n");
        printf("2. Withdraw money\n");
        printf("3. Check balance\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter amount to deposit: ");
                scanf("%f", &my_account.balance);
                printf("Amount deposited successfully!\n");
                break;
            case 2:
                printf("Enter amount to withdraw: ");
                scanf("%f", &my_account.balance);
                printf("Amount withdrawn successfully!\n");
                break;
            case 3:
                printf("Your current balance is: $%.2f\n", my_account.balance);
                break;
            case 4:
                printf("Thank you for using the Personal Finance Planner!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}