//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_LENGTH 100
#define ENCRYPTION_KEY 5 // Simple encryption key for demo purposes

typedef struct {
    char account[MAX_LENGTH];
    char password[MAX_LENGTH];
} PasswordEntry;

void encrypt(char *password) {
    for (int i = 0; password[i] != '\0'; i++) {
        password[i] += ENCRYPTION_KEY; // Simple character shift for encryption
    }
}

void decrypt(char *password) {
    for (int i = 0; password[i] != '\0'; i++) {
        password[i] -= ENCRYPTION_KEY; // Revert character shift for decryption
    }
}

void addPassword(const char *filename, PasswordEntry entry) {
    FILE *file = fopen(filename, "a");
    if (!file) {
        fprintf(stderr, "Error opening file!\n");
        return;
    }
    
    encrypt(entry.password); // Encrypt password before saving
    fprintf(file, "%s,%s\n", entry.account, entry.password);
    fclose(file);
    printf("Password for '%s' added successfully.\n", entry.account);
}

void viewPasswords(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening file!\n");
        return;
    }
    
    printf("Stored Passwords:\n");
    char line[MAX_LENGTH * 2]; // To accommodate account and password
    while (fgets(line, sizeof(line), file)) {
        char account[MAX_LENGTH], password[MAX_LENGTH];
        sscanf(line, "%[^,],%s", account, password);
        decrypt(password); // Decrypt password before displaying
        printf("Account: %s, Password: %s\n", account, password);
    }
    fclose(file);
}

void deletePassword(const char *filename, const char *accountToDelete) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening file!\n");
        return;
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if (!tempFile) {
        fprintf(stderr, "Error creating temporary file!\n");
        fclose(file);
        return;
    }

    char line[MAX_LENGTH * 2];
    int found = 0;
    while (fgets(line, sizeof(line), file)) {
        char account[MAX_LENGTH];
        sscanf(line, "%[^,]", account);
        
        if (strcmp(account, accountToDelete) == 0) {
            found = 1; // Account found, do not write to temp file
            printf("Deleted password for account: %s\n", account);
            continue; // Skip writing this line to temp file
        }
        fprintf(tempFile, "%s", line); // Write other accounts to temp file
    }

    fclose(file);
    fclose(tempFile);

    remove(filename); // Remove the original file
    rename("temp.txt", filename); // Rename temp file to original filename

    if (!found) {
        printf("No account found with the name: %s\n", accountToDelete);
    }
}

int main() {
    const char *filename = "passwords.txt";
    int choice;
    PasswordEntry entry;

    while (1) {
        printf("\nPassword Management System\n");
        printf("1. Add Password\n");
        printf("2. View Passwords\n");
        printf("3. Delete Password\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character left by scanf

        switch (choice) {
            case 1:
                printf("Enter Account Name: ");
                fgets(entry.account, MAX_LENGTH, stdin);
                entry.account[strcspn(entry.account, "\n")] = 0; // Remove newline

                printf("Enter Password: ");
                fgets(entry.password, MAX_LENGTH, stdin);
                entry.password[strcspn(entry.password, "\n")] = 0; // Remove newline

                addPassword(filename, entry);
                break;

            case 2:
                viewPasswords(filename);
                break;

            case 3:
                printf("Enter Account Name to Delete: ");
                fgets(entry.account, MAX_LENGTH, stdin);
                entry.account[strcspn(entry.account, "\n")] = 0; // Remove newline

                deletePassword(filename, entry.account);
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}