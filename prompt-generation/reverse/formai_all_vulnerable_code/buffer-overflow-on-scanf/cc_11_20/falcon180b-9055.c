//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: immersive
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int check_strength(char* password);

int main() {
    char password[100];
    printf("Enter your password: ");
    scanf("%s", password);
    int strength = check_strength(password);
    printf("Password strength: %d\n", strength);
    return 0;
}

int check_strength(char* password) {
    int length = strlen(password);
    int uppercase = 0;
    int lowercase = 0;
    int number = 0;
    int special = 0;
    int strength = 0;

    // Check for uppercase letters
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercase = 1;
        }
    }

    // Check for lowercase letters
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            lowercase = 1;
        }
    }

    // Check for numbers
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            number = 1;
        }
    }

    // Check for special characters
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            special = 1;
        }
    }

    // Calculate password strength
    if (length < 8) {
        strength = 1;
    } else if (length >= 8 && length < 12) {
        strength = 2;
    } else if (length >= 12) {
        strength = 3;
    }

    if (uppercase && lowercase && number && special) {
        strength++;
    } else if (uppercase && lowercase && (number || special)) {
        strength++;
    } else if ((uppercase || lowercase) && number && special) {
        strength++;
    } else if (uppercase || lowercase || number || special) {
        strength++;
    }

    return strength;
}