//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Generate a random number between min and max
int rand_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Generate a random character from the given character set
char rand_char(const char *charset) {
    return charset[rand_range(0, strlen(charset) - 1)];
}

// Generate a random password of the given length
char *generate_password(int length) {
    // Character sets for different types of characters
    const char *lowercase_charset = "abcdefghijklmnopqrstuvwxyz";
    const char *uppercase_charset = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char *digit_charset = "0123456789";
    const char *symbol_charset = "!@#$%^&*()_+=-";

    // Allocate memory for the password
    char *password = malloc(length + 1);

    // Initialize the password with random characters
    for (int i = 0; i < length; i++) {
        // Generate a random type of character
        int type = rand_range(0, 3);

        // Generate a random character from the selected character set
        switch (type) {
            case 0:
                password[i] = rand_char(lowercase_charset);
                break;
            case 1:
                password[i] = rand_char(uppercase_charset);
                break;
            case 2:
                password[i] = rand_char(digit_charset);
                break;
            case 3:
                password[i] = rand_char(symbol_charset);
                break;
        }
    }

    // Terminate the password with a null character
    password[length] = '\0';

    // Return the generated password
    return password;
}

// Print the generated password
void print_password(char *password) {
    printf("Your secure password is: %s\n", password);
}

// Free the memory allocated for the password
void free_password(char *password) {
    free(password);
}

int main() {
    // Set the random seed
    srand(time(NULL));

    // Get the desired password length from the user
    int length;
    printf("Enter the desired password length: ");
    scanf("%d", &length);

    // Generate a random password
    char *password = generate_password(length);

    // Print the generated password
    print_password(password);

    // Free the memory allocated for the password
    free_password(password);

    return 0;
}