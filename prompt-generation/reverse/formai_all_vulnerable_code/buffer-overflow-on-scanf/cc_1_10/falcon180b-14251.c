//Falcon-180B DATASET v1.0 Category: Password management ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} password_t;

int main() {
    password_t passwords[MAX_PASSWORDS];
    int num_passwords = 0;

    while (1) {
        printf("Enter a new username and password (or enter 'q' to quit):\n");
        char username[MAX_PASSWORD_LENGTH];
        char password[MAX_PASSWORD_LENGTH];
        scanf("%s %s", username, password);

        if (strcmp(username, "q") == 0) {
            break;
        }

        if (num_passwords >= MAX_PASSWORDS) {
            printf("Error: maximum number of passwords reached.\n");
            continue;
        }

        strcpy(passwords[num_passwords].username, username);
        strcpy(passwords[num_passwords].password, password);
        num_passwords++;
    }

    printf("\nPassword Manager\n");
    printf("=================\n");

    while (1) {
        printf("\nEnter a username to search for:\n");
        char username[MAX_PASSWORD_LENGTH];
        scanf("%s", username);

        int found = 0;
        for (int i = 0; i < num_passwords; i++) {
            if (strcmp(passwords[i].username, username) == 0) {
                printf("\nUsername: %s\nPassword: %s\n", passwords[i].username, passwords[i].password);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Username not found.\n");
        }
    }

    return 0;
}