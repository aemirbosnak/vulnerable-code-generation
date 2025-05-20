//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: complete
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Function to determine if a character is a digit */
int is_digit(char c) {
    return c >= '0' && c <= '9';
}

/* Function to determine if a character is a lowercase letter */
int is_lower(char c) {
    return c >= 'a' && c <= 'z';
}

/* Function to determine if a character is an uppercase letter */
int is_upper(char c) {
    return c >= 'A' && c <= 'Z';
}

/* Function to determine if a character is a special character */
int is_special(char c) {
    return !is_digit(c) && !is_lower(c) && !is_upper(c);
}

/* Function to calculate password strength */
int password_strength(char* password) {
    int length = strlen(password);
    int score = 0;
    int digit_count = 0;
    int lower_count = 0;
    int upper_count = 0;
    int special_count = 0;

    /* Iterate over each character in the password */
    for (int i = 0; i < length; i++) {
        char c = password[i];

        /* Increase the score if the character is a digit, lowercase letter,
           uppercase letter, or special character */
        if (is_digit(c)) {
            score += 2;
            digit_count++;
        } else if (is_lower(c)) {
            score += 2;
            lower_count++;
        } else if (is_upper(c)) {
            score += 2;
            upper_count++;
        } else if (is_special(c)) {
            score += 5;
            special_count++;
        }
    }

    /* Apply bonus points for mixed character types */
    if (digit_count > 0 && lower_count > 0 && upper_count > 0 && special_count > 0) {
        score += 15;
    } else if ((digit_count > 0 && lower_count > 0 && upper_count > 0) ||
               (digit_count > 0 && lower_count > 0 && special_count > 0) ||
               (digit_count > 0 && upper_count > 0 && special_count > 0) ||
               (lower_count > 0 && upper_count > 0 && special_count > 0)) {
        score += 10;
    } else if ((digit_count > 0 && lower_count > 0) ||
               (digit_count > 0 && upper_count > 0) ||
               (digit_count > 0 && special_count > 0) ||
               (lower_count > 0 && upper_count > 0) ||
               (lower_count > 0 && special_count > 0) ||
               (upper_count > 0 && special_count > 0)) {
        score += 5;
    }

    /* Apply penalty points for consecutive characters */
    int consecutive_count = 0;
    for (int i = 0; i < length - 1; i++) {
        char c = password[i];
        char next_c = password[i + 1];

        if (c == next_c) {
            consecutive_count++;
        } else {
            if (consecutive_count > 0) {
                score -= 3 * consecutive_count;
                consecutive_count = 0;
            }
        }
    }
    if (consecutive_count > 0) {
        score -= 3 * consecutive_count;
    }

    return score;
}

int main() {
    char password[100];

    /* Read the password from the user */
    printf("Enter your password: ");
    scanf("%s", password);

    /* Calculate the strength of the password */
    int strength = password_strength(password);

    /* Print the strength of the password */
    printf("\nPassword strength: %d\n", strength);

    return 0;
}