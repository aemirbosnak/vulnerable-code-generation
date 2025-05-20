//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 50
#define MAX_TRANSACTIONS 100
#define BUFFER_SIZE 256

typedef struct {
    int id;
    char name[BUFFER_SIZE];
    double balance;
    char password[BUFFER_SIZE];
} Account;

typedef struct {
    int userId;
    char action[BUFFER_SIZE];
    double amount;
} Transaction;

Account accounts[MAX_USERS];
int userCount = 0;
Transaction transactions[MAX_TRANSACTIONS];
int transactionCount = 0;

// Function to encrypt passwords
void encryptPassword(char *password) {
    for (int i = 0; password[i] != '\0'; i++) {
        password[i] += i % 5;  // Simple encryption
    }
}

// Function to verify passwords
int verifyPassword(char *enteredPassword, char *storedPassword) {
    char encrypted[BUFFER_SIZE];
    strcpy(encrypted, enteredPassword);
    for (int i = 0; encrypted[i] != '\0'; i++) {
        encrypted[i] += i % 5;  // Reapply the encryption method
    }
    return strcmp(encrypted, storedPassword) == 0;
}

// Function to add a new user account
void addAccount() {
    if (userCount >= MAX_USERS) {
        printf("Account limit reached! Cannot create more accounts.\n");
        return;
    }
    
    Account newAccount;
    newAccount.id = userCount + 1;

    printf("Enter your name: ");
    fgets(newAccount.name, BUFFER_SIZE, stdin);
    newAccount.name[strcspn(newAccount.name, "\n")] = 0; // Remove newline

    printf("Set your password: ");
    fgets(newAccount.password, BUFFER_SIZE, stdin);
    newAccount.password[strcspn(newAccount.password, "\n")] = 0; // Remove newline
    encryptPassword(newAccount.password);

    newAccount.balance = 0.0; // Initialize balance to zero
    
    accounts[userCount++] = newAccount;

    printf("Account successfully created! Beware to keep your credentials safe!\n");
}

// Function to deposit money
void depositMoney(int userId) {
    double amount;
    printf("Enter amount to deposit: ");
    scanf("%lf", &amount);
    while (amount <= 0.0) {
        printf("Invalid amount. Try again: ");
        scanf("%lf", &amount);
    }
    accounts[userId - 1].balance += amount;

    // Log transaction
    Transaction newTransaction = {userId, "Deposit", amount};
    transactions[transactionCount++] = newTransaction;

    printf("Deposited %.2f to your account. Always check your balance!\n", amount);
}

// Function to withdraw money
void withdrawMoney(int userId) {
    double amount;
    printf("Enter amount to withdraw: ");
    scanf("%lf", &amount);
    while (amount <= 0.0 || amount > accounts[userId - 1].balance) {
        printf("Invalid amount. Must be less than or equal to your balance. Try again: ");
        scanf("%lf", &amount);
    }
    accounts[userId - 1].balance -= amount;

    // Log transaction
    Transaction newTransaction = {userId, "Withdraw", amount};
    transactions[transactionCount++] = newTransaction;

    printf("Withdrew %.2f from your account. Ensure you keep track of your finances!\n", amount);
}

// Function to view account details
void viewAccount(int userId) {
    printf("Account ID: %d\n", accounts[userId - 1].id);
    printf("Name: %s\n", accounts[userId - 1].name);
    printf("Balance: %.2f\n", accounts[userId - 1].balance);
}

// Validate user access
int validateUser() {
    int id;
    char password[BUFFER_SIZE];
    
    printf("Enter your account ID: ");
    scanf("%d", &id);
    if (id < 1 || id > userCount) {
        printf("Account does not exist. Always be wary!\n");
        return -1;
    }

    printf("Enter your password: ");
    getchar(); // Flush newline
    fgets(password, BUFFER_SIZE, stdin);
    password[strcspn(password, "\n")] = 0; // Remove newline

    if (!verifyPassword(password, accounts[id - 1].password)) {
        printf("Access denied! Suspicious activity detected!\n");
        return -1;
    }

    return id;
}

// Main program loop
int main() {
    int choice, userId;

    while (1) {
        printf("\n--- Paranoid Banking System ---\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. View Account\n");
        printf("5. Exit\n");
        printf("Choose an action: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAccount();
                break;
            case 2:
            case 3:
            case 4:
                userId = validateUser();
                if (userId != -1) {
                    if (choice == 2) {
                        depositMoney(userId);
                    } else if (choice == 3) {
                        withdrawMoney(userId);
                    } else {
                        viewAccount(userId);
                    }
                }
                break;
            case 5:
                printf("Exiting... Ensure all data is saved and secure!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Stay alert!\n");
        }
    }

    return 0;
}