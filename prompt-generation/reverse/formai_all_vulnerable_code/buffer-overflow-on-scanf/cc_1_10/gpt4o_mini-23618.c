//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define USERNAME_LENGTH 20
#define PASSWORD_LENGTH 20

typedef struct {
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];
    float balance;
    int isLoggedIn;
} User;

User users[MAX_USERS];
int userCount = 0;

void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached. Cannot register more users.\n");
        return;
    }
    User newUser;
    printf("Enter username: ");
    scanf("%s", newUser.username);
    printf("Enter password: ");
    scanf("%s", newUser.password);
    newUser.balance = 0.0;
    newUser.isLoggedIn = 0;
    users[userCount++] = newUser;
    printf("User registered successfully!\n");
}

int locateUser(const char *username) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            return i;
        }
    }
    return -1;
}

void loginUser() {
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    int idx = locateUser(username);
    if (idx == -1 || strcmp(users[idx].password, password) != 0) {
        printf("Invalid username or password!\n");
        return;
    }
    users[idx].isLoggedIn = 1;
    printf("Login successful! Welcome, %s!\n", users[idx].username);
}

void depositMoney() {
    char username[USERNAME_LENGTH];
    float amount;
    printf("Enter your username: ");
    scanf("%s", username);

    int idx = locateUser(username);
    if (idx == -1 || !users[idx].isLoggedIn) {
        printf("You must be logged in to deposit money!\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    if (amount < 0) {
        printf("Deposit amount must be positive.\n");
        return;
    }
    users[idx].balance += amount;
    printf("Successfully deposited $%.2f to your account. New balance: $%.2f\n", amount, users[idx].balance);
}

void withdrawMoney() {
    char username[USERNAME_LENGTH];
    float amount;
    printf("Enter your username: ");
    scanf("%s", username);

    int idx = locateUser(username);
    if (idx == -1 || !users[idx].isLoggedIn) {
        printf("You must be logged in to withdraw money!\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount < 0) {
        printf("Withdrawal amount must be positive.\n");
        return;
    }
    if (users[idx].balance < amount) {
        printf("Insufficient funds! Current balance: $%.2f\n", users[idx].balance);
        return;
    }
    users[idx].balance -= amount;
    printf("Successfully withdrew $%.2f from your account. New balance: $%.2f\n", amount, users[idx].balance);
}

void displayAccountDetails() {
    char username[USERNAME_LENGTH];
    printf("Enter your username: ");
    scanf("%s", username);

    int idx = locateUser(username);
    if (idx == -1 || !users[idx].isLoggedIn) {
        printf("You must be logged in to view account details!\n");
        return;
    }

    printf("Account details for %s:\n", users[idx].username);
    printf("Balance: $%.2f\n", users[idx].balance);
}

int main() {
    int choice;
    while (1) {
        printf("\n=== Banking Record System ===\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. View Account Details\n");
        printf("6. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                depositMoney();
                break;
            case 4:
                withdrawMoney();
                break;
            case 5:
                displayAccountDetails();
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option, try again.\n");
        }
    }
    return 0;
}