//Falcon-180B DATASET v1.0 Category: Password management ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 100

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password() {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }

    printf("Enter username: ");
    scanf("%s", passwords[num_passwords].username);

    printf("Enter password: ");
    scanf("%s", passwords[num_passwords].password);

    num_passwords++;

    printf("Password added successfully.\n");
}

void remove_password() {
    if (num_passwords == 0) {
        printf("Error: No passwords to remove.\n");
        return;
    }

    int choice;
    printf("Enter the index of the password to remove (0-%d): ", num_passwords - 1);
    scanf("%d", &choice);

    if (choice < 0 || choice >= num_passwords) {
        printf("Error: Invalid password index.\n");
        return;
    }

    num_passwords--;

    for (int i = choice; i < num_passwords; i++) {
        strcpy(passwords[i].username, passwords[i + 1].username);
        strcpy(passwords[i].password, passwords[i + 1].password);
    }

    printf("Password removed successfully.\n");
}

void search_password() {
    if (num_passwords == 0) {
        printf("Error: No passwords to search.\n");
        return;
    }

    char search_username[MAX_USERNAME_LENGTH];
    printf("Enter username to search for: ");
    scanf("%s", search_username);

    int found = 0;
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, search_username) == 0) {
            printf("Password found:\n");
            printf("Username: %s\n", passwords[i].username);
            printf("Password: %s\n", passwords[i].password);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Password not found.\n");
    }
}

int main() {
    printf("Password Manager\n");

    while (1) {
        printf("\nOptions:\n");
        printf("1. Add password\n");
        printf("2. Remove password\n");
        printf("3. Search password\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_password();
            break;
        case 2:
            remove_password();
            break;
        case 3:
            search_password();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid option.\n");
        }
    }

    return 0;
}