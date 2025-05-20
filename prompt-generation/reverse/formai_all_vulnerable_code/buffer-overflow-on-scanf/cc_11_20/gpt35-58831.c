//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: single-threaded
#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
 Function to calculate the password strength using a scoring mechanism.
 Scores are assigned based on different conditions such as length, uppercase and lowercase 
 letters, digits, special characters, etc.
*/

int password_strength(const char *password) {
    int score = 0;
    int len = strlen(password);

    // Assign scores based on password length
    if (len < 8) {
        score -= 10;
    } else if (len >= 8 && len <= 10) {
        score += 5;
    } else {
        score += 10;
    }

    // Assign scores based on uppercase letters
    int uppercase_count = 0;
    for (int i = 0; i < len; i++) {
        if (isupper(password[i])) {
            uppercase_count++;
        }
    }
    if (uppercase_count == 0) {
        score -= 10;
    } else if (uppercase_count == 1) {
        score += 5;
    } else {
        score += 10;
    }

    // Assign scores based on lowercase letters
    int lowercase_count = 0;
    for (int i = 0; i < len; i++) {
        if (islower(password[i])) {
            lowercase_count++;
        }
    }
    if (lowercase_count == 0) {
        score -= 10;
    } else if (lowercase_count == 1) {
        score += 5;
    } else {
        score += 10;
    }

    // Assign scores based on digits
    int digit_count = 0;
    for (int i = 0; i < len; i++) {
        if (isdigit(password[i])) {
            digit_count++;
        }
    }
    if (digit_count == 0) {
        score -= 10;
    } else if (digit_count == 1) {
        score += 5;
    } else {
        score += 10;
    }

    // Assign scores based on special characters
    int special_char_count = 0;
    for (int i = 0; i < len; i++) {
        if (!isalnum(password[i])) {
            special_char_count++;
        }
    }
    if (special_char_count == 0) {
        score -= 10;
    } else if (special_char_count == 1) {
        score += 5;
    } else {
        score += 10;
    }

    return score;
}

int main() {
    char password[100];
    printf("Enter a password: ");
    scanf("%s", password);

    int score = password_strength(password);
    printf("Your password score is: %d\n", score);

    if (score < 0) {
        printf("Your password is weak! Please try again.\n");
    } else if (score < 30) {
        printf("Your password is somewhat weak. Please consider a stronger password.\n");
    } else if (score < 60) {
        printf("Your password is moderately strong. Good job!\n");
    } else if (score < 80) {
        printf("Your password is very strong! Impressive.\n");
    } else {
        printf("Your password is extremely strong! Well done.\n");
    }

    return 0;
}