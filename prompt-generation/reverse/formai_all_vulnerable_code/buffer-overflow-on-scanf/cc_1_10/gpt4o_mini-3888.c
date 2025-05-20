//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_LENGTH 256
#define DATA_FILE "passwords.txt"

typedef struct {
    char service[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} PasswordEntry;

// Function declarations
void addPassword();
void viewPasswords();
void deletePassword();
void displayMenu();

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
                viewPasswords();
                break;
            case 3:
                deletePassword();
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n--- Password Manager ---\n");
    printf("1. Add Password\n");
    printf("2. View Passwords\n");
    printf("3. Delete Password\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
}

void addPassword() {
    PasswordEntry entry;
    FILE *file = fopen(DATA_FILE, "a");

    if (!file) {
        perror("Unable to open file");
        return;
    }

    printf("Enter service name: ");
    getchar(); // to consume newline character after scanf
    fgets(entry.service, MAX_LENGTH, stdin);
    entry.service[strcspn(entry.service, "\n")] = 0; // Removing newline

    printf("Enter username: ");
    fgets(entry.username, MAX_LENGTH, stdin);
    entry.username[strcspn(entry.username, "\n")] = 0; // Removing newline

    printf("Enter password: ");
    fgets(entry.password, MAX_LENGTH, stdin);
    entry.password[strcspn(entry.password, "\n")] = 0; // Removing newline

    fprintf(file, "%s\n%s\n%s\n", entry.service, entry.username, entry.password);
    fclose(file);
    printf("Password added successfully.\n");
}

void viewPasswords() {
    PasswordEntry entry;
    FILE *file = fopen(DATA_FILE, "r");

    if (!file) {
        perror("Unable to open file");
        return;
    }

    printf("\n--- Stored Passwords ---\n");
    while (fgets(entry.service, MAX_LENGTH, file)) {
        fgets(entry.username, MAX_LENGTH, file);
        fgets(entry.password, MAX_LENGTH, file);
        printf("Service: %sUsername: %sPassword: %s\n",
               entry.service, entry.username, entry.password);
    }
    fclose(file);
}

void deletePassword() {
    PasswordEntry entry;
    FILE *file = fopen(DATA_FILE, "r");
    FILE *tempFile = fopen("temp.txt", "w");
    char serviceToDelete[MAX_LENGTH];

    if (!file || !tempFile) {
        perror("Unable to open file");
        return;
    }

    printf("Enter service name to delete: ");
    getchar(); // to consume newline character after scanf
    fgets(serviceToDelete, MAX_LENGTH, stdin);
    serviceToDelete[strcspn(serviceToDelete, "\n")] = 0; // Removing newline

    int found = 0;
    while (fgets(entry.service, MAX_LENGTH, file)) {
        fgets(entry.username, MAX_LENGTH, file);
        fgets(entry.password, MAX_LENGTH, file);

        if (strcmp(entry.service, serviceToDelete) == 0) {
            found = 1;
            printf("Deleting entry for service: %s\n", entry.service);
            continue;
        }
        fprintf(tempFile, "%s\n%s\n%s\n", entry.service, entry.username, entry.password);
    }

    fclose(file);
    fclose(tempFile);

    remove(DATA_FILE);
    rename("temp.txt", DATA_FILE);

    if (!found) {
        printf("Service not found.\n");
    } else {
        printf("Password deleted successfully.\n");
    }
}