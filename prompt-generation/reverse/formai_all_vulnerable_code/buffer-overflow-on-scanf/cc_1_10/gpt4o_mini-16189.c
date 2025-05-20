//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define PASSWORD_LENGTH 100
#define FILENAME "passwords.txt"

typedef struct {
    char service[PASSWORD_LENGTH];
    char username[PASSWORD_LENGTH];
    char password[PASSWORD_LENGTH];
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
        printf("Select an option: ");
        scanf("%d", &choice);
        clearBuffer();

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
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void addPassword() {
    FILE *file = fopen(FILENAME, "a");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }

    PasswordEntry entry;
    printf("Enter service name: ");
    fgets(entry.service, PASSWORD_LENGTH, stdin);
    entry.service[strcspn(entry.service, "\n")] = 0; // Remove newline

    printf("Enter username: ");
    fgets(entry.username, PASSWORD_LENGTH, stdin);
    entry.username[strcspn(entry.username, "\n")] = 0; // Remove newline

    printf("Enter password: ");
    fgets(entry.password, PASSWORD_LENGTH, stdin);
    entry.password[strcspn(entry.password, "\n")] = 0; // Remove newline

    fprintf(file, "%s;%s;%s\n", entry.service, entry.username, entry.password);
    fclose(file);
    printf("Password entry added successfully!\n");
}

void viewPasswords() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        printf("Error opening file for reading.\n");
        return;
    }

    char line[3 * PASSWORD_LENGTH];
    printf("\n--- Stored Passwords ---\n");
    while (fgets(line, sizeof(line), file)) {
        char *service = strtok(line, ";");
        char *username = strtok(NULL, ";");
        char *password = strtok(NULL, ";");

        printf("Service: %s\n", service);
        printf("Username: %s\n", username);
        printf("Password: %s\n", password);
        printf("-------------------------\n");
    }
    fclose(file);
}

void deletePassword() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        printf("Error opening file for reading.\n");
        return;
    }

    PasswordEntry entries[MAX_PASSWORDS];
    int count = 0;
    char line[3 * PASSWORD_LENGTH];

    while (fgets(line, sizeof(line), file) && count < MAX_PASSWORDS) {
        sscanf(line, "%[^;];%[^;];%[^;]", entries[count].service, entries[count].username, entries[count].password);
        count++;
    }
    fclose(file);

    printf("\n--- Stored Passwords ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Service: %s\n", i + 1, entries[i].service);
    }
    
    int index;
    printf("Enter the number of the password to delete: ");
    scanf("%d", &index);
    clearBuffer();

    if (index < 1 || index > count) {
        printf("Invalid index. No entry deleted.\n");
        return;
    }

    file = fopen(FILENAME, "w");
    for (int i = 0; i < count; i++) {
        if (i + 1 != index) {
            fprintf(file, "%s;%s;%s\n", entries[i].service, entries[i].username, entries[i].password);
        }
    }
    fclose(file);
    printf("Password entry deleted successfully!\n");
}

void clearBuffer() {
    while (getchar() != '\n');
}