//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 100
#define FILE_NAME "passwords.txt"

typedef struct {
    char service[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} PasswordEntry;

PasswordEntry entries[MAX_ENTRIES];
int entryCount = 0;

// Function prototypes
void loadPasswords();
void savePassword();
void displayPasswords();
void deletePassword();
void clearInputBuffer();

int main() {
    loadPasswords();
    
    int choice;
    do {
        printf("\n--- Password Manager ---\n");
        printf("1. Add Password\n");
        printf("2. Display Passwords\n");
        printf("3. Delete Password\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                savePassword();
                break;
            case 2:
                displayPasswords();
                break;
            case 3:
                deletePassword();
                break;
            case 4:
                printf("Exiting... Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}

void loadPasswords() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("No previous data found, starting fresh!\n");
        return;
    }

    while (fscanf(file, "%[^,],%[^,],%s\n",
                  entries[entryCount].service,
                  entries[entryCount].username,
                  entries[entryCount].password) != EOF) {
        entryCount++;
    }
    fclose(file);
}

void savePassword() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Maximum entry limit reached! Cannot save more passwords.\n");
        return;
    }

    printf("Enter Service Name: ");
    fgets(entries[entryCount].service, MAX_LENGTH, stdin);
    entries[entryCount].service[strcspn(entries[entryCount].service, "\n")] = 0; // Remove newline

    printf("Enter Username: ");
    fgets(entries[entryCount].username, MAX_LENGTH, stdin);
    entries[entryCount].username[strcspn(entries[entryCount].username, "\n")] = 0; // Remove newline

    printf("Enter Password: ");
    fgets(entries[entryCount].password, MAX_LENGTH, stdin);
    entries[entryCount].password[strcspn(entries[entryCount].password, "\n")] = 0; // Remove newline

    entryCount++;

    FILE *file = fopen(FILE_NAME, "a");
    if (file) {
        fprintf(file, "%s,%s,%s\n", entries[entryCount - 1].service,
                entries[entryCount - 1].username,
                entries[entryCount - 1].password);
        fclose(file);
        printf("Password saved successfully!\n");
    } else {
        printf("Error opening file to save password!\n");
    }
}

void displayPasswords() {
    if (entryCount == 0) {
        printf("No passwords saved yet!\n");
        return;
    }

    printf("\n--- Saved Passwords ---\n");
    for (int i = 0; i < entryCount; i++) {
        printf("Service: %s, Username: %s, Password: %s\n",
               entries[i].service, entries[i].username, entries[i].password);
    }
}

void deletePassword() {
    if (entryCount == 0) {
        printf("No passwords to delete.\n");
        return;
    }

    char service[MAX_LENGTH];
    printf("Enter the Service name of the password you want to delete: ");
    fgets(service, MAX_LENGTH, stdin);
    service[strcspn(service, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < entryCount; i++) {
        if (strcmp(entries[i].service, service) == 0) {
            found = 1;
            for (int j = i; j < entryCount - 1; j++) {
                entries[j] = entries[j + 1];  // Shift entries left
            }
            entryCount--;
            printf("Password for service '%s' deleted successfully!\n", service);
            break;
        }
    }

    if (!found) {
        printf("Service '%s' not found!\n", service);
    }

    // Save current entries back to file
    FILE *file = fopen(FILE_NAME, "w");
    if (file) {
        for (int i = 0; i < entryCount; i++) {
            fprintf(file, "%s,%s,%s\n", entries[i].service, entries[i].username, entries[i].password);
        }
        fclose(file);
    }
}

void clearInputBuffer() {
    while (getchar() != '\n');
}