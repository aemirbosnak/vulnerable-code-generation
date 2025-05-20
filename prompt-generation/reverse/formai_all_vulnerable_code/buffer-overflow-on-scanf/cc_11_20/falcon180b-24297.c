//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

int main() {
    char password[100];
    int length;
    printf("Enter your password: ");
    scanf("%s", password);
    length = strlen(password);

    bool has_uppercase = false;
    bool has_lowercase = false;
    bool has_number = false;
    bool has_special_char = false;

    // Check for uppercase letters
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            has_uppercase = true;
            break;
        }
    }

    // Check for lowercase letters
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            has_lowercase = true;
            break;
        }
    }

    // Check for numbers
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            has_number = true;
            break;
        }
    }

    // Check for special characters
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            has_special_char = true;
            break;
        }
    }

    int score = 0;
    // Calculate the password strength score
    if (length >= 8) {
        score += 1;
    }
    if (has_uppercase) {
        score += 1;
    }
    if (has_lowercase) {
        score += 1;
    }
    if (has_number) {
        score += 1;
    }
    if (has_special_char) {
        score += 1;
    }

    if (score <= 2) {
        printf("Weak password\n");
    } else if (score <= 4) {
        printf("Moderate password\n");
    } else {
        printf("Strong password\n");
    }

    return 0;
}