//MISTRAL-7B DATASET v1.0 Category: Password Strength Checker ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MIN_LENGTH 8
#define MAX_ATTEMPTS 5
#define WEAK_THRESHOLD 3

void print_strength(int strength) {
    switch (strength) {
        case 0: printf("Very Weak\n"); break;
        case 1: printf("Weak\n"); break;
        case 2: printf("Moderate\n"); break;
        case 3: printf("Strong\n"); break;
        case 4: printf("Very Strong\n"); break;
    }
}

int check_password_strength(char* password) {
    int length = strlen(password);
    int has_upper = 0;
    int has_lower = 0;
    int has_digit = 0;
    int has_special = 0;
    int strength = 0;

    for (int i = 0; password[i]; i++) {
        if (isupper(password[i])) has_upper = 1;
        if (islower(password[i])) has_lower = 1;
        if (isdigit(password[i])) has_digit = 1;
        if (!isalnum(password[i])) {
            has_special = 1;
            strength++;
        }
        if (length >= MIN_LENGTH) strength++;
    }

    if (has_upper && has_lower && has_digit) strength++;
    if (has_special) strength++;

    return strength;
}

int main() {
    char password[MAX_ATTEMPTS][MIN_LENGTH + 1];
    int attempts = 0;
    int strength;

    printf("Enter a password (minimum 8 characters): ");
    scanf("%s", password);
    strength = check_password_strength(password);
    print_strength(strength);

    while (attempts < MAX_ATTEMPTS && strength < 4) {
        printf("\nPassword is too weak. Try again: ");
        scanf("%s", password);
        strength = check_password_strength(password);
        attempts++;
    }

    if (attempts >= MAX_ATTEMPTS) {
        printf("\nMaximum attempts reached. Exiting...\n");
        exit(EXIT_FAILURE);
    }

    print_strength(strength);
    printf("Password accepted.\n");

    return EXIT_SUCCESS;
}