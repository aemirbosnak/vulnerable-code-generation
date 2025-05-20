//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate a random character from the given character set
char rand_char(char *charset) {
    return charset[rand() % strlen(charset)];
}

// Function to generate a random password of the given length
char *generate_password(int length) {
    // Initialize the character set
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()";

    // Allocate memory for the password
    char *password = malloc(length + 1);

    // Generate the password
    for (int i = 0; i < length; i++) {
        password[i] = rand_char(charset);
    }

    // Terminate the password with a null character
    password[length] = '\0';

    // Return the password
    return password;
}

// Function to print the password
void print_password(char *password) {
    printf("Your new password is: %s\n", password);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Get the length of the password from the user
    int length;
    printf("How long do you want your password to be? ");
    scanf("%d", &length);

    // Generate the password
    char *password = generate_password(length);

    // Print the password
    print_password(password);

    // Free the memory allocated for the password
    free(password);

    return 0;
}