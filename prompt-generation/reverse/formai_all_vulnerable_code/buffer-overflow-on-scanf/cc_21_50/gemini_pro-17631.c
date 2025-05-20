//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char password[100];
    int strength = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    int len = strlen(password);

    if (len < 8) {
        printf("Password is too short!\n");
        return 0;
    }

    int hasUpper = 0;
    int hasLower = 0;
    int hasNumber = 0;
    int hasSpecial = 0;

    for (int i = 0; i < len; i++) {
        char c = password[i];

        if (c >= 'A' && c <= 'Z') {
            hasUpper = 1;
        } else if (c >= 'a' && c <= 'z') {
            hasLower = 1;
        } else if (c >= '0' && c <= '9') {
            hasNumber = 1;
        } else {
            hasSpecial = 1;
        }
    }

    if (hasUpper && hasLower && hasNumber) {
        strength += 3;
    } else if (hasUpper && hasLower) {
        strength += 2;
    } else if (hasUpper || hasLower) {
        strength++;
    }

    if (hasSpecial) {
        strength++;
    }

    if (len >= 12) {
        strength++;
    }

    printf("Password strength: %d\n", strength);

    if (strength < 3) {
        printf("Password is weak!\n");
    } else if (strength < 4) {
        printf("Password is fair!\n");
    } else if (strength < 5) {
        printf("Password is good!\n");
    } else {
        printf("Password is strong!\n");
    }

    return 0;
}