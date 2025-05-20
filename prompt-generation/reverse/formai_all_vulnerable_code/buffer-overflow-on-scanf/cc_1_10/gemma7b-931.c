//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char *pin_number = malloc(10);
    printf("Enter your PIN number: ");
    scanf("%s", pin_number);

    if (strcmp(pin_number, "1234") != 0) {
        printf("Incorrect PIN number. Please try again.\n");
        free(pin_number);
        return 1;
    }

    char *account_number = malloc(20);
    printf("Enter your account number: ");
    scanf("%s", account_number);

    if (strcmp(account_number, "512346") != 0) {
        printf("Incorrect account number. Please try again.\n");
        free(pin_number);
        free(account_number);
        return 1;
    }

    double balance = 1000.0;
    printf("Your current balance is: $%.2lf\n", balance);

    char *withdrawal_amount = malloc(20);
    printf("Enter the withdrawal amount: ");
    scanf("%s", withdrawal_amount);

    double withdrawal_amount_double = atof(withdrawal_amount);

    if (withdrawal_amount_double > balance) {
        printf("Insufficient funds. Withdrawal declined.\n");
        free(pin_number);
        free(account_number);
        free(withdrawal_amount);
        return 1;
    }

    balance -= withdrawal_amount_double;
    printf("Your new balance is: $%.2lf\n", balance);

    free(pin_number);
    free(account_number);
    free(withdrawal_amount);

    return 0;
}