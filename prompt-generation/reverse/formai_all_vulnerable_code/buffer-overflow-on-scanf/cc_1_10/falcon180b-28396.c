//Falcon-180B DATASET v1.0 Category: Password management ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 64

typedef struct {
    char *username;
    char *password;
} Password;

void generate_password(char *password, int length) {
    const char *chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    for (int i = 0; i < length; i++) {
        password[i] = chars[rand() % strlen(chars)];
    }
    password[length] = '\0';
}

int main() {
    Password passwords[MAX_PASSWORDS];
    int num_passwords = 0;

    while (1) {
        printf("Enter a website or application name: ");
        char *name = malloc(256);
        scanf("%s", name);

        if (num_passwords >= MAX_PASSWORDS) {
            printf("Maximum number of passwords reached.\n");
            continue;
        }

        printf("Enter a username: ");
        char *username = malloc(256);
        scanf("%s", username);

        int password_length = 16;
        char *password = malloc(password_length + 1);
        generate_password(password, password_length);

        passwords[num_passwords] = (Password) {
           .username = username,
           .password = password
        };
        num_passwords++;

        printf("Password generated for %s:\n", name);
        printf("Username: %s\n", username);
        printf("Password: %s\n\n", password);
    }

    return 0;
}