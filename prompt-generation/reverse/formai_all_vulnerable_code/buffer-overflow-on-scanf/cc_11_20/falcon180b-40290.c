//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: shocked
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int length, i;

    // ask user to input password
    printf("Enter password: ");
    scanf("%s", password);

    // check length of password
    length = strlen(password);

    // check if password contains at least one uppercase letter
    int has_uppercase = 0;
    for (i = 0; i < length; i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
            break;
        }
    }

    // check if password contains at least one lowercase letter
    int has_lowercase = 0;
    for (i = 0; i < length; i++) {
        if (islower(password[i])) {
            has_lowercase = 1;
            break;
        }
    }

    // check if password contains at least one digit
    int has_digit = 0;
    for (i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            has_digit = 1;
            break;
        }
    }

    // check if password contains at least one special character
    int has_special = 0;
    for (i = 0; i < length; i++) {
        if (!isalpha(password[i]) &&!isdigit(password[i])) {
            has_special = 1;
            break;
        }
    }

    // determine password strength based on criteria
    int strength = 0;
    if (length >= 8) {
        strength++;
    }
    if (has_uppercase) {
        strength++;
    }
    if (has_lowercase) {
        strength++;
    }
    if (has_digit) {
        strength++;
    }
    if (has_special) {
        strength++;
    }

    // print password strength
    printf("Password strength: ");
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
    }

    return 0;
}