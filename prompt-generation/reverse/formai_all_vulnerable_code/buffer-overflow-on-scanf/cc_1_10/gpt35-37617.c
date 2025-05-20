//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: futuristic
#include <stdio.h>
#include <string.h>
#define MIN_LENGTH 8
#define SPECIAL_CHARS "!@#$%&*"

int is_upper(char c) {
    return (c >= 'A' && c <= 'Z');
}

int is_lower(char c) {
    return (c >= 'a' && c <= 'z');
}

int is_digit(char c) {
    return (c >= '0' && c <= '9');
}

int is_special_char(char c) {
    char special_chars[] = SPECIAL_CHARS;
    for (int i = 0; i < strlen(special_chars); i++) {
        if (special_chars[i] == c) {
            return 1;
        }
    }
    return 0;
}

int calculate_strength(char * password) {
    int length = strlen(password);
    int strength = length;
    int upper_count = 0;
    int lower_count = 0;
    int digit_count = 0;
    int special_count = 0;

    for (int i = 0; i < length; i++) {
        char c = password[i];
        if (is_upper(c)) {
            upper_count++;
        } else if (is_lower(c)) {
            lower_count++;
        } else if (is_digit(c)) {
            digit_count++;
        } else if (is_special_char(c)){
            special_count++;
        }
    }

    if (upper_count == 0) {
        strength -= 2;
    }
    if (lower_count == 0) {
        strength -= 2;
    }
    if (digit_count == 0) {
        strength -= 2;
    }
    if (special_count == 0) {
        strength -= 2;
    }

    if (length >= MIN_LENGTH && strength >= MIN_LENGTH) {
        strength += 5;
    }

    return strength;
}

int main() {
    char password[50];
    printf("Enter your password: ");
    scanf("%s", password);
    printf("Your password strength is %d\n", calculate_strength(password));
    return 0;
}