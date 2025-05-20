//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define PASSWORD_LENGTH 256

// Structure to hold password information
typedef struct {
    char name[50];
    char password[PASSWORD_LENGTH];
} PasswordEntry;

// Function prototypes
void addPassword(PasswordEntry passwords[], int *count);
void viewPasswords(const PasswordEntry passwords[], int count);
void deletePassword(PasswordEntry passwords[], int *count);
void encryptPassword(char *password);
void decryptPassword(char *password);
int isValidPassword(const char *password);

int main() {
    PasswordEntry passwords[MAX_PASSWORDS];
    int count = 0;
    int choice = 0;

    do {
        printf("\n*** Password Manager ***\n");
        printf("1. Add Password\n");
        printf("2. View Passwords\n");
        printf("3. Delete Password\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);
        getchar();  // Clear newline from input buffer

        switch (choice) {
            case 1:
                addPassword(passwords, &count);
                break;
            case 2:
                viewPasswords(passwords, count);
                break;
            case 3:
                deletePassword(passwords, &count);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to add a password entry
void addPassword(PasswordEntry passwords[], int *count) {
    if (*count >= MAX_PASSWORDS) {
        printf("Password storage is full!\n");
        return;
    }

    PasswordEntry newEntry;
    printf("Enter the name of the service: ");
    fgets(newEntry.name, sizeof(newEntry.name), stdin);
    newEntry.name[strcspn(newEntry.name, "\n")] = 0;  // Remove newline character

    char password[PASSWORD_LENGTH];
    printf("Enter the password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0;  // Remove newline character

    if (isValidPassword(password)) {
        encryptPassword(password);
        strncpy(newEntry.password, password, PASSWORD_LENGTH);
        passwords[*count] = newEntry;
        (*count)++;
        printf("Password added successfully!\n");
    } else {
        printf("Password does not meet the requirements.\n");
    }
}

// Function to view all saved passwords
void viewPasswords(const PasswordEntry passwords[], int count) {
    if (count == 0) {
        printf("No passwords stored!\n");
        return;
    }

    printf("\nStored Passwords:\n");
    for (int i = 0; i < count; i++) {
        printf("Service: %s\n", passwords[i].name);
        char decryptedPassword[PASSWORD_LENGTH];
        strncpy(decryptedPassword, passwords[i].password, PASSWORD_LENGTH);
        decryptPassword(decryptedPassword);
        printf("Password: %s\n", decryptedPassword);
    }
}

// Function to delete a password entry
void deletePassword(PasswordEntry passwords[], int *count) {
    if (*count == 0) {
        printf("No passwords to delete!\n");
        return;
    }

    char serviceName[50];
    printf("Enter the service name to delete: ");
    fgets(serviceName, sizeof(serviceName), stdin);
    serviceName[strcspn(serviceName, "\n")] = 0;  // Remove newline character

    for (int i = 0; i < *count; i++) {
        if (strcmp(passwords[i].name, serviceName) == 0) {
            // Shift all the entries left to delete the specified service
            for (int j = i; j < *count - 1; j++) {
                passwords[j] = passwords[j + 1];
            }
            (*count)--;
            printf("Password for %s deleted successfully!\n", serviceName);
            return;
        }
    }

    printf("Service not found!\n");
}

// Encrypt the password using a simple caesar cipher
void encryptPassword(char *password) {
    for (int i = 0; password[i] != '\0'; i++) {
        password[i] += 3;  // Shift by 3 for encryption
    }
}

// Decrypt the password using the same caesar cipher
void decryptPassword(char *password) {
    for (int i = 0; password[i] != '\0'; i++) {
        password[i] -= 3;  // Shift back by 3 for decryption
    }
}

// Function to validate password criteria
int isValidPassword(const char *password) {
    int hasUpper = 0, hasLower = 0, hasDigit = 0, length = strlen(password);

    if (length < 8) return 0;  // Require at least 8 characters

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) hasUpper = 1;
        if (islower(password[i])) hasLower = 1;
        if (isdigit(password[i])) hasDigit = 1;
    }

    return hasUpper && hasLower && hasDigit;  // Must have at least one of each type
}