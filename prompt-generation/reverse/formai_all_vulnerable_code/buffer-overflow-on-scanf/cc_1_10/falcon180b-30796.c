//Falcon-180B DATASET v1.0 Category: Password management ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int length;
} password_t;

void generate_password(password_t *password) {
    char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int i, j;

    for (i = 0; i < password->length; i++) {
        do {
            password->password[i] = chars[rand() % strlen(chars)];
        } while (!isalnum(password->password[i]));
    }

    password->password[password->length] = '\0';
}

int main() {
    int num_passwords, i;
    password_t passwords[MAX_PASSWORDS];

    printf("Enter the number of passwords to generate: ");
    scanf("%d", &num_passwords);

    for (i = 0; i < num_passwords; i++) {
        printf("Enter the username for password %d: ", i + 1);
        scanf("%s", passwords[i].username);

        printf("Enter the length of the password for %s (between 8 and 100): ", passwords[i].username);
        scanf("%d", &passwords[i].length);

        if (passwords[i].length < 8 || passwords[i].length > 100) {
            printf("Invalid password length. Password length must be between 8 and 100.\n");
            i--;
            continue;
        }

        generate_password(&passwords[i]);

        printf("Password for %s: %s\n", passwords[i].username, passwords[i].password);
    }

    return 0;
}