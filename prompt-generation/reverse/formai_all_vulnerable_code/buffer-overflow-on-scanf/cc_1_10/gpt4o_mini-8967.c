//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: sophisticated
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

void addPassword(PasswordEntry entries[], int *count);
void viewPasswords(const PasswordEntry entries[], int count);
void deletePassword(PasswordEntry entries[], int *count);
void savePasswords(const PasswordEntry entries[], int count);
void loadPasswords(PasswordEntry entries[], int *count);

int main() {
    PasswordEntry entries[MAX_SERVICES];
    int count = 0;
    int option;

    loadPasswords(entries, &count);

    while (1) {
        printf("\n=== Password Manager ===\n");
        printf("1. Add Password\n");
        printf("2. View Passwords\n");
        printf("3. Delete Password\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        
        scanf("%d", &option);
        getchar(); // Consume newline character

        switch (option) {
            case 1:
                addPassword(entries, &count);
                break;
            case 2:
                viewPasswords(entries, count);
                break;
            case 3:
                deletePassword(entries, &count);
                break;
            case 4:
                savePasswords(entries, count);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}

void addPassword(PasswordEntry entries[], int *count) {
    if (*count >= MAX_SERVICES) {
        printf("Maximum number of services reached!\n");
        return;
    }

    PasswordEntry entry;
    printf("Enter service name: ");
    fgets(entry.service, MAX_LENGTH, stdin);
    entry.service[strcspn(entry.service, "\n")] = 0; // Removing newline

    printf("Enter username: ");
    fgets(entry.username, MAX_LENGTH, stdin);
    entry.username[strcspn(entry.username, "\n")] = 0; // Removing newline

    printf("Enter password: ");
    fgets(entry.password, MAX_LENGTH, stdin);
    entry.password[strcspn(entry.password, "\n")] = 0; // Removing newline

    entries[*count] = entry;
    (*count)++;
    printf("Password added successfully!\n");
}

void viewPasswords(const PasswordEntry entries[], int count) {
    if (count == 0) {
        printf("No passwords stored.\n");
        return;
    }

    printf("\nStored Passwords:\n");
    for (int i = 0; i < count; i++) {
        printf("Service: %s\nUsername: %s\nPassword: %s\n\n", 
                entries[i].service, entries[i].username, entries[i].password);
    }
}

void deletePassword(PasswordEntry entries[], int *count) {
    char service[MAX_LENGTH];
    printf("Enter the service name to delete: ");
    fgets(service, MAX_LENGTH, stdin);
    service[strcspn(service, "\n")] = 0; // Removing newline
    
    for (int i = 0; i < *count; i++) {
        if (strcmp(entries[i].service, service) == 0) {
            for (int j = i; j < *count - 1; j++) {
                entries[j] = entries[j + 1];
            }
            (*count)--;
            printf("Password for '%s' deleted successfully!\n", service);
            return;
        }
    }
    printf("Service not found!\n");
}

void savePasswords(const PasswordEntry entries[], int count) {
    FILE *file = fopen("passwords.txt", "w");
    if (!file) {
        perror("Could not open file for writing");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s|%s|%s\n", entries[i].service, entries[i].username, entries[i].password);
    }
    fclose(file);
    printf("Passwords saved successfully!\n");
}

void loadPasswords(PasswordEntry entries[], int *count) {
    FILE *file = fopen("passwords.txt", "r");
    if (!file) {
        printf("No saved passwords found.\n");
        return;
    }

    while (fscanf(file, "%[^|]|%[^|]|%[^\n]\n", 
                  entries[*count].service, 
                  entries[*count].username, 
                  entries[*count].password) == 3) {
        (*count)++;
    }

    fclose(file);
    printf("Passwords loaded from file successfully!\n");
}