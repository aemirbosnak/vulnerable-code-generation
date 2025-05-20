//GPT-4o-mini DATASET v1.0 Category: Mortgage Calculator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void display_intro() {
    printf("====================================\n");
    printf("  Welcome to the Neon Mortgage\n");
    printf("____________________________________\n");
    printf("In a world where debt reigns supreme,\n");
    printf("Calculate your mortgage before it consumes you.\n");
    printf("====================================\n");
}

double calculate_monthly_payment(double principal, double annual_rate, int years) {
    double monthly_rate = annual_rate / 100 / 12;
    int number_of_payments = years * 12;
    
    return (principal * monthly_rate) / (1 - pow(1 + monthly_rate, -number_of_payments));
}

void get_user_input(double *principal, double *annual_rate, int *years) {
    char input[MAX_INPUT_LENGTH];

    printf("Enter the principal amount (the sum of your debts): ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    *principal = atof(input);

    printf("Enter the annual interest rate (in percentage): ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    *annual_rate = atof(input);

    printf("Enter the number of years for the mortgage: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    *years = atoi(input);
}

void display_results(double principal, double annual_rate, int years, double monthly_payment) {
    printf("\n===============================\n");
    printf("     Mortgage Calculation       \n");
    printf("===============================\n");
    printf("Principal Amount:  $%.2f\n", principal);
    printf("Annual Interest Rate:  %.2f%%\n", annual_rate);
    printf("Duration:  %d years\n", years);
    printf("Monthly Payment:  $%.2f\n", monthly_payment);
    printf("===============================\n");
}

void prompt_to_continue() {
    char choice[MAX_INPUT_LENGTH];
    printf("Do you want to calculate another mortgage? (y/n): ");
    fgets(choice, MAX_INPUT_LENGTH, stdin);
    clear_input_buffer();
    
    if (choice[0] == 'y' || choice[0] == 'Y') {
        printf("\nRebooting...\n");
        main(); // restart the program
    } else {
        printf("Terminating the program. May the neon lights guide your path.\n");
        exit(0);
    }
}

int main() {
    double principal, annual_rate, monthly_payment;
    int years;

    display_intro();
    
    while (1) {
        get_user_input(&principal, &annual_rate, &years);
        
        monthly_payment = calculate_monthly_payment(principal, annual_rate, years);
        
        display_results(principal, annual_rate, years, monthly_payment);
        
        prompt_to_continue();
    }
    
    return 0;
}