//Falcon-180B DATASET v1.0 Category: Mortgage Calculator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_LEN 100

struct mortgage {
    char name[MAX_LEN];
    double principal;
    double interest_rate;
    int term;
};

void print_mortgage(struct mortgage mortgage) {
    printf("Name: %s\n", mortgage.name);
    printf("Principal: $%.2f\n", mortgage.principal);
    printf("Interest Rate: %.2f%%\n", mortgage.interest_rate * 100);
    printf("Term: %d years\n", mortgage.term);
}

double calculate_monthly_payment(double principal, double interest_rate, int term) {
    double payment = (principal * interest_rate) / (1 - pow(1 + interest_rate, -term * 12));
    return payment;
}

int main() {
    int num_mortgages;
    printf("Enter the number of mortgages: ");
    scanf("%d", &num_mortgages);

    struct mortgage mortgages[num_mortgages];

    for (int i = 0; i < num_mortgages; i++) {
        printf("Enter the name for mortgage %d: ", i + 1);
        scanf("%s", mortgages[i].name);

        printf("Enter the principal for mortgage %d: $", i + 1);
        scanf("%lf", &mortgages[i].principal);

        printf("Enter the interest rate for mortgage %d: ", i + 1);
        scanf("%lf", &mortgages[i].interest_rate);

        printf("Enter the term for mortgage %d (in years): ", i + 1);
        scanf("%d", &mortgages[i].term);
    }

    for (int i = 0; i < num_mortgages; i++) {
        double monthly_payment = calculate_monthly_payment(mortgages[i].principal, mortgages[i].interest_rate, mortgages[i].term);
        printf("Mortgage %d monthly payment: $%.2f\n", i + 1, monthly_payment);
    }

    return 0;
}