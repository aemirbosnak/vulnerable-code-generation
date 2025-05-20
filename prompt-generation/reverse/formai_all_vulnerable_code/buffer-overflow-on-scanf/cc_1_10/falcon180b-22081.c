//Falcon-180B DATASET v1.0 Category: Password management ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 64

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    int length;
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char *password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }

    int length = strlen(password);
    if (length > MAX_PASSWORD_LENGTH) {
        printf("Error: Password is too long.\n");
        return;
    }

    strcpy(passwords[num_passwords].password, password);
    passwords[num_passwords].length = length;
    num_passwords++;
}

void remove_password(char *password) {
    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].password, password) == 0) {
            num_passwords--;
            break;
        }
    }
}

void print_passwords() {
    printf("Passwords:\n");
    int i;
    for (i = 0; i < num_passwords; i++) {
        printf("%d. ", i + 1);
        int j;
        for (j = 0; j < passwords[i].length; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    printf("Password Manager\n");
    printf("Commands: add, remove, print, quit\n");

    char command[64];
    while (1) {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            char *password;
            printf("Enter password: ");
            scanf("%s", password);
            add_password(password);
        } else if (strcmp(command, "remove") == 0) {
            char *password;
            printf("Enter password to remove: ");
            scanf("%s", password);
            remove_password(password);
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