//FormAI DATASET v1.0 Category: Password management ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASS_LENGTH 20
#define MAX_ACCTS_NUMBER 10

// Structure to hold account information
struct account {
    char name[MAX_PASS_LENGTH];
    char username[MAX_PASS_LENGTH];
    char password[MAX_PASS_LENGTH];
};

// Function to create new account given a set of credentials
void create_account(struct account *accounts, int *num_accts) {
    if (*num_accts >= MAX_ACCTS_NUMBER) {
        printf("Maximum number of accounts exceeded.\n");
        return;
    }

    char name[MAX_PASS_LENGTH];
    char username[MAX_PASS_LENGTH];
    char password[MAX_PASS_LENGTH];

    // Gather account information from user input
    printf("Enter account name: ");
    scanf("%s", name);
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    // Add account to array
    strcpy(accounts[*num_accts].name, name);
    strcpy(accounts[*num_accts].username, username);
    strcpy(accounts[*num_accts].password, password);
    (*num_accts)++;
}

// Function to search for an account by name
void search_accounts(struct account *accounts, int num_accts) {
    char name[MAX_PASS_LENGTH];
    printf("Enter account name to search for: ");
    scanf("%s", name);

    // Iterate through array and print any matching accounts
    for (int i = 0; i < num_accts; i++) {
        if (strcmp(name, accounts[i].name) == 0) {
            printf("Account found:\n");
            printf("Name: %s\nUsername: %s\nPassword: %s\n", accounts[i].name, accounts[i].username, accounts[i].password);
            return;
        }
    }
    
    // Account not found
    printf("Account not found.\n");
}

// Function to print all stored accounts
void print_accounts(struct account *accounts, int num_accts) {
    if (num_accts == 0) {
        printf("No accounts found.\n");
        return;
    }

    printf("Stored accounts:\n");

    // Iterate through array and print all accounts
    for (int i = 0; i < num_accts; i++) {
        printf("Name: %s\nUsername: %s\nPassword: %s\n\n", accounts[i].name, accounts[i].username, accounts[i].password);
    }
}

// Main function to run program and menu
int main() {
    struct account accounts[MAX_ACCTS_NUMBER];
    int num_accts = 0;
    int choice = 0;

    // Loop menu until user quits
    while (choice != 4) {
        printf("\nPassword Manager\n");
        printf("-----------------\n");
        printf("1. Create new account\n");
        printf("2. Search for account\n");
        printf("3. Print all accounts\n");
        printf("4. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_account(accounts, &num_accts);
                break;
            case 2:
                search_accounts(accounts, num_accts);
                break;
            case 3:
                print_accounts(accounts, num_accts);
                break;
            case 4:
                printf("Exiting password manager.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}