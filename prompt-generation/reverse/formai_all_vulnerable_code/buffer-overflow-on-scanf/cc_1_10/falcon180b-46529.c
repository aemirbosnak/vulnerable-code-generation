//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 16
#define CHARSET_SIZE 64

// Define the character set to use for the password
char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                   "abcdefghijklmnopqrstuvwxyz"
                   "0123456789"
                   "!@#$%^&*()_+";

// Generate a random password of the specified length
char* generate_password(int length) {
    char* password = malloc(length + 1);
    if (password == NULL) {
        printf("Error: Failed to allocate memory for password.\n");
        exit(1);
    }

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Fill the password with random characters from the character set
    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % CHARSET_SIZE];
    }

    // Terminate the password string with a null character
    password[length] = '\0';

    return password;
}

int main() {
    // Prompt the user for the desired password length
    int length = 0;
    while (length <= 0 || length > PASSWORD_LENGTH) {
        printf("Enter the desired password length (between 1 and %d): ", PASSWORD_LENGTH);
        scanf("%d", &length);
    }

    // Generate the password and print it to the console
    char* password = generate_password(length);
    printf("Your secure password is: %s\n", password);

    // Free the memory allocated for the password
    free(password);

    return 0;
}