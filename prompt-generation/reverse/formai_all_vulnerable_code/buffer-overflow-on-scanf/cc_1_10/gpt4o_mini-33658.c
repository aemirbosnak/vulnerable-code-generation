//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORDS 100
#define MAX_LENGTH 50
#define FILENAME "passwords.txt"

typedef struct {
    char service[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} PasswordEntry;

void generateRandomString(char *str, size_t length) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+";
    if (length) {
        for (size_t n = 0; n < length; n++) {
            int key = rand() % (int)(sizeof(charset) - 1);
            str[n] = charset[key];
        }
        str[length] = '\0';
    }
}

void savePassword(PasswordEntry entry) {
    FILE *file = fopen(FILENAME, "a");
    if (file) {
        fprintf(file, "%s|%s|%s\n", entry.service, entry.username, entry.password);
        fclose(file);
    } else {
        printf("Could not save password to file.\n");
    }
}

void listPasswords() {
    FILE *file = fopen(FILENAME, "r");
    if (file) {
        char line[256];
        printf("\n--- Passwords Stored ---\n");
        while (fgets(line, sizeof(line), file)) {
            char *token = strtok(line, "|");
            printf("Service: %s | ", token);
            token = strtok(NULL, "|");
            printf("Username: %s | ", token);
            token = strtok(NULL, "|");
            printf("Password: %s\n", token);
        }
        fclose(file);
    } else {
        printf("No passwords stored yet.\n");
    }
}

void deleteEntry(char *serviceName) {
    char buffer[255];
    FILE *file = fopen(FILENAME, "r");

    if (!file) {
        printf("Could not open file for reading.\n");
        return;
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if (!tempFile) {
        printf("Could not open temporary file for writing.\n");
        fclose(file);
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, serviceName) == NULL) {
            fputs(line, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);
    remove(FILENAME);
    rename("temp.txt", FILENAME);
    printf("Entry for '%s' deleted.\n", serviceName);
}

void displayMenu() {
    printf("\n--- Password Manager ---\n");
    printf("1. Save new password\n");
    printf("2. List stored passwords\n");
    printf("3. Delete a password entry\n");
    printf("4. Generate a random password\n");
    printf("5. Exit\n");
}

int main() {
    srand(time(NULL));
    int choice;
    PasswordEntry entry;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                printf("Service Name: ");
                fgets(entry.service, MAX_LENGTH, stdin);
                strtok(entry.service, "\n"); // Remove newline from string

                printf("Username: ");
                fgets(entry.username, MAX_LENGTH, stdin);
                strtok(entry.username, "\n");

                printf("Password: ");
                fgets(entry.password, MAX_LENGTH, stdin);
                strtok(entry.password, "\n");

                savePassword(entry);
                break;

            case 2:
                listPasswords();
                break;

            case 3:
                printf("Enter service to delete: ");
                char serviceName[MAX_LENGTH];
                fgets(serviceName, MAX_LENGTH, stdin);
                strtok(serviceName, "\n");
                deleteEntry(serviceName);
                break;

            case 4:
                printf("Generated Password: ");
                char randomPassword[MAX_LENGTH];
                generateRandomString(randomPassword, 12);
                printf("%s\n", randomPassword);
                break;

            case 5:
                printf("Exiting password manager.\n");
                return 0;

            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}