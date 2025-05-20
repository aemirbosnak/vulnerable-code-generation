//FormAI DATASET v1.0 Category: Password management ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_ACCOUNTS 10
#define MAX_PASSWORD_LEN 20

/* Account structure */
struct Account {
    char name[MAX_PASSWORD_LEN];
    char password[MAX_PASSWORD_LEN];
};

/* Function declarations */
int displayMenu();
void addAccount(struct Account accArr[], int *numAccounts);
void viewAccounts(struct Account accArr[], int numAccounts);
void deleteAccount(struct Account accArr[], int *numAccounts);

/* Main function */
int main() {
    struct Account accountArr[MAX_ACCOUNTS];
    int numAccounts = 0;
    int choice;

    do {
        choice = displayMenu();

        switch (choice) {
            case 1:
                addAccount(accountArr, &numAccounts);
                break;
            case 2:
                viewAccounts(accountArr, numAccounts);
                break;
            case 3:
                deleteAccount(accountArr, &numAccounts);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid choice.\n\n");
        }
    } while (choice != 4);

    return 0;
}

/* Function to display the menu */
int displayMenu() {
    int choice;

    printf("Password Management System\n");
    printf("--------------------------\n");
    printf("1. Add Account\n");
    printf("2. View Accounts\n");
    printf("3. Delete Account\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("\n");

    return choice;
}

/* Function to add an account */
void addAccount(struct Account accArr[], int *numAccounts) {
    if (*numAccounts == MAX_ACCOUNTS) {
        printf("Cannot add more accounts. Maximum limit reached.\n");
        printf("Please delete an account to add a new one.\n\n");
        return;
    }

    printf("Enter the name for the account: ");
    scanf(" %[^\n]", accArr[*numAccounts].name);

    printf("Enter the password for the account: ");
    scanf(" %[^\n]", accArr[*numAccounts].password);

    printf("Account added successfully.\n\n");

    (*numAccounts)++;
}

/* Function to view all the accounts */
void viewAccounts(struct Account accArr[], int numAccounts) {
    if (numAccounts == 0) {
        printf("No accounts added yet.\n\n");
        return;
    }

    printf("Accounts:\n");
    printf("---------\n");
    for (int i = 0; i < numAccounts; i++) {
        printf("Account %d:\n", i+1);
        printf("Name: %s\n", accArr[i].name);
        printf("Password: %s\n\n", accArr[i].password);
    }
}

/* Function to delete an account */
void deleteAccount(struct Account accArr[], int *numAccounts) {
    if (*numAccounts == 0) {
        printf("No accounts added yet.\n\n");
        return;
    }

    printf("Enter the name of the account to delete: ");
    char accountToDelete[MAX_PASSWORD_LEN];
    scanf(" %[^\n]", accountToDelete);

    int accountIndexToDelete = -1;
    for (int i = 0; i < *numAccounts; i++) {
        if (strcmp(accArr[i].name, accountToDelete) == 0) {
            accountIndexToDelete = i;
            break;
        }
    }

    if (accountIndexToDelete == -1) {
        printf("Account not found.\n\n");
        return;
    }

    for (int i = accountIndexToDelete; i < (*numAccounts)-1; i++) {
        strcpy(accArr[i].name, accArr[i+1].name);
        strcpy(accArr[i].password, accArr[i+1].password);
    }

    (*numAccounts)--;
    printf("Account deleted successfully.\n\n");
}