//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_LENGTH 100

typedef struct {
    char service[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} PasswordEntry;

PasswordEntry passwords[MAX_PASSWORDS];
int password_count = 0;

void load_passwords();
void save_passwords();
void add_password();
void display_passwords();
void delete_password();

int main() {
    int choice;
    load_passwords();

    do {
        printf("\nPassword Manager Menu:\n");
        printf("1. Add Password\n");
        printf("2. Display Passwords\n");
        printf("3. Delete Password\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from the input buffer

        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                display_passwords();
                break;
            case 3:
                delete_password();
                break;
            case 4:
                save_passwords();
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void load_passwords() {
    FILE *file = fopen("passwords.dat", "rb");
    if (file != NULL) {
        password_count = fread(passwords, sizeof(PasswordEntry), MAX_PASSWORDS, file);
        fclose(file);
    }
}

void save_passwords() {
    FILE *file = fopen("passwords.dat", "wb");
    if (file != NULL) {
        fwrite(passwords, sizeof(PasswordEntry), password_count, file);
        fclose(file);
    } else {
        printf("Error saving passwords.\n");
    }
}

void add_password() {
    if (password_count >= MAX_PASSWORDS) {
        printf("Password storage is full. Cannot add more passwords.\n");
        return;
    }

    PasswordEntry new_entry;

    printf("Enter service name: ");
    fgets(new_entry.service, MAX_LENGTH, stdin);
    strtok(new_entry.service, "\n"); // Remove newline character

    printf("Enter username: ");
    fgets(new_entry.username, MAX_LENGTH, stdin);
    strtok(new_entry.username, "\n"); // Remove newline character

    printf("Enter password: ");
    fgets(new_entry.password, MAX_LENGTH, stdin);
    strtok(new_entry.password, "\n"); // Remove newline character

    passwords[password_count++] = new_entry;
    printf("Password added successfully!\n");
}

void display_passwords() {
    if (password_count == 0) {
        printf("No passwords stored.\n");
        return;
    }

    printf("\nStored Passwords:\n");
    for (int i = 0; i < password_count; i++) {
        printf("Service: %s\n", passwords[i].service);
        printf("Username: %s\n", passwords[i].username);
        printf("Password: %s\n", passwords[i].password);
        printf("---------------------------\n");
    }
}

void delete_password() {
    char service[MAX_LENGTH];

    printf("Enter the service name of the password to delete: ");
    fgets(service, MAX_LENGTH, stdin);
    strtok(service, "\n"); // Remove newline character

    int i;
    for (i = 0; i < password_count; i++) {
        if (strcmp(passwords[i].service, service) == 0) {
            break;
        }
    }

    if (i == password_count) {
        printf("Service not found.\n");
        return;
    }

    for (int j = i; j < password_count - 1; j++) {
        passwords[j] = passwords[j + 1];
    }
    password_count--;
    printf("Password for service '%s' deleted successfully.\n", service);
}