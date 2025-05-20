//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: unmistakable
#include <stdio.h>
#include <string.h>

#define LENGTH_MIN 8
#define LENGTH_MAX 20
#define CHARACTER_SET "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}|;:,.<>/?~"

int main() {
    char password[LENGTH_MAX];
    int length = 0;
    int score = 0;
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_number = 0;
    int has_special = 0;

    printf("Enter a password: ");
    scanf("%s", password);

    length = strlen(password);

    if (length < LENGTH_MIN || length > LENGTH_MAX) {
        printf("Password length must be between %d and %d characters.\n", LENGTH_MIN, LENGTH_MAX);
        return 1;
    }

    for (int i = 0; i < length; i++) {
        if (strchr(CHARACTER_SET, password[i]) == NULL) {
            printf("Password must contain only the characters %s.\n", CHARACTER_SET);
            return 1;
        }
    }

    if (strspn(password, "ABCDEFGHIJKLMNOPQRSTUVWXYZ") > 0) {
        has_uppercase = 1;
    }

    if (strspn(password, "abcdefghijklmnopqrstuvwxyz") > 0) {
        has_lowercase = 1;
    }

    if (strspn(password, "0123456789") > 0) {
        has_number = 1;
    }

    if (strspn(password, "!@#$%^&*()_+-=[]{}|;:,.<>/?~") > 0) {
        has_special = 1;
    }

    if (has_uppercase && has_lowercase && has_number && has_special) {
        score = length * 4;
    } else if (has_uppercase && has_lowercase && has_number) {
        score = length * 3;
    } else if (has_uppercase && has_lowercase) {
        score = length * 2;
    } else {
        score = length;
    }

    printf("Password strength score: %d\n", score);

    return 0;
}