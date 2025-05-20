//GEMINI-pro DATASET v1.0 Category: Password management ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 32

typedef struct {
    char *username;
    char *password;
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char *username, char *password) {
    if (num_passwords == MAX_PASSWORDS) {
        printf("Error: Password limit reached!\n");
        return;
    }

    passwords[num_passwords].username = strdup(username);
    passwords[num_passwords].password = strdup(password);
    num_passwords++;
}

void print_passwords() {
    for (int i = 0; i < num_passwords; i++) {
        printf("Username: %s\n", passwords[i].username);
        printf("Password: %s\n", passwords[i].password);
        printf("\n");
    }
}

int main() {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Welcome to the most secure password manager in the universe!\n");

    while (1) {
        printf("\nWhat do you want to do?\n");
        printf("1. Add a password\n");
        printf("2. Print all passwords\n");
        printf("3. Quit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter username: ");
                scanf("%s", username);

                printf("Enter password: ");
                scanf("%s", password);

                add_password(username, password);

                printf("Password added!\n");
                break;

            case 2:
                print_passwords();
                break;

            case 3:
                printf("Bye!\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}