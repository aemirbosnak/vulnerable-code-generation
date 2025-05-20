//Falcon-180B DATASET v1.0 Category: Password management ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50
#define HASH_LENGTH 32

typedef struct {
    char *username;
    char *password;
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void hashPassword(char *password, char *hash) {
    size_t i;
    for (i = 0; i < strlen(password); i++) {
        hash[i] = password[i] ^ 'k';
    }
    hash[i] = '\0';
}

int comparePasswords(char *password1, char *password2) {
    return strcmp(password1, password2) == 0;
}

int main() {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char hash[HASH_LENGTH];

    while (true) {
        printf("Enter your username: ");
        scanf("%s", username);

        int i;
        for (i = 0; i < numPasswords; i++) {
            if (comparePasswords(passwords[i].username, username)) {
                printf("Enter your password: ");
                scanf("%s", password);

                hashPassword(password, hash);

                if (strcmp(hash, passwords[i].password) == 0) {
                    printf("Login successful!\n");
                    break;
                } else {
                    printf("Incorrect password.\n");
                }
            }
        }

        if (i == numPasswords) {
            printf("User not found.\n");
        }
    }

    return 0;
}