//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_LENGTH 100
#define FILE_NAME "passwords.txt"

// Structure to hold each password entry
typedef struct {
    char service[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} PasswordEntry;

// Function prototypes
void addPassword(PasswordEntry *entries, int *count);
void viewPasswords(PasswordEntry *entries, int count);
void deletePassword(PasswordEntry *entries, int *count);
void savePasswordsToFile(PasswordEntry *entries, int count);
void loadPasswordsFromFile(PasswordEntry *entries, int *count);
void clearBuffer();

int main() {
    PasswordEntry entries[MAX_PASSWORDS];
    int count = 0;
    int choice;
    
    loadPasswordsFromFile(entries, &count);

    while (1) {
        printf("\nPassword Manager\n");
        printf("1. Add Password\n");
        printf("2. View Passwords\n");
        printf("3. Delete Password\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        clearBuffer(); // Clear the newline from the input buffer
        
        switch (choice) {
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
                savePasswordsToFile(entries, count);
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void addPassword(PasswordEntry *entries, int *count) {
    if (*count >= MAX_PASSWORDS) {
        printf("Maximum password limit reached.\n");
        return;
    }
    
    PasswordEntry newEntry;
    printf("Enter service: ");
    fgets(newEntry.service, MAX_LENGTH, stdin);
    newEntry.service[strcspn(newEntry.service, "\n")] = 0; // Remove newline
    printf("Enter username: ");
    fgets(newEntry.username, MAX_LENGTH, stdin);
    newEntry.username[strcspn(newEntry.username, "\n")] = 0; // Remove newline
    printf("Enter password: ");
    fgets(newEntry.password, MAX_LENGTH, stdin);
    newEntry.password[strcspn(newEntry.password, "\n")] = 0; // Remove newline
    
    entries[*count] = newEntry;
    (*count)++;
    printf("Password added successfully!\n");
}

void viewPasswords(PasswordEntry *entries, int count) {
    if (count == 0) {
        printf("No passwords stored.\n");
        return;
    }

    printf("Stored Passwords:\n");
    for (int i = 0; i < count; i++) {
        printf("Service: %s, Username: %s, Password: %s\n", 
                entries[i].service, 
                entries[i].username, 
                entries[i].password);
    }
}

void deletePassword(PasswordEntry *entries, int *count) {
    if (*count == 0) {
        printf("No passwords to delete.\n");
        return;
    }

    char service[MAX_LENGTH];
    printf("Enter the service name to delete: ");
    fgets(service, MAX_LENGTH, stdin);
    service[strcspn(service, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (strcmp(entries[i].service, service) == 0) {
            found = 1;
            // Shift entries to remove the found entry
            for (int j = i; j < *count - 1; j++) {
                entries[j] = entries[j + 1];
            }
            (*count)--;
            printf("Password for '%s' deleted successfully.\n", service);
            break;
        }
    }

    if (!found) {
        printf("No password found for service '%s'.\n", service);
    }
}

void savePasswordsToFile(PasswordEntry *entries, int count) {
    FILE *file = fopen(FILE_NAME, "w");
    if (!file) {
        perror("Unable to save passwords");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s\n%s\n%s\n", 
                entries[i].service, 
                entries[i].username, 
                entries[i].password);
    }

    fclose(file);
    printf("Passwords saved to file successfully!\n");
}

void loadPasswordsFromFile(PasswordEntry *entries, int *count) {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        return; // No file exists yet, which is fine
    }

    while (fgets(entries[*count].service, MAX_LENGTH, file) != NULL) {
        entries[*count].service[strcspn(entries[*count].service, "\n")] = 0; // Remove newline
        fgets(entries[*count].username, MAX_LENGTH, file);
        entries[*count].username[strcspn(entries[*count].username, "\n")] = 0; // Remove newline
        fgets(entries[*count].password, MAX_LENGTH, file);
        entries[*count].password[strcspn(entries[*count].password, "\n")] = 0; // Remove newline
        (*count)++;
    }

    fclose(file);
}

void clearBuffer() {
    while (getchar() != '\n'); // Clear the input buffer
}