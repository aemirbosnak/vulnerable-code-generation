//MISTRAL-7B DATASET v1.0 Category: Password Strength Checker ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MIN_LENGTH 8
#define WEAK_POINTS 3

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <password>\n", argv[0]);
        return 1;
    }

    const char *password = argv[1];
    size_t len = strlen(password);

    int num_lower = 0, num_upper = 0, num_digits = 0, num_specials = 0;

    for (size_t i = 0; password[i] != '\0'; i++) {
        if (islower(password[i])) {
            num_lower++;
            continue;
        }

        if (isupper(password[i])) {
            num_upper++;
            continue;
        }

        if (isdigit(password[i])) {
            num_digits++;
            continue;
        }

        if (!strchr("!@#$%^&*()-_+=[]{}|;:,.<>/?`~", password[i]))
            continue;

        num_specials++;
    }

    int strength = 0;

    if (len < MIN_LENGTH) {
        printf("Password is too short.\n");
        return 1;
    }

    if (num_lower > 0 && num_upper > 0 && num_digits > 0)
        strength++;

    if (num_specials > WEAK_POINTS)
        strength++;

    switch (strength) {
        case 0:
            printf("Password is very weak.\n");
            break;
        case 1:
            printf("Password is weak.\n");
            break;
        case 2:
            printf("Password is moderate.\n");
            break;
        case 3:
            printf("Password is strong.\n");
            break;
        case 4:
            printf("Password is very strong.\n");
            break;
        default:
            printf("Password strength: %d\n", strength);
            break;
    }

    return 0;
}