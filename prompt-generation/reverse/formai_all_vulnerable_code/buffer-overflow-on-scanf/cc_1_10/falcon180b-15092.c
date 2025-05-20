//Falcon-180B DATASET v1.0 Category: Mortgage Calculator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_LEN 100

typedef struct {
    char name[MAX_LEN];
    double balance;
    double interest_rate;
    int term;
} mortgage;

void input_mortgage(mortgage* m) {
    printf("Enter name: ");
    scanf("%s", m->name);

    printf("Enter balance: ");
    scanf("%lf", &m->balance);

    printf("Enter interest rate: ");
    scanf("%lf", &m->interest_rate);

    printf("Enter term in years: ");
    scanf("%d", &m->term);
}

double calculate_payment(double balance, double interest_rate, int term) {
    double payment = (balance * interest_rate) / (1 - pow(1 + interest_rate, -term));
    return payment;
}

void print_mortgage(mortgage* m) {
    printf("Name: %s\n", m->name);
    printf("Balance: $%.2lf\n", m->balance);
    printf("Interest rate: %.2lf%%\n", m->interest_rate * 100);
    printf("Term: %d years\n", m->term);
    printf("Monthly payment: $%.2lf\n", calculate_payment(m->balance, m->interest_rate, m->term) / 12);
    printf("\n");
}

int main() {
    srand(time(NULL));

    int num_mortgages = rand() % 10 + 1;
    mortgage* mortgages = malloc(num_mortgages * sizeof(mortgage));

    for (int i = 0; i < num_mortgages; i++) {
        input_mortgage(&mortgages[i]);
    }

    for (int i = 0; i < num_mortgages; i++) {
        print_mortgage(&mortgages[i]);
    }

    free(mortgages);

    return 0;
}