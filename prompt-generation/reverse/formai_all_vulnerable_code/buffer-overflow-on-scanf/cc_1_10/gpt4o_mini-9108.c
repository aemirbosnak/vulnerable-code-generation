//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define FILENAME "passwords.txt"

// Function to add a password entry
void add_password() {
    FILE *file = fopen(FILENAME, "a");
    if (!file) {
        perror("Unable to open file");
        return;
    }
    
    char service[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];

    printf("Enter service name: ");
    fgets(service, MAX_LENGTH, stdin);
    service[strcspn(service, "\n")] = 0;  // Remove newline

    printf("Enter username: ");
    fgets(username, MAX_LENGTH, stdin);
    username[strcspn(username, "\n")] = 0;  // Remove newline

    printf("Enter password: ");
    fgets(password, MAX_LENGTH, stdin);
    password[strcspn(password, "\n")] = 0;  // Remove newline

    fprintf(file, "%s|%s|%s\n", service, username, password);
    fclose(file);
    printf("Password entry added!\n");
}

// Function to view all passwords
void view_passwords() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    char line[MAX_LENGTH];
    printf("Stored Passwords:\n");
    while (fgets(line, sizeof(line), file)) {
        char *service = strtok(line, "|");
        char *username = strtok(NULL, "|");
        char *password = strtok(NULL, "|");
        
        printf("Service: %s\nUsername: %s\nPassword: %s\n\n", service, username, password);
    }
    fclose(file);
}

// Function to delete a password entry
void delete_password() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    char temp_filename[] = "temp.txt";
    FILE *temp_file = fopen(temp_filename, "w");
    if (!temp_file) {
        perror("Unable to create temp file");
        fclose(file);
        return;
    }

    char service[MAX_LENGTH];
    printf("Enter service name to delete: ");
    fgets(service, MAX_LENGTH, stdin);
    service[strcspn(service, "\n")] = 0;  // Remove newline

    char line[MAX_LENGTH];
    int found = 0;
    while (fgets(line, sizeof(line), file)) {
        char *curr_service = strtok(line, "|");
        if (strcmp(curr_service, service) != 0) {
            fputs(line, temp_file);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(temp_file);

    remove(FILENAME);
    rename(temp_filename, FILENAME);

    if (found) {
        printf("Password for %s deleted!\n", service);
    } else {
        printf("Service %s not found!\n", service);
    }
}

// Function to show menu options
void show_menu() {
    printf("------ Password Manager ------\n");
    printf("1. Add Password\n");
    printf("2. View Passwords\n");
    printf("3. Delete Password\n");
    printf("4. Exit\n");
    printf("-----------------------------\n");
}

// Main function
int main() {
    int choice;
    do {
        show_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume the newline character

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
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);

    return 0;
}