//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 100
#define FILENAME "passwords.txt"

typedef struct {
    char website[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} PasswordEntry;

void addPassword();
void viewPasswords();
void deletePassword();
void clearBuffer();

int main() {
    int choice;

    while (1) {
        printf("\n--- Password Manager ---\n");
        printf("1. Add Password\n");
        printf("2. View Passwords\n");
        printf("3. Delete Password\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1: addPassword(); break;
            case 2: viewPasswords(); break;
            case 3: deletePassword(); break;
            case 4: exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

void addPassword() {
    PasswordEntry entry;
    FILE *file = fopen(FILENAME, "a");

    if (!file) {
        perror("Failed to open file");
        return;
    }

    printf("Enter Website: ");
    fgets(entry.website, MAX_LENGTH, stdin);
    strtok(entry.website, "\n"); // Remove newline character

    printf("Enter Username: ");
    fgets(entry.username, MAX_LENGTH, stdin);
    strtok(entry.username, "\n"); // Remove newline character

    printf("Enter Password: ");
    fgets(entry.password, MAX_LENGTH, stdin);
    strtok(entry.password, "\n"); // Remove newline character

    fprintf(file, "%s,%s,%s\n", entry.website, entry.username, entry.password);
    fclose(file);
    printf("Password added successfully!\n");
}

void viewPasswords() {
    PasswordEntry entry;
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    printf("\nStored Passwords:\n");
    while (fscanf(file, "%99[^,],%99[^,],%99[^\n]\n", entry.website, entry.username, entry.password) == 3) {
        printf("Website: %s | Username: %s | Password: %s\n", entry.website, entry.username, entry.password);
    }
    fclose(file);
}

void deletePassword() {
    PasswordEntry entry;
    char website[MAX_LENGTH];
    FILE *file = fopen(FILENAME, "r");
    FILE *tempFile = fopen("temp.txt", "w");

    if (!file || !tempFile) {
        perror("Failed to open file");
        return;
    }

    printf("Enter Website to delete: ");
    fgets(website, MAX_LENGTH, stdin);
    strtok(website, "\n"); // Remove newline character

    int found = 0;
    while (fscanf(file, "%99[^,],%99[^,],%99[^\n]\n", entry.website, entry.username, entry.password) == 3) {
        if (strcmp(entry.website, website) == 0) {
            found = 1;
            printf("Deleted entry for %s\n", entry.website);
        } else {
            fprintf(tempFile, "%s,%s,%s\n", entry.website, entry.username, entry.password);
        }
    }

    fclose(file);
    fclose(tempFile);
    remove(FILENAME);
    rename("temp.txt", FILENAME);

    if (!found) {
        printf("No entry found for %s\n", website);
    }
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}