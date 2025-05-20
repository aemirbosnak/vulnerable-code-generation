//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 128

#define STRENGTH_WEAK  1
#define STRENGTH_MEDIUM 2
#define STRENGTH_STRONG 3

int check_length(const char *password) {
    return strlen(password) >= MIN_LENGTH && strlen(password) <= MAX_LENGTH;
}

int check_variety(const char *password) {
    int variety = 0;
    int i;
    for (i = 0; i < strlen(password); i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            variety |= 1;
        } else if (password[i] >= 'A' && password[i] <= 'Z') {
            variety |= 2;
        } else if (password[i] >= '0' && password[i] <= '9') {
            variety |= 4;
        } else {
            variety |= 8;
        }
    }
    return variety;
}

int check_strength(const char *password) {
    int strength = 0;
    strength += check_length(password);
    strength += check_variety(password);
    if (strength < 3) {
        return STRENGTH_WEAK;
    } else if (strength < 5) {
        return STRENGTH_MEDIUM;
    } else {
        return STRENGTH_STRONG;
    }
}

int main(void) {
    char password[MAX_LENGTH + 1];
    int strength;
    printf("Enter a password: ");
    scanf("%s", password);
    strength = check_strength(password);
    switch (strength) {
        case STRENGTH_WEAK:
            printf("Your password is weak.\n");
            break;
        case STRENGTH_MEDIUM:
            printf("Your password is medium.\n");
            break;
        case STRENGTH_STRONG:
            printf("Your password is strong.\n");
            break;
    }
    return 0;
}