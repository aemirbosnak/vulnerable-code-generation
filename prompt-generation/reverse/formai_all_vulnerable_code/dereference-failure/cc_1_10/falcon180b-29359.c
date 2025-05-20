//Falcon-180B DATASET v1.0 Category: Password management ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char *username;
    char *password;
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char *username, char *password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }

    Password *new_password = &passwords[num_passwords];
    new_password->username = strdup(username);
    new_password->password = strdup(password);

    num_passwords++;
}

Password *get_password(char *username) {
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            return &passwords[i];
        }
    }

    return NULL;
}

void delete_password(char *username) {
    Password *password = get_password(username);

    if (password == NULL) {
        printf("Error: Password not found.\n");
        return;
    }

    free(password->username);
    free(password->password);

    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            memmove(&passwords[i], &passwords[i+1], (num_passwords - i - 1) * sizeof(Password));
            num_passwords--;
            break;
        }
    }
}

void print_passwords() {
    printf("Username\tPassword\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%s\t%s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    add_password("example", "password123");
    add_password("test", "testpassword");

    print_passwords();

    delete_password("example");

    print_passwords();

    return 0;
}