//Code Llama-13B DATASET v1.0 Category: Password management ; Style: configurable
// Password Management Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define MAX_USERS 100

typedef struct {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} User;

User users[MAX_USERS];

int add_user(char *username, char *password) {
    for (int i = 0; i < MAX_USERS; i++) {
        if (users[i].username[0] == '\0') {
            strcpy(users[i].username, username);
            strcpy(users[i].password, password);
            return 1;
        }
    }
    return 0;
}

int check_user(char *username, char *password) {
    for (int i = 0; i < MAX_USERS; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char username[MAX_LENGTH], password[MAX_LENGTH];
    char choice;

    while (1) {
        printf("Enter your username: ");
        scanf("%s", username);
        printf("Enter your password: ");
        scanf("%s", password);

        if (check_user(username, password)) {
            printf("Welcome %s!\n", username);
            break;
        } else {
            printf("Invalid username or password\n");
            printf("Would you like to try again (y/n)? ");
            scanf(" %c", &choice);
            if (choice == 'n') {
                break;
            }
        }
    }

    return 0;
}