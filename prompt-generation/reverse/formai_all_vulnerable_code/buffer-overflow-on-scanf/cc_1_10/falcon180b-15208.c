//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: secure
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_uppercase(char *password) {
    int count = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            count++;
        }
    }
    return count;
}

int count_lowercase(char *password) {
    int count = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (islower(password[i])) {
            count++;
        }
    }
    return count;
}

int count_digits(char *password) {
    int count = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (isdigit(password[i])) {
            count++;
        }
    }
    return count;
}

int count_special_chars(char *password) {
    int count = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (!isalnum(password[i])) {
            count++;
        }
    }
    return count;
}

int check_password_strength(char *password) {
    int length = strlen(password);
    int uppercase_count = count_uppercase(password);
    int lowercase_count = count_lowercase(password);
    int digit_count = count_digits(password);
    int special_char_count = count_special_chars(password);

    int score = 0;
    if (length >= 8) {
        score += 1;
    }
    if (uppercase_count > 0) {
        score += 1;
    }
    if (lowercase_count > 0) {
        score += 1;
    }
    if (digit_count > 0) {
        score += 1;
    }
    if (special_char_count > 0) {
        score += 1;
    }

    if (score >= 4) {
        printf("Password is strong.\n");
    } else {
        printf("Password is weak.\n");
    }

    return score;
}

int main() {
    char password[100];
    printf("Enter password: ");
    scanf("%s", password);

    int strength = check_password_strength(password);

    return 0;
}