//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: immersive
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char password[100];
    int len, i, j, count = 0, lower = 0, upper = 0, num = 0, special = 0;
    float strength = 0.0;
    char ch;
    printf("Enter password: ");
    scanf("%s", password);
    len = strlen(password);

    // Check for lowercase characters
    for (i = 0; i < len; i++) {
        if (islower(password[i])) {
            lower++;
        }
    }

    // Check for uppercase characters
    for (i = 0; i < len; i++) {
        if (isupper(password[i])) {
            upper++;
        }
    }

    // Check for numeric characters
    for (i = 0; i < len; i++) {
        if (isdigit(password[i])) {
            num++;
        }
    }

    // Check for special characters
    for (i = 0; i < len; i++) {
        if (!isalnum(password[i])) {
            special++;
        }
    }

    // Check for password length
    if (len < 8) {
        printf("Password is too short.\n");
        exit(0);
    } else if (len > 20) {
        printf("Password is too long.\n");
        exit(0);
    }

    // Calculate password strength
    if (lower && upper && num && special) {
        strength = 1.0;
        printf("Password strength: Very Strong\n");
    } else if (lower && upper && num) {
        strength = 0.8;
        printf("Password strength: Strong\n");
    } else if (lower && upper) {
        strength = 0.6;
        printf("Password strength: Medium\n");
    } else if (lower && num || upper && num) {
        strength = 0.5;
        printf("Password strength: Weak\n");
    } else {
        strength = 0.0;
        printf("Password strength: Very Weak\n");
    }

    return 0;
}