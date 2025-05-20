//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_PASSWORD_LENGTH 64 // maximum length of password

int main() {
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter your password: ");
    scanf("%s", password);

    int length = strlen(password);
    int uppercase_count = 0;
    int lowercase_count = 0;
    int digit_count = 0;
    int special_count = 0;

    // check password length
    if (length < 8) {
        printf("Password is too short.\n");
        return 0;
    }

    // check uppercase letters
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercase_count++;
        }
    }

    // check lowercase letters
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            lowercase_count++;
        }
    }

    // check digits
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            digit_count++;
        }
    }

    // check special characters
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            special_count++;
        }
    }

    // calculate password strength
    int strength = 0;
    if (length > 12) {
        strength++;
    }
    if (uppercase_count > 0) {
        strength++;
    }
    if (lowercase_count > 0) {
        strength++;
    }
    if (digit_count > 0) {
        strength++;
    }
    if (special_count > 0) {
        strength++;
    }

    // print password strength
    printf("Password strength: %d\n", strength);

    return 0;
}