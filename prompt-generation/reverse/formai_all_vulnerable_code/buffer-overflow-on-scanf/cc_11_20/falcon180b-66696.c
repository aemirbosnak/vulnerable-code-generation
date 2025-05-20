//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: decentralized
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define LENGTH 8

int main() {
    char password[LENGTH];
    int score = 0;
    printf("Enter your password: ");
    scanf("%s", password);
    int length = strlen(password);
    if (length < LENGTH) {
        printf("Password must be at least %d characters long.\n", LENGTH);
        return 0;
    }
    if (strspn(password, "ABCDEFGHIJKLMNOPQRSTUVWXYZ") == 0) {
        printf("Password must contain at least one uppercase letter.\n");
        return 0;
    }
    if (strspn(password, "abcdefghijklmnopqrstuvwxyz") == 0) {
        printf("Password must contain at least one lowercase letter.\n");
        return 0;
    }
    if (strspn(password, "0123456789") == 0) {
        printf("Password must contain at least one digit.\n");
        return 0;
    }
    if (strspn(password, "!@#$%^&*()_+-=[]{}|;:,.<>?") == 0) {
        printf("Password must contain at least one special character.\n");
        return 0;
    }
    if (strspn(password, "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}|;:,.<>?") == length) {
        score += 1;
    }
    if (strspn(password, "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz") == length) {
        score += 1;
    }
    if (strspn(password, "0123456789") == length) {
        score += 1;
    }
    if (strspn(password, "!@#$%^&*()_+-=[]{}|;:,.<>? ") == length) {
        score += 1;
    }
    if (score == 0) {
        printf("Password is very weak.\n");
    } else if (score == 1) {
        printf("Password is weak.\n");
    } else if (score == 2) {
        printf("Password is good.\n");
    } else {
        printf("Password is strong.\n");
    }
    return 0;
}