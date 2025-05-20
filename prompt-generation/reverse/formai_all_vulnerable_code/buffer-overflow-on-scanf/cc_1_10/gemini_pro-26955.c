//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 32
#define NUM_ALPHA_LOWERCASE 26
#define NUM_ALPHA_UPPERCASE 26
#define NUM_NUMERIC 10
#define NUM_SYMBOLS 32

// Calculate the entropy of a password
double calculate_entropy(char *password) {
    int length = strlen(password);
    int num_alpha_lowercase = 0;
    int num_alpha_uppercase = 0;
    int num_numeric = 0;
    int num_symbols = 0;

    // Count the number of each type of character
    for (int i = 0; i < length; i++) {
        char c = password[i];
        if (c >= 'a' && c <= 'z') {
            num_alpha_lowercase++;
        } else if (c >= 'A' && c <= 'Z') {
            num_alpha_uppercase++;
        } else if (c >= '0' && c <= '9') {
            num_numeric++;
        } else {
            num_symbols++;
        }
    }

    // Calculate the entropy
    double entropy = 0.0;
    if (num_alpha_lowercase > 0) {
        entropy += NUM_ALPHA_LOWERCASE * log2(NUM_ALPHA_LOWERCASE);
    }
    if (num_alpha_uppercase > 0) {
        entropy += NUM_ALPHA_UPPERCASE * log2(NUM_ALPHA_UPPERCASE);
    }
    if (num_numeric > 0) {
        entropy += NUM_NUMERIC * log2(NUM_NUMERIC);
    }
    if (num_symbols > 0) {
        entropy += NUM_SYMBOLS * log2(NUM_SYMBOLS);
    }
    entropy /= length;

    return entropy;
}

// Check the strength of a password
int check_password_strength(char *password) {
    int length = strlen(password);

    // Check the length of the password
    if (length < MIN_LENGTH) {
        return -1;
    } else if (length > MAX_LENGTH) {
        return -2;
    }

    // Calculate the entropy of the password
    double entropy = calculate_entropy(password);

    // Check the entropy of the password
    if (entropy < 40) {
        return 0;
    } else if (entropy < 60) {
        return 1;
    } else if (entropy < 80) {
        return 2;
    } else {
        return 3;
    }
}

// Generate a random password
char *generate_random_password(int length) {
    char *password = malloc(length + 1);

    // Generate a random seed
    srand(time(NULL));

    // Generate the password
    for (int i = 0; i < length; i++) {
        int type = rand() % 4;
        switch (type) {
            case 0:
                password[i] = 'a' + rand() % NUM_ALPHA_LOWERCASE;
                break;
            case 1:
                password[i] = 'A' + rand() % NUM_ALPHA_UPPERCASE;
                break;
            case 2:
                password[i] = '0' + rand() % NUM_NUMERIC;
                break;
            case 3:
                password[i] = '!' + rand() % NUM_SYMBOLS;
                break;
        }
    }

    password[length] = '\0';

    return password;
}

// Main function
int main() {
    // Get the password from the user
    char password[MAX_LENGTH + 1];
    printf("Enter a password: ");
    scanf("%s", password);

    // Check the strength of the password
    int strength = check_password_strength(password);

    // Print the strength of the password
    switch (strength) {
        case -1:
            printf("Password is too short\n");
            break;
        case -2:
            printf("Password is too long\n");
            break;
        case 0:
            printf("Password is weak\n");
            break;
        case 1:
            printf("Password is moderate\n");
            break;
        case 2:
            printf("Password is strong\n");
            break;
        case 3:
            printf("Password is very strong\n");
            break;
    }

    return 0;
}