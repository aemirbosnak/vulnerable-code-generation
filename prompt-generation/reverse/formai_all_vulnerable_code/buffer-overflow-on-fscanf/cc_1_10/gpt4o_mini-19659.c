//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SERVICES 100
#define MAX_LENGTH 100

typedef struct {
    char service[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} PasswordEntry;

void addPassword();
void viewPasswords();
void deletePassword();
void displayMenu();
void saveToFile(PasswordEntry entries[], int count);
int loadFromFile(PasswordEntry entries[]);

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
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
            case 4:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\nPassword Management System\n");
    printf("1. Add Password\n");
    printf("2. View Passwords\n");
    printf("3. Delete Password\n");
    printf("4. Exit\n");
}

void addPassword() {
    PasswordEntry entry;
    FILE *file;
    file = fopen("passwords.txt", "a");

    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter service name: ");
    scanf("%s", entry.service);
    printf("Enter username: ");
    scanf("%s", entry.username);
    printf("Enter password: ");
    scanf("%s", entry.password);

    fprintf(file, "%s %s %s\n", entry.service, entry.username, entry.password);
    fclose(file);

    printf("Password added successfully!\n");
}

void viewPasswords() {
    PasswordEntry entries[MAX_SERVICES];
    int count = loadFromFile(entries);
    
    if (count == 0) {
        printf("No passwords stored.\n");
        return;
    }

    printf("\nStored Passwords:\n");
    for (int i = 0; i < count; i++) {
        printf("Service: %s, Username: %s, Password: %s\n", entries[i].service, entries[i].username, entries[i].password);
    }
}

void deletePassword() {
    PasswordEntry entries[MAX_SERVICES];
    int count = loadFromFile(entries);
    char serviceToDelete[MAX_LENGTH];
    FILE *file;

    if (count == 0) {
        printf("No passwords stored to delete.\n");
        return;
    }

    printf("Enter the service name to delete: ");
    scanf("%s", serviceToDelete);

    file = fopen("passwords.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    int deleted = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(entries[i].service, serviceToDelete) != 0) {
            fprintf(file, "%s %s %s\n", entries[i].service, entries[i].username, entries[i].password);
        } else {
            deleted = 1;
        }
    }
    fclose(file);

    if (deleted) {
        printf("Password entry for %s deleted successfully!\n", serviceToDelete);
    } else {
        printf("Service not found!\n");
    }
}

int loadFromFile(PasswordEntry entries[]) {
    FILE *file;
    file = fopen("passwords.txt", "r");
    int count = 0;

    if (file == NULL) {
        return 0;
    }

    while (fscanf(file, "%s %s %s", entries[count].service, entries[count].username, entries[count].password) != EOF) {
        count++;
        if (count >= MAX_SERVICES) {
            break;
        }
    }
    fclose(file);
    return count;
}