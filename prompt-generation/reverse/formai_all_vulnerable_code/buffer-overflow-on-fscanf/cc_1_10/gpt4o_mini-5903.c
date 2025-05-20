//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 100
#define MAX_SERVICE_LENGTH 50
#define MAX_ENTRIES 100

typedef struct {
    char service[MAX_SERVICE_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} PasswordEntry;

PasswordEntry passwordEntries[MAX_ENTRIES];
int entryCount = 0;

void encrypt(char *password) {
    // Simple character shifting for encryption
    for (int i = 0; password[i] != '\0'; i++) {
        password[i] += 3; // Shift each character by 3
    }
}

void decrypt(char *password) {
    // Reverse the simple character shifting for decryption
    for (int i = 0; password[i] != '\0'; i++) {
        password[i] -= 3; // Shift each character back by 3
    }
}

void add_password() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Entry limit reached. Cannot add more passwords.\n");
        return;
    }

    PasswordEntry newEntry;
    printf("Enter Service Name: ");
    scanf("%s", newEntry.service);

    printf("Enter Password: ");
    scanf("%s", newEntry.password);
    encrypt(newEntry.password);

    passwordEntries[entryCount++] = newEntry;
    printf("Password added successfully!\n");
}

void display_passwords() {
    printf("\nStored Passwords:\n");
    printf("------------------------------------------------------\n");
    for (int i = 0; i < entryCount; i++) {
        char decryptedPassword[MAX_PASSWORD_LENGTH];
        strcpy(decryptedPassword, passwordEntries[i].password);
        decrypt(decryptedPassword);
        printf("Service: %s, Password: %s\n", passwordEntries[i].service, decryptedPassword);
    }
    printf("------------------------------------------------------\n");
}

void delete_password() {
    char service[MAX_SERVICE_LENGTH];
    printf("Enter Service Name to delete: ");
    scanf("%s", service);

    for (int i = 0; i < entryCount; i++) {
        if (strcmp(passwordEntries[i].service, service) == 0) {
            for (int j = i; j < entryCount - 1; j++) {
                passwordEntries[j] = passwordEntries[j + 1];
            }
            entryCount--;
            printf("Password for %s deleted successfully!\n", service);
            return;
        }
    }
    printf("Service not found.\n");
}

void save_to_file() {
    FILE *file = fopen("passwords.txt", "w");
    if (file == NULL) {
        printf("Unable to open file for saving.\n");
        return;
    }
    for (int i = 0; i < entryCount; i++) {
        fprintf(file, "%s %s\n", passwordEntries[i].service, passwordEntries[i].password);
    }
    fclose(file);
    printf("Passwords saved to file.\n");
}

void load_from_file() {
    FILE *file = fopen("passwords.txt", "r");
    if (file == NULL) {
        printf("No saved passwords found.\n");
        return;
    }
    while (fscanf(file, "%s %s", passwordEntries[entryCount].service, passwordEntries[entryCount].password) != EOF && entryCount < MAX_ENTRIES) {
        decrypt(passwordEntries[entryCount].password);
        entryCount++;
    }
    fclose(file);
    printf("Passwords loaded from file.\n");
}

int main() {
    load_from_file();

    while (1) {
        printf("\nPassword Manager\n");
        printf("1. Add Password\n");
        printf("2. Display Passwords\n");
        printf("3. Delete Password\n");
        printf("4. Save to File\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1: add_password(); break;
            case 2: display_passwords(); break;
            case 3: delete_password(); break;
            case 4: save_to_file(); break;
            case 5: exit(0);
            default: printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}