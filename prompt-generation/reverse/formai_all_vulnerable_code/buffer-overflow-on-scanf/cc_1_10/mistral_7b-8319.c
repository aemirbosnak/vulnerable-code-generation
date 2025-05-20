//MISTRAL-7B DATASET v1.0 Category: Password Strength Checker ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MIN_LENGTH 8
#define MIN_DIGITS 2
#define MIN_UPPER 2
#define MIN_LOWER 2
#define MIN_SPECIAL 1

const char *symbols = "!@#$%^&*()_+-=[]{}|;:,.<>?";

int check_strength(const char *password) {
    int length = strlen(password);
    int digits = 0, upper = 0, lower = 0, special = 0;

    for (int i = 0; password[i]; i++) {
        if (isdigit(password[i])) digits++;
        else if (isupper(password[i])) upper++;
        else if (islower(password[i])) lower++;
        else if (strchr(symbols, password[i])) special++;
    }

    return length >= MIN_LENGTH
           && digits >= MIN_DIGITS
           && upper >= MIN_UPPER
           && lower >= MIN_LOWER
           && special >= MIN_SPECIAL;
}

int main() {
    char password[256];
    int strength;

    printf("Enter your password: ");
    scanf("%s", password);

    strength = check_strength(password);

    if (!strength) {
        printf("Warning: Your password is weak!\n");
        printf("Please consider using a stronger password.\n");
    }

    printf("\nProgram ended.\n");

    return 0;
}