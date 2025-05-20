//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to calculate the entropy of a password
double calculate_entropy(char *password) {
    int password_length = strlen(password);
    int character_count[256] = {0};
    double entropy = 0.0;

    // Count the occurrences of each character in the password
    for (int i = 0; i < password_length; i++) {
        character_count[(int)password[i]]++;
    }

    // Calculate the entropy of the password
    for (int i = 0; i < 256; i++) {
        if (character_count[i] > 0) {
            double probability = (double)character_count[i] / (double)password_length;
            entropy += probability * log2(probability);
        }
    }

    return entropy;
}

// Function to check the strength of a password
int check_password_strength(char *password) {
    double entropy = calculate_entropy(password);

    // Check if the password is strong
    if (entropy >= 4.0) {
        return 1;
    }

    // Check if the password is weak
    if (entropy < 2.0) {
        return -1;
    }

    // The password is neither strong nor weak
    return 0;
}

int main() {
    char password[100];

    // Get the password from the user
    printf("Enter your password: ");
    scanf("%s", password);

    // Check the strength of the password
    int strength = check_password_strength(password);

    // Print the result
    if (strength == 1) {
        printf("Your password is strong.\n");
    } else if (strength == 0) {
        printf("Your password is of medium strength.\n");
    } else {
        printf("Your password is weak.\n");
    }

    return 0;
}