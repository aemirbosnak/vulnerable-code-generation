//FormAI DATASET v1.0 Category: Password management ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 20

struct PasswordEntry {
    char website[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

void addPassword(struct PasswordEntry *passwords, int *numPasswords);
void viewPasswords(struct PasswordEntry *passwords, int numPasswords);
void deletePassword(struct PasswordEntry *passwords, int *numPasswords);
void encryptPasswords(struct PasswordEntry *passwords, int numPasswords);
void decryptPasswords(struct PasswordEntry *passwords, int numPasswords);

int main(void) {
    struct PasswordEntry passwords[MAX_PASSWORDS];
    int numPasswords = 0;
    int choice = 0;

    while (choice != 6) {
        printf("\n--- PASSWORD MANAGER ---\n\n");
        printf("1. Add a password\n");
        printf("2. View passwords\n");
        printf("3. Delete a password\n");
        printf("4. Encrypt passwords\n");
        printf("5. Decrypt passwords\n");
        printf("6. Exit\n");
        printf("\nEnter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPassword(passwords, &numPasswords);
                break;
            case 2:
                viewPasswords(passwords, numPasswords);
                break;
            case 3:
                deletePassword(passwords, &numPasswords);
                break;
            case 4:
                encryptPasswords(passwords, numPasswords);
                break;
            case 5:
                decryptPasswords(passwords, numPasswords);
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }

    return 0;
}

void addPassword(struct PasswordEntry *passwords, int *numPasswords) {
    if (*numPasswords == MAX_PASSWORDS) {
        printf("Maximum number of passwords reached.\n");
        return;
    }

    struct PasswordEntry newEntry;

    printf("\nEnter website: ");
    scanf("%s", newEntry.website);

    printf("Enter username: ");
    scanf("%s", newEntry.username);

    printf("Enter password: ");
    scanf("%s", newEntry.password);

    passwords[*numPasswords] = newEntry;
    *numPasswords += 1;

    printf("\nPassword added successfully.\n");
}

void viewPasswords(struct PasswordEntry *passwords, int numPasswords) {
    if (numPasswords == 0) {
        printf("\nNo passwords added yet.\n");
        return;
    }

    for (int i = 0; i < numPasswords; i++) {
        printf("\nWebsite: %s\n", passwords[i].website);
        printf("Username: %s\n", passwords[i].username);
        printf("Password: %s\n", passwords[i].password);
    }
}

void deletePassword(struct PasswordEntry *passwords, int *numPasswords) {
    if (*numPasswords == 0) {
        printf("\nNo passwords added yet.\n");
        return;
    }

    char website[MAX_PASSWORD_LENGTH];

    printf("\nEnter website for password to delete: ");
    scanf("%s", website);

    int indexToDelete = -1;

    for (int i = 0; i < *numPasswords; i++) {
        if (strcmp(passwords[i].website, website) == 0) {
            indexToDelete = i;
            break;
        }
    }

    if (indexToDelete == -1) {
        printf("\nPassword not found.\n");
        return;
    }

    for (int i = indexToDelete; i < *numPasswords - 1; i++) {
        passwords[i] = passwords[i + 1];
    }

    *numPasswords -= 1;

    printf("\nPassword deleted successfully.\n");
}

void encryptPasswords(struct PasswordEntry *passwords, int numPasswords) {
    if (numPasswords == 0) {
        printf("\nNo passwords added yet.\n");
        return;
    }

    for (int i = 0; i < numPasswords; i++) {
        char *password = passwords[i].password;

        for (int j = 0; j < strlen(password); j++) {
            if (password[j] >= 'a' && password[j] <= 'z') {
                password[j] -= 'a';
                password[j] = (password[j] + i) % 26;
                password[j] += 'a';
            } else if (password[j] >= 'A' && password[j] <= 'Z') {
                password[j] -= 'A';
                password[j] = (password[j] + i) % 26;
                password[j] += 'A';
            } else if (password[j] >= '0' && password[j] <= '9') {
                password[j] -= '0';
                password[j] = (password[j] + i) % 10;
                password[j] += '0';
            }
        }
    }

    printf("\nPasswords encrypted successfully.\n");
}

void decryptPasswords(struct PasswordEntry *passwords, int numPasswords) {
    if (numPasswords == 0) {
        printf("\nNo passwords added yet.\n");
        return;
    }

    for (int i = 0; i < numPasswords; i++) {
        char *password = passwords[i].password;

        for (int j = 0; j < strlen(password); j++) {
            if (password[j] >= 'a' && password[j] <= 'z') {
                password[j] -= 'a';
                password[j] = (password[j] - i + 26) % 26;
                password[j] += 'a';
            } else if (password[j] >= 'A' && password[j] <= 'Z') {
                password[j] -= 'A';
                password[j] = (password[j] - i + 26) % 26;
                password[j] += 'A';
            } else if (password[j] >= '0' && password[j] <= '9') {
                password[j] -= '0';
                password[j] = (password[j] - i + 10) % 10;
                password[j] += '0';
            }
        }
    }

    printf("\nPasswords decrypted successfully.\n");
}