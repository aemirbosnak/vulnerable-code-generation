//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

// Function declarations
void generate_password(int length);

int main()
{
    // Seed the random number generator with the current time
    srand((unsigned) time(NULL));

    int password_length;

    // Prompt the user for password length
    printf("Enter the desired password length: ");
    scanf("%d", &password_length);

    // Generate the password
    generate_password(password_length);

    return 0;
}

void generate_password(int length)
{
    // Define character sets for password generation
    const char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    const char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char numbers[] = "0123456789";
    const char symbols[] = "!@#$%^&*()-=_+[]{}\\|;:'\",.<>/?";

    // Define variables for password generation
    char password[length + 1];
    int lowercase_count = 0, uppercase_count = 0, number_count = 0, symbol_count = 0;

    // Set initial values for password characters to null characters
    for (int i = 0; i < length; i++) {
        password[i] = '\0';
    }

    // Generate the password character by character
    for (int i = 0; i < length; i++) {
        int character_set = rand() % 4;

        if (character_set == 0) {
            // Add a lowercase letter
            password[i] = lowercase[rand() % sizeof(lowercase)];
            lowercase_count++;
        }
        else if (character_set == 1) {
            // Add an uppercase letter
            password[i] = uppercase[rand() % sizeof(uppercase)];
            uppercase_count++;
        }
        else if (character_set == 2) {
            // Add a number
            password[i] = numbers[rand() % sizeof(numbers)];
            number_count++;
        }
        else {
            // Add a symbol
            password[i] = symbols[rand() % sizeof(symbols)];
            symbol_count++;
        }
    }

    // Ensure that the password meets the requirements
    if (lowercase_count == 0 || uppercase_count == 0 || number_count == 0 || symbol_count == 0) {
        generate_password(length);
    }

    // Convert any remaining null characters to a random character
    for (int i = 0; i < length; i++) {
        if (password[i] == '\0') {
            int character_set = rand() % 4;

            if (character_set == 0) {
                // Add a lowercase letter
                password[i] = lowercase[rand() % sizeof(lowercase)];
            }
            else if (character_set == 1) {
                // Add an uppercase letter
                password[i] = uppercase[rand() % sizeof(uppercase)];
            }
            else if (character_set == 2) {
                // Add a number
                password[i] = numbers[rand() % sizeof(numbers)];
            }
            else {
                // Add a symbol
                password[i] = symbols[rand() % sizeof(symbols)];
            }
        }
    }

    // Convert the password to a string and print it
    password[length] = '\0';
    printf("Your new password is: %s\n", password);
}