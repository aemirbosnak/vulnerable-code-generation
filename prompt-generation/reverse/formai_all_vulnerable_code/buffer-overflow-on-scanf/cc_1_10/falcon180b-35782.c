//Falcon-180B DATASET v1.0 Category: Password management ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

typedef struct {
    char *username;
    char *password;
} password_t;

password_t passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char *username, char *password) {
    if (num_passwords == MAX_PASSWORDS) {
        printf("Error: Cannot add more passwords.\n");
        return;
    }

    passwords[num_passwords].username = strdup(username);
    passwords[num_passwords].password = strdup(password);

    num_passwords++;
}

void delete_password(char *username) {
    int i;

    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            free(passwords[i].username);
            free(passwords[i].password);

            for (; i < num_passwords - 1; i++) {
                passwords[i] = passwords[i + 1];
            }

            num_passwords--;
            break;
        }
    }
}

void display_passwords() {
    int i;

    for (i = 0; i < num_passwords; i++) {
        printf("Username: %s\nPassword: %s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    char command[MAX_PASSWORD_LENGTH];
    char *args[3];

    while (1) {
        printf("Enter command: ");
        scanf("%s", command);

        args[0] = strtok(command, " ");
        args[1] = strtok(NULL, " ");
        args[2] = strtok(NULL, " ");

        if (strcmp(args[0], "add") == 0) {
            add_password(args[1], args[2]);
        } else if (strcmp(args[0], "delete") == 0) {
            delete_password(args[1]);
        } else if (strcmp(args[0], "display") == 0) {
            display_passwords();
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}