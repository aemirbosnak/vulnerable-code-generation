//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {

    char password[25];
    int length, small_alpha, capital_alpha, numerical, special_char = 0;
    int strength_score = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);

    //checking for lowercase alphabets
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            small_alpha = 1;
            break;
        }
    }

    //checking for uppercase alphabets
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            capital_alpha = 1;
            break;
        }
    }

    //checking for numerical digits
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            numerical = 1;
            break;
        }
    }

    //checking for special characters
    for (int i = 0; i < length; i++) {
        if (!(isalnum(password[i]))) {
            special_char = 1;
            break;
        }
    }

    //calculating strength score
    strength_score = small_alpha + capital_alpha + numerical + special_char;

    if (length < 8 || strength_score < 3) {
        printf("Password is weak\n");
    } else if (length >= 8 && length <= 12 && strength_score >= 3 && strength_score <= 4) {
        printf("Password is moderately strong\n");
    } else if (length >= 13 && strength_score >= 4) {
        printf("Password is very strong\n");
    }

    return 0;
}