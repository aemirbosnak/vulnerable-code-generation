//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LEN 256
#define MIN_PASSWORD_LEN 8
#define MAX_PASSWORD_SCORE 100

// Password strength scoring system
int score_password(char *password)
{
    int score = 0;

    // Length of the password
    int len = strlen(password);
    if (len < MIN_PASSWORD_LEN) {
        score -= len * 5;
    } else if (len > MAX_PASSWORD_LEN) {
        score -= (len - MAX_PASSWORD_LEN) * 3;
    } else {
        score += len * 5;
    }

    // Character types
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_number = 0;
    int has_symbol = 0;
    for (int i = 0; i < len; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            has_uppercase = 1;
        } else if (password[i] >= 'a' && password[i] <= 'z') {
            has_lowercase = 1;
        } else if (password[i] >= '0' && password[i] <= '9') {
            has_number = 1;
        } else {
            has_symbol = 1;
        }
    }
    if (has_uppercase) score += 25;
    if (has_lowercase) score += 25;
    if (has_number) score += 25;
    if (has_symbol) score += 25;

    // Common patterns
    char *common_patterns[] = {
        "password",
        "12345678",
        "qwerty",
        "abc123",
        "iloveyou",
        "princess",
    };
    for (int i = 0; i < sizeof(common_patterns) / sizeof(common_patterns[0]); i++) {
        if (strstr(password, common_patterns[i]) != NULL) {
            score -= 50;
            break;
        }
    }

    // Return the score
    return score;
}

int main(void)
{
    // Get the password from the user
    char password[MAX_PASSWORD_LEN + 1];
    printf("Enter your password: ");
    scanf("%s", password);

    // Score the password
    int score = score_password(password);

    // Print the password strength
    if (score < 0) {
        printf("Your password is very weak.\n");
    } else if (score < 50) {
        printf("Your password is weak.\n");
    } else if (score < 75) {
        printf("Your password is strong.\n");
    } else {
        printf("Your password is very strong.\n");
    }

    return 0;
}