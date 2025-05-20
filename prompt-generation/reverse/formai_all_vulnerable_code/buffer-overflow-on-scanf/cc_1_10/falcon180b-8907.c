//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: Claude Shannon
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 64

#define HAS_LOWER_CASE 1
#define HAS_UPPER_CASE 2
#define HAS_DIGIT 4
#define HAS_SPECIAL 8

int has_lower_case(char *password) {
    int i = 0;
    while (password[i]) {
        if (islower(password[i])) {
            return 1;
        }
        i++;
    }
    return 0;
}

int has_upper_case(char *password) {
    int i = 0;
    while (password[i]) {
        if (isupper(password[i])) {
            return 1;
        }
        i++;
    }
    return 0;
}

int has_digit(char *password) {
    int i = 0;
    while (password[i]) {
        if (isdigit(password[i])) {
            return 1;
        }
        i++;
    }
    return 0;
}

int has_special(char *password) {
    int i = 0;
    while (password[i]) {
        if (!isalnum(password[i])) {
            return 1;
        }
        i++;
    }
    return 0;
}

int check_strength(char *password) {
    int strength = 0;
    if (has_lower_case(password)) {
        strength |= HAS_LOWER_CASE;
    }
    if (has_upper_case(password)) {
        strength |= HAS_UPPER_CASE;
    }
    if (has_digit(password)) {
        strength |= HAS_DIGIT;
    }
    if (has_special(password)) {
        strength |= HAS_SPECIAL;
    }
    return strength;
}

void print_strength(int strength) {
    if (strength & HAS_LOWER_CASE) {
        printf("Lowercase letters present.\n");
    }
    if (strength & HAS_UPPER_CASE) {
        printf("Uppercase letters present.\n");
    }
    if (strength & HAS_DIGIT) {
        printf("Digits present.\n");
    }
    if (strength & HAS_SPECIAL) {
        printf("Special characters present.\n");
    }
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter password: ");
    scanf("%s", password);

    int strength = check_strength(password);
    printf("Password strength: ");
    print_strength(strength);

    return 0;
}