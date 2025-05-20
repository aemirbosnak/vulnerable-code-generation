//Falcon-180B DATASET v1.0 Category: Password management ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORDS 1000
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} password_t;

int num_passwords = 0;
password_t passwords[MAX_PASSWORDS];

void add_password(char* username, char* password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Too many passwords!\n");
        return;
    }

    strcpy(passwords[num_passwords].username, username);
    strcpy(passwords[num_passwords].password, password);
    num_passwords++;
}

int find_password(char* username) {
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            printf("Password for %s: %s\n", username, passwords[i].password);
            return 1;
        }
    }
    printf("Password for %s not found.\n", username);
    return 0;
}

int main() {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Welcome to the password manager!\n");
    printf("Enter your username: ");
    scanf("%s", username);

    if (find_password(username)) {
        return 0;
    }

    printf("Enter your password: ");
    scanf("%s", password);

    add_password(username, password);

    printf("Password saved!\n");
    return 0;
}