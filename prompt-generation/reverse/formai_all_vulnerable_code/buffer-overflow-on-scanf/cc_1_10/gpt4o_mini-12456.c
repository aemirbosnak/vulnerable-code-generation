//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100
#define NAME_LENGTH 30
#define PASSWORD_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    char password[PASSWORD_LENGTH];
    float balance;
} Customer;

Customer customers[MAX_CUSTOMERS];
int customerCount = 0;

void createAccount() {
    if (customerCount >= MAX_CUSTOMERS) {
        printf("Sorry, we are out of customers! Go make some friends!\n");
        return;
    }

    printf("Welcome to QuirkBank! Let's get you an account, shall we?\n");
    Customer newCustomer;
    printf("Enter your quirky name (up to %d characters): ", NAME_LENGTH - 1);
    scanf("%s", newCustomer.name);
    printf("Choose a super-secret password (up to %d characters): ", PASSWORD_LENGTH - 1);
    scanf("%s", newCustomer.password);
    newCustomer.balance = 0.0;

    customers[customerCount] = newCustomer;
    customerCount++;
    printf("Congratulations, %s! You've successfully opened an account at QuirkBank! Your balance is $%.2f.\n\n", newCustomer.name, newCustomer.balance);
}

void deposit() {
    char name[NAME_LENGTH], password[PASSWORD_LENGTH];
    float amount;

    printf("Time to deposit some cash! What’s your quirky name? ");
    scanf("%s", name);
    printf("And your password? ");
    scanf("%s", password);
    
    for (int i = 0; i < customerCount; i++) {
        if (strcmp(customers[i].name, name) == 0 && strcmp(customers[i].password, password) == 0) {
            printf("How much would you like to deposit? (No funny business!) ");
            scanf("%f", &amount);
            if (amount < 0) {
                printf("Oh no! Can't deposit negative money! Try again with a positive amount!\n");
                return;
            }
            customers[i].balance += amount;
            printf("You've deposited $%.2f! Your new balance is $%.2f.\n\n", amount, customers[i].balance);
            return;
        }
    }
    printf("Oops! That name or password is as wrong as a sock on a chicken!\n\n");
}

void withdraw() {
    char name[NAME_LENGTH], password[PASSWORD_LENGTH];
    float amount;

    printf("Time to make it rain! What’s your quirky name? ");
    scanf("%s", name);
    printf("And your password? ");
    scanf("%s", password);
    
    for (int i = 0; i < customerCount; i++) {
        if (strcmp(customers[i].name, name) == 0 && strcmp(customers[i].password, password) == 0) {
            printf("How much would you like to withdraw? (Don't take all the funny money!) ");
            scanf("%f", &amount);
            if (amount < 0) {
                printf("Whoa there! You can't withdraw negative money! What do you think this is, a magic show?\n");
                return;
            }
            if (amount > customers[i].balance) {
                printf("You can't withdraw more than you have! That’s like trying to pull a rabbit out of an empty hat!\n");
                return;
            }
            customers[i].balance -= amount;
            printf("You've withdrawn $%.2f! Your magical new balance is $%.2f.\n\n", amount, customers[i].balance);
            return;
        }
    }
    printf("Oops! That name or password is as wrong as a hat on a pumpkin!\n\n");
}

void checkBalance() {
    char name[NAME_LENGTH], password[PASSWORD_LENGTH];

    printf("Let's check how wealthy you are! What’s your quirky name? ");
    scanf("%s", name);
    printf("And your password? ");
    scanf("%s", password);
    
    for (int i = 0; i < customerCount; i++) {
        if (strcmp(customers[i].name, name) == 0 && strcmp(customers[i].password, password) == 0) {
            printf("Your balance is $%.2f! Now, isn’t that a sight for sore eyes?\n\n", customers[i].balance);
            return;
        }
    }
    printf("Oops! That name or password is as wrong as a flip-flop in the snow!\n\n");
}

void showMenu() {
    printf("Welcome to QuirkBank! Please choose an option:\n");
    printf("1. Create Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Check Balance\n");
    printf("5. Exit\n");
}

int main() {
    int choice;

    while (1) {
        showMenu();
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                printf("Thanks for banking with QuirkBank! Remember to stay quirky!\n");
                exit(0);
                break;
            default:
                printf("That’s not a valid choice! We don’t have a button for that quirky idea!\n\n");
                break;
        }
    }

    return 0;
}