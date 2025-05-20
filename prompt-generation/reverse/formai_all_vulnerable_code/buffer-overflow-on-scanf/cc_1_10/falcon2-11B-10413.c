//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: paranoid
#include <stdio.h>

int main() {
    // Initialize the balance to 0
    int balance = 0;

    // Get the initial balance from the user
    printf("Enter the initial balance: ");
    scanf("%d", &balance);

    // Loop until the user quits
    while (1) {
        // Prompt the user for input
        printf("Enter 'd' to deposit, 'w' to withdraw, or 'q' to quit: ");

        // Read the user's input
        char input;
        scanf(" %c", &input);

        // Handle the different input options
        switch (input) {
            case 'd':
                // Prompt the user for the amount to deposit
                printf("Enter the amount to deposit: ");
                int deposit_amount;
                scanf("%d", &deposit_amount);

                // Check if the amount is positive and less than the balance
                if (deposit_amount > 0 && deposit_amount <= balance) {
                    // Add the deposit amount to the balance
                    balance += deposit_amount;

                    // Print a confirmation message
                    printf("Deposit of $%d accepted.\n", deposit_amount);
                } else {
                    // Print an error message if the amount is negative or exceeds the balance
                    printf("Invalid deposit amount.\n");
                }
                break;

            case 'w':
                // Prompt the user for the amount to withdraw
                printf("Enter the amount to withdraw: ");
                int withdrawal_amount;
                scanf("%d", &withdrawal_amount);

                // Check if the amount is positive and less than the balance
                if (withdrawal_amount > 0 && withdrawal_amount <= balance) {
                    // Subtract the withdrawal amount from the balance
                    balance -= withdrawal_amount;

                    // Print a confirmation message
                    printf("Withdrawal of $%d accepted.\n", withdrawal_amount);
                } else {
                    // Print an error message if the amount is negative or exceeds the balance
                    printf("Invalid withdrawal amount.\n");
                }
                break;

            case 'q':
                // Exit the loop and print a goodbye message
                printf("Goodbye!\n");
                break;

            default:
                // Print an error message if the input is invalid
                printf("Invalid input.\n");
                break;
        }
    }

    return 0;
}