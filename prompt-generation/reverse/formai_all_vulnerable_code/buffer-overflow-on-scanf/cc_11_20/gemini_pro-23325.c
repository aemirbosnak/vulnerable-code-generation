//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: excited
// Welcome to C Banking Record System! Let's get our finances in shape!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our virtual bank account struct
typedef struct account {
    char name[50];
    int account_number;
    double balance;
} account_t;

account_t account_list[100]; // We can manage up to 100 bank accounts

int main() {
    // Let's get started with some awesome variables!
    int choice, i, account_count = 0;
    char ch;

    printf("Welcome to the C Banking Record System! Your personal finance assistant is here!\n\n");

    // Our main banking menu, where the magic happens!
    while (1) {
        printf("------------------------------------------------------------------\n");
        printf("MAIN MENU\n");
        printf("------------------------------------------------------------------\n");
        printf("1. Create a new bank account\n");
        printf("2. Deposit money into an account\n");
        printf("3. Withdraw money from an account\n");
        printf("4. Check account balance\n");
        printf("5. Display all accounts\n");
        printf("6. Exit the system\n");
        printf("------------------------------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Create a new bank account
                printf("Creating a new bank account...\n");
                printf("Enter your name: ");
                scanf(" %[^\n]%*c", account_list[account_count].name); // Let's use scanf's secret power to handle spaces in names!
                printf("Enter your account number: ");
                scanf("%d", &account_list[account_count].account_number);
                printf("Enter your initial deposit: ");
                scanf("%lf", &account_list[account_count].balance);
                printf("Congratulations! Your account has been created successfully.\n");
                account_count++;
                break;

            case 2: // Deposit money into an account
                printf("Depositing money into an account...\n");
                printf("Enter your account number: ");
                scanf("%d", &i);
                if (i >= 0 && i < account_count) {
                    printf("Enter the amount to deposit: ");
                    double amount;
                    scanf("%lf", &amount);
                    account_list[i].balance += amount;
                    printf("Amount deposited successfully.\n");
                } else {
                    printf("Invalid account number.\n");
                }
                break;

            case 3: // Withdraw money from an account
                printf("Withdrawing money from an account...\n");
                printf("Enter your account number: ");
                scanf("%d", &i);
                if (i >= 0 && i < account_count) {
                    printf("Enter the amount to withdraw: ");
                    double amount;
                    scanf("%lf", &amount);
                    if (amount <= account_list[i].balance) {
                        account_list[i].balance -= amount;
                        printf("Amount withdrawn successfully.\n");
                    } else {
                        printf("Insufficient funds.\n");
                    }
                } else {
                    printf("Invalid account number.\n");
                }
                break;

            case 4: // Check account balance
                printf("Checking account balance...\n");
                printf("Enter your account number: ");
                scanf("%d", &i);
                if (i >= 0 && i < account_count) {
                    printf("Your account balance is: %.2lf\n", account_list[i].balance);
                } else {
                    printf("Invalid account number.\n");
                }
                break;

            case 5: // Display all accounts
                printf("Displaying all accounts...\n");
                for (i = 0; i < account_count; i++) {
                    printf("Account %d:\n", i + 1);
                    printf("Name: %s\n", account_list[i].name);
                    printf("Account number: %d\n", account_list[i].account_number);
                    printf("Balance: %.2lf\n\n", account_list[i].balance);
                }
                if (account_count == 0) {
                    printf("No accounts to display.\n");
                }
                break;

            case 6: // Exit the system
                printf("Exiting the system...\n");
                printf("Thank you for using C Banking Record System!\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("Do you want to continue (Y/N)? ");
        scanf(" %c", &ch);
        if (ch == 'N' || ch == 'n') {
            printf("Exiting the system...\n");
            printf("Thank you for using C Banking Record System!\n");
            exit(0);
        }
    }

    return 0;
}