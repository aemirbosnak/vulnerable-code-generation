//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: retro
#include <stdio.h>

int main() {
    char name[20];
    int balance;
    float interest;

    printf("Welcome to Retro Banking Record System!\n");

    printf("Please enter your name: ");
    scanf("%s", name);

    printf("Enter your initial balance: ");
    scanf("%d", &balance);

    printf("Enter the interest rate (in decimal form): ");
    scanf("%f", &interest);

    while (1) {
        printf("Your current balance is %d\n", balance);

        printf("Would you like to deposit funds? (Y/N): ");
        char deposit[2];
        scanf(" %s", deposit);

        if (strcmp(deposit, "Y") == 0) {
            printf("Enter the amount to deposit: ");
            scanf("%d", &balance);
        } else if (strcmp(deposit, "N") == 0) {
            printf("Enter the amount to withdraw: ");
            scanf("%d", &balance);
        } else {
            printf("Invalid input. Please try again.\n");
        }

        if (balance >= 0) {
            printf("Your current balance is %d\n", balance);
        } else {
            printf("You cannot withdraw more than your current balance. Please try again.\n");
        }

        printf("Would you like to check your balance? (Y/N): ");
        char check[2];
        scanf(" %s", check);

        if (strcmp(check, "Y") == 0) {
            printf("Your current balance is %d\n", balance);
        } else if (strcmp(check, "N") == 0) {
            printf("Thank you for using Retro Banking Record System! Goodbye!\n");
            break;
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }

    return 0;
}