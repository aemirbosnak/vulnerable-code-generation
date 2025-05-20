//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random number between min and max
int random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate a random character
char random_char() {
    // ASCII values of lowercase letters are from 97 to 122
    int min_ascii = 97;
    int max_ascii = 122;
    return random_number(min_ascii, max_ascii);
}

// Function to generate a random digit
char random_digit() {
    // ASCII values of digits are from 48 to 57
    int min_ascii = 48;
    int max_ascii = 57;
    return random_number(min_ascii, max_ascii);
}

// Function to generate a random special character
char random_special_char() {
    // ASCII values of special characters are from 33 to 47 and from 58 to 64
    int min_ascii = 33;
    int max_ascii = 64;
    int range1_size = 47 - 33;
    int range2_size = 64 - 58;
    int random_range = random_number(0, 1);
    if (random_range == 0) {
        return random_number(min_ascii, min_ascii + range1_size);
    } else {
        return random_number(min_ascii + range1_size + 1, min_ascii + range1_size + range2_size);
    }
}

// Function to generate a random password
char *generate_password(int length) {
    char *password = (char *)malloc(sizeof(char) * (length + 1));
    for (int i = 0; i < length; i++) {
        // Randomly choose between lowercase letter, digit, or special character
        int random_type = random_number(0, 2);
        switch (random_type) {
            case 0:
                password[i] = random_char();
                break;
            case 1:
                password[i] = random_digit();
                break;
            case 2:
                password[i] = random_special_char();
                break;
            default:
                password[i] = 'a'; // Default to lowercase letter
        }
    }
    password[length] = '\0'; // Null-terminate the string
    return password;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Get the length of the password from the user
    int password_length;
    printf("Enter the length of the password: ");
    scanf("%d", &password_length);

    // Generate a random password
    char *password = generate_password(password_length);

    // Print the password
    printf("Your password is: %s\n", password);

    // Free the memory allocated for the password
    free(password);

    return 0;
}