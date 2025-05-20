//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    // Define the variables needed
    int length, num_symbols, num_numbers;
    char password[100];
    int password_length = 0;
    int symbols_length = 0;
    int numbers_length = 0;

    // Get user input for password length, number of symbols and number of numbers
    printf("Enter password length: ");
    scanf("%d", &length);
    printf("Enter number of symbols in password: ");
    scanf("%d", &num_symbols);
    printf("Enter number of numbers in password: ");
    scanf("%d", &num_numbers);

    // Define arrays containing all possible symbols and numbers
    char symbols[] = "~!@#$%^&*()_+`-=\\{}\[]|;':\",./<>?";
    char numbers[] = "0123456789";

    // Seed random number generator with current time
    srand((unsigned int)time(NULL));

    // Generate random symbols for password
    for (int i = 0; i < num_symbols; i++) {
        int random_index = rand() % sizeof(symbols) - 1;
        password[password_length++] = symbols[random_index];
        symbols_length++;
    }

    // Generate random numbers for password
    for (int i = 0; i < num_numbers; i++) {
        int random_index = rand() % sizeof(numbers) - 1;
        password[password_length++] = numbers[random_index];
        numbers_length++;
    }

    // Generate random letters for password
    int remaining_length = length - num_symbols - num_numbers;
    for (int i = 0; i < remaining_length; i++) {
        int random_index = rand() % 52;
        if (random_index < 26) { // lowercase letter
            password[password_length++] = random_index + 97; // ASCII code for 'a'
        } else { // uppercase letter
            password[password_length++] = random_index - 26 + 65; // ASCII code for 'A'
        }
    }

    // Shuffle the password array using Fisher-Yates algorithm
    for (int i = length - 1; i > 0; i--) {
        int random_index = rand() % i;
        char temp = password[i];
        password[i] = password[random_index];
        password[random_index] = temp;
    }

    // Print the final password
    printf("Generated password: %s\n", password);

    // Print statistics about password composition
    printf("Password contains %d symbols, %d numbers, and %d letters\n", symbols_length, numbers_length, remaining_length);

    return 0;
}