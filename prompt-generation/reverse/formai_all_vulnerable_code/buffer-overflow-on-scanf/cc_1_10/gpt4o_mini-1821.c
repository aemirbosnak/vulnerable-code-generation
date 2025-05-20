//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100

typedef struct {
    int accountNumber;
    char name[50];
    float balance;
} Customer;

Customer customers[MAX_CUSTOMERS];
int customerCount = 0;

void addCustomer() {
    if (customerCount >= MAX_CUSTOMERS) {
        printf("Whoa there! We can’t handle any more customers! Our bank is on a diet!\n");
        return;
    }

    Customer newCustomer;
    newCustomer.accountNumber = customerCount + 1; // For simplicity, account number is just index + 1
    printf("Welcome to the bank of Chuckle! What's your name? ");
    scanf("%s", newCustomer.name);
    newCustomer.balance = 0.0; // All new accounts start with zero balance
    customers[customerCount++] = newCustomer;
    printf("Hello, %s! Your account number is %d. You've officially joined the bank of Chuckle!\n\n", newCustomer.name, newCustomer.accountNumber);
}

void deposit() {
    int accountNumber;
    float amount;

    printf("Please enter your account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 1 || accountNumber > customerCount) {
        printf("Account number doesn't exist. Did you accidentally enter the number of pancakes you had for breakfast?\n");
        return;
    }

    printf("How much money would you like to deposit, oh noble banker? ");
    scanf("%f", &amount);
    
    if(amount < 0) {
        printf("Negative money? Are you trying to turn us into a black hole? Please, be kind to your banker!\n");
        return;
    }

    customers[accountNumber - 1].balance += amount;
    printf("Woohoo! You deposited $%.2f successfully! Your new balance is $%.2f! 🎉\n\n", amount, customers[accountNumber - 1].balance);
}

void withdraw() {
    int accountNumber;
    float amount;

    printf("Enter your account number to withdraw some cash: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 1 || accountNumber > customerCount) {
        printf("Account number doesn't exist. Did you enter your dog’s name instead? Woof woof!\n");
        return;
    }

    printf("How much would you like to withdraw? (Please don’t tell us it’s a vacation fund!) ");
    scanf("%f", &amount);

    if(amount < 0) {
        printf("Negative withdrawals? Are you trying to transfer funds to the abyss? Please refrain!\n");
        return;
    }

    if (customers[accountNumber - 1].balance < amount) {
        printf("Oops! You can’t withdraw this much! Your balance is thinner than a pancake!\n");
        return;
    }

    customers[accountNumber - 1].balance -= amount;
    printf("A miracle has happened! You withdrew $%.2f! Your new balance is $%.2f! Don’t spend it all in one place!\n\n", amount, customers[accountNumber - 1].balance);
}

void displayBalance() {
    int accountNumber;

    printf("Let us check your balance, oh well-to-do patron! Enter your account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 1 || accountNumber > customerCount) {
        printf("Account number doesn't exist. You must have a big imagination!\n");
        return;
    }

    printf("Dear %s, your current balance is: $%.2f. Spend wisely, or at least spend FUNNY!\n\n", customers[accountNumber - 1].name, customers[accountNumber - 1].balance);
}

void displayMenu() {
    printf("Welcome to the Wacky World of Chuckle Banking System! What would you like to do?\n");
    printf("1. Add Customer\n"
           "2. Deposit Money\n"
           "3. Withdraw Money\n"
           "4. Check Balance\n"
           "5. Exit\n");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Please enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                addCustomer(); 
                break;
            case 2: 
                deposit(); 
                break;
            case 3: 
                withdraw(); 
                break;
            case 4: 
                displayBalance(); 
                break;
            case 5:
                printf("Exiting... Thank you for banking with us! Keep smiling like a banknote! 😄\n"); 
                exit(0);
            default: 
                printf("Hmm... That choice looks as confused as a cat at a dog show. Try again!\n");
        }
    }

    return 0;
}