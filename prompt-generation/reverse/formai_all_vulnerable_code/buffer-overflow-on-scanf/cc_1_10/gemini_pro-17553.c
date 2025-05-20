//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 32

char *generate_password(int length) {
    // Initialize the password string.
    char *password = malloc(length + 1);
    password[length] = '\0';

    // Seed the random number generator.
    srand(time(NULL));

    // Generate each character of the password.
    for (int i = 0; i < length; i++) {
        int random_number = rand() % 94 + 33;

        // Make sure the character is printable.
        while (!isprint(random_number)) {
            random_number = rand() % 94 + 33;
        }

        password[i] = (char)random_number;
    }

    // Return the password string.
    return password;
}

int main() {
    // Get the desired password length from the user.
    int length;
    printf("Enter the desired password length (between %d and %d): ", MIN_LENGTH, MAX_LENGTH);
    scanf("%d", &length);

    // Make sure the length is valid.
    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        printf("Invalid password length. Please enter a length between %d and %d.\n", MIN_LENGTH, MAX_LENGTH);
        return 1;
    }

    // Generate the password.
    char *password = generate_password(length);

    // Print the password to the console.
    printf("Your password is: %s\n", password);

    // Free the memory allocated for the password.
    free(password);

    return 0;
}