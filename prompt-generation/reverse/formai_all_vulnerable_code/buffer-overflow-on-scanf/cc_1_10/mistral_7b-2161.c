//MISTRAL-7B DATASET v1.0 Category: Password management ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PASSWORDS 100
#define PASSWORD_LENGTH 50

typedef struct {
    char username[PASSWORD_LENGTH];
    char password[PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

bool validate_username(char *username) {
    // validation logic for usernames here
}

bool validate_password(char *password) {
    // validation logic for passwords here
}

void add_password(char *username, char *password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Password manager is full.\n");
        return;
    }

    if (!validate_username(username)) {
        printf("Invalid username.\n");
        return;
    }

    if (!validate_password(password)) {
        printf("Invalid password.\n");
        return;
    }

    strcpy(passwords[num_passwords].username, username);
    strcpy(passwords[num_passwords].password, password);
    num_passwords++;
}

void print_passwords() {
    for (int i = 0; i < num_passwords; i++) {
        printf("%s:\t%s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    char username[PASSWORD_LENGTH], password[PASSWORD_LENGTH];

    while (true) {
        printf("Enter a command (add/print/quit): ");
        char command[5];
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter a username: ");
            scanf("%s", username);
            printf("Enter a password: ");
            scanf("%s", password);
            add_password(username, password);
        } else if (strcmp(command, "print") == 0) {
            print_passwords();
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}