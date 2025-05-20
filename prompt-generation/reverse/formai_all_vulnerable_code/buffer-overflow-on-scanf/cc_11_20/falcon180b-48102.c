//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: ephemeral
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef enum {
    LOW,
    MEDIUM,
    HIGH,
    VERY_HIGH
} Strength;

Strength check_password_strength(char *password) {
    int length = strlen(password);
    bool has_uppercase = false;
    bool has_lowercase = false;
    bool has_number = false;
    bool has_special_char = false;

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            has_uppercase = true;
        } else if (islower(password[i])) {
            has_lowercase = true;
        } else if (isdigit(password[i])) {
            has_number = true;
        } else if (ispunct(password[i])) {
            has_special_char = true;
        }
    }

    if (length < 8 ||!has_uppercase ||!has_lowercase ||!has_number ||!has_special_char) {
        return LOW;
    } else if (length >= 8 && length < 12 && has_uppercase && has_lowercase && has_number && has_special_char) {
        return MEDIUM;
    } else if (length >= 12 && has_uppercase && has_lowercase && has_number && has_special_char) {
        return HIGH;
    } else {
        return VERY_HIGH;
    }
}

void main() {
    char password[50];
    printf("Enter password: ");
    scanf("%s", password);

    Strength strength = check_password_strength(password);

    switch (strength) {
        case LOW:
            printf("Password strength: Low\n");
            break;
        case MEDIUM:
            printf("Password strength: Medium\n");
            break;
        case HIGH:
            printf("Password strength: High\n");
            break;
        case VERY_HIGH:
            printf("Password strength: Very High\n");
            break;
    }
}