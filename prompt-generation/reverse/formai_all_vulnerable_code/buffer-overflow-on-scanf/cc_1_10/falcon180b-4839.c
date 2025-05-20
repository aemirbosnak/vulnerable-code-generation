//Falcon-180B DATASET v1.0 Category: Password management ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
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
            num_passwords--;
            break;
        }
    }
}

void print_passwords() {
    int i;

    for (i = 0; i < num_passwords; i++) {
        printf("%s: %s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    char command[100];

    while (1) {
        printf("Enter command (add/remove/print/exit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            char username[MAX_PASSWORD_LENGTH];
            char password[MAX_PASSWORD_LENGTH];

            printf("Enter username: ");
            scanf("%s", username);
            printf("Enter password: ");
            scanf("%s", password);

            add_password(username, password);
        } else if (strcmp(command, "remove") == 0) {
            char username[MAX_PASSWORD_LENGTH];

            printf("Enter username: ");
            scanf("%s", username);

            remove_password(username);
        } else if (strcmp(command, "print") == 0) {
            print_passwords();
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}