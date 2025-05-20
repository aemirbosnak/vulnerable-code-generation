//Falcon-180B DATASET v1.0 Category: Password management ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 64

typedef struct {
    char *username;
    char *password;
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char *username, char *password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: maximum number of passwords reached.\n");
        return;
    }

    passwords[num_passwords].username = strdup(username);
    passwords[num_passwords].password = strdup(password);

    num_passwords++;
}

Password *get_password(char *username) {
    int i;

    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            return &passwords[i];
        }
    }

    return NULL;
}

void delete_password(char *username) {
    Password *password = get_password(username);

    if (password == NULL) {
        printf("Error: password not found.\n");
        return;
    }

    free(password->username);
    free(password->password);

    num_passwords--;
}

void print_passwords() {
    int i;

    for (i = 0; i < num_passwords; i++) {
        printf("Username: %s\nPassword: %s\n\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    while (1) {
        printf("Enter username (leave blank to exit):\n");
        scanf("%s", username);

        if (username[0] == '\0') {
            break;
        }

        printf("Enter password:\n");
        scanf("%s", password);

        add_password(username, password);
    }

    printf("Passwords:\n");
    print_passwords();

    return 0;
}