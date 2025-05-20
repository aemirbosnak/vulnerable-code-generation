//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 100
#define MIN_PASSWORD_LENGTH 8

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int length;

    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);

    if (length < MIN_PASSWORD_LENGTH) {
        printf("Password is too short. Must be at least %d characters.\n", MIN_PASSWORD_LENGTH);
        return 1;
    }

    int has_uppercase = 0, has_lowercase = 0, has_number = 0, has_special_char = 0;

    for (int i = 0; i < length; i++) {
        if (isalpha(password[i])) {
            if (isupper(password[i])) {
                has_uppercase = 1;
            } else {
                has_lowercase = 1;
            }
        } else if (isdigit(password[i])) {
            has_number = 1;
        } else if (!isalnum(password[i])) {
            has_special_char = 1;
        }
    }

    int score = 0;

    if (has_uppercase) {
        score += 1;
    }

    if (has_lowercase) {
        score += 1;
    }

    if (has_number) {
        score += 1;
    }

    if (has_special_char) {
        score += 1;
    }

    if (score == 0) {
        printf("Password is too weak. Must contain at least one uppercase letter, one lowercase letter, one number, and one special character.\n");
        return 1;
    } else if (score == 1) {
        printf("Password is weak. Consider adding more complexity.\n");
    } else if (score == 2) {
        printf("Password is moderate. Consider adding more complexity.\n");
    } else {
        printf("Password is strong.\n");
    }

    return 0;
}