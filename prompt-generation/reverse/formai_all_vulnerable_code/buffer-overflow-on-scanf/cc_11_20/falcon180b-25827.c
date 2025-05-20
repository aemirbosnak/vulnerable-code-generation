//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int strength = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    int length = strlen(password);

    // Check for length
    if (length >= 8) {
        strength++;
    }

    // Check for uppercase letters
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            strength++;
            break;
        }
    }

    // Check for lowercase letters
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            strength++;
            break;
        }
    }

    // Check for digits
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            strength++;
            break;
        }
    }

    // Check for special characters
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            strength++;
            break;
        }
    }

    printf("Your password strength is: ");

    switch (strength) {
        case 0:
            printf("Very Weak\n");
            break;
        case 1:
            printf("Weak\n");
            break;
        case 2:
            printf("Moderate\n");
            break;
        case 3:
            printf("Strong\n");
            break;
        case 4:
            printf("Very Strong\n");
            break;
        default:
            printf("Invalid\n");
            break;
    }

    return 0;
}