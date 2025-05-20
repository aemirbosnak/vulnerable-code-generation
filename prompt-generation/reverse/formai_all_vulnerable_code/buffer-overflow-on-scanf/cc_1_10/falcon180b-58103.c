//Falcon-180B DATASET v1.0 Category: Mortgage Calculator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double principal, rate, term, payment;
    char option;
    int flag = 0;

    printf("Welcome to the Post-Apocalyptic Mortgage Calculator\n");
    printf("Please enter the principal amount: ");
    scanf("%lf", &principal);

    while (1) {
        printf("\nPlease select an option:\n");
        printf("1. Enter interest rate\n");
        printf("2. Enter term in years\n");
        printf("3. Calculate payment\n");
        printf("4. Exit\n");
        scanf(" %c", &option);

        switch (option) {
            case '1':
                printf("Enter interest rate: ");
                scanf("%lf", &rate);
                flag |= 1;
                break;
            case '2':
                printf("Enter term in years: ");
                scanf("%d", &term);
                flag |= 2;
                break;
            case '3':
                if (flag == 3) {
                    payment = principal * pow(1 + rate / 1200, 1200) / (pow(1 + rate / 1200, 1200) - 1) * term;
                    printf("\nYour monthly payment is: $%.2lf\n", payment);
                } else {
                    printf("\nPlease enter interest rate and term first.\n");
                }
                break;
            case '4':
                printf("\nExiting...\n");
                exit(0);
            default:
                printf("\nInvalid option. Please try again.\n");
        }
    }

    return 0;
}