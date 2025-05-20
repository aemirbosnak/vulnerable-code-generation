//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define PASSWORD_LENGTH 12 // Length of the generated password
#define CHARACTER_SET "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+=-[]{}|;:,.<>?/~`" // Set of characters to choose from

// Function to generate a random password of given length
char* generate_password(int length) {
    char* password = (char*)malloc(length + 1); // Allocate memory for the password
    if (!password) {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }

    // Initialize the password with random characters
    for (int i = 0; i < length; i++) {
        password[i] = CHARACTER_SET[rand() % strlen(CHARACTER_SET)];
    }

    // Add a random special character to the password
    int special_index = rand() % strlen(CHARACTER_SET);
    password[length - 1] = CHARACTER_SET[special_index];

    return password;
}

// Function to print the generated password
void print_password(char* password) {
    printf("Your password is: %s\n", password);
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    // Prompt the user for the desired password length
    int length;
    do {
        printf("Enter the desired password length (between 1 and %d): ", PASSWORD_LENGTH);
        scanf("%d", &length);
    } while (length < 1 || length > PASSWORD_LENGTH);

    // Generate and print the password
    char* password = generate_password(length);
    print_password(password);

    // Free the memory allocated for the password
    free(password);

    return 0;
}