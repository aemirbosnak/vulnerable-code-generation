//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    char password[255];
    int strength = 0;

    printf("Enter a password: ");
    scanf("%s", password);

    // Check for minimum length
    if (strlen(password) < 8) {
        strength++;
    }

    // Check for uppercase letter
    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            strength++;
        }
    }

    // Check for lowercase letter
    for (int i = 0; i < strlen(password); i++) {
        if (islower(password[i])) {
            strength++;
        }
    }

    // Check for number
    for (int i = 0; i < strlen(password); i++) {
        if (isdigit(password[i])) {
            strength++;
        }
    }

    // Check for special character
    for (int i = 0; i < strlen(password); i++) {
        if (ispunct(password[i])) {
            strength++;
        }
    }

    // Print strength
    switch (strength) {
        case 0:
            printf("Password strength: Weak\n");
            break;
        case 1:
            printf("Password strength: Moderate\n");
            break;
        case 2:
            printf("Password strength: Strong\n");
            break;
        case 3:
            printf("Password strength: Excellent\n");
            break;
    }

    return 0;
}