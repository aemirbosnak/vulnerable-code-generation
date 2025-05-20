//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_LENGTH 8

int check_length(char *password) {
    return strlen(password) < MIN_LENGTH ? 0 : 1;
}

int check_uppercase(char *password) {
    int i;
    for (i = 0; password[i] != '\0'; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            return 1;
        }
    }
    return 0;
}

int check_lowercase(char *password) {
    int i;
    for (i = 0; password[i] != '\0'; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            return 1;
        }
    }
    return 0;
}

int check_digit(char *password) {
    int i;
    for (i = 0; password[i] != '\0'; i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            return 1;
        }
    }
    return 0;
}

int check_special(char *password) {
    int i;
    for (i = 0; password[i] != '\0'; i++) {
        if (!((password[i] >= 'A' && password[i] <= 'Z') ||
              (password[i] >= 'a' && password[i] <= 'z') ||
              (password[i] >= '0' && password[i] <= '9'))) {
            return 1;
        }
    }
    return 0;
}

int check_strength(char *password) {
    int score = 0;
    score += check_length(password);
    score += check_uppercase(password);
    score += check_lowercase(password);
    score += check_digit(password);
    score += check_special(password);
    return score;
}

int main() {
    char password[100];
    int strength;

    printf("Enter password: ");
    scanf("%s", password);

    strength = check_strength(password);

    printf("Password strength: ");
    switch (strength) {
        case 0:
            printf("Very weak");
            break;
        case 1:
            printf("Weak");
            break;
        case 2:
            printf("Fair");
            break;
        case 3:
            printf("Good");
            break;
        case 4:
            printf("Strong");
            break;
        case 5:
            printf("Very strong");
            break;
    }

    printf("\n");

    return 0;
}