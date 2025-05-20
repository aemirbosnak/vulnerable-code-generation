//Falcon-180B DATASET v1.0 Category: Password management ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 64
#define SALT_LENGTH 32

struct password {
    char *username;
    char *password;
    char *salt;
    time_t created_at;
};

void generate_salt(char *salt) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789~!@#$%^&*()_+-={}|[]\\:;\"'<>,.?/";
    int i;

    for (i = 0; i < SALT_LENGTH; i++) {
        salt[i] = charset[rand() % strlen(charset)];
    }

    salt[SALT_LENGTH] = '\0';
}

int main() {
    int num_passwords = 0;
    struct password passwords[MAX_PASSWORDS];

    char *user = "John";
    char *pass = "password123";
    char *salt = "~!@#$%^&*()_+-={}|[]\\:;\"'<>,.?/";
    int i, j;

    printf("Enter number of passwords to generate: ");
    scanf("%d", &num_passwords);

    for (i = 0; i < num_passwords; i++) {
        char *username = malloc(MAX_PASSWORD_LENGTH);
        char *password = malloc(MAX_PASSWORD_LENGTH);
        char *new_salt = malloc(SALT_LENGTH + 1);

        generate_salt(new_salt);

        strncpy(username, user, MAX_PASSWORD_LENGTH);
        strncpy(password, pass, MAX_PASSWORD_LENGTH);
        strncpy(passwords[i].salt, new_salt, SALT_LENGTH);

        passwords[i].created_at = time(NULL);
        passwords[i].username = username;
        passwords[i].password = password;
        passwords[i].salt = new_salt;

        printf("Password %d:\n", i+1);
        printf("Username: %s\n", passwords[i].username);
        printf("Password: %s\n", passwords[i].password);
        printf("Salt: %s\n", passwords[i].salt);
        printf("\n");
    }

    return 0;
}