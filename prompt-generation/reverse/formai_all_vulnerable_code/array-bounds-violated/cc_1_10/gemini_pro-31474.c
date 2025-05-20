//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cyberpunk-themed bank account structure
typedef struct {
    int account_number;
    char *name;
    double balance;
    char *city;
    char *occupation;
} cyberpunk_account;

// Array of account records
cyberpunk_account accounts[100];

// Function to create a new account
void create_account(int account_number, char *name, double balance, char *city, char *occupation) {
    accounts[account_number].account_number = account_number;
    accounts[account_number].name = malloc(strlen(name) + 1);
    strcpy(accounts[account_number].name, name);
    accounts[account_number].balance = balance;
    accounts[account_number].city = malloc(strlen(city) + 1);
    strcpy(accounts[account_number].city, city);
    accounts[account_number].occupation = malloc(strlen(occupation) + 1);
    strcpy(accounts[account_number].occupation, occupation);
}

// Function to print account details
void print_account(int account_number) {
    printf("Account Number: %d\n", accounts[account_number].account_number);
    printf("Name: %s\n", accounts[account_number].name);
    printf("Balance: %.2f\n", accounts[account_number].balance);
    printf("City: %s\n", accounts[account_number].city);
    printf("Occupation: %s\n", accounts[account_number].occupation);
}

// Function to make a withdrawal
void make_withdrawal(int account_number, double amount) {
    accounts[account_number].balance -= amount;
}

// Function to make a deposit
void make_deposit(int account_number, double amount) {
    accounts[account_number].balance += amount;
}

// Main function
int main() {
    // Create some sample accounts
    create_account(123456, "Jane Doe", 1000.00, "Neo-Tokyo", "Hacker");
    create_account(654321, "John Smith", 2000.00, "Night City", "Corpo");

    // Print account details
    print_account(123456);
    print_account(654321);

    // Make a withdrawal from account 123456
    make_withdrawal(123456, 500.00);

    // Make a deposit into account 654321
    make_deposit(654321, 1000.00);

    // Print account details again
    print_account(123456);
    print_account(654321);

    return 0;
}