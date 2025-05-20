//FormAI DATASET v1.0 Category: Banking Record System ; Style: energetic
#include <stdio.h>

// Define a user-defined data type to hold account information
typedef struct {
    int accNumber;
    char accHolder[100];
    float balance;
} Account;

// Function to initialize an account
void initialize(Account *acc) {
    printf("Enter the account number: ");
    scanf("%d", &acc->accNumber);
    printf("Enter the account holder name: ");
    scanf("%s", acc->accHolder);
    printf("Enter the opening balance: ");
    scanf("%f", &acc->balance);
}

// Function to deposit money into an account
void deposit(Account *acc) {
    float amount;
    printf("Enter the amount to deposit: ");
    scanf("%f", &amount);
    acc->balance += amount;
}

// Function to withdraw money from an account
void withdraw(Account *acc) {
    float amount;
    printf("Enter the amount to withdraw: ");
    scanf("%f", &amount);
    if (amount <= acc->balance) {
        acc->balance -= amount;
    } else {
        printf("Withdrawal amount is greater than available balance.\n");
    }
}

// Function to display account information
void display(Account *acc) {
    printf("Account number: %d\n", acc->accNumber);
    printf("Account holder name: %s\n", acc->accHolder);
    printf("Account balance: %.2f\n", acc->balance);
}

int main() {

    // Maximum of 100 accounts can be created.
    Account accounts[100];
    int numAccounts = 0;
    int choice;
    int i;

    do {
        printf("\n***** BANKING RECORD SYSTEM *****\n");
        printf("1. Create a new account\n");
        printf("2. Deposit money in an account\n");
        printf("3. Withdraw money from an account\n");
        printf("4. Display account information\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Create a new account
                initialize(&accounts[numAccounts]);
                numAccounts++;
                break;
            case 2: // Deposit money in an account
                printf("Enter the account number: ");
                int depositAccNum;
                scanf("%d", &depositAccNum);
                for (i = 0; i < numAccounts; i++) {
                    if (accounts[i].accNumber == depositAccNum) {
                        deposit(&accounts[i]);
                        break;
                    }
                }
                if (i == numAccounts) {
                    printf("Account number not found.\n");
                }
                break;
            case 3: // Withdraw money from an account
                printf("Enter the account number: ");
                int withdrawAccNum;
                scanf("%d", &withdrawAccNum);
                for (i = 0; i < numAccounts; i++) {
                    if (accounts[i].accNumber == withdrawAccNum) {
                        withdraw(&accounts[i]);
                        break;
                    }
                }
                if (i == numAccounts) {
                    printf("Account number not found.\n");
                }
                break;
            case 4: // Display account information
                printf("Enter the account number: ");
                int displayAccNum;
                scanf("%d", &displayAccNum);
                for (i = 0; i < numAccounts; i++) {
                    if (accounts[i].accNumber == displayAccNum) {
                        display(&accounts[i]);
                        break;
                    }
                }
                if (i == numAccounts) {
                    printf("Account number not found.\n");
                }
                break;
            case 5: // Exit
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}