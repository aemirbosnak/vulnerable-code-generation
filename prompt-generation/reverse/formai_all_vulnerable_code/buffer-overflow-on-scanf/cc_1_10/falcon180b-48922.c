//Falcon-180B DATASET v1.0 Category: Password management ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORDS 100
#define PASSWORD_LENGTH 20

typedef struct {
    char username[100];
    char password[PASSWORD_LENGTH];
} password_t;

password_t passwords[MAX_PASSWORDS];
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
            memset(passwords[i].password, 0, PASSWORD_LENGTH);
            num_passwords--;
            break;
        }
    }
}

void print_passwords() {
    int i;

    if (num_passwords == 0) {
        printf("No passwords found.\n");
        return;
    }

    printf("Passwords:\n");
    for (i = 0; i < num_passwords; i++) {
        printf("%s: %s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    char username[100];
    char password[PASSWORD_LENGTH];

    while (1) {
        printf("Enter username: ");
        scanf("%s", username);

        printf("Enter password: ");
        scanf("%s", password);

        add_password(username, password);
    }

    return 0;
}