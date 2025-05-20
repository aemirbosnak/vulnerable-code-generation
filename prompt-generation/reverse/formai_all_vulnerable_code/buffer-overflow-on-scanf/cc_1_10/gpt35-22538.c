//FormAI DATASET v1.0 Category: Password management ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

struct PasswordManager {
    char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH];
    int num_passwords;
};

void print_menu() {
    printf("1. Add password\n");
    printf("2. Remove password\n");
    printf("3. View all passwords\n");
    printf("4. Exit\n");
}

void add_password(struct PasswordManager *password_manager) {
    char new_password[MAX_PASSWORD_LENGTH];
    printf("Enter new password: ");
    scanf("%s", new_password);
    if (password_manager->num_passwords < MAX_PASSWORDS) {
        strcpy(password_manager->passwords[password_manager->num_passwords], new_password);
        password_manager->num_passwords++;
        printf("Password added successfully!\n");
    } else {
        printf("Maximum number of passwords reached.\n");
    }
}

void remove_password(struct PasswordManager *password_manager) {
    int password_index;
    printf("Enter index of password to remove: ");
    scanf("%d", &password_index);
    if (password_index >= 0 && password_index < password_manager->num_passwords) {
        for (int i = password_index; i < password_manager->num_passwords - 1; i++) {
            strcpy(password_manager->passwords[i], password_manager->passwords[i + 1]);
        }
        password_manager->num_passwords--;
        printf("Password removed successfully!\n");
    } else {
        printf("Invalid password index.\n");
    }
}

void view_passwords(struct PasswordManager *password_manager) {
    printf("All passwords:\n");
    for (int i = 0; i < password_manager->num_passwords; i++) {
        printf("%d - %s\n", i, password_manager->passwords[i]);
    }
}

int main() {
    struct PasswordManager password_manager = {{0}, 0};
    int choice = 0;
    
    while (choice != 4) {
        print_menu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_password(&password_manager);
                break;
            case 2:
                remove_password(&password_manager);
                break;
            case 3:
                view_passwords(&password_manager);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}