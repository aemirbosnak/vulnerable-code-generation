//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: Linus Torvalds
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
} PasswordEntry;

PasswordEntry passwords[MAX_PASSWORDS];
int password_count = 0;

// Function declarations
void load_passwords();
void save_passwords();
void add_password(const char* service, const char* username, const char* password);
void view_passwords();
void delete_password(const char* service);
void clear_input_buffer();

int main() {
    load_passwords();
    int choice;

    do {
        printf("\n--- Password Manager ---\n");
        printf("1. Add Password\n");
        printf("2. View Passwords\n");
        printf("3. Delete Password\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        clear_input_buffer();

        switch (choice) {
            case 1: {
                char service[MAX_LENGTH], username[MAX_LENGTH], password[MAX_LENGTH];
                printf("Enter Service Name: ");
                fgets(service, MAX_LENGTH, stdin);
                service[strcspn(service, "\n")] = 0; // Removing newline
                printf("Enter Username: ");
                fgets(username, MAX_LENGTH, stdin);
                username[strcspn(username, "\n")] = 0; // Removing newline
                printf("Enter Password: ");
                fgets(password, MAX_LENGTH, stdin);
                password[strcspn(password, "\n")] = 0; // Removing newline
                add_password(service, username, password);
                break;
            }
            case 2:
                view_passwords();
                break;
            case 3: {
                char service[MAX_LENGTH];
                printf("Enter Service Name to Delete: ");
                fgets(service, MAX_LENGTH, stdin);
                service[strcspn(service, "\n")] = 0; // Removing newline
                delete_password(service);
                break;
            }
            case 4:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    save_passwords();
    return 0;
}

void load_passwords() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        return; // File does not exist, nothing to load
    }
    while (fscanf(file, "%99s %99s %99s", passwords[password_count].service, 
                  passwords[password_count].username, 
                  passwords[password_count].password) == 3) {
        password_count++;
    }
    fclose(file);
}

void save_passwords() {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Error saving passwords.\n");
        return;
    }
    for (int i = 0; i < password_count; i++) {
        fprintf(file, "%s %s %s\n", passwords[i].service, 
                passwords[i].username, 
                passwords[i].password);
    }
    fclose(file);
}

void add_password(const char* service, const char* username, const char* password) {
    if (password_count >= MAX_PASSWORDS) {
        printf("Password storage is full. Cannot add more passwords.\n");
        return;
    }
    strcpy(passwords[password_count].service, service);
    strcpy(passwords[password_count].username, username);
    strcpy(passwords[password_count].password, password);
    password_count++;
    printf("Password for %s added successfully.\n", service);
}

void view_passwords() {
    printf("\nStored Passwords:\n");
    for (int i = 0; i < password_count; i++) {
        printf("Service: %s, Username: %s, Password: %s\n", 
                passwords[i].service, 
                passwords[i].username, 
                passwords[i].password);
    }
}

void delete_password(const char* service) {
    int found = 0;
    for (int i = 0; i < password_count; i++) {
        if (strcmp(passwords[i].service, service) == 0) {
            found = 1;
            for (int j = i; j < password_count - 1; j++) {
                passwords[j] = passwords[j + 1]; // Shift entries left
            }
            password_count--;
            printf("Password for %s deleted successfully.\n", service);
            break;
        }
    }
    if (!found) {
        printf("Service not found.\n");
    }
}

void clear_input_buffer() {
    while (getchar() != '\n');
}