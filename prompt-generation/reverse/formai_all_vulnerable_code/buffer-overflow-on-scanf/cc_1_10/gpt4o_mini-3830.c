//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 100
#define MAX_SITE_LENGTH 50
#define MAX_RECORDS 100
#define DATA_FILE "passwords.dat"

typedef struct {
    char site[MAX_SITE_LENGTH];
    char username[MAX_SITE_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} PasswordRecord;

void addPassword();
void viewPasswords();
void deletePassword();
void listPasswords();
void clearScreen();
void showMenu();

int main() {
    int choice;
    
    while (1) {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Clear the newline character after integer input

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
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void showMenu() {
    clearScreen();
    printf("=== Password Manager ===\n");
    printf("1. Add Password\n");
    printf("2. View Passwords\n");
    printf("3. Delete Password\n");
    printf("4. Exit\n");
}

void addPassword() {
    PasswordRecord record;
    FILE *file = fopen(DATA_FILE, "ab");
    if (!file) {
        perror("Unable to open data file");
        return;
    }

    printf("Enter site name: ");
    fgets(record.site, MAX_SITE_LENGTH, stdin);
    strtok(record.site, "\n"); // Remove newline character

    printf("Enter username: ");
    fgets(record.username, MAX_SITE_LENGTH, stdin);
    strtok(record.username, "\n");

    printf("Enter password: ");
    fgets(record.password, MAX_PASSWORD_LENGTH, stdin);
    strtok(record.password, "\n");

    fwrite(&record, sizeof(PasswordRecord), 1, file);
    fclose(file);

    printf("Password for %s added successfully!\n", record.site);
    getchar(); // Wait for user to press Enter
}

void viewPasswords() {
    PasswordRecord record;
    FILE *file = fopen(DATA_FILE, "rb");
    if (!file) {
        perror("Unable to open data file");
        return;
    }

    printf("=== Stored Passwords ===\n");
    while (fread(&record, sizeof(PasswordRecord), 1, file)) {
        printf("Site: %s, Username: %s, Password: %s\n", record.site, record.username, record.password);
    }

    fclose(file);
    getchar(); // Wait for user to press Enter
}

void deletePassword() {
    PasswordRecord record;
    PasswordRecord records[MAX_RECORDS];
    int count = 0;
    char site[MAX_SITE_LENGTH];
    FILE *file = fopen(DATA_FILE, "rb");

    if (!file) {
        perror("Unable to open data file");
        return;
    }

    while (fread(&record, sizeof(PasswordRecord), 1, file)) {
        records[count++] = record;
    }
    fclose(file);

    printf("Enter the site name of the password to delete: ");
    fgets(site, MAX_SITE_LENGTH, stdin);
    strtok(site, "\n");

    file = fopen(DATA_FILE, "wb");
    if (!file) {
        perror("Unable to open data file");
        return;
    }

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(records[i].site, site) != 0) {
            fwrite(&records[i], sizeof(PasswordRecord), 1, file);
        } else {
            found = 1;
        }
    }

    fclose(file);

    if (found) {
        printf("Password for %s deleted successfully!\n", site);
    } else {
        printf("No password found for %s.\n", site);
    }
    getchar(); // Wait for user to press Enter
}

void clearScreen() {
    printf("\033[H\033[J"); // ANSI escape code to clear console
}