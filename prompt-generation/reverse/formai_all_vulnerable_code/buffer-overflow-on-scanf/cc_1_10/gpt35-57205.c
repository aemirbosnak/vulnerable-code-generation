//FormAI DATASET v1.0 Category: Banking Record System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

// Structure definition for Account
struct Account {
    int acc_num;
    char name[MAX];
    char address[MAX];
    int balance;
} acc[MAX];

// Declare functions for menu items
void addAccount();
void deleteAccount();
void updateAccount();
void viewAllAccounts();
void viewAccountDetails();

// Declare function for checking if account already exists
bool findAccount(int);

int main() {
    int i, choice, acc_num;
    char temp[MAX];
    do {
        // Display menu
        printf("\n\nBANKING RECORD SYSTEM");
        printf("\n1. Add an account");
        printf("\n2. Delete an account");
        printf("\n3. Update an account");
        printf("\n4. View All Accounts");
        printf("\n5. View Account Details");
        printf("\n6. Exit");

        // Get input from user
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add account
                addAccount();
                break;
            case 2: // Delete account
                deleteAccount();
                break;
            case 3: // Update account
                updateAccount();
                break;
            case 4: // View all accounts
                viewAllAccounts();
                break;
            case 5: // View account details
                viewAccountDetails();
                break;
            case 6: // Exit
                printf("\nExiting program...");
                exit(0);
            default:
                printf("\nInvalid choice, please try again.");
                break;
        }
    } while (choice != 6);
    return 0;
}

void addAccount() {
    // Find free slot to add account
    int i;
    for (i = 0; i < MAX; i++) {
        if (acc[i].acc_num == 0) break;
    }
    // Check if all accounts already exist
    if (i == MAX) {
        printf("\nCannot add account as maximum number of accounts already exist.");
        return;
    }
    // Get account details from user
    printf("\nEnter Account Number: ");
    scanf("%d", &acc[i].acc_num);
    getchar(); // Consume newline character
    // Check if account already exists
    if (findAccount(acc[i].acc_num)) {
        printf("\nAccount with account number %d already exists.", acc[i].acc_num);
        return;
    }
    printf("Enter Name: ");
    fgets(acc[i].name, sizeof(acc[i].name), stdin);
    printf("Enter Address: ");
    fgets(acc[i].address, sizeof(acc[i].address), stdin);
    printf("Enter Balance: ");
    scanf("%d", &acc[i].balance);
    printf("\nAccount added successfully.");
}

void deleteAccount() {
    int acc_num, i;
    printf("\nEnter Account Number: ");
    scanf("%d", &acc_num);
    // Check if account exists
    for (i = 0; i < MAX; i++) {
        if (acc[i].acc_num == acc_num) {
            // Account found, delete it
            acc[i].acc_num = 0; // Set account number to zero
            acc[i].name[0] = '\0'; // Set name to empty string
            acc[i].address[0] = '\0'; // Set address to empty string
            acc[i].balance = 0; // Set balance to zero
            printf("\nAccount with account number %d deleted successfully.", acc_num);
            return;
        }
    }
    printf("\nCannot delete account as account with account number %d does not exist.", acc_num);
}

void updateAccount() {
    int acc_num, i;
    printf("\nEnter Account Number: ");
    scanf("%d", &acc_num);
    // Check if account exists
    for (i = 0; i < MAX; i++) {
        if (acc[i].acc_num == acc_num) {
            // Account found, get updated details from user
            getchar(); // Consume newline character
            printf("Enter Name: ");
            fgets(acc[i].name, sizeof(acc[i].name), stdin);
            printf("Enter Address: ");
            fgets(acc[i].address, sizeof(acc[i].address), stdin);
            printf("Enter Balance: ");
            scanf("%d", &acc[i].balance);
            printf("\nAccount with account number %d updated successfully.", acc_num);
            return;
        }
    }
    printf("\nCannot update account as account with account number %d does not exist.", acc_num);
}

void viewAllAccounts() {
    int i;
    printf("\nAll Accounts:\n");
    printf("Account Number\tName\t\tAddress\t\tBalance\n");
    for (i = 0; i < MAX; i++) {
        if (acc[i].acc_num != 0)
            printf("%d\t\t%s\t\t%s\t%d\n", acc[i].acc_num, acc[i].name, acc[i].address, acc[i].balance);
    }
}

void viewAccountDetails() {
    int acc_num, i;
    printf("\nEnter Account Number: ");
    scanf("%d", &acc_num);
    // Check if account exists
    for (i = 0; i < MAX; i++) {
        if (acc[i].acc_num == acc_num) {
            // Account found, display its details
            printf("\nDetails of account with account number %d:\n", acc_num);
            printf("Name\t\tAddress\t\tBalance\n");
            printf("%s\t\t%s\t%d\n", acc[i].name, acc[i].address, acc[i].balance);
            return;
        }
    }
    printf("\nCannot display account details as account with account number %d does not exist.", acc_num);
}

bool findAccount(int acc_num) {
    int i;
    for (i = 0; i < MAX; i++) {
        if (acc[i].acc_num == acc_num) return true;
    }
    return false;
}