//Falcon-180B DATASET v1.0 Category: Password management ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100
#define MAX_LOGIN_ATTEMPTS 3

typedef struct {
    char username[MAX_LOGIN_ATTEMPTS];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char* username, char* password) {
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            printf("Password for %s already exists.\n", username);
            return;
        }
    }

    strcpy(passwords[num_passwords].username, username);
    strcpy(passwords[num_passwords].password, password);

    num_passwords++;
}

void login(char* username, char* password) {
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            if (strcmp(passwords[i].password, password) == 0) {
                printf("Login successful!\n");
                return;
            } else {
                printf("Incorrect password for %s.\n", username);
                return;
            }
        }
    }

    printf("User %s not found.\n", username);
}

int main() {
    char username[MAX_LOGIN_ATTEMPTS];
    char password[MAX_PASSWORD_LENGTH];

    int login_attempts = 0;

    while (1) {
        printf("Enter username: ");
        scanf("%s", username);

        printf("Enter password: ");
        scanf("%s", password);

        if (login_attempts >= MAX_LOGIN_ATTEMPTS) {
            printf("Maximum login attempts reached.\n");
            break;
        }

        login(username, password);

        if (login_attempts == 0) {
            printf("Login successful!\n");
        }

        login_attempts++;
    }

    return 0;
}