//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SERVICES 100
#define MAX_NAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 100
#define FILE_NAME "passwords.txt"

typedef struct {
    char service[MAX_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} PasswordEntry;

void displayBanner() {
    printf("\n==============================\n");
    printf("     Password Manager          \n");
    printf("==============================\n\n");
}

void addPassword(PasswordEntry *entries, int *count) {
    if (*count >= MAX_SERVICES) {
        printf("Maximum service limit reached!\n");
        return;
    }
    
    printf("Enter the service name: ");
    scanf("%s", entries[*count].service);
    printf("Enter the password: ");
    scanf("%s", entries[*count].password);
    
    (*count)++;
    printf("Password added successfully!\n");
}

void viewPasswords(PasswordEntry *entries, int count) {
    if (count == 0) {
        printf("No passwords stored yet!\n");
        return;
    }
    
    printf("\nStored Passwords:\n");
    for (int i = 0; i < count; i++) {
        printf("Service: %s, Password: %s\n", entries[i].service, entries[i].password);
    }
}

void deletePassword(PasswordEntry *entries, int *count) {
    char service[MAX_NAME_LENGTH];
    printf("Enter the service name to delete the password: ");
    scanf("%s", service);
    
    for (int i = 0; i < *count; i++) {
        if (strcmp(entries[i].service, service) == 0) {
            for (int j = i; j < *count - 1; j++) {
                entries[j] = entries[j + 1];
            }
            (*count)--;
            printf("Password for %s deleted successfully!\n", service);
            return;
        }
    }
    
    printf("Service not found!\n");
}

void savePasswords(PasswordEntry *entries, int count) {
    FILE *file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        printf("Error saving passwords!\n");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %s\n", entries[i].service, entries[i].password);
    }
    
    fclose(file);
    printf("Passwords saved successfully to %s!\n", FILE_NAME);
}

void loadPasswords(PasswordEntry *entries, int *count) {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("No saved passwords found!\n");
        return;
    }
    
    while (fscanf(file, "%s %s", entries[*count].service, entries[*count].password) != EOF) {
        (*count)++;
    }
    
    fclose(file);
    printf("Passwords loaded successfully!\n");
}

int main() {
    PasswordEntry entries[MAX_SERVICES];
    int count = 0;
    loadPasswords(entries, &count);
    
    int choice;
    
    while (1) {
        displayBanner();
        printf("1. Add Password\n");
        printf("2. View Passwords\n");
        printf("3. Delete Password\n");
        printf("4. Save Passwords\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
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
                savePasswords(entries, count);
                break;
            case 5:
                printf("Exiting. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select again.\n");
        }
    }
    
    return 0;
}