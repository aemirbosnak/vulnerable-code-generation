//Falcon-180B DATASET v1.0 Category: Password management ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50
#define MAX_USERNAME_LENGTH 50

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char *username, char *password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }

    strcpy(passwords[num_passwords].username, username);
    strcpy(passwords[num_passwords].password, password);

    num_passwords++;
}

void remove_password(char *username) {
    int i;

    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            memset(passwords[i].password, '\0', MAX_PASSWORD_LENGTH);
            num_passwords--;
            return;
        }
    }

    printf("Error: Password not found.\n");
}

void change_password(char *username, char *old_password, char *new_password) {
    int i;

    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0 && strcmp(passwords[i].password, old_password) == 0) {
            strcpy(passwords[i].password, new_password);
            return;
        }
    }

    printf("Error: Old password incorrect.\n");
}

void print_passwords() {
    int i;

    for (i = 0; i < num_passwords; i++) {
        printf("Username: %s\nPassword: %s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    while (true) {
        printf("Enter username: ");
        scanf("%s", username);

        if (strlen(username) == 0) {
            printf("Error: Username cannot be empty.\n");
            continue;
        }

        printf("Enter password: ");
        scanf("%s", password);

        if (strlen(password) == 0) {
            printf("Error: Password cannot be empty.\n");
            continue;
        }

        if (!isalnum(password[0])) {
            printf("Error: Password must start with a letter or number.\n");
            continue;
        }

        add_password(username, password);
        printf("Password added successfully.\n");
    }

    return 0;
}