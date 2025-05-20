//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: Cryptic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 100
#define MIN_PASSWORD_LENGTH 8
#define MIN_LOWER_CASES 1
#define MIN_UPPER_CASES 1
#define MIN_DIGITS 1
#define MIN_SPECIAL_CHARS 1

int check_password_strength(char *password) {
    int length = strlen(password);
    int lower_cases = 0;
    int upper_cases = 0;
    int digits = 0;
    int special_chars = 0;

    if (length < MIN_PASSWORD_LENGTH) {
        printf("Password is too short.\n");
        return 0;
    }

    for (int i = 0; i < length; i++) {
        if (isalpha(password[i])) {
            if (islower(password[i])) {
                lower_cases++;
            } else if (isupper(password[i])) {
                upper_cases++;
            }
        } else if (isdigit(password[i])) {
            digits++;
        } else {
            special_chars++;
        }
    }

    if (lower_cases < MIN_LOWER_CASES || upper_cases < MIN_UPPER_CASES || digits < MIN_DIGITS || special_chars < MIN_SPECIAL_CHARS) {
        printf("Password does not meet the minimum requirements.\n");
        return 0;
    }

    printf("Password is strong.\n");
    return 1;
}

int main() {
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter your password: ");
    scanf("%s", password);

    check_password_strength(password);

    return 0;
}