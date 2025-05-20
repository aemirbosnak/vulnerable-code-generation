//MISTRAL-7B DATASET v1.0 Category: Mortgage Calculator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define _CRT_SECURE_NO_WARNINGS

typedef struct {
    char name[32];
    float salary;
    int age;
} citizen;

typedef struct {
    char bank_name[32];
    float interest_rate;
    float loan_amount;
    int loan_term;
} bank;

void calc_mortgage(bank*, citizen*);

int main() {
    citizen user = {
        .salary = 4500.0,
        .age = 32
    };

    bank the_bank = {
        .bank_name = "MegaCorp Bank",
        .interest_rate = 0.06,
        .loan_amount = 150000.0,
        .loan_term = 30
    };

    printf("\n\x1b[31m*****************************************************************\n");
    printf("\x1b[31m*                           WELCOME TO THE BANK                   *\n");
    printf("\x1b[31m*                        OF MISERY AND DEBT                      *\n");
    printf("\x1b[31m*                       YOUR CYBERPUNK MORTGAGE AIDE              *\n");
    printf("\x1b[31m*****************************************************************\n\n");

    calc_mortgage(&the_bank, &user);

    return 0;
}

void calc_mortgage(bank* bank_data, citizen* user_data) {
    float monthly_interest_rate = bank_data->interest_rate / 12.0;
    int num_payments = bank_data->loan_term * 12;

    float monthly_payment = powf(1 + monthly_interest_rate, num_payments) * monthly_interest_rate * bank_data->loan_amount / (powf(1 + monthly_interest_rate, num_payments) - 1);

    printf("\nYour monthly mortgage payment is: $%.2f\n", monthly_payment);
}