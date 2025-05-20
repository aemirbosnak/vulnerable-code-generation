//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 0 and 9
int random_digit() {
    return rand() % 10;
}

// Function to generate a random lowercase letter
char random_lowercase_letter() {
    return (char) ((rand() % 26) + 'a');
}

// Function to generate a random uppercase letter
char random_uppercase_letter() {
    return (char) ((rand() % 26) + 'A');
}

// Function to generate a random symbol
char random_symbol() {
    char symbols[] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '{', '}', '[', ']', '<', '>', '/', '?'};
    return symbols[rand() % sizeof(symbols)];
}

// Function to generate a random password of a given length
char *generate_password(int length) {
    char *password = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        int type = rand() % 4;
        switch (type) {
            case 0:
                password[i] = random_digit();
                break;
            case 1:
                password[i] = random_lowercase_letter();
                break;
            case 2:
                password[i] = random_uppercase_letter();
                break;
            case 3:
                password[i] = random_symbol();
                break;
        }
    }
    password[length] = '\0';
    return password;
}

int main() {
    srand(time(NULL));

    // Get the length of the password from the user
    int length;
    printf("Enter the length of the password you want: ");
    scanf("%d", &length);

    // Generate a random password
    char *password = generate_password(length);

    // Print the generated password
    printf("Your password is: %s\n", password);

    // Free the allocated memory
    free(password);

    return 0;
}