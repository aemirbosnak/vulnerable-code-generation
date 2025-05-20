//Falcon-180B DATASET v1.0 Category: Password management ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORDS 50
#define MAX_PASSWORD_LENGTH 100

typedef struct {
    char *username;
    char *password;
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char *username, char *password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Sorry, you have reached the maximum number of passwords.\n");
        return;
    }

    passwords[num_passwords].username = strdup(username);
    passwords[num_passwords].password = strdup(password);

    num_passwords++;
}

void delete_password(int index) {
    if (index < 0 || index >= num_passwords) {
        printf("Invalid password index.\n");
        return;
    }

    free(passwords[index].username);
    free(passwords[index].password);

    for (int i = index; i < num_passwords - 1; i++) {
        passwords[i] = passwords[i + 1];
    }

    num_passwords--;
}

void search_password(char *username) {
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            printf("Password found: %s\n", passwords[i].password);
            return;
        }
    }

    printf("Password not found.\n");
}

void print_passwords() {
    printf("Passwords:\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("Username: %s\nPassword: %s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    add_password("example@gmail.com", "password123");
    add_password("test@gmail.com", "qwerty456");

    print_passwords();

    search_password("example@gmail.com");
    search_password("test@gmail.com");
    search_password("invalid@gmail.com");

    delete_password(0);

    print_passwords();

    return 0;
}