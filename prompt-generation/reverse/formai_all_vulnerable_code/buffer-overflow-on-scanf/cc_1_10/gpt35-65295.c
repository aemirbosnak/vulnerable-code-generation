//FormAI DATASET v1.0 Category: Password management ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD_LENGTH 20
#define MAX_PASSWORDS 100

typedef struct {
    char name[50];
    char password[PASSWORD_LENGTH + 1]; // +1 for null terminator
} password_entry;

password_entry passwords[MAX_PASSWORDS];
int num_passwords = 0;

void print_menu() {
    printf("Welcome to the password manager!\n\n");
    printf("1. Add a new password\n");
    printf("2. Display all passwords\n");
    printf("3. Search for a password by name\n");
    printf("4. Quit\n");
}

void add_password() {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Sorry, you have reached the maximum number of passwords.\n");
        return;
    }

    printf("Enter the name for the new password: ");
    scanf("%s", passwords[num_passwords].name);

    printf("Enter the password for %s (max length %d): ", passwords[num_passwords].name, PASSWORD_LENGTH);
    scanf("%s", passwords[num_passwords].password);

    num_passwords++;

    printf("Password added successfully!\n");
}

void display_passwords() {
    printf("Your saved passwords:\n");

    for (int i = 0; i < num_passwords; i++) {
        printf("%s: %s\n", passwords[i].name, passwords[i].password);
    }
}

void search_password() {
    char search_name[50];
    printf("Enter the name of the password you want to search: ");
    scanf("%s", search_name);

    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].name, search_name) == 0) {
            printf("Password found: %s\n", passwords[i].password);
            return;
        }
    }

    printf("Password not found.\n");
}

int main() {
    int choice = 0;

    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                display_passwords();
                break;
            case 3:
                search_password();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}