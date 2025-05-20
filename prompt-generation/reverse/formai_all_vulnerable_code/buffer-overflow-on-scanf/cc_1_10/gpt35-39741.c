//FormAI DATASET v1.0 Category: Banking Record System ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ACCOUNTS 100 // Maximum number of accounts that can be stored
#define PASSWORD_LENGTH 10 // Maximum length for the login password
#define MAX_TRANSACTIONS 100 // Maximum number of transactions per account
#define MAX_TRY_COUNT 5 // Maximum number of login attempts allowed
#define PARANOID_LEVEL 3 // Level of paranoia for the system (tie this to security measures)

// Define struct for transactions
typedef struct {
    char type; // 'd' for deposit, 'w' for withdrawal
    double amount;
    char date[11]; // Stores date of transaction in format DD/MM/YYYY
} transaction_t;

// Define struct for account
typedef struct {
    int account_number;
    char password[PASSWORD_LENGTH+1]; // Extra character for null termination
    double balance;
    transaction_t transactions[MAX_TRANSACTIONS];
    int transaction_count;
} account_t;

// Globals
account_t accounts[MAX_ACCOUNTS];
int account_count = 0; // Number of current accounts stored

// Function prototypes
void clean_stdin(void);
int login(void);
void logout(void);
void view_account(int);
void make_transaction(int);
void deposit(int, double);
void withdraw(int, double);
void view_transactions(int);

int main(void) {
    int choice;
    int current_account = -1;

    while(1) {
        printf("-------------\n");
        printf("BANKING SYSTEM\n");
        printf("-------------\n");
        printf("1. Login\n");
        printf("2. View Account\n");
        printf("3. Make Transaction\n");
        printf("4. Logout\n");
        printf("5. Exit\n");
        
        // Paranoid check
        if (PARANOID_LEVEL >= 2) {
            char buffer[256];
            printf("Admin access code: ");
            fgets(buffer, sizeof(buffer), stdin);
            if (strcmp(buffer, "sup3rs3cr3t\n") == 0) {
                printf("Welcome %s\n", buffer);
                // Paranoid check
                if (PARANOID_LEVEL >= 3) {
                    printf("Paranoid level 3: Deleting all account records...\n");
                    memset(accounts, 0, sizeof(accounts));
                    account_count = 0;
                }
            }
        }

        printf("Enter choice: ");
        scanf("%d", &choice);
        clean_stdin(); // Clean std input

        switch(choice) {
            case 1:
                current_account = login();
                break;
            case 2:
                if (current_account != -1) {
                    view_account(current_account);
                } else {
                    printf("Please login first.\n");
                }
                break;
            case 3:
                if (current_account != -1) {
                    make_transaction(current_account);
                } else {
                    printf("Please login first.\n");
                }
                break;
            case 4:
                logout();
                current_account = -1;
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

// Helper function to clean std input
void clean_stdin(void) {
    int c = getchar();
    while (c != '\n' && c != EOF) {
        c = getchar();
    }
    if (PARANOID_LEVEL >= 1) {
        printf("Cleaned input.\n");
    }
}

// Handles user login
int login(void) {
    int account_number, i, tries_left = MAX_TRY_COUNT;
    char password[PASSWORD_LENGTH+1];

    while(tries_left) {
        printf("Enter account number: ");
        scanf("%d", &account_number);
        clean_stdin();

        // Check if account number exists
        for(i=0; i<account_count; i++) {
            if (accounts[i].account_number == account_number) {
                break;
            }
        }

        if (i == account_count) {
            printf("Account not found. Please try again.\n");
            tries_left--;
        } else {
            printf("Enter password: ");
            fgets(password, sizeof(password), stdin);
            password[strlen(password)-1] = '\0'; // Remove newline character

            if (strcmp(accounts[i].password, password) == 0) {
                printf("Login successful!\n");
                return i; // Return index of account struct
            } else {
                printf("Incorrect password. ");
                tries_left--;
                printf("%d tries left.\n", tries_left);
            }
        }
    }

    printf("Too many incorrect attempts. Returning to main menu.\n");
    return -1;
}

// Logs user out
void logout(void) {
    if (PARANOID_LEVEL >= 1) {
        printf("User logged out.\n");
    }
}

// Displays an account's details
void view_account(int index) {
    account_t account = accounts[index];
    printf("Account number: %d\n", account.account_number);
    printf("Balance: %.2f\n", account.balance);
    printf("Transaction history:\n");
    view_transactions(index);
}

// Prompts user for transaction type
void make_transaction(int index) {
    char choice;
    double amount;

    printf("d - Deposit\nw - Withdrawal\nEnter choice: ");
    scanf(" %c", &choice);
    clean_stdin();

    printf("Enter amount: ");
    scanf("%lf", &amount);
    clean_stdin();

    if (choice == 'd') {
        deposit(index, amount);
    } else if (choice == 'w') {
        withdraw(index, amount);
    } else {
        printf("Invalid choice.\n");
    }
}

// Deposits funds into an account
void deposit(int index, double amount) {
    accounts[index].balance += amount;
    strcpy(accounts[index].transactions[accounts[index].transaction_count].date, "CHANGE THIS TO CURRENT DATE"); // Paranoid measure to prevent snooping
    accounts[index].transactions[accounts[index].transaction_count].type = 'd';
    accounts[index].transactions[accounts[index].transaction_count].amount = amount;
    accounts[index].transaction_count++;
    printf("Deposit successful! New balance: %.2f\n", accounts[index].balance);
}

// Withdraws funds from an account
void withdraw(int index, double amount) {
    if (amount > accounts[index].balance) {
        printf("Insufficient funds.\n");
    } else {
        accounts[index].balance -= amount;
        strcpy(accounts[index].transactions[accounts[index].transaction_count].date, "CHANGE THIS TO CURRENT DATE"); // Paranoid measure to prevent snooping
        accounts[index].transactions[accounts[index].transaction_count].type = 'w';
        accounts[index].transactions[accounts[index].transaction_count].amount = amount;
        accounts[index].transaction_count++;
        printf("Withdrawal successful! New balance: %.2f\n", accounts[index].balance);
    }
}

// Displays transaction history for an account
void view_transactions(int index) {
    transaction_t* transactions = accounts[index].transactions;
    int count = accounts[index].transaction_count;
    int i;

    for(i=0; i<count; i++) {
        printf("%s - %c %.2f\n", transactions[i].date, transactions[i].type, transactions[i].amount);
    }
}