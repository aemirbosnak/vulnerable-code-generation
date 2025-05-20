//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random lowercase letter
char getLowercase() {
    return rand() % 26 + 'a';
}

// Function to generate a random uppercase letter
char getUppercase() {
    return rand() % 26 + 'A';
}

// Function to generate a random digit
char getDigit() {
    return rand() % 10 + '0';
}

// Function to generate a random special character
char getSpecial() {
    char specialChars[] = "!@#$%^&*()_+-=[]{};:,.<>?\\/\"";
    return specialChars[rand() % sizeof(specialChars) - 1];
}

// Generate a secure password
int main() {
    srand(time(NULL));  // Seed random number generator with time

    int length = 0;
    printf("How long do you want your password to be? ");
    scanf("%d", &length);

    if (length < 8) {  // Make sure the password is at least 8 characters long
        printf("Password must be at least 8 characters long.\n");
        return 1;
    }

    char password[length+1];  // Add 1 for the null terminator
    password[length] = '\0';

    for (int i = 0; i < length; i++) {
        int choice = rand() % 4;

        switch (choice) {
            case 0:
                password[i] = getLowercase();
                break;
            case 1:
                password[i] = getUppercase();
                break;
            case 2:
                password[i] = getDigit();
                break;
            case 3:
                password[i] = getSpecial();
                break;
        }
    }

    printf("Your secure password is: %s\n", password);

    return 0;
}