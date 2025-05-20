//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SERVICES 100
#define MAX_PASSWORD_LENGTH 100
#define MAX_SERVICE_NAME_LENGTH 50

typedef struct {
    char serviceName[MAX_SERVICE_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} PasswordEntry;

typedef struct {
    PasswordEntry entries[MAX_SERVICES];
    int count;
} PasswordManager;

void initPasswordManager(PasswordManager *manager) {
    manager->count = 0;
}

int addPassword(PasswordManager *manager, const char *serviceName, const char *password) {
    if (manager->count < MAX_SERVICES) {
        strncpy(manager->entries[manager->count].serviceName, serviceName, MAX_SERVICE_NAME_LENGTH);
        strncpy(manager->entries[manager->count].password, password, MAX_PASSWORD_LENGTH);
        manager->count++;
        return 1; // Added successfully
    } else {
        return 0; // No space left
    }
}

int deletePassword(PasswordManager *manager, const char *serviceName) {
    for (int i = 0; i < manager->count; i++) {
        if (strcmp(manager->entries[i].serviceName, serviceName) == 0) {
            // Shift remaining entries left
            for (int j = i; j < manager->count - 1; j++) {
                manager->entries[j] = manager->entries[j + 1];
            }
            manager->count--;
            return 1; // Deleted successfully
        }
    }
    return 0; // Service not found
}

const char* getPassword(PasswordManager *manager, const char *serviceName) {
    for (int i = 0; i < manager->count; i++) {
        if (strcmp(manager->entries[i].serviceName, serviceName) == 0) {
            return manager->entries[i].password; // Return password
        }
    }
    return NULL; // Service not found
}

void displayAllPasswords(PasswordManager *manager) {
    if (manager->count == 0) {
        printf("No stored passwords.\n");
        return;
    }
    
    printf("Stored Passwords:\n");
    for (int i = 0; i < manager->count; i++) {
        printf("Service: %s, Password: %s\n", manager->entries[i].serviceName, manager->entries[i].password);
    }
}

void menu() {
    printf("Password Manager\n");
    printf("1. Add Password\n");
    printf("2. Retrieve Password\n");
    printf("3. Delete Password\n");
    printf("4. Display All Passwords\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    PasswordManager manager;
    initPasswordManager(&manager);
    
    int choice;
    char serviceName[MAX_SERVICE_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    
    while (1) {
        menu();
        scanf("%d", &choice);
        getchar(); // Consume newline
        
        switch (choice) {
            case 1:
                printf("Enter service name: ");
                fgets(serviceName, MAX_SERVICE_NAME_LENGTH, stdin);
                serviceName[strcspn(serviceName, "\n")] = 0; // Remove newline
                printf("Enter password: ");
                fgets(password, MAX_PASSWORD_LENGTH, stdin);
                password[strcspn(password, "\n")] = 0; // Remove newline
                if (addPassword(&manager, serviceName, password)) {
                    printf("Password added successfully!\n");
                } else {
                    printf("Failed to add password, storage full.\n");
                }
                break;
            case 2:
                printf("Enter service name to retrieve password: ");
                fgets(serviceName, MAX_SERVICE_NAME_LENGTH, stdin);
                serviceName[strcspn(serviceName, "\n")] = 0; // Remove newline
                const char* foundPassword = getPassword(&manager, serviceName);
                if (foundPassword) {
                    printf("Password for '%s': %s\n", serviceName, foundPassword);
                } else {
                    printf("Service not found.\n");
                }
                break;
            case 3:
                printf("Enter service name to delete password: ");
                fgets(serviceName, MAX_SERVICE_NAME_LENGTH, stdin);
                serviceName[strcspn(serviceName, "\n")] = 0; // Remove newline
                if (deletePassword(&manager, serviceName)) {
                    printf("Password deleted successfully!\n");
                } else {
                    printf("Service not found.\n");
                }
                break;
            case 4:
                displayAllPasswords(&manager);
                break;
            case 5:
                printf("Exiting Password Manager.\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }
    
    return 0;
}