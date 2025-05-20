//FormAI DATASET v1.0 Category: Password management ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASS_SIZE 20
#define MAX_USERNAME_SIZE 20
#define MAX_ACCOUNTS 5

// Structure to store account details
typedef struct{
    char username[MAX_USERNAME_SIZE];
    char password[MAX_PASS_SIZE];
} Account;

// Function prototypes
int login(Account accounts[], int numAccounts);
int addAccount(Account accounts[], int numAccounts);
void printAccounts(Account accounts[], int numAccounts);

// Main function
int main()
{
    Account accounts[MAX_ACCOUNTS];
    int numAccounts = 0;
    int choice, loggedIn = 0;
    
    do {
        printf("\n1. Login\n");
        printf("2. Add Account\n");
        printf("3. Print Accounts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                if(login(accounts, numAccounts))
                    loggedIn = 1;
                else
                    printf("\nInvalid username or password.\n");
                break;
            case 2:
                if(addAccount(accounts, numAccounts))
                    numAccounts++;
                break;
            case 3:
                printAccounts(accounts, numAccounts);
                break;
            case 4:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}

// Function to authenticate user login
int login(Account accounts[], int numAccounts)
{
    char username[MAX_USERNAME_SIZE], password[MAX_PASS_SIZE];
    int i;

    printf("\nEnter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);
    
    for(i = 0; i < numAccounts; i++){
        if(strcmp(accounts[i].username, username) == 0 && strcmp(accounts[i].password, password) == 0){
            printf("\nWelcome, %s!\n", accounts[i].username);
            return 1;
        }
    }
    return 0;
}

// Function to add new account to database
int addAccount(Account accounts[], int numAccounts)
{
    char username[MAX_USERNAME_SIZE], password[MAX_PASS_SIZE];

    printf("\nEnter a new username: ");
    scanf("%s", username);
    printf("Enter a new password: ");
    scanf("%s", password);

    if(numAccounts == MAX_ACCOUNTS){
        printf("\nCan't add more than %d accounts.\n", MAX_ACCOUNTS);
        return 0;
    }

    strcpy(accounts[numAccounts].username, username);
    strcpy(accounts[numAccounts].password, password);

    printf("\nAccount added successfully!\n");
    
    return 1;
}

// Function to print all accounts
void printAccounts(Account accounts[], int numAccounts)
{
    int i;

    if(numAccounts == 0){
        printf("\nNo accounts found.\n");
        return;
    }

    printf("\nUsername\tPassword\n");
    printf("--------------------------------\n");

    for(i = 0; i < numAccounts; i++){
        printf("%s\t\t%s\n", accounts[i].username, accounts[i].password);
    }
}