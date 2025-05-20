//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: paranoid
#include<stdio.h>

int main() {

char name[100], pin[10], ans;
double principal, rate, time, interest, total, amount;

printf("Welcome to Secure Mortgage Calculator!\n");
printf("Please enter your name: ");
scanf("%s", name);

printf("Enter your 4-digit PIN: ");
scanf("%s", pin);

printf("Are you sure you want to proceed? (Y/N): ");
scanf(" %c", &ans);

if (ans == 'Y' || ans == 'y') {

printf("\nEnter the mortgage amount: ");
scanf("%lf", &principal);

printf("Enter the interest rate (in percentage): ");
scanf("%lf", &rate);

printf("Enter the time period (in years): ");
scanf("%lf", &time);

interest = (principal * rate * time) / 100.0;
total = principal + interest;
amount = total / (time * 12);

printf("\nCalculating your mortgage...\n");

sleep(3);

printf("\nHi %s, your monthly mortgage payment is $ %.2lf\n", name, amount);

printf("\nThank you for using Secure Mortgage Calculator!\n");

} else if (ans == 'N' || ans == 'n') {

printf("\nYour security matters to us! Goodbye!\n");

} else {

printf("\nInvalid response. Please try again.\n");

}

return 0;
}