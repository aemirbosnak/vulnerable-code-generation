//FormAI DATASET v1.0 Category: Password management ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ACCOUNTS 10

// Define account struct
struct account {
    char username[20];
    char password[20];
};

// Function to print all accounts
void printAccounts(struct account accounts[MAX_ACCOUNTS], int count) {
    printf("Total Accounts: %d\n", count);
    for(int i = 0; i < count; i++) {
        printf("Account %d:\n", i+1);
        printf("\tUsername: %s\n", accounts[i].username);
        printf("\tPassword: %s\n", accounts[i].password);
    }
}

// Function to add new account
void addAccount(struct account accounts[MAX_ACCOUNTS], int* count) {
    printf("Enter Username: ");
    scanf("%s", accounts[*count].username);
    printf("Enter Password: ");
    scanf("%s", accounts[*count].password);
    (*count)++;
    printf("Account Added!\n");
}

// Function to change password of an account
void changePassword(struct account accounts[MAX_ACCOUNTS], int count) {
    printf("Enter Username: ");
    char username[20];
    scanf("%s", username);
    bool accountFound = false;
    for(int i = 0; i < count; i++) {
        if(strcmp(accounts[i].username, username) == 0) {
            printf("Enter New Password: ");
            scanf("%s", accounts[i].password);
            printf("Password Changed!\n");
            accountFound = true;
            break;
        }
    }
    if(!accountFound) {
        printf("Account Not Found!\n");
    }
}

int main() {
    int count = 0;
    struct account accounts[MAX_ACCOUNTS];
    bool exit = false;
    
    while(!exit) {
        // Print menu options
        printf("\nPassword Management System\n");
        printf("1. Display All Accounts\n");
        printf("2. Add New Account\n");
        printf("3. Change Password\n");
        printf("4. Exit\n");
        
        // Get user choice
        int choice;
        printf("Enter Choice: ");
        scanf("%d", &choice);
        
        // Take action based on user choice
        switch(choice) {
            case 1:
                printAccounts(accounts, count);
                break;
            case 2:
                if(count >= MAX_ACCOUNTS) {
                    printf("Cannot Add More Accounts. Maximum Limit Reached.\n");
                } else {
                    addAccount(accounts, &count);
                }
                break;
            case 3:
                changePassword(accounts, count);
                break;
            case 4:
                exit = true;
                break;
            default:
                printf("Invalid Choice!\n");
        }
    }
    
    return 0;
}