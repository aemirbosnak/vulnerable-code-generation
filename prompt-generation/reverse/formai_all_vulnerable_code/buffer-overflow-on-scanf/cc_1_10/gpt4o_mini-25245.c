//GPT-4o-mini DATASET v1.0 Category: Password Strength Checker ; Style: curious
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MIN_LENGTH 8
#define MIN_UPPER 1
#define MIN_LOWER 1
#define MIN_DIGITS 1
#define MIN_SPECIAL 1

int check_length(const char *password) {
    return strlen(password) >= MIN_LENGTH;
}

int check_uppercase(const char *password) {
    int count = 0;
    for (int i = 0; password[i]; i++) {
        if (isupper(password[i])) {
            count++;
        }
    }
    return count >= MIN_UPPER;
}

int check_lowercase(const char *password) {
    int count = 0;
    for (int i = 0; password[i]; i++) {
        if (islower(password[i])) {
            count++;
        }
    }
    return count >= MIN_LOWER;
}

int check_digits(const char *password) {
    int count = 0;
    for (int i = 0; password[i]; i++) {
        if (isdigit(password[i])) {
            count++;
        }
    }
    return count >= MIN_DIGITS;
}

int check_special_characters(const char *password) {
    int count = 0;
    const char *special_chars = "!@#$%^&*()-_+=<>?/|~`";
    for (int i = 0; password[i]; i++) {
        if (strchr(special_chars, password[i])) {
            count++;
        }
    }
    return count >= MIN_SPECIAL;
}

int check_password_strength(const char *password) {
    int strength = 0;

    if (check_length(password)) {
        strength++;
    }
    if (check_uppercase(password)) {
        strength++;
    }
    if (check_lowercase(password)) {
        strength++;
    }
    if (check_digits(password)) {
        strength++;
    }
    if (check_special_characters(password)) {
        strength++;
    }

    return strength;
}

void display_strength(int strength) {
    switch (strength) {
        case 0:
        case 1:
            printf("Password strength: Weak\n");
            break;
        case 2:
            printf("Password strength: Moderate\n");
            break;
        case 3:
            printf("Password strength: Strong\n");
            break;
        case 4:
        case 5:
            printf("Password strength: Very Strong\n");
            break;
        default:
            printf("Unidentified strength: Consult a wizard!\n");
    }
}

int main() {
    char password[256];

    printf("Welcome to the Mysterious Password Strength Checker!\n");
    printf("Please enter a password to check its strength:\n");

    scanf("%s", password);

    int strength = check_password_strength(password);

    printf("Your password: \"%s\"\n", password);
    display_strength(strength);

    if (strength < 3) {
        printf("Tips for a stronger password:\n");
        if (!check_length(password)) {
            printf("- At least %d characters long.\n", MIN_LENGTH);
        }
        if (!check_uppercase(password)) {
            printf("- At least %d uppercase letters.\n", MIN_UPPER);
        }
        if (!check_lowercase(password)) {
            printf("- At least %d lowercase letters.\n", MIN_LOWER);
        }
        if (!check_digits(password)) {
            printf("- At least %d digits.\n", MIN_DIGITS);
        }
        if (!check_special_characters(password)) {
            printf("- At least %d special characters (%s).\n", MIN_SPECIAL, "!@#$%^&*()-_+=<>?/|~`");
        }
    }

    printf("Thank you for testing the strength of your password! Until next time!\n");

    return 0;
}