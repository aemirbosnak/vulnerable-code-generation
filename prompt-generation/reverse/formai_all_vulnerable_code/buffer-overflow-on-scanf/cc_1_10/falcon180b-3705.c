//Falcon-180B DATASET v1.0 Category: Password management ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 1000
#define MAX_PASSWORD_LENGTH 50
#define MAX_USERNAME_LENGTH 50

struct password {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

struct password passwords[MAX_PASSWORDS];
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

void search_password() {
    printf("Enter username to search: ");
    char username[MAX_USERNAME_LENGTH];
    scanf("%s", username);

    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            printf("Password: %s\n", passwords[i].password);
            return;
        }
    }

    printf("Password not found.\n");
}

int main() {
    printf("Welcome to the password manager!\n");

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Add password\n");
        printf("2. Search password\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                search_password();
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}