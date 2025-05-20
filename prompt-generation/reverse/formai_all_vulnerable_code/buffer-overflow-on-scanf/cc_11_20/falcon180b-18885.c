//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 100

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int length, i;
    printf("Enter password: ");
    scanf("%s", password);
    length = strlen(password);

    // Check length
    if (length < 8) {
        printf("Password is too short.\n");
        return 1;
    }

    // Check for special characters
    int special_count = 0;
    for (i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            special_count++;
        }
    }
    if (special_count == 0) {
        printf("Password must contain at least one special character.\n");
        return 1;
    }

    // Check for uppercase letters
    int uppercase_count = 0;
    for (i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercase_count++;
        }
    }
    if (uppercase_count == 0) {
        printf("Password must contain at least one uppercase letter.\n");
        return 1;
    }

    // Check for lowercase letters
    int lowercase_count = 0;
    for (i = 0; i < length; i++) {
        if (islower(password[i])) {
            lowercase_count++;
        }
    }
    if (lowercase_count == 0) {
        printf("Password must contain at least one lowercase letter.\n");
        return 1;
    }

    // Check for numbers
    int number_count = 0;
    for (i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            number_count++;
        }
    }
    if (number_count == 0) {
        printf("Password must contain at least one number.\n");
        return 1;
    }

    printf("Password is strong.\n");
    return 0;
}