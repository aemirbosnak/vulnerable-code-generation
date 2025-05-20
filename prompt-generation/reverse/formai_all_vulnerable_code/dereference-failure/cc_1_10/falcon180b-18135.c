//Falcon-180B DATASET v1.0 Category: Password management ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 1000
#define MAX_PASSWORD_LENGTH 100

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

    int username_length = strlen(username);
    if (username_length > MAX_PASSWORD_LENGTH) {
        printf("Error: username too long.\n");
        return;
    }

    int password_length = strlen(password);
    if (password_length > MAX_PASSWORD_LENGTH) {
        printf("Error: password too long.\n");
        return;
    }

    passwords[num_passwords].username = malloc(username_length + 1);
    strcpy(passwords[num_passwords].username, username);

    passwords[num_passwords].password = malloc(password_length + 1);
    strcpy(passwords[num_passwords].password, password);

    num_passwords++;
}

void delete_password(char *username) {
    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            free(passwords[i].username);
            free(passwords[i].password);

            memmove(&passwords[i], &passwords[i+1], (num_passwords - i - 1) * sizeof(Password));

            num_passwords--;
            return;
        }
    }

    printf("Error: password not found.\n");
}

void print_passwords() {
    if (num_passwords == 0) {
        printf("No passwords stored.\n");
        return;
    }

    printf("Username\tPassword\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%s\t%s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    add_password("example@example.com", "password123");
    add_password("test@test.com", "testpassword");
    print_passwords();

    delete_password("example@example.com");
    print_passwords();

    return 0;
}