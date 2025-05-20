//Falcon-180B DATASET v1.0 Category: Password management ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50
#define MAX_USERNAME_LENGTH 50

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

int num_passwords = 0;
Password passwords[MAX_PASSWORDS];

void add_password() {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Sorry, you've reached the maximum number of passwords!\n");
        return;
    }

    char username[MAX_USERNAME_LENGTH];
    printf("Enter a username: ");
    scanf("%s", username);

    char password[MAX_PASSWORD_LENGTH];
    printf("Enter a password: ");
    scanf("%s", password);

    strcpy(passwords[num_passwords].username, username);
    strcpy(passwords[num_passwords].password, password);
    num_passwords++;

    printf("Password added successfully!\n");
}

void view_passwords() {
    if (num_passwords == 0) {
        printf("No passwords found.\n");
        return;
    }

    printf("Username\t\tPassword\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%s\t\t%s\n", passwords[i].username, passwords[i].password);
    }
}

void search_password() {
    char search_username[MAX_USERNAME_LENGTH];
    printf("Enter a username to search for: ");
    scanf("%s", search_username);

    int found = 0;
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, search_username) == 0) {
            printf("Password found: %s\n", passwords[i].password);
            found = 1;
        }
    }

    if (!found) {
        printf("Password not found.\n");
    }
}

int main() {
    printf("Welcome to the password manager!\n");

    while (1) {
        printf("\nOptions:\n");
        printf("1. Add a password\n");
        printf("2. View all passwords\n");
        printf("3. Search for a password\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_password();
            break;
        case 2:
            view_passwords();
            break;
        case 3:
            search_password();
            break;
        case 4:
            printf("Goodbye!\n");
            return 0;
        default:
            printf("Invalid option.\n");
        }
    }

    return 0;
}