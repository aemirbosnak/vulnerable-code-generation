//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 16

// Function to generate a random uppercase letter
char random_uppercase() {
    return (char)(rand() % 26 + 65);
}

// Function to generate a random lowercase letter
char random_lowercase() {
    return (char)(rand() % 26 + 97);
}

// Function to generate a random digit
char random_digit() {
    return (char)(rand() % 10 + 48);
}

// Function to generate a random symbol
char random_symbol() {
    char symbols[] = "!@#$%^&*()_+-=[]\\{}|;\':\",./<>?";
    return symbols[rand() % 29];
}

// Function to generate a random password
void generate_password(int length) {
    char password[MAX_LENGTH];
    int i, r;

    // Seed the random number generator
    srand((unsigned int)time(NULL));

    // Randomly generate password
    for (i = 0; i < length; i++) {
        r = rand() % 4;
        switch (r) {
            case 0:
                password[i] = random_uppercase();
                break;
            case 1:
                password[i] = random_lowercase();
                break;
            case 2:
                password[i] = random_digit();
                break;
            case 3:
                password[i] = random_symbol();
                break;
        }
    }
    password[i] = '\0';

    // Print password
    printf("Your generated password: %s\n", password);
}

int main() {
    int length;

    // Get password length from user
    printf("Enter the password length (between %d and %d): ", MIN_LENGTH, MAX_LENGTH);
    scanf("%d", &length);

    // Check if password length is within range
    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        printf("Password length must be between %d and %d\n", MIN_LENGTH, MAX_LENGTH);
        return 1;
    }

    // Generate and print password
    generate_password(length);

    return 0;
}