//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_NAME_LENGTH 50
#define MAX_ACCOUNT_NUMBER_LENGTH 20
#define PIN_LENGTH 5

typedef struct {
    char name[MAX_NAME_LENGTH];
    char accountNumber[MAX_ACCOUNT_NUMBER_LENGTH];
    float balance;
    char pin[PIN_LENGTH];
} BankUser;

BankUser users[MAX_USERS];
int userCount = 0;

void addUser() {
    if (userCount >= MAX_USERS) {
        printf("Maximum user limit reached.\n");
        return;
    }

    printf("Registering new user:\n");
    BankUser newUser;

    printf("Enter name: ");
    fgets(newUser.name, MAX_NAME_LENGTH, stdin);
    newUser.name[strcspn(newUser.name, "\n")] = 0; // Remove trailing newline

    printf("Enter account number: ");
    fgets(newUser.accountNumber, MAX_ACCOUNT_NUMBER_LENGTH, stdin);
    newUser.accountNumber[strcspn(newUser.accountNumber, "\n")] = 0;

    printf("Set initial balance: ");
    scanf("%f", &newUser.balance);
    getchar(); // Consume newline

    printf("Set a 4-digit PIN: ");
    fgets(newUser.pin, PIN_LENGTH, stdin);
    newUser.pin[strcspn(newUser.pin, "\n")] = 0;

    if (strlen(newUser.pin) != 4 || !isdigit(newUser.pin[0])) {
        printf("Invalid PIN. Must be 4 digits long.\n");
        return;
    }

    users[userCount++] = newUser;
    printf("User '%s' registered successfully.\n", newUser.name);
}

int authenticateUser(char *accountNumber, char *pin) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].accountNumber, accountNumber) == 0 &&
            strcmp(users[i].pin, pin) == 0) {
            return i; // Return user index if authenticated
        }
    }
    return -1; // Authentication failed
}

void displayUserDetails(int userIndex) {
    if (userIndex >= 0 && userIndex < userCount) {
        printf("User Details:\n");
        printf("Name: %s\n", users[userIndex].name);
        printf("Account Number: %s\n", users[userIndex].accountNumber);
        printf("Balance: %.2f\n", users[userIndex].balance);
    } else {
        printf("Invalid user index.\n");
    }
}

void deposit(int userIndex) {
    if (userIndex < 0 || userIndex >= userCount) {
        printf("Invalid user.\n");
        return;
    }

    float amount;
    printf("Enter deposit amount: ");
    scanf("%f", &amount);
    getchar(); // Consume newline

    if (amount <= 0) {
        printf("Invalid amount! Deposit must be positive.\n");
        return;
    }

    users[userIndex].balance += amount;
    printf("Successfully deposited %.2f to %s's account.\n", amount, users[userIndex].name);
}

void withdraw(int userIndex) {
    if (userIndex < 0 || userIndex >= userCount) {
        printf("Invalid user.\n");
        return;
    }

    float amount;
    printf("Enter withdrawal amount: ");
    scanf("%f", &amount);
    getchar(); // Consume newline

    if (amount > users[userIndex].balance) {
        printf("Insufficient balance for withdrawal!\n");
        return;
    }
    if (amount <= 0) {
        printf("Invalid amount! Withdrawal must be positive.\n");
        return;
    }

    users[userIndex].balance -= amount;
    printf("Successfully withdrew %.2f from %s's account.\n", amount, users[userIndex].name);
}

void bankingOperations(int userIndex) {
    int choice;
    do {
        printf("\nBanking Operations Menu:\n");
        printf("1. View Details\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Exit\n");
        printf("Choose an operation: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                displayUserDetails(userIndex);
                break;
            case 2:
                deposit(userIndex);
                break;
            case 3:
                withdraw(userIndex);
                break;
            case 4:
                printf("Exiting banking operations.\n");
                break;
            default:
                printf("Invalid choice. Please select again.\n");
                break;
        }
    } while (choice != 4);
}

int main() {
    int option;

    do {
        printf("Banking Record System\n");
        printf("1. Register User\n");
        printf("2. User Login\n");
        printf("3. Exit\n");
        printf("Select an option: ");
        scanf("%d", &option);
        getchar(); // Consume newline

        switch (option) {
            case 1:
                addUser();
                break;
            case 2: {
                char accountNumber[MAX_ACCOUNT_NUMBER_LENGTH];
                char pin[PIN_LENGTH];

                printf("Enter account number: ");
                fgets(accountNumber, MAX_ACCOUNT_NUMBER_LENGTH, stdin);
                accountNumber[strcspn(accountNumber, "\n")] = 0;

                printf("Enter PIN: ");
                fgets(pin, PIN_LENGTH, stdin);
                pin[strcspn(pin, "\n")] = 0;

                int userIndex = authenticateUser(accountNumber, pin);
                if (userIndex != -1) {
                    printf("Login successful!\n");
                    bankingOperations(userIndex);
                } else {
                    printf("Login failed! Invalid account number or PIN.\n");
                }
                break;
            }
            case 3:
                printf("Exiting system. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please choose again.\n");
                break;
        }
    } while (option != 3);

    return 0;
}