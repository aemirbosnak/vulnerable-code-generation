//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: light-weight
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    char password[101];
    int strength = 0;
    int length = 0;
    int upper = 0;
    int lower = 0;
    int digit = 0;
    int special = 0;

    printf("Enter password: ");
    scanf("%s", password);

    length = strlen(password);

    for (int i = 0; i < length; i++) {
        char c = password[i];
        if (isupper(c)) {
            upper++;
        } else if (islower(c)) {
            lower++;
        } else if (isdigit(c)) {
            digit++;
        } else {
            special++;
        }
    }

    if (length >= 8) {
        strength++;
    }
    if (upper >= 1) {
        strength++;
    }
    if (lower >= 1) {
        strength++;
    }
    if (digit >= 1) {
        strength++;
    }
    if (special >= 1) {
        strength++;
    }

    switch (strength) {
        case 0:
            printf("Very weak password.\n");
            break;
        case 1:
            printf("Weak password.\n");
            break;
        case 2:
            printf("Medium password.\n");
            break;
        case 3:
            printf("Strong password.\n");
            break;
        case 4:
            printf("Very strong password.\n");
            break;
        case 5:
            printf("Excellent password.\n");
            break;
        default:
            printf("Invalid password.\n");
    }

    return 0;
}