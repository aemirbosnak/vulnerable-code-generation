//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    // Future-scape user interface
    system("clear");
    printf("WELCOME TO THE FUTURISTIC PERSONAL FINANCE MANAGER!\n");

    // Create a virtual account
    int account_num = rand() % 1000000;
    char account_name[20] = "John Doe's Account";

    // Define account balance
    double account_balance = 1000.0;

    // Display account information
    printf("Account Number: %d\n", account_num);
    printf("Account Name: %s\n", account_name);
    printf("Account Balance: $%.2lf\n", account_balance);

    // Simulate transactions
    double transaction_amount = 0.0;
    char transaction_type[20];

    // Loop until the user enters a valid transaction type
    printf("Enter transaction type (deposit/withdrawal): ");
    scanf("%s", transaction_type);

    // Validate transaction type
    if (strcmp(transaction_type, "deposit") == 0) {
        printf("Enter transaction amount: $");
        scanf("%lf", &transaction_amount);
        account_balance += transaction_amount;
    } else if (strcmp(transaction_type, "withdrawal") == 0) {
        printf("Enter transaction amount: $");
        scanf("%lf", &transaction_amount);
        if (account_balance - transaction_amount >= 0) {
            account_balance -= transaction_amount;
        } else {
            printf("Insufficient funds.\n");
        }
    } else {
        printf("Invalid transaction type.\n");
    }

    // Update account balance
    account_balance = account_balance;

    // Display updated account information
    printf("Updated Account Balance: $%.2lf\n", account_balance);

    // Exit the program
    printf("Thank you for using the futuristic personal finance manager. Goodbye!\n");
    return 0;
}