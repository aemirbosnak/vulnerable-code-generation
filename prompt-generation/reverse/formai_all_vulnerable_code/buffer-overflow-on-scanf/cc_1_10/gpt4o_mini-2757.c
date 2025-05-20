//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_PASSWORDS 100
#define MAX_LENGTH 128

typedef struct {
    char site[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} PasswordEntry;

PasswordEntry passwordList[MAX_PASSWORDS];
int passwordCount = 0;

void addPassword() {
    if (passwordCount >= MAX_PASSWORDS) {
        printf("Password storage is full!\n");
        return;
    }

    PasswordEntry newEntry;

    printf("Enter site name: ");
    scanf("%s", newEntry.site);
    printf("Enter username: ");
    scanf("%s", newEntry.username);
    printf("Enter password: ");
    scanf("%s", newEntry.password);

    passwordList[passwordCount++] = newEntry;
    printf("Password added successfully!\n");
}

void listPasswords() {
    if (passwordCount == 0) {
        printf("No passwords stored.\n");
        return;
    }

    printf("Stored Passwords:\n");
    for (int i = 0; i < passwordCount; i++) {
        printf("Site: %s, Username: %s, Password: %s\n",
                passwordList[i].site,
                passwordList[i].username,
                passwordList[i].password);
    }
}

int validatePassword(const char *password) {
    int hasUpper = 0, hasLower = 0, hasDigit = 0;

    for(int i = 0; password[i]; i++) {
        if (isupper(password[i])) hasUpper++;
        if (islower(password[i])) hasLower++;
        if (isdigit(password[i])) hasDigit++;
    }

    return hasUpper && hasLower && hasDigit && strlen(password) >= 8;
}

void generateRandomPassword(char *password, int length) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+";
    for (int i = 0; i < length; i++) {
        int key = rand() % (int)(sizeof(charset) - 1);
        password[i] = charset[key];
    }
    password[length] = '\0';
}

void createSecurePassword() {
    char newPassword[MAX_LENGTH];
    int length;

    printf("Enter desired password length (minimum 8): ");
    scanf("%d", &length);

    if(length < 8) {
        printf("Password length must be at least 8 characters.\n");
        return;
    }

    generateRandomPassword(newPassword, length);
    printf("Generated secure password: %s\n", newPassword);
}

void deletePassword() {
    if (passwordCount == 0) {
        printf("No passwords to delete.\n");
        return;
    }

    char site[MAX_LENGTH];
    printf("Enter the site name of the password to delete: ");
    scanf("%s", site);

    for (int i = 0; i < passwordCount; i++) {
        if (strcmp(passwordList[i].site, site) == 0) {
            // Shift remaining entries left
            for (int j = i; j < passwordCount - 1; j++) {
                passwordList[j] = passwordList[j + 1];
            }
            passwordCount--;
            printf("Password for site %s deleted successfully!\n", site);
            return;
        }
    }
    printf("No password found for site: %s\n", site);
}

void displayMenu() {
    printf("\nPassword Management System\n");
    printf("1. Add New Password\n");
    printf("2. List All Passwords\n");
    printf("3. Create a Secure Random Password\n");
    printf("4. Delete Password\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPassword();
                break;
            case 2:
                listPasswords();
                break;
            case 3:
                createSecurePassword();
                break;
            case 4:
                deletePassword();
                break;
            case 5:
                printf("Exiting Password Management System. Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}