//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: cheerful
#include <stdio.h>

// Define the structure of a banking record
struct BankingRecord {
    int accountNumber;
    char name[50];
    double balance;
};

int main() {
    int choice;
    struct BankingRecord record;

    // Initialize the account number to 0
    record.accountNumber = 0;

    // Initialize the name to an empty string
    strcpy(record.name, "");

    // Initialize the balance to 0
    record.balance = 0;

    // Start the program
    do {
        // Display the main menu
        printf("Welcome to the Happy Banking Record System!\n");
        printf("Please choose an option:\n");
        printf("1. Create account\n");
        printf("2. Deposit money\n");
        printf("3. Withdraw money\n");
        printf("4. Check balance\n");
        printf("5. Exit\n");

        // Get the user's choice
        scanf("%d", &choice);

        // Perform the chosen action
        switch (choice) {
        case 1:
            // Create account
            printf("Please enter your name:\n");
            scanf("%s", record.name);
            printf("Your account number is %d.\n", record.accountNumber);
            break;
        case 2:
            // Deposit money
            printf("Please enter the amount to deposit:\n");
            scanf("%lf", &record.balance);
            printf("You have successfully deposited $%.2f.\n", record.balance);
            break;
        case 3:
            // Withdraw money
            printf("Please enter the amount to withdraw:\n");
            scanf("%lf", &record.balance);
            printf("You have successfully withdrawn $%.2f.\n", record.balance);
            break;
        case 4:
            // Check balance
            printf("Your current balance is $%.2f.\n", record.balance);
            break;
        case 5:
            // Exit the program
            printf("Goodbye! Have a happy day!\n");
            break;
        default:
            // Invalid choice
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 5);

    // Return 0 to indicate successful program termination
    return 0;
}