//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: detailed
#include <stdio.h>
#include <string.h>

int main() {
    char password[101];
    int strength = 0;

    printf("Enter a password: ");
    scanf("%s", password);

    int len = strlen(password);
    if (len < 8) {
        strength += 1;
    } else if (len < 12) {
        strength += 2;
    } else if (len < 16) {
        strength += 3;
    } else {
        strength += 4;
    }

    int has_upper = 0;
    int has_lower = 0;
    int has_digit = 0;
    int has_special = 0;
    for (int i = 0; i < len; i++) {
        char c = password[i];
        if (c >= 'A' && c <= 'Z') {
            has_upper = 1;
        } else if (c >= 'a' && c <= 'z') {
            has_lower = 1;
        } else if (c >= '0' && c <= '9') {
            has_digit = 1;
        } else {
            has_special = 1;
        }
    }

    if (has_upper) {
        strength += 1;
    }
    if (has_lower) {
        strength += 1;
    }
    if (has_digit) {
        strength += 1;
    }
    if (has_special) {
        strength += 1;
    }

    printf("Strength: %d\n", strength);

    return 0;
}