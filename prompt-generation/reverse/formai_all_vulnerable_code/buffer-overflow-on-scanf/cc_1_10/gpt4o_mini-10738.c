//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ACCOUNTS 100
#define PASS_LEN 20
#define USER_LEN 30

typedef struct {
    char username[USER_LEN];
    char password[PASS_LEN];
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void addAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Oh no! Account limit reached. Can't add more accounts!\n");
        return;
    }

    Account newAccount;
    printf("Enter username: ");
    scanf("%s", newAccount.username);
    
    printf("Enter password (max %d characters): ", PASS_LEN);
    scanf("%s", newAccount.password);

    // Simple password check
    if (strlen(newAccount.password) < 8 || 
        !strpbrk(newAccount.password, "0123456789") ||
        !strpbrk(newAccount.password, "!@#$%^&*()")) {
        printf("Your password must be at least 8 characters, contain a number, and include a special character!\n");
        return;
    }

    accounts[accountCount] = newAccount;
    accountCount++;
    printf("Account added successfully! You currently have %d accounts.\n", accountCount);
}

void viewAccounts() {
    if (accountCount == 0) {
        printf("Oh no! No accounts are available to display!\n");
        return;
    }
    
    printf("\n--- Your Accounts ---\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account %d: %s\n", i + 1, accounts[i].username);
    }
    printf("---------------------\n");
}

void deleteAccount() {
    if (accountCount == 0) {
        printf("Yikes! No accounts to delete!\n");
        return;
    }
    
    viewAccounts();
    int index;
    printf("Enter the account number to delete (1-%d): ", accountCount);
    scanf("%d", &index);
    
    if (index < 1 || index > accountCount) {
        printf("Uh-oh! Invalid account number!\n");
        return;
    }
    
    for (int i = index - 1; i < accountCount - 1; i++) {
        accounts[i] = accounts[i + 1];
    }
    accountCount--;

    printf("Account deleted successfully! You now have %d accounts left.\n", accountCount);
}

void modifyAccount() {
    if (accountCount == 0) {
        printf("Oops! No accounts available to modify!\n");
        return;
    }

    viewAccounts();
    int index;
    printf("Enter the account number to modify (1-%d): ", accountCount);
    scanf("%d", &index);

    if (index < 1 || index > accountCount){
        printf("Whoa! That's not a valid account number!\n");
        return;
    }

    Account *accountToModify = &accounts[index - 1];
    printf("Modifying account %s...\n", accountToModify->username);
    
    printf("Enter new password: ");
    scanf("%s", accountToModify->password);

    if (strlen(accountToModify->password) < 8 || 
        !strpbrk(accountToModify->password, "0123456789") ||
        !strpbrk(accountToModify->password, "!@#$%^&*()")) {
        printf("Eek! Your new password doesn't meet the criteria!\n");
        return;
    }

    printf("Account modified successfully!\n");
}

void clearAccounts() {
    printf("Are you sure you want to delete ALL accounts? (y/n): ");
    char confirm;
    scanf(" %c", &confirm);

    if (confirm == 'y' || confirm == 'Y'){
        accountCount = 0;
        printf("All accounts cleared! That's a bold move!\n");
    } else {
        printf("Accounts not cleared. Phew!\n");
    }
}

void displayMenu() {
    printf("\n=== Password Management System ===\n");
    printf("1. Add Account\n");
    printf("2. View Accounts\n");
    printf("3. Modify Account\n");
    printf("4. Delete Account\n");
    printf("5. Clear All Accounts\n");
    printf("6. Exit\n");
    printf("===================================\n");
    printf("Choose an option: ");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAccount();
                break;
            case 2:
                viewAccounts();
                break;
            case 3:
                modifyAccount();
                break;
            case 4:
                deleteAccount();
                break;
            case 5:
                clearAccounts();
                break;
            case 6:
                printf("Exiting... Safe travels with your passwords!\n");
                exit(0);
            default:
                printf("Invalid choice! That's unexpected!\n");
        }
    }

    return 0;
}