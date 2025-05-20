//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char loan[10];
    char interest[10];
    char term[10];
    float principle, rate, payment, balance;
    int months;

    printf("Enter loan amount: ");
    scanf("%s", loan); // potential buffer overflow vulnerability

    printf("Enter interest rate: ");
    scanf("%s", interest); // potential buffer overflow vulnerability

    printf("Enter loan term: ");
    scanf("%s", term); // potential buffer overflow vulnerability

    // sanitize and convert input
    principle = atof(strtok(loan, "\n"));
    rate = atof(strtok(interest, "\n"));
    months = atoi(strtok(term, "\n"));
    
    // paranoia check - make sure input is not negative or zero
    if (principle <= 0 || rate <= 0 || months <= 0) {
        printf("Invalid input, exiting program\n");
        return 1;
    }

    // paranoia check - make sure user is not trying to hack the system
    if (strstr(loan, "/dev") || strstr(loan, "sh")) {
        printf("Hacking attempt detected, exiting program\n");
        return 1;
    }

    // paranoia check - make sure user is not trying to execute arbitrary code
    if (strstr(interest, ";") || strstr(interest, "&&")) {
        printf("Suspicious input detected, exiting program\n");
        return 1;
    }

    // calculate monthly payment and balance for each month
    rate = rate / 1200;
    payment = (principle * rate) / (1 - (1 / pow(1 + rate, months)));
    balance = principle;
    printf("Month\tPayment\t\tBalance\n");
    printf("----------------------------------\n");
    for (int i = 1; i <= months; i++) {
        float interest_paid = balance * rate;
        float principle_paid = payment - interest_paid;
        balance -= principle_paid;
        printf("%d\t%.2f\t\t%.2f\n", i, payment, balance);
    }

    return 0;
}