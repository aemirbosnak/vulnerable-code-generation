//Falcon-180B DATASET v1.0 Category: Password management ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50
#define MAX_USERNAME_LENGTH 50

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char *username, char *password) {
    strncpy(passwords[num_passwords].username, username, MAX_USERNAME_LENGTH);
    strncpy(passwords[num_passwords].password, password, MAX_PASSWORD_LENGTH);
    num_passwords++;
}

int main() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Welcome to the password manager!\n");
    printf("Please enter your username: ");
    scanf("%s", username);

    int found = 0;
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            found = 1;
            printf("Please enter your password: ");
            scanf("%s", password);

            if (strcmp(passwords[i].password, password) == 0) {
                printf("Password correct!\n");
            } else {
                printf("Password incorrect.\n");
            }
        }
    }

    if (!found) {
        printf("User not found.\n");
    }

    return 0;
}