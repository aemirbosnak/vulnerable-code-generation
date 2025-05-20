//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: shape shifting
#include <stdio.h>
#include <string.h>

// Password strength checker function
int passwordStrengthCheck(char* password) {
    int len = strlen(password);

    // Initial strength
    int strength = 0;

    // Check length of password and increase strength accordingly
    if (len >= 8 && len <= 12) {
        strength += 10;
    }
    else if (len > 12) {
        strength += 25;
    }

    // Check for upper and lower case letters
    int uppercase = 0, lowercase = 0;
    for (int i = 0; i < len; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            uppercase = 1;
        }
        else if (password[i] >= 'a' && password[i] <= 'z') {
            lowercase = 1;
        }
    }

    if (uppercase && lowercase) {
        strength += 20;
    }

    // Check for numbers
    int digits = 0;
    for (int i = 0; i < len; i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            digits = 1;
        }
    }

    if (digits) {
        strength += 20;
    }

    // Check for special characters
    int specialChar = 0;
    for (int i = 0; i < len; i++) {
        if ((password[i] >= '!' && password[i] <= '/') ||
            (password[i] >= ':' && password[i] <= '@') ||
            (password[i] >= '[' && password[i] <= '`') ||
            (password[i] >= '{' && password[i] <= '~')) {
            specialChar = 1;
        }
    }

    if (specialChar) {
        strength += 25;
    }

    return strength;
}

int main() {
    char password[50];
    printf("Enter password: ");
    scanf("%s", password);

    int strength = passwordStrengthCheck(password);

    printf("\nPassword strength: %d%%\n", strength);
    return 0;
}