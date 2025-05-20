//Falcon-180B DATASET v1.0 Category: Password management ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PASSWORD_LENGTH 64
#define SALT_LENGTH 16

typedef struct {
    char password[PASSWORD_LENGTH];
    char salt[SALT_LENGTH];
    time_t created_at;
} Password;

void generate_password(Password *password) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_-+={}[];:,.<>? ";
    size_t charset_size = strlen(charset);
    size_t password_length = PASSWORD_LENGTH - 1; // Leave room for null terminator

    srand(time(NULL));

    for (size_t i = 0; i < password_length; i++) {
        password->password[i] = charset[rand() % charset_size];
    }

    password->password[password_length] = '\0';
}

void generate_salt(Password *password) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_-+={}[];:,.<>? ";
    size_t charset_size = strlen(charset);
    size_t salt_length = SALT_LENGTH - 1; // Leave room for null terminator

    srand(time(NULL));

    for (size_t i = 0; i < salt_length; i++) {
        password->salt[i] = charset[rand() % charset_size];
    }

    password->salt[salt_length] = '\0';
}

void hash_password(Password *password) {
    char salt_copy[SALT_LENGTH];
    strcpy(salt_copy, password->salt);

    char password_copy[PASSWORD_LENGTH];
    strcpy(password_copy, password->password);

    char hash[PASSWORD_LENGTH];
    hash[0] = '$';
    hash[1] = '6';
    hash[2] = '$';

    for (size_t i = 0; i < SALT_LENGTH; i++) {
        hash[3 + i * 2] = salt_copy[i];
    }

    for (size_t i = 0; i < PASSWORD_LENGTH; i++) {
        hash[3 + SALT_LENGTH * 2 + i * 2] = password_copy[i];
    }

    hash[3 + SALT_LENGTH * 2 + PASSWORD_LENGTH * 2 - 1] = '\0';

    strcpy(password->password, hash);
}

int main() {
    Password password;

    generate_password(&password);
    generate_salt(&password);
    hash_password(&password);

    printf("Password: %s\n", password.password);
    printf("Salt: %s\n", password.salt);
    printf("Created at: %ld\n", password.created_at);

    return 0;
}