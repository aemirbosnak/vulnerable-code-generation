//MISTRAL-7B DATASET v1.0 Category: Password Strength Checker ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MIN_LENGTH 8
#define MAX_TRIES 3

typedef enum { L_WEAK, L_MEDIUM, L_STRONG, L_VERY_STRONG } strength_t;

strength_t check_password(char *password) {
    size_t length = strlen(password);
    int has_digit = 0, has_upper = 0, has_lower = 0, has_special = 0;

    for (int i = 0; password[i] || (--length > 0 && password[i] == '\0'); i++) {
        if (isdigit(password[i])) {
            has_digit = 1;
        } else if (isupper(password[i])) {
            has_upper = 1;
        } else if (islower(password[i])) {
            has_lower = 1;
        } else {
            if (strchr("!@#$%^&*()_+-=[]{};:,.<>|\\/?~`", password[i])) {
                has_special = 1;
            }
        }

        if (length <= 0) break;
    }

    if (!length || (length == 1 && !has_digit && !has_upper && !has_lower && !has_special))
        return L_WEAK;

    if (length >= MIN_LENGTH && (has_digit && has_upper && has_lower))
        return L_MEDIUM;

    if (length >= MIN_LENGTH && (has_digit && has_upper && has_lower && has_special))
        return L_STRONG;

    if (length >= MIN_LENGTH && (has_digit && has_upper && has_lower && has_special)
            && (password[0] > 'Z' || password[length - 1] > 'Z'))
        return L_VERY_STRONG;

    return L_WEAK;
}

int main(int argc, char **argv) {
    int tries = 0;
    char *password;

    if (argc != 2) {
        printf("Usage: %s <password>\n", argv[0]);
        exit(1);
    }

    password = malloc(strlen(argv[1]) + 1);
    strcpy(password, argv[1]);

    while (tries < MAX_TRIES && check_password(password) < L_MEDIUM) {
        printf("Password is weak. Try again:\n");
        printf("> ");
        fgets(password, sizeof(password), stdin);
        password[strcspn(password, "\n")] = '\0';
        tries++;
    }

    if (tries >= MAX_TRIES) {
        printf("Maximum number of tries reached. Exiting...\n");
        free(password);
        exit(1);
    }

    strength_t strength = check_password(password);
    printf("Password is %s strength.\n", strength < L_MEDIUM ? "below" : "at least");

    free(password);
    return 0;
}