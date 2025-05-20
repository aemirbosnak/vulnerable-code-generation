//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int length, i, upper_count = 0, lower_count = 0, digit_count = 0, special_count = 0;
    printf("Enter password: ");
    scanf("%s", password);
    length = strlen(password);

    // Check for uppercase letter
    for (i = 0; i < length; i++) {
        if (isupper(password[i])) {
            upper_count++;
        }
    }

    // Check for lowercase letter
    for (i = 0; i < length; i++) {
        if (islower(password[i])) {
            lower_count++;
        }
    }

    // Check for digit
    for (i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            digit_count++;
        }
    }

    // Check for special character
    for (i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            special_count++;
        }
    }

    if (length >= 8) {
        if (upper_count && lower_count && digit_count && special_count) {
            printf("Strong password\n");
        } else {
            printf("Weak password\n");
        }
    } else {
        printf("Password must be at least 8 characters long\n");
    }

    return 0;
}