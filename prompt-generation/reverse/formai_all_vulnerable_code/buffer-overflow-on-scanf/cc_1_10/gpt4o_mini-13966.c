//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_LENGTH 100
#define FILENAME "passwords.txt"
#define BUFFER_SIZE 256

typedef struct {
    char account[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} PasswordEntry;

void displayMenu();
void addPassword();
void viewPasswords();
void deletePassword();
void clearBuffer();

int main() {
    int choice;
    
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer();  // Clear the newline from input buffer

        switch (choice) {
            case 1:
                addPassword();
                break;
            case 2:
                viewPasswords();
                break;
            case 3:
                deletePassword();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);
    
    return 0;
}

void displayMenu() {
    printf("\nPassword Management System\n");
    printf("1. Add Password\n");
    printf("2. View Passwords\n");
    printf("3. Delete Password\n");
    printf("4. Exit\n");
}

void addPassword() {
    PasswordEntry entry;
    FILE *file = fopen(FILENAME, "a");

    if (file == NULL) {
        perror("Unable to open file");
        return;
    }

    printf("Enter account name: ");
    fgets(entry.account, MAX_LENGTH, stdin);
    entry.account[strcspn(entry.account, "\n")] = 0; // Remove newline

    printf("Enter username: ");
    fgets(entry.username, MAX_LENGTH, stdin);
    entry.username[strcspn(entry.username, "\n")] = 0; // Remove newline

    printf("Enter password: ");
    fgets(entry.password, MAX_LENGTH, stdin);
    entry.password[strcspn(entry.password, "\n")] = 0; // Remove newline

    fprintf(file, "%s,%s,%s\n", entry.account, entry.username, entry.password);
    fclose(file);

    printf("Password entry added successfully!\n");
}

void viewPasswords() {
    FILE *file = fopen(FILENAME, "r");
    char buffer[BUFFER_SIZE];

    if (file == NULL) {
        perror("Unable to open file");
        return;
    }

    printf("\nStored Passwords:\n");
    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        char *account = strtok(buffer, ",");
        char *username = strtok(NULL, ",");
        char *password = strtok(NULL, ",");

        if (account && username && password) {
            printf("Account: %s, Username: %s, Password: %s", account, username, password);
        }
    }
    fclose(file);
}

void deletePassword() {
    char accountToDelete[MAX_LENGTH];
    FILE *file = fopen(FILENAME, "r");
    FILE *tempFile = fopen("temp.txt", "w");
    char buffer[BUFFER_SIZE];

    if (file == NULL || tempFile == NULL) {
        perror("Unable to open file");
        return;
    }

    printf("Enter account name to delete: ");
    fgets(accountToDelete, MAX_LENGTH, stdin);
    accountToDelete[strcspn(accountToDelete, "\n")] = 0; // Remove newline

    int found = 0;

    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        char *account = strtok(buffer, ",");
        if (account && strcmp(account, accountToDelete) == 0) {
            found = 1;  // Mark as found
            printf("Deleted entry for account: %s\n", account);
            continue;  // Skip writing this entry
        }
        fputs(buffer, tempFile);  // Write unchanged entry to temp file
    }
    
    fclose(file);
    fclose(tempFile);
    remove(FILENAME);  // Remove original file
    rename("temp.txt", FILENAME);  // Rename temp file to original file

    if (!found) {
        printf("No entry found for account: %s\n", accountToDelete);
    }
}

void clearBuffer() {
    while (getchar() != '\n');
}