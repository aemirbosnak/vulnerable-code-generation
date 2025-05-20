//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: complete
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

int main() {
    char pwd[100];
    int len, score = 0, flag_lower = 0, flag_upper = 0, flag_digit = 0, flag_special = 0;

    printf("Enter the password: ");
    scanf("%s", pwd);

    len = strlen(pwd);

    // Check minimum length
    if (len < 8) {
        printf("Password is too short\n");
        return 0;
    }

    // Calculate score for each character
    for (int i = 0; i < len; i++) {
        char c = pwd[i];

        if (islower(c) && flag_lower == 0) {
            score += 2;
            flag_lower = 1;
        }
        else if (isupper(c) && flag_upper == 0) {
            score += 2;
            flag_upper = 1;
        }
        else if (isdigit(c) && flag_digit == 0) {
            score += 2;
            flag_digit = 1;
        }
        else if (!isalnum(c) && flag_special == 0) {
            score += 2;
            flag_special = 1;
        }
        else {
            score += 1;
        }
    }

    // Check password strength based on score
    if (score < 4) {
        printf("Weak password\n");
    }
    else if (score < 8) {
        printf("Medium strength password\n");
    }
    else {
        printf("Strong password\n");
    }

    return 0;
}