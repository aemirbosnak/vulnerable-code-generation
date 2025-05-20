//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: mathematical
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int length = 0;
    int upper_case = 0;
    int lower_case = 0;
    int digit = 0;
    int special_char = 0;

    // Get password from user
    printf("Enter your password: ");
    scanf("%s", password);

    // Calculate length of password
    length = strlen(password);

    // Check for upper and lower case letters
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            upper_case = 1;
        } else if (islower(password[i])) {
            lower_case = 1;
        }
    }

    // Check for digits
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            digit = 1;
        }
    }

    // Check for special characters
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            special_char = 1;
        }
    }

    // Check if password meets requirements
    if (length >= 8 && upper_case && lower_case && digit && special_char) {
        printf("Password is strong.\n");
    } else {
        printf("Password is weak.\n");
    }

    return 0;
}