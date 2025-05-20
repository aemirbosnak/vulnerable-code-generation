//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: safe
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int length, has_uppercase = 0, has_lowercase = 0, has_number = 0, has_special_char = 0, score = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);

    // Check for uppercase
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
            break;
        }
    }

    // Check for lowercase
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            has_lowercase = 1;
            break;
        }
    }

    // Check for numbers
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            has_number = 1;
            break;
        }
    }

    // Check for special characters
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            has_special_char = 1;
            break;
        }
    }

    // Calculate password strength score
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

    // Print password strength score
    printf("Your password strength score is: %d\n", score);

    return 0;
}