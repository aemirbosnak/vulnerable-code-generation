//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random integer within a specified range
int randomInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate a secure password
void generatePassword(char *password, int length) {

    // Define a string of possible characters for the password
    char *chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()_+-=";

    // Get the length of the character string
    int charLen = strlen(chars);

    // Set the seed for the random number generator
    srand(time(NULL));

    // Generate the password
    for (int i = 0; i < length; i++) {
        int randomIndex = randomInt(0, charLen - 1);
        password[i] = chars[randomIndex];
    }

    // Add null character at the end of the password string
    password[length] = '\0';
}

int main() {

    // Define a variable to store the length of the password
    int length;

    // Get the desired length of the password from the user
    printf("Enter the desired length of the password: ");
    scanf("%d", &length);

    // Allocate memory for the password string
    char *password = (char *) malloc(sizeof(char) * (length + 1));

    // Generate the password
    generatePassword(password, length);

    // Print the password to the console
    printf("Your secure password is: %s\n", password);

    // Free the memory allocated for the password string
    free(password);

    return 0;
}