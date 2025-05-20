//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_LENGTH 100
#define FILENAME "passwords.txt"

typedef struct {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} Credential;

Credential credentials[MAX_PASSWORDS];
int credential_count = 0;

void display_menu() {
    printf("\n=== Password Manager ===\n");
    printf("1. Add a Password\n");
    printf("2. View Passwords\n");
    printf("3. Delete a Password\n");
    printf("4. Save Passwords to File\n");
    printf("5. Exit Program\n");
    printf("========================\n");
    printf("Select an option: ");
}

void add_password() {
    if (credential_count >= MAX_PASSWORDS) {
        printf("Password storage is full!\n");
        return;
    }

    Credential new_creds;
    printf("Enter Username: ");
    scanf(" %[^\n]", new_creds.username);

    printf("Enter Password: ");
    scanf(" %[^\n]", new_creds.password);

    credentials[credential_count++] = new_creds;
    printf("Password added successfully!\n");
}

void view_passwords() {
    printf("\n=== Stored Passwords ===\n");
    for (int i = 0; i < credential_count; i++) {
        printf("Entry %d:\n", i + 1);
        printf("Username: %s\n", credentials[i].username);
        printf("Password: %s\n", credentials[i].password);
        printf("------------------------\n");
    }
}

void delete_password() {
    if (credential_count == 0) {
        printf("No passwords to delete!\n");
        return;
    }

    int index;
    printf("Enter the entry number to delete (1-%d): ", credential_count);
    scanf("%d", &index);

    if (index < 1 || index > credential_count) {
        printf("Invalid entry number!\n");
        return;
    }

    for (int i = index - 1; i < credential_count - 1; i++) {
        credentials[i] = credentials[i + 1];
    }
    credential_count--;
    printf("Password deleted successfully!\n");
}

void save_passwords_to_file() {
    FILE *file = fopen(FILENAME, "w");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    for (int i = 0; i < credential_count; i++) {
        fprintf(file, "%s:%s\n", credentials[i].username, credentials[i].password);
    }

    fclose(file);
    printf("Passwords saved to %s successfully!\n", FILENAME);
}

int main() {
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                view_passwords();
                break;
            case 3:
                delete_password();
                break;
            case 4:
                save_passwords_to_file();
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}