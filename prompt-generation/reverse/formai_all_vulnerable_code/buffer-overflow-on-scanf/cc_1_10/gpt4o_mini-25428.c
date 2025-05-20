//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_LENGTH 100
#define DATA_FILE "passwords.txt"

typedef struct {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} Credential;

void add_password();
void view_passwords();
void delete_password();
void clear_buffer();

int main() {
    int choice;

    while (1) {
        printf("\nPassword Manager\n");
        printf("1. Add Password\n");
        printf("2. View Passwords\n");
        printf("3. Delete Password\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clear_buffer(); // Clear newline from input buffer

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
                printf("Exiting Password Manager. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void add_password() {
    Credential credential;
    FILE *file = fopen(DATA_FILE, "a");

    if (file == NULL) {
        perror("Unable to open file");
        return;
    }

    printf("Enter Username: ");
    fgets(credential.username, MAX_LENGTH, stdin);
    strtok(credential.username, "\n"); // Remove newline character

    printf("Enter Password: ");
    fgets(credential.password, MAX_LENGTH, stdin);
    strtok(credential.password, "\n"); // Remove newline character

    fprintf(file, "%s:%s\n", credential.username, credential.password);
    fclose(file);
    printf("Password added successfully!\n");
}

void view_passwords() {
    FILE *file = fopen(DATA_FILE, "r");
    char line[MAX_LENGTH * 2];

    if (file == NULL) {
        perror("Unable to open file");
        return;
    }

    printf("\nStored Passwords:\n");
    while (fgets(line, sizeof(line), file)) {
        char *username = strtok(line, ":");
        char *password = strtok(NULL, "\n");
        if (username && password) {
            printf("Username: %s, Password: %s\n", username, password);
        }
    }

    fclose(file);
}

void delete_password() {
    FILE *file = fopen(DATA_FILE, "r");
    FILE *temp_file = fopen("temp.txt", "w");
    char line[MAX_LENGTH * 2];
    char username[MAX_LENGTH];

    if (file == NULL || temp_file == NULL) {
        perror("Unable to open file");
        return;
    }

    printf("Enter Username to delete: ");
    fgets(username, MAX_LENGTH, stdin);
    strtok(username, "\n"); // Remove newline character

    int found = 0;
    while (fgets(line, sizeof(line), file)) {
        char *current_username = strtok(line, ":");
        if (current_username && strcmp(current_username, username) == 0) {
            found = 1;
            printf("Deleted entry for username: %s\n", current_username);
            continue; // Skip writing this line to new file
        }
        fputs(line, temp_file);
    }

    fclose(file);
    fclose(temp_file);

    if (!found) {
        printf("No entry found for username: %s\n", username);
    } else {
        remove(DATA_FILE);         // Remove original file
        rename("temp.txt", DATA_FILE); // Rename temp file to original
    }
}

void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {} // Clear buffer of stdin
}