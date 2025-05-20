//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random password
void generate_password(char *password, int length) {
    const char *characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int i;

    for (i = 0; i < length; ++i) {
        password[i] = characters[rand() % strlen(characters)];
    }

    password[length] = '\0';
}

// Function to print the generated password
void print_password(const char *password) {
    int i;

    for (i = 0; password[i]!= '\0'; ++i) {
        printf("%c", password[i]);
    }

    printf("\n");
}

int main() {
    char password[32]; // Maximum length of 32 characters
    int length;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Ask the user for the desired password length
    printf("Enter the desired password length (between 8 and 32 characters): ");
    scanf("%d", &length);

    // Validate the input
    if (length < 8 || length > 32) {
        printf("Invalid password length. Please enter a value between 8 and 32.\n");
        return 1;
    }

    // Generate the password
    generate_password(password, length);

    // Print the generated password
    printf("Your secure password is: ");
    print_password(password);

    return 0;
}