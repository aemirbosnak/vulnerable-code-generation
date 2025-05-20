//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_LENGTH 50

typedef struct {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} Account;

Account passwordManager[MAX_ACCOUNTS];
int accountCount = 0;

void addAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Account limit reached. Cannot add more accounts.\n");
        return;
    }

    char username[MAX_LENGTH];
    char password[MAX_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    strcpy(passwordManager[accountCount].username, username);
    strcpy(passwordManager[accountCount].password, password);
    accountCount++;
    
    printf("Account added successfully!\n");
}

void retrieveAccount() {
    char username[MAX_LENGTH];
    printf("Enter username to retrieve: ");
    scanf("%s", username);

    for (int i = 0; i < accountCount; i++) {
        if (strcmp(passwordManager[i].username, username) == 0) {
            printf("Username: %s\n", passwordManager[i].username);
            printf("Password: %s\n", passwordManager[i].password);
            return;
        }
    }

    printf("Account not found!\n");
}

void deleteAccount() {
    char username[MAX_LENGTH];
    printf("Enter username to delete: ");
    scanf("%s", username);

    for (int i = 0; i < accountCount; i++) {
        if (strcmp(passwordManager[i].username, username) == 0) {
            for (int j = i; j < accountCount - 1; j++) {
                passwordManager[j] = passwordManager[j + 1];
            }
            accountCount--;
            printf("Account deleted successfully!\n");
            return;
        }
    }

    printf("Account not found!\n");
}

void displayAccounts() {
    if (accountCount == 0) {
        printf("No accounts stored.\n");
        return;
    }
    printf("Stored Accounts:\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Username: %s\n", passwordManager[i].username);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Password Management System ---\n");
        printf("1. Add Account\n");
        printf("2. Retrieve Account\n");
        printf("3. Delete Account\n");
        printf("4. Display All Accounts\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAccount();
                break;
            case 2:
                retrieveAccount();
                break;
            case 3:
                deleteAccount();
                break;
            case 4:
                displayAccounts();
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}