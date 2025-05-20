//FormAI DATASET v1.0 Category: Password management ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Password {
    char website[50];
    char username[50];
    char password[50];
};

void addPassword(struct Password **passwords, int *numPasswords);
void viewPasswords(struct Password **passwords, int numPasswords);
void savePasswords(struct Password **passwords, int numPasswords);

int main() {
    struct Password *passwords = NULL;
    int numPasswords = 0;

    printf("Welcome to Password Manager!\n\n");

    while (true) {
        printf("Please select an option:\n");
        printf("1. Add a password\n");
        printf("2. View saved passwords\n");
        printf("3. Save and exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPassword(&passwords, &numPasswords);
                break;
            case 2:
                viewPasswords(&passwords, numPasswords);
                break;
            case 3:
                savePasswords(&passwords, numPasswords);
                printf("Successfully saved passwords and exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void addPassword(struct Password **passwords, int *numPasswords) {
    printf("\nAdding a password\n");

    *numPasswords += 1;
    *passwords = realloc(*passwords, sizeof(struct Password) * (*numPasswords));

    struct Password *password = &((*passwords)[*numPasswords - 1]);

    printf("Please enter the website:\n");
    scanf("%s", password->website);

    printf("Please enter the username:\n");
    scanf("%s", password->username);

    printf("Please enter the password:\n");
    scanf("%s", password->password);

    printf("Successfully added password!\n\n");
}

void viewPasswords(struct Password **passwords, int numPasswords) {
    printf("\nViewing saved passwords\n");

    if (numPasswords == 0) {
        printf("No passwords saved.\n\n");
        return;
    }

    for (int i = 0; i < numPasswords; i++) {
        struct Password *password = &((*passwords)[i]);

        printf("Website: %s\n", password->website);
        printf("Username: %s\n", password->username);
        printf("Password: %s\n\n", password->password);
    }
}

void savePasswords(struct Password **passwords, int numPasswords) {
    printf("\nSaving passwords...\n");

    if (numPasswords == 0) {
        printf("No passwords to save.\n\n");
        return;
    }

    FILE *file = fopen("passwords.txt", "w");
    if (file == NULL) {
        printf("Failed to save passwords.\n\n");
        return;
    }

    fprintf(file, "website,username,password\n");

    for (int i = 0; i < numPasswords; i++) {
        struct Password *password = &((*passwords)[i]);

        fprintf(file, "%s,%s,%s\n", password->website, password->username, password->password);
    }

    fclose(file);
}