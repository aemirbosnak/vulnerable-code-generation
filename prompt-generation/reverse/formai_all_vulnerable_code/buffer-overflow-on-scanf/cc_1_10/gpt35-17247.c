//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random uppercase letter
char random_uppercase_letter() {
    return rand() % 26 + 65;
}

// Function to generate a random lowercase letter
char random_lowercase_letter() {
    return rand() % 26 + 97;
}

// Function to generate a random digit
char random_digit() {
    return rand() % 10 + 48;
}

// Function to generate a random special character
char random_special_character() {
    char special_characters[] = "!@#$%^&*()_+={}[]\\|;:'\",.<>/?";
    return special_characters[rand() % 29];
}

// Function to generate a secure password
void generate_password(int length) {
    // Initialize random seed
    srand(time(NULL));

    // Variables to store the password
    char password[length+1];
    password[length] = '\0';

    // Generate a random password
    for (int i = 0; i < length; i++) {
        int random_number = rand() % 4;
        if (random_number == 0) {
            password[i] = random_uppercase_letter();
        } else if (random_number == 1) {
            password[i] = random_lowercase_letter();
        } else if (random_number == 2) {
            password[i] = random_digit();
        } else {
            password[i] = random_special_character();
        }
    }

    // Print the password
    printf("Your secure password is: %s\n", password);
}

// Main function
int main() {
    // Prompt the user to enter the length of the password
    int length;
    printf("Enter the length of the password: ");
    scanf("%d", &length);

    // Generate a secure password
    generate_password(length);

    return 0;
}