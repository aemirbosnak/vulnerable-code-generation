//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PASSWORD_LENGTH 20

typedef struct password_strength {
    int strength;
    char *message;
} password_strength;

password_strength check_password_strength(char *password) {
    password_strength ps;
    ps.strength = 0;
    ps.message = malloc(PASSWORD_LENGTH);

    if (strlen(password) < 8) {
        strcpy(ps.message, "Password is too short!");
    } else if (strlen(password) >= 8 && strlen(password) < 16) {
        strcpy(ps.message, "Password is adequate.");
        ps.strength = 1;
    } else if (strlen(password) >= 16) {
        strcpy(ps.message, "Password is strong!");
        ps.strength = 2;
    } else {
        strcpy(ps.message, "Invalid password.");
    }

    return ps;
}

int main() {
    char password[PASSWORD_LENGTH];

    printf("Enter your password: ");
    scanf("%s", password);

    password_strength ps = check_password_strength(password);

    switch (ps.strength) {
        case 0:
            printf("Error: %s\n", ps.message);
            break;
        case 1:
            printf("Warning: %s\n", ps.message);
            break;
        case 2:
            printf("Good: %s\n", ps.message);
            break;
        default:
            printf("Invalid password.\n");
            break;
    }

    return 0;
}