//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 100
#define FILE_NAME "passwords.txt"

typedef struct {
    char service[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} PasswordEntry;

void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char a = isupper(text[i]) ? 'A' : 'a';
            text[i] = (text[i] - a + shift) % 26 + a;
        }
    }
}

void decrypt(char *text, int shift) {
    encrypt(text, 26 - shift); 
}

void addPassword() {
    FILE *file = fopen(FILE_NAME, "a");
    if (!file) {
        printf("Couldn't open file for writing.\n");
        return;
    }

    PasswordEntry entry;
    printf("Enter service name: ");
    scanf("%s", entry.service);
    printf("Enter username: ");
    scanf("%s", entry.username);
    printf("Enter password: ");
    scanf("%s", entry.password);

    encrypt(entry.password, 3);  // Encrypt password
    fprintf(file, "%s %s %s\n", entry.service, entry.username, entry.password);
    fclose(file);
    printf("Password added successfully!\n");
}

void viewPasswords() {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("No passwords stored yet.\n");
        return;
    }

    PasswordEntry entry;
    printf("Stored Passwords:\n");
    while (fscanf(file, "%s %s %s", entry.service, entry.username, entry.password) != EOF) {
        decrypt(entry.password, 3);  // Decrypt password
        printf("Service: %s, Username: %s, Password: %s\n", entry.service, entry.username, entry.password);
    }
    fclose(file);
}

void deletePassword() {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("No passwords to delete.\n");
        return;
    }

    char service[MAX_LENGTH];
    printf("Enter the service name of the password to delete: ");
    scanf("%s", service);

    PasswordEntry entries[MAX_ENTRIES];
    int count = 0;
    int found = 0;

    while (fscanf(file, "%s %s %s", entries[count].service, entries[count].username, entries[count].password) != EOF) {
        if (strcmp(entries[count].service, service) == 0) {
            found = 1;
            printf("Deleting entry for service: %s\n", service);
            decrypt(entries[count].password, 3); 
            printf("Deleted entry - Service: %s, Username: %s, Password: %s\n", entries[count].service, entries[count].username, entries[count].password);
        } else {
            count++;
        }
    }
    fclose(file);

    if (!found) {
        printf("Service not found.\n");
        return;
    }

    file = fopen(FILE_NAME, "w");
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %s %s\n", entries[i].service, entries[i].username, entries[i].password);
    }
    fclose(file);
    printf("Password(s) deleted successfully.\n");
}

int main() {
    int choice;
    do {
        printf("\nPassword Management System\n");
        printf("1. Add Password\n");
        printf("2. View Passwords\n");
        printf("3. Delete Password\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
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
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 4);
    return 0;
}