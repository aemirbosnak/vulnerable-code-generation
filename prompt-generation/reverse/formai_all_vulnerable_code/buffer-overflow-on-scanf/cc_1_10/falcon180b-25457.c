//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define PASSWORD_LEN 8

int check_password_strength(char *password) {
    int score = 0;

    // Check for uppercase letters
    if (strspn(password, "ABCDEFGHIJKLMNOPQRSTUVWXYZ") > 0) {
        score++;
    }

    // Check for lowercase letters
    if (strspn(password, "abcdefghijklmnopqrstuvwxyz") > 0) {
        score++;
    }

    // Check for numbers
    if (strspn(password, "0123456789") > 0) {
        score++;
    }

    // Check for special characters
    if (strspn(password, "!@#$%^&*()_-=+[{]}\\|;:'\",<.>/?") > 0) {
        score++;
    }

    // Check for length
    if (strlen(password) >= PASSWORD_LEN) {
        score++;
    }

    if (score == 0) {
        printf("Weak password\n");
    } else if (score == 1) {
        printf("Fair password\n");
    } else if (score == 2) {
        printf("Good password\n");
    } else {
        printf("Strong password\n");
    }

    return score;
}

int main() {
    char password[PASSWORD_LEN + 1];

    printf("Enter your password: ");
    scanf("%s", password);

    int strength = check_password_strength(password);

    return 0;
}