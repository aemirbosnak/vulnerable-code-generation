//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: relaxed
#include <stdio.h>
#include <string.h>

int main() {
    char password[100];
    printf("Enter your password: ");
    scanf("%s", password);

    int length = strlen(password);
    int upper = 0, lower = 0, digit = 0, special = 0;

    // Loop through each character in the password
    for (int i = 0; i < length; i++) {
        // Check if the character is uppercase
        if (password[i] >= 'A' && password[i] <= 'Z') {
            upper++;
        }
        // Check if the character is lowercase
        else if (password[i] >= 'a' && password[i] <= 'z') {
            lower++;
        }
        // Check if the character is a digit
        else if (password[i] >= '0' && password[i] <= '9') {
            digit++;
        }
        // Check if the character is a special character
        else {
            special++;
        }
    }

    // Calculate the final strength score
    int strength = 0;
    if (upper > 0) {
        strength += 2;
    }
    if (lower > 0) {
        strength += 2;
    }
    if (digit > 0) {
        strength += 2;
    }
    if (special > 0) {
        strength += 4;
    }
    if (length >= 8) {
        strength += 4;
    }
    if (length >= 12) {
        strength += 2;
    }

    // Output the strength score and rating
    printf("Password Strength Score: %d\n", strength);
    if (strength >= 12) {
        printf("Very Strong\n");
    }
    else if (strength >= 8) {
        printf("Strong\n");
    }
    else if (strength >= 4) {
        printf("Weak\n");
    }
    else {
        printf("Very Weak\n");
    }

    return 0;
}