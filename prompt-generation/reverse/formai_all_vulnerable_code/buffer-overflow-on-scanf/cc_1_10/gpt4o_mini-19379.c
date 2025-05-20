//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_LENGTH 100
#define FILENAME "passwords.txt"

typedef struct {
    char service[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} Credential;

Credential database[MAX_PASSWORDS];
int count = 0;

void loadPasswords() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("No existing password file found. Starting fresh!\n");
        return;
    }
    
    while (fscanf(file, "%s %s %s", 
                  database[count].service, 
                  database[count].username, 
                  database[count].password) != EOF) {
        count++;
    }
    fclose(file);
}

void savePasswords() {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Error saving passwords!\n");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %s %s\n", 
                database[i].service, 
                database[i].username, 
                database[i].password);
    }
    fclose(file);
}

void addPassword() {
    if (count >= MAX_PASSWORDS) {
        printf("Password database is full!\n");
        return;
    }

    printf("Enter service name: ");
    scanf("%s", database[count].service);
    printf("Enter username: ");
    scanf("%s", database[count].username);
    printf("Enter password: ");
    scanf("%s", database[count].password);
    count++;
    savePasswords();
    printf("Password added!\n");
}

void viewPasswords() {
    printf("\nStored Passwords:\n");
    for (int i = 0; i < count; i++) {
        printf("Service: %s, Username: %s, Password: %s\n", 
                database[i].service, 
                database[i].username, 
                database[i].password);
    }
}

void deletePassword() {
    char service[MAX_LENGTH];
    printf("Enter the service name to delete: ");
    scanf("%s", service);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(database[i].service, service) == 0) {
            for (int j = i; j < count - 1; j++) {
                database[j] = database[j + 1];
            }
            count--;
            savePasswords();
            printf("Password for %s deleted!\n", service);
            return;
        }
    }
    printf("Service not found!\n");
}

void updatePassword() {
    char service[MAX_LENGTH];
    printf("Enter the service to update: ");
    scanf("%s", service);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(database[i].service, service) == 0) {
            printf("Enter new username: ");
            scanf("%s", database[i].username);
            printf("Enter new password: ");
            scanf("%s", database[i].password);
            savePasswords();
            printf("Password updated for %s!\n", service);
            return;
        }
    }
    printf("Service not found!\n");
}

void displayMenu() {
    printf("\nPassword Manager Options:\n");
    printf("1. Add Password\n");
    printf("2. View Passwords\n");
    printf("3. Delete Password\n");
    printf("4. Update Password\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    loadPasswords();
    
    while (1) {
        displayMenu();
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addPassword();
                break;
            case 2:
                if (count == 0) {
                    printf("No passwords stored!\n");
                } else {
                    viewPasswords();
                }
                break;
            case 3:
                deletePassword();
                break;
            case 4:
                updatePassword();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
    
    return 0;
}