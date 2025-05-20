//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 100

int main() {
    char password[MAX_PASSWORD_LENGTH + 1];
    int length, i;
    int score = 0;

    printf("Enter password: ");
    scanf("%s", password);
    length = strlen(password);

    // Check for password length
    if (length < 8) {
        printf("Password is too short.\n");
        return 0;
    }

    // Check for uppercase letter
    if (!isupper(password[0])) {
        printf("Password must start with an uppercase letter.\n");
        return 0;
    }

    // Check for lowercase letter
    if (!islower(password[1])) {
        printf("Password must contain at least one lowercase letter.\n");
        return 0;
    }

    // Check for special character
    if (!strspn(password, "!@#$%^&*()_+")) {
        printf("Password must contain at least one special character.\n");
        return 0;
    }

    // Check for number
    if (!isdigit(password[2])) {
        printf("Password must contain at least one number.\n");
        return 0;
    }

    // Calculate password strength score
    if (length >= 8 && length <= 12) {
        score += 1;
    }
    if (length > 12) {
        score += 2;
    }
    if (strspn(password, "!@#$%^&*()_+") > 0) {
        score += 1;
    }
    if (strspn(password, "ABCDEFGHIJKLMNOPQRSTUVWXYZ") > 0) {
        score += 1;
    }
    if (strspn(password, "abcdefghijklmnopqrstuvwxyz") > 0) {
        score += 1;
    }
    if (strspn(password, "0123456789") > 0) {
        score += 1;
    }

    // Print password strength score
    switch (score) {
        case 1:
            printf("Password is weak.\n");
            break;
        case 2:
            printf("Password is fair.\n");
            break;
        case 3:
            printf("Password is good.\n");
            break;
        case 4:
            printf("Password is strong.\n");
            break;
        case 5:
            printf("Password is very strong.\n");
            break;
        default:
            printf("Password strength score is %d.\n", score);
            break;
    }

    return 0;
}