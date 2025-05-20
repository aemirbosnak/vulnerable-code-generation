//MISTRAL-7B DATASET v1.0 Category: Password Strength Checker ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MIN_LENGTH 8
#define WEAK_POINTS 3

int password_strength(char *password) {
    int length = strlen(password);
    int strength = 0;
    int upper = 0, lower = 0, digit = 0, special = 0;

    for (int i = 0; password[i] != '\0'; i++) {
        if (isalpha(password[i])) {
            lower++;
        } else if (isupper(password[i])) {
            upper++;
        } else if (isdigit(password[i])) {
            digit++;
        } else {
            special++;
        }
    }

    strength += upper > 0 ? 1 : 0;
    strength += lower > 0 ? 1 : 0;
    strength += digit > 0 ? 1 : 0;
    strength += special > 0 ? 1 : 0;
    strength += length > MIN_LENGTH ? 1 : 0;

    int weak_points = 0;
    for (int i = 0; i < length - WEAK_POINTS + 1; i++) {
        if (password[i] == password[i + 1] && password[i + 1] == password[i + 2]) {
            weak_points++;
        }
    }

    strength -= weak_points > 0 ? WEAK_POINTS : 0;

    return strength;
}

int main() {
    char password[32];
    int strength;

    printf("Enter your post-apocalyptic password: ");
    scanf("%s", password);

    strength = password_strength(password);

    if (strength > 6) {
        printf("Your password is strong enough for the wasteland!\n");
    } else {
        printf("Your password is weak and vulnerable to raiders! Strengthen it.\n");
    }

    return 0;
}