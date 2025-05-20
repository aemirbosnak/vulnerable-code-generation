//FormAI DATASET v1.0 Category: Password management ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORDS 100 // Max number of passwords
#define MAX_PASSWORD_LENGTH 50 // Max length of password
#define MAX_ATTEMPTS 3 // Max attempts to enter a password

struct password {
    char service[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    time_t last_updated;
};

struct password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void print_menu();
void add_password();
void view_passwords();
void edit_password();
void delete_password();

int main() {
    int option;

    // Main menu loop
    while (1) {
        print_menu();
        scanf("%d", &option);

        switch(option) {
            case 1:
                add_password();
                break;
            case 2:
                view_passwords();
                break;
            case 3:
                edit_password();
                break;
            case 4:
                delete_password();
                break;
            case 5:
                printf("Exiting program...");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
}

void print_menu() {
    printf("=====================\n");
    printf("PASSWORD MANAGEMENT\n");
    printf("=====================\n");
    printf("1. Add password\n");
    printf("2. View passwords\n");
    printf("3. Edit password\n");
    printf("4. Delete password\n");
    printf("5. Exit\n");
    printf("=====================\n");
    printf("Enter your choice: ");
}

void add_password() {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Max number of passwords reached.\n");
        return;
    }

    struct password p;
    printf("Enter service name: ");
    scanf("%s", p.service);
    printf("Enter username: ");
    scanf("%s", p.username);
    printf("Enter password: ");
    scanf("%s", p.password);
    p.last_updated = time(NULL);

    passwords[num_passwords++] = p;
    printf("Password added successfully.\n");
}

void view_passwords() {
    if (num_passwords == 0) {
        printf("No passwords found.\n");
        return;
    }

    for (int i = 0; i < num_passwords; i++) {
        printf("Service: %s\n", passwords[i].service);
        printf("Username: %s\n", passwords[i].username);
        printf("Password: %s\n", passwords[i].password);
        printf("Last updated: %s\n", ctime(&passwords[i].last_updated));
        printf("--------------------------------\n");
    }
}

void edit_password() {
    if (num_passwords == 0) {
        printf("No passwords found.\n");
        return;
    }

    char service[MAX_PASSWORD_LENGTH];
    printf("Enter the service name: ");
    scanf("%s", service);

    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].service, service) == 0) {
            char password_attempt[MAX_PASSWORD_LENGTH];
            int attempts = MAX_ATTEMPTS;

            while (attempts > 0) {
                printf("Enter current password to edit: ");
                scanf("%s", password_attempt);

                if (strcmp(password_attempt, passwords[i].password) == 0) {
                    printf("Enter new password: ");
                    scanf("%s", passwords[i].password);
                    passwords[i].last_updated = time(NULL);
                    printf("Password updated successfully.\n");
                    return;
                } else {
                    attempts--;
                    printf("Incorrect password. %d attempts remaining.\n", attempts);
                }
            }

            printf("Too many incorrect password attempts. Password not updated.\n");
            return;
        }
    }

    printf("Service not found.\n");
}

void delete_password() {
    if (num_passwords == 0) {
        printf("No passwords found.\n");
        return;
    }

    char service[MAX_PASSWORD_LENGTH];
    printf("Enter the service name: ");
    scanf("%s", service);

    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].service, service) == 0) {
            char password_attempt[MAX_PASSWORD_LENGTH];
            int attempts = MAX_ATTEMPTS;

            while (attempts > 0) {
                printf("Enter current password to delete: ");
                scanf("%s", password_attempt);

                if (strcmp(password_attempt, passwords[i].password) == 0) {
                    passwords[i] = passwords[num_passwords-1];
                    num_passwords--;
                    printf("Password deleted successfully.\n");
                    return;
                } else {
                    attempts--;
                    printf("Incorrect password. %d attempts remaining.\n", attempts);
                }
            }

            printf("Too many incorrect password attempts. Password not deleted.\n");
            return;
        }
    }

    printf("Service not found.\n");
}