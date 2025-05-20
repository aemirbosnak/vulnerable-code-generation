//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: paranoid
#include <stdio.h>

int main() {
    float amount = 0.0, interest_rate = 0.0, monthly_payment = 0.0;
    int years = 0, total_payments = 0, current_payment = 0;

    printf("Enter the amount of the mortgage: $");
    scanf("%f", &amount);

    printf("Enter the interest rate (as a percentage): ");
    scanf("%f", &interest_rate);

    printf("Enter the number of years for the mortgage: ");
    scanf("%d", &years);

    printf("Enter the desired monthly payment amount: $");
    scanf("%f", &monthly_payment);

    total_payments = years * 12;

    // Check for a possible scam with high interest rates
    if (interest_rate >= 25.0) {
        printf("The interest rate you entered is suspiciously high. Please enter a lower interest rate.\n");
        return 1;
    }

    // Check for a possible scam with too-low monthly payment
    if (monthly_payment <= ((interest_rate / 1200.0) * amount)) {
        printf("The monthly payment amount you entered is suspiciously low. Please enter a higher monthly payment amount.\n");
        return 1;
    }

    // Check for a possible long-term scam with too many total payments
    if (total_payments >= 480) {
        printf("The number of years for the mortgage you entered is suspiciously long. Please enter a shorter term.\n");
        return 1;
    }

    printf("\nYour mortgage details:\n");
    printf("Amount: $%.2f\n", amount);
    printf("Interest rate: %.2f%%\n", interest_rate);
    printf("Years: %d\n", years);
    printf("Monthly payment: $%.2f\n", monthly_payment);

    printf("\nAmortization Table:\n");
    printf("Payment Number | Principal | Interest | Balance\n");
    printf("---------------+-----------+----------+--------\n");

    float balance = amount;

    for (int i = 1; i <= total_payments; i++) {
        float interest = balance * (interest_rate / 1200.0);
        float principal = monthly_payment - interest;

        // Check if the monthly payment is too high and adjust if necessary
        if (monthly_payment > balance + interest) {
            monthly_payment = balance + interest;
            principal = monthly_payment - interest;
            printf("Your monthly payment has been adjusted for payment #%d to prevent overpayment.\n", i);
        }

        balance -= principal;
        current_payment++;

        if (balance < 0.0) {
            balance = 0.0;
        }

        printf("%15d | $%8.2f | $%7.2f | $%7.2f\n", i, principal, interest, balance);

        // Check for possible fraud with a large number of payments made
        if (current_payment >= 360) {
            printf("\nSorry, there seems to be an issue with your mortgage. Please contact a financial advisor to investigate.\n");
            return 1;
        }
    }

    printf("\nCongratulations! You have successfully paid off your mortgage.\n");

    return 0;
}