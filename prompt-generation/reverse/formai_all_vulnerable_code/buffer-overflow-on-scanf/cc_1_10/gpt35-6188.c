//FormAI DATASET v1.0 Category: Password management ; Style: intelligent
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct Password {
    char name[50];
    char password[50];
};

void add_password(struct Password passwords[], int* num_passwords) {
    if (*num_passwords == 10) { // Only allow 10 passwords to be stored
        printf("You have reached the maximum number of passwords allowed.\n");
        return;
    }

    struct Password new_password;

    printf("Enter the name for the password: ");
    scanf("%s", new_password.name); // Get name for new password

    for(int i = 0; i < *num_passwords; i++) {
        if(strcmp(new_password.name, passwords[i].name) == 0) {
            printf("A password with that name already exists.\n");
            return;
        }
    }

    printf("Enter the password: ");
    scanf("%s", new_password.password); // Get password for new password

    passwords[*num_passwords] = new_password;
    (*num_passwords)++;

    printf("Password added successfully.\n");
}

void view_passwords(struct Password passwords[], int num_passwords) {
    if (num_passwords == 0) {
        printf("No passwords stored.\n");
        return;
    }

    printf("Passwords:\n");

    for (int i = 0; i < num_passwords; i++) {
        printf("\tName: %s\tPassword: %s\n", passwords[i].name, passwords[i].password);
    }
}

void find_password(struct Password passwords[], int num_passwords) {
    if (num_passwords == 0) {
        printf("No passwords stored.\n");
        return;
    }

    char search_name[50];

    printf("Enter the name of the password to search for: ");
    scanf("%s", search_name); // Get name to search for

    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(search_name, passwords[i].name) == 0) {
            printf("Password: %s\n", passwords[i].password);
            return;
        }
    }

    printf("No password found with that name.\n");
}

int main() {
    struct Password passwords[10]; // Store up to 10 passwords
    int num_passwords = 0;
    int choice;

    do {
        printf("1. Add a password\n");
        printf("2. View passwords\n");
        printf("3. Find a password\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice); // Get user choice

        switch (choice) {
            case 1:
                add_password(passwords, &num_passwords);
                break;
            case 2:
                view_passwords(passwords, num_passwords);
                break;
            case 3:
                find_password(passwords, num_passwords);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }

        printf("\n"); // Print newline for readability

    } while (choice != 4);

    return 0;
}