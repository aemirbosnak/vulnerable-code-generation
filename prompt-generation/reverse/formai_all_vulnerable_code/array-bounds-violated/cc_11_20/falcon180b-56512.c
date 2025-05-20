//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: invasive
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    char password[MAX_LENGTH];
    int length;

    // Get password from user
    printf("Enter password: ");
    if (fgets(password, MAX_LENGTH, stdin) == NULL) {
        printf("Error: Password too long.\n");
        return 1;
    }
    length = strlen(password);

    // Remove newline character
    if (password[length - 1] == '\n') {
        password[length - 1] = '\0';
        length--;
    }

    // Check password strength
    int uppercase = 0, lowercase = 0, numbers = 0, symbols = 0;
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercase = 1;
        } else if (islower(password[i])) {
            lowercase = 1;
        } else if (isdigit(password[i])) {
            numbers = 1;
        } else if (ispunct(password[i])) {
            symbols = 1;
        }
    }

    int strength = 0;
    if (length >= 8) {
        strength++;
    }
    if (uppercase) {
        strength++;
    }
    if (lowercase) {
        strength++;
    }
    if (numbers) {
        strength++;
    }
    if (symbols) {
        strength++;
    }

    if (strength == 0) {
        printf("Weak\n");
    } else if (strength == 1) {
        printf("Fair\n");
    } else if (strength == 2) {
        printf("Good\n");
    } else if (strength == 3) {
        printf("Strong\n");
    } else {
        printf("Very strong\n");
    }

    return 0;
}