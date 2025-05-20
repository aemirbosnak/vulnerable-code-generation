//GEMINI-pro DATASET v1.0 Category: Password management ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 20
#define MAX_PASSLENGTH 30
#define MASTER_PASS "M@st3rP@ssw0rd"

// Account data structure
typedef struct {
    char username[30];
    char password[30];
} Account;

void displayMenu();
void addAccount(Account* accounts, int* numAccounts);
void viewAccount(Account* accounts, int numAccounts);
void editAccount(Account* accounts, int numAccounts);
void deleteAccount(Account* accounts, int* numAccounts);

int main() {
    int numAccounts = 0;
    Account accounts[MAX_ACCOUNTS];

    char masterPassword[30];

    printf("Welcome to the Visionary Password Manager!\n");

    // Prompt for master password
    printf("Enter master password: ");
    scanf("%s", masterPassword);

    // Check if the master password is correct
    if (strcmp(masterPassword, MASTER_PASS) != 0) {
        printf("Incorrect master password. Try again.\n");
        return 1;
    }

    // Display the menu
    int choice = 0;
    do {
        displayMenu();

        // Get user input
        scanf("%d", &choice);

        // Perform the selected action
        switch (choice) {
            case 1:
                addAccount(accounts, &numAccounts);
                break;
            case 2:
                viewAccount(accounts, numAccounts);
                break;
            case 3:
                editAccount(accounts, numAccounts);
                break;
            case 4:
                deleteAccount(accounts, &numAccounts);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Add an account\n");
    printf("2. View an account\n");
    printf("3. Edit an account\n");
    printf("4. Delete an account\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

void addAccount(Account* accounts, int* numAccounts) {
    if (*numAccounts >= MAX_ACCOUNTS) {
        printf("Sorry, you cannot add more than %d accounts.\n", MAX_ACCOUNTS);
        return;
    }

    // Get the account details
    printf("Enter username: ");
    scanf("%s", accounts[*numAccounts].username);
    printf("Enter password: ");
    scanf("%s", accounts[*numAccounts].password);

    // Increment the number of accounts
    (*numAccounts)++;

    printf("Account added successfully.\n");
}

void viewAccount(Account* accounts, int numAccounts) {
    if (numAccounts == 0) {
        printf("Sorry, there are no accounts to view.\n");
        return;
    }

    // Get the index of the account to view
    int index;
    printf("Enter the index of the account to view (0-%d): ", numAccounts - 1);
    scanf("%d", &index);

    // Check if the index is valid
    if (index < 0 || index >= numAccounts) {
        printf("Invalid index. Please enter a number between 0 and %d.\n", numAccounts - 1);
        return;
    }

    // Display the account details
    printf("Username: %s\n", accounts[index].username);
    printf("Password: %s\n", accounts[index].password);
}

void editAccount(Account* accounts, int numAccounts) {
    if (numAccounts == 0) {
        printf("Sorry, there are no accounts to edit.\n");
        return;
    }

    // Get the index of the account to edit
    int index;
    printf("Enter the index of the account to edit (0-%d): ", numAccounts - 1);
    scanf("%d", &index);

    // Check if the index is valid
    if (index < 0 || index >= numAccounts) {
        printf("Invalid index. Please enter a number between 0 and %d.\n", numAccounts - 1);
        return;
    }

    // Get the new account details
    printf("Enter new username: ");
    scanf("%s", accounts[index].username);
    printf("Enter new password: ");
    scanf("%s", accounts[index].password);

    printf("Account edited successfully.\n");
}

void deleteAccount(Account* accounts, int* numAccounts) {
    if (*numAccounts == 0) {
        printf("Sorry, there are no accounts to delete.\n");
        return;
    }

    // Get the index of the account to delete
    int index;
    printf("Enter the index of the account to delete (0-%d): ", *numAccounts - 1);
    scanf("%d", &index);

    // Check if the index is valid
    if (index < 0 || index >= *numAccounts) {
        printf("Invalid index. Please enter a number between 0 and %d.\n", *numAccounts - 1);
        return;
    }

    // Shift the accounts down to fill the gap
    for (int i = index; i < *numAccounts - 1; i++) {
        accounts[i] = accounts[i + 1];
    }

    // Decrement the number of accounts
    (*numAccounts)--;

    printf("Account deleted successfully.\n");
}