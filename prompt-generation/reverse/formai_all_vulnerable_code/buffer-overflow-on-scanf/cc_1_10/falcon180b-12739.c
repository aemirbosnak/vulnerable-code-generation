//Falcon-180B DATASET v1.0 Category: Mortgage Calculator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum length of the input string
#define MAX_LEN 100

// Define the interest rate and duration
#define INTEREST_RATE 0.05
#define DURATION 30

// Define the structure of the mortgage
struct mortgage {
    char name[MAX_LEN];
    double principal;
    double interest;
    double monthly_payment;
};

// Function to calculate the monthly payment
double calculate_monthly_payment(double principal, double interest_rate, int duration) {
    double monthly_rate = interest_rate / 1200;
    double monthly_payment = (principal * monthly_rate) / (1 - pow(1 + monthly_rate, -duration * 12));
    return monthly_payment;
}

// Function to print the mortgage details
void print_mortgage(struct mortgage mortgage) {
    printf("Name: %s\n", mortgage.name);
    printf("Principal: $%.2f\n", mortgage.principal);
    printf("Interest Rate: %.2f%%\n", (INTEREST_RATE * 100));
    printf("Monthly Payment: $%.2f\n", mortgage.monthly_payment);
}

// Function to read the input from the user
struct mortgage read_input() {
    struct mortgage mortgage;
    printf("Enter your name: ");
    scanf("%s", mortgage.name);
    printf("Enter the principal amount: $");
    scanf("%lf", &mortgage.principal);
    mortgage.monthly_payment = calculate_monthly_payment(mortgage.principal, INTEREST_RATE, DURATION);
    return mortgage;
}

// Function to validate the input
int validate_input(struct mortgage mortgage) {
    if (strlen(mortgage.name) > MAX_LEN) {
        printf("Error: Name is too long.\n");
        return 0;
    }
    if (mortgage.principal <= 0) {
        printf("Error: Principal amount must be greater than zero.\n");
        return 0;
    }
    return 1;
}

int main() {
    struct mortgage mortgage;
    mortgage = read_input();
    if (validate_input(mortgage)) {
        print_mortgage(mortgage);
    }
    return 0;
}