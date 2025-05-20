//GEMINI-pro DATASET v1.0 Category: Password management ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* passwords[100]; // 100 passwords should be enough, right?

// The classic Caesar cipher, updated with a dash of humor
char *caesar_plus(char *password, int shift) {
    int i;
    for (i = 0; password[i]; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            password[i] = (password[i] - 'a' + shift + 26) % 26 + 'a';
        } else if (password[i] >= 'A' && password[i] <= 'Z') {
            password[i] = (password[i] - 'A' + shift + 26) % 26 + 'A';
        }
    }
    return password;
}

// Store a password with a bit of spice
void store_password(char *password) {
    char *encrypted = caesar_plus(password, 13);
    printf("Your password '%s' has been safely stored as '%s'.\n", password, encrypted);
    passwords[rand() % 100] = strdup(encrypted);
}

// Retrieve a password with a dash of wit
char *retrieve_password(char *password) {
    char *encrypted = caesar_plus(password, 13);
    int i;
    for (i = 0; i < 100; i++) {
        if (passwords[i] && strcmp(passwords[i], encrypted) == 0) {
            free(passwords[i]);
            return caesar_plus(encrypted, -13);
        }
    }
    printf("Sorry, your password was either entered incorrectly or stolen by a sneaky squirrel. Try again, or contact our squirrels for assistance.\n");
    return NULL;
}

int main() {
    char command[100], password[100];
    printf("Welcome to the password manager, where laughter is our encryption algorithm!\n");
    while (1) {
        printf("Enter 'store' to store a password, 'retrieve' to retrieve one, or 'exit' to quit:\n");
        scanf("%s", command);
        if (strcmp(command, "store") == 0) {
            printf("Enter your password:\n");
            scanf("%s", password);
            store_password(password);
        } else if (strcmp(command, "retrieve") == 0) {
            printf("Enter your password:\n");
            scanf("%s", password);
            char *retrieved = retrieve_password(password);
            if (retrieved) {
                printf("Your password is: %s\n", retrieved);
            }
        } else if (strcmp(command, "exit") == 0) {
            printf("Bye-bye, have a password-filled day!\n");
            return 0;
        } else {
            printf("Come on, don't be a joker! Enter a valid command.\n");
        }
    }
    return 0;
}