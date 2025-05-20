//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_LENGTH 50
#define ENCRYPTION_KEY 0xAA  // Simple XOR encryption key

typedef struct {
    char account[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

// Function prototypes
void loadAccounts();
void saveAccounts();
void encryptDecrypt(char *input, char *output);
void addAccount();
void listAccounts();
void searchAccount();
void deleteAccount();
void clearBuffer();

int main() {
    loadAccounts();
    int choice;

    do {
        printf("\nPassword Management System\n");
        printf("1. Add Account\n");
        printf("2. List Accounts\n");
        printf("3. Search Account\n");
        printf("4. Delete Account\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        clearBuffer();  // Clear input buffer

        switch (choice) {
            case 1:
                addAccount();
                break;
            case 2:
                listAccounts();
                break;
            case 3:
                searchAccount();
                break;
            case 4:
                deleteAccount();
                break;
            case 5:
                saveAccounts();
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void loadAccounts() {
    FILE *file = fopen("accounts.dat", "rb");
    if (file == NULL) return;  // No file to load

    while (fread(&accounts[accountCount], sizeof(Account), 1, file)) {
        accountCount++;
    }

    fclose(file);
}

void saveAccounts() {
    FILE *file = fopen("accounts.dat", "wb");
    if (file == NULL) {
        printf("Error saving accounts!\n");
        return;
    }

    for (int i = 0; i < accountCount; i++) {
        fwrite(&accounts[i], sizeof(Account), 1, file);
    }

    fclose(file);
}

void encryptDecrypt(char *input, char *output) {
    for (int i = 0; input[i] != '\0'; i++) {
        output[i] = input[i] ^ ENCRYPTION_KEY;  // Simple XOR encryption
    }
    output[strlen(input)] = '\0';  // Null-terminate the output string
}

void addAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Account limit reached!\n");
        return;
    }

    Account newAccount;
    printf("Enter account name: ");
    fgets(newAccount.account, MAX_LENGTH, stdin);
    newAccount.account[strcspn(newAccount.account, "\n")] = 0; // Remove newline

    printf("Enter username: ");
    fgets(newAccount.username, MAX_LENGTH, stdin);
    newAccount.username[strcspn(newAccount.username, "\n")] = 0; // Remove newline

    printf("Enter password: ");
    fgets(newAccount.password, MAX_LENGTH, stdin);
    newAccount.password[strcspn(newAccount.password, "\n")] = 0; // Remove newline

    // Encrypt password before storing
    char encryptedPassword[MAX_LENGTH];
    encryptDecrypt(newAccount.password, encryptedPassword);
    strcpy(newAccount.password, encryptedPassword);

    accounts[accountCount] = newAccount;
    accountCount++;
    printf("Account added successfully!\n");
}

void listAccounts() {
    printf("\nStored Accounts:\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account: %s, Username: %s\n", accounts[i].account, accounts[i].username);
    }
}

void searchAccount() {
    char search[MAX_LENGTH];
    printf("Enter account name to search: ");
    fgets(search, MAX_LENGTH, stdin);
    search[strcspn(search, "\n")] = 0; // Remove newline

    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].account, search) == 0) {
            char decryptedPassword[MAX_LENGTH];
            encryptDecrypt(accounts[i].password, decryptedPassword);
            printf("Account: %s, Username: %s, Password: %s\n", accounts[i].account, accounts[i].username, decryptedPassword);
            return;
        }
    }
    printf("Account not found!\n");
}

void deleteAccount() {
    char deleteAccountName[MAX_LENGTH];
    printf("Enter account name to delete: ");
    fgets(deleteAccountName, MAX_LENGTH, stdin);
    deleteAccountName[strcspn(deleteAccountName, "\n")] = 0; // Remove newline

    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].account, deleteAccountName) == 0) {
            for (int j = i; j < accountCount - 1; j++) {
                accounts[j] = accounts[j + 1];  // Shift accounts left
            }
            accountCount--;  // Decrease the account count
            printf("Account deleted successfully!\n");
            return;
        }
    }
    printf("Account not found!\n");
}

void clearBuffer() {
    while (getchar() != '\n'); // Clear the input buffer
}