//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 32
#define MIN_PASSWORD_LENGTH 8

#define UPPER_CASE_LETTERS "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define LOWER_CASE_LETTERS "abcdefghijklmnopqrstuvwxyz"
#define DIGITS "0123456789"
#define SPECIAL_CHARACTERS "!@#$%^&*()_+-=[]{}|;:,.<>?/~`"

char *generate_password(int length) {
    char *password = malloc(length + 1);
    if (password == NULL) {
        printf("Error: Could not allocate memory for password.\n");
        exit(1);
    }

    int i;
    for (i = 0; i < length; i++) {
        char c;
        do {
            c = rand() % 94 + 33;
        } while (!isalnum(c) &&!strchr(SPECIAL_CHARACTERS, c));
        password[i] = c;
    }
    password[length] = '\0';

    return password;
}

int main() {
    int password_length = 0;

    printf("Enter the desired password length (between %d and %d): ", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
    scanf("%d", &password_length);

    while (password_length < MIN_PASSWORD_LENGTH || password_length > MAX_PASSWORD_LENGTH) {
        printf("Invalid password length. Please enter a value between %d and %d: ", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        scanf("%d", &password_length);
    }

    char *password = generate_password(password_length);

    printf("Your password is: %s\n", password);

    free(password);
    return 0;
}