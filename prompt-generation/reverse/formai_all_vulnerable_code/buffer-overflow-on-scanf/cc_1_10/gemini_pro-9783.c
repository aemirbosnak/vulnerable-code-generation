//GEMINI-pro DATASET v1.0 Category: Password management ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100

typedef struct {
    char *username;
    char *password;
} password_t;

password_t passwords[MAX_PASSWORDS];

int num_passwords = 0;

void add_password(char *username, char *password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Too many passwords.\n");
        return;
    }

    passwords[num_passwords].username = malloc(strlen(username) + 1);
    strcpy(passwords[num_passwords].username, username);
    passwords[num_passwords].password = malloc(strlen(password) + 1);
    strcpy(passwords[num_passwords].password, password);

    num_passwords++;
}

void print_passwords() {
    for (int i = 0; i < num_passwords; i++) {
        printf("%s: %s\n", passwords[i].username, passwords[i].password);
    }
}

void free_passwords() {
    for (int i = 0; i < num_passwords; i++) {
        free(passwords[i].username);
        free(passwords[i].password);
    }

    num_passwords = 0;
}

int main() {
    char username[100];
    char password[100];

    while (1) {
        printf("Enter username: ");
        scanf("%s", username);

        if (strcmp(username, "exit") == 0) {
            break;
        }

        printf("Enter password: ");
        scanf("%s", password);

        add_password(username, password);
    }

    print_passwords();

    free_passwords();

    return 0;
}