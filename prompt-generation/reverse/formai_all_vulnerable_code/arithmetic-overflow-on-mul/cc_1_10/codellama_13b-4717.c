//Code Llama-13B DATASET v1.0 Category: Banking Record System ; Style: romantic
// Banking Record System in a romantic style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Struct to store bank account information
typedef struct {
    char name[50];
    int account_number;
    float balance;
} BankAccount;

// Function to print the header of the banking record
void print_header() {
    printf("-----------------------------------------------------------------\n");
    printf("|                    Banking Record System                      |\n");
    printf("-----------------------------------------------------------------\n");
}

// Function to print the menu of options
void print_menu() {
    printf("-----------------------------------------------------------------\n");
    printf("|   1. Deposit Money                                            |\n");
    printf("|   2. Withdraw Money                                           |\n");
    printf("|   3. Check Balance                                            |\n");
    printf("|   4. Transfer Money                                           |\n");
    printf("|   5. Exit                                                     |\n");
    printf("-----------------------------------------------------------------\n");
}

// Function to get the account number from the user
int get_account_number() {
    int account_number;
    printf("Enter the account number: ");
    scanf("%d", &account_number);
    return account_number;
}

// Function to get the amount to be deposited or withdrawn from the user
float get_amount() {
    float amount;
    printf("Enter the amount: ");
    scanf("%f", &amount);
    return amount;
}

// Function to get the account number and amount from the user and perform the deposit operation
void deposit_money() {
    int account_number = get_account_number();
    float amount = get_amount();
    printf("Depositing %f into account number %d\n", amount, account_number);
}

// Function to get the account number and amount from the user and perform the withdraw operation
void withdraw_money() {
    int account_number = get_account_number();
    float amount = get_amount();
    printf("Withdrawing %f from account number %d\n", amount, account_number);
}

// Function to get the account number from the user and display the balance
void check_balance() {
    int account_number = get_account_number();
    printf("Balance of account number %d is %f\n", account_number, account_number * 100);
}

// Function to get the account number and amount from the user and perform the transfer operation
void transfer_money() {
    int from_account_number = get_account_number();
    int to_account_number = get_account_number();
    float amount = get_amount();
    printf("Transferring %f from account number %d to account number %d\n", amount, from_account_number, to_account_number);
}

// Function to exit the program
void exit_program() {
    printf("Exiting the program\n");
}

// Main function to run the program
int main() {
    int option;
    do {
        print_header();
        print_menu();
        printf("Enter your option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                deposit_money();
                break;
            case 2:
                withdraw_money();
                break;
            case 3:
                check_balance();
                break;
            case 4:
                transfer_money();
                break;
            case 5:
                exit_program();
                break;
            default:
                printf("Invalid option. Please try again\n");
                break;
        }
    } while (option != 5);
    return 0;
}