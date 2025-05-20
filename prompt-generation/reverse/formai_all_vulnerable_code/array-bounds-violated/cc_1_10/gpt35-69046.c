//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 16

// Function to generate a random integer within a given range
int generate_random_number(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Function to generate a random uppercase character
char generate_random_uppercase_char() {
    return generate_random_number(65, 90);
}

// Function to generate a random lowercase character
char generate_random_lowercase_char() {
    return generate_random_number(97, 122);
}

// Function to generate a random digit
char generate_random_digit() {
    return generate_random_number(48, 57);
}

// Function to generate a random special character
char generate_random_special_char() {
    char special_chars[] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '+', '=', '{', '}', '[', ']', ';', ':', '"', '\'', ',', '<', '.', '>', '/', '?', '\\', '|'};
    int index = generate_random_number(0, 30);
    return special_chars[index];
}

// Function to generate a secure password
char* generate_secure_password() {
    char* password = (char*) malloc(MAX_PASSWORD_LENGTH + 1);
    int password_length = generate_random_number(MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
    bool uppercase = false, lowercase = false, digit = false, special = false;
    int i;

    // Generate the password
    srand(time(NULL));
    for(i = 0; i < password_length; i++) {
        int choice = generate_random_number(1, 4);

        switch(choice) {
            case 1:
                password[i] = generate_random_uppercase_char();
                uppercase = true;
                break;
            case 2:
                password[i] = generate_random_lowercase_char();
                lowercase = true;
                break;
            case 3:
                password[i] = generate_random_digit();
                digit = true;
                break;
            case 4:
                password[i] = generate_random_special_char();
                special = true;
                break;
        }
    }

    // Ensure that the password contains at least one of each: uppercase, lowercase, digit, and special character
    if(!uppercase) {
        password[generate_random_number(0, password_length - 1)] = generate_random_uppercase_char();
    }
    if(!lowercase) {
        password[generate_random_number(0, password_length - 1)] = generate_random_lowercase_char();
    }
    if(!digit) {
        password[generate_random_number(0, password_length - 1)] = generate_random_digit();
    }
    if(!special) {
        password[generate_random_number(0, password_length - 1)] = generate_random_special_char();
    }

    password[password_length] = '\0';
    return password;
}

int main() {
    char* password = generate_secure_password();
    printf("Generated password: %s\n", password);
    free(password);
    return 0;
}