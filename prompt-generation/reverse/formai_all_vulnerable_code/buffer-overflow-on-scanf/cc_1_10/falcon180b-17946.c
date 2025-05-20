//Falcon-180B DATASET v1.0 Category: Mortgage Calculator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct Mortgage {
    char name[50];
    int loan_amount;
    int down_payment;
    int interest_rate;
    int loan_term;
};

int main() {
    int choice, n;
    struct Mortgage m[100];
    char filename[50];
    FILE *fp;

    printf("Welcome to the Mortgage Calculator!\n");
    printf("Please enter your name: ");
    scanf("%s", m[0].name);

    printf("\nPlease choose an option:\n");
    printf("1. Enter a new mortgage\n");
    printf("2. View all mortgages\n");
    printf("3. Exit\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("\nEnter mortgage details:\n");
            printf("Loan amount: ");
            scanf("%d", &m[0].loan_amount);
            printf("Down payment: ");
            scanf("%d", &m[0].down_payment);
            printf("Interest rate: ");
            scanf("%d", &m[0].interest_rate);
            printf("Loan term: ");
            scanf("%d", &m[0].loan_term);
            printf("\nMortgage added successfully!\n");
            break;

        case 2:
            printf("\nAll Mortgages:\n");
            for(n=0; n<1; n++) {
                printf("\nName: %s\n", m[n].name);
                printf("Loan amount: %d\n", m[n].loan_amount);
                printf("Down payment: %d\n", m[n].down_payment);
                printf("Interest rate: %d\n", m[n].interest_rate);
                printf("Loan term: %d\n", m[n].loan_term);
                printf("\n");
            }
            break;

        case 3:
            printf("\nExiting...\n");
            break;

        default:
            printf("\nInvalid choice! Please try again.\n");
    }

    return 0;
}