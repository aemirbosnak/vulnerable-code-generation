//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    char password[256];
    printf("Enter a password: ");
    scanf("%s", password);

    int password_strength = 0;

    // Check for minimum length of 8 characters
    if (strlen(password) >= 8) {
        password_strength++;
    }

    // Check for presence of uppercase letter
    if (strchr(password, 'A') || strchr(password, 'B') || strchr(password, 'C') || strchr(password, 'D') || strchr(password, 'E') || strchr(password, 'F') || strchr(password, 'G') || strchr(password, 'H') || strchr(password, 'I') || strchr(password, 'J')) {
        password_strength++;
    }

    // Check for presence of lowercase letter
    if (strchr(password, 'a') || strchr(password, 'b') || strchr(password, 'c') || strchr(password, 'd') || strchr(password, 'e') || strchr(password, 'f') || strchr(password, 'g') || strchr(password, 'h') || strchr(password, 'i') || strchr(password, 'j')) {
        password_strength++;
    }

    // Check for presence of number
    if (strchr(password, '0') || strchr(password, '1') || strchr(password, '2') || strchr(password, '3') || strchr(password, '4') || strchr(password, '5') || strchr(password, '6') || strchr(password, '7') || strchr(password, '8') || strchr(password, '9')) {
        password_strength++;
    }

    // Check for presence of special character
    if (strchr(password, '$') || strchr(password, '%') || strchr(password, '^') || strchr(password, '&') || strchr(password, '*')) {
        password_strength++;
    }

    // Print password strength
    switch (password_strength) {
        case 0:
            printf("Password strength: Weak\n");
            break;
        case 1:
            printf("Password strength: Moderate\n");
            break;
        case 2:
            printf("Password strength: Good\n");
            break;
        case 3:
            printf("Password strength: Strong\n");
            break;
        case 4:
            printf("Password strength: Excellent\n");
            break;
    }

    return 0;
}