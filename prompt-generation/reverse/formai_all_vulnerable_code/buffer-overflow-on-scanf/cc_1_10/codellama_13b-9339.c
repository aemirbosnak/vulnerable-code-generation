//Code Llama-13B DATASET v1.0 Category: Personal Finance Planner ; Style: inquisitive
int main() {
    // Declare variables
    float balance, interest, principal, payments, total_payments;
    char option;
    int i;

    // Initialize variables
    balance = 0;
    interest = 0;
    principal = 0;
    payments = 0;
    total_payments = 0;
    option = 'n';
    i = 1;

    // Print menu
    printf("Welcome to the Personal Finance Planner!\n");
    printf("What would you like to do?\n");
    printf("1. Calculate the interest on your current balance\n");
    printf("2. Calculate the monthly payments for a loan\n");
    printf("3. Calculate the total payments for a loan\n");
    printf("4. Quit\n");
    printf("Enter your choice: ");

    // Get user input
    scanf("%d", &option);

    // Calculate interest on current balance
    if (option == '1') {
        printf("Enter your current balance: ");
        scanf("%f", &balance);
        interest = balance * 0.02;
        printf("Your interest is $%.2f\n", interest);
    }

    // Calculate monthly payments for a loan
    else if (option == '2') {
        printf("Enter the principal amount: ");
        scanf("%f", &principal);
        printf("Enter the interest rate: ");
        scanf("%f", &interest);
        payments = principal * (interest / 12);
        printf("Your monthly payments are $%.2f\n", payments);
    }

    // Calculate total payments for a loan
    else if (option == '3') {
        printf("Enter the principal amount: ");
        scanf("%f", &principal);
        printf("Enter the interest rate: ");
        scanf("%f", &interest);
        printf("Enter the number of payments: ");
        scanf("%d", &i);
        total_payments = principal * (interest / 12) * i;
        printf("Your total payments are $%.2f\n", total_payments);
    }

    // Quit
    else if (option == '4') {
        printf("Thank you for using the Personal Finance Planner!\n");
    }

    // Invalid option
    else {
        printf("Invalid option. Try again.\n");
    }

    return 0;
}