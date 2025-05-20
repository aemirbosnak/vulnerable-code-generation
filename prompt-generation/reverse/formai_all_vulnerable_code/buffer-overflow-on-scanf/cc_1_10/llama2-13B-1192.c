//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

// Define a struct to hold the bank's data
struct bank {
    int balance;
};

// Define a function to handle errors
void error_handler(const char *message) {
    printf("Oopsie! %s\n", message);
}

int main() {
    // Create a new bank with $100
    struct bank bank = {100};

    // Loop until the user quits
    while (1) {
        // Ask the user for a command (deposit, withdraw, or quit)
        char command[50];
        printf("Enter a command (d/ deposit, w/ withdraw, or q/ quit): ");
        fgets(command, 50, stdin);

        // Parse the command
        if (strcmp(command, "d") == 0) {
            // Ask the user for an amount to deposit
            int amount;
            printf("Enter an amount to deposit: ");
            scanf("%d", &amount);

            // Check if the amount is valid
            if (amount > 0) {
                bank.balance += amount;
                printf("Deposit successful! Your balance is now %d\n", bank.balance);
            } else {
                error_handler("Invalid amount");
            }
        } else if (strcmp(command, "w") == 0) {
            // Ask the user for an amount to withdraw
            int amount;
            printf("Enter an amount to withdraw: ");
            scanf("%d", &amount);

            // Check if the amount is valid
            if (amount > 0 && amount <= bank.balance) {
                bank.balance -= amount;
                printf("Withdrawal successful! Your balance is now %d\n", bank.balance);
            } else {
                error_handler("Invalid amount");
            }
        } else if (strcmp(command, "q") == 0) {
            break;
        } else {
            error_handler("Invalid command");
        }
    }

    // Print the final balance
    printf("Your final balance is %d\n", bank.balance);

    return 0;
}