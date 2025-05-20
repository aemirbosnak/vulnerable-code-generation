//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define NAME_LENGTH 50
#define PASSWORD_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    char password[PASSWORD_LENGTH];
    double balance;
    int isActive;
} User;

User users[MAX_USERS];
int userCount = 0;

// Function Declarations
void registerUser();
void loginUser();
void deposit(int userIndex);
void withdraw(int userIndex);
void checkBalance(int userIndex);
void displayMenu(int userIndex);

int main() {
    int choice;

    while (1) {
        printf("\n=== Banking Record System ===\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                printf("Exiting system. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached. Cannot register more users.\n");
        return;
    }

    User newUser;
    printf("Enter your name: ");
    scanf("%s", newUser.name);
    printf("Enter your password: ");
    scanf("%s", newUser.password);
    newUser.balance = 0.0;
    newUser.isActive = 0;

    users[userCount++] = newUser;
    printf("Registered successfully! You can now login.\n");
}

void loginUser() {
    char name[NAME_LENGTH], password[PASSWORD_LENGTH];
    int found = -1;
    
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].name, name) == 0 && strcmp(users[i].password, password) == 0) {
            found = i;
            users[i].isActive = 1; // Set user as active
            break;
        }
    }

    if (found != -1) {
        displayMenu(found);
    } else {
        printf("Login failed. Invalid name or password.\n");
    }
}

void displayMenu(int userIndex) {
    int choice;
    while (1) {
        printf("\n=== Welcome, %s ===\n", users[userIndex].name);
        printf("1. Deposit Money\n");
        printf("2. Withdraw Money\n");
        printf("3. Check Balance\n");
        printf("4. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                deposit(userIndex);
                break;
            case 2:
                withdraw(userIndex);
                break;
            case 3:
                checkBalance(userIndex);
                break;
            case 4:
                users[userIndex].isActive = 0; // Set user as inactive
                printf("Logged out successfully.\n");
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void deposit(int userIndex) {
    double amount;
    printf("Enter amount to deposit: ");
    scanf("%lf", &amount);
    
    if (amount > 0) {
        users[userIndex].balance += amount;
        printf("Successfully deposited $%.2lf. New balance: $%.2lf\n", amount, users[userIndex].balance);
    } else {
        printf("Invalid amount. Please try again.\n");
    }
}

void withdraw(int userIndex) {
    double amount;
    printf("Enter amount to withdraw: ");
    scanf("%lf", &amount);

    if (amount > 0 && amount <= users[userIndex].balance) {
        users[userIndex].balance -= amount;
        printf("Successfully withdrew $%.2lf. New balance: $%.2lf\n", amount, users[userIndex].balance);
    } else {
        printf("Invalid amount or insufficient balance. Please try again.\n");
    }
}

void checkBalance(int userIndex) {
    printf("Your current balance is: $%.2lf\n", users[userIndex].balance);
}