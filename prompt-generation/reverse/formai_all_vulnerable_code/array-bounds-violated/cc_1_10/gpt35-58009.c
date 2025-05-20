//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Character arrays for our password components
char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char digits[] = "0123456789";
char symbols[] = "!@#$%^&*()+=_-{}[]<>/?\\|";

int main()
{
    int length, num_lower, num_upper, num_digits, num_symbols;
    int i, rand_index;
    char password[64] = ""; // Initialize our password string

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Get user input for password length and component counts
    printf("Enter password length: ");
    scanf("%d", &length);
    printf("Enter number of lowercase letters: ");
    scanf("%d", &num_lower);
    printf("Enter number of uppercase letters: ");
    scanf("%d", &num_upper);
    printf("Enter number of digits: ");
    scanf("%d", &num_digits);
    printf("Enter number of special symbols: ");
    scanf("%d", &num_symbols);

    // Add lowercase letters to password
    for (i = 0; i < num_lower; i++)
    {
        rand_index = rand() % 26; // Generate random index for lowercase character array
        password[i] = lowercase[rand_index];
    }

    // Add uppercase letters to password
    for (i = num_lower; i < num_lower + num_upper; i++)
    {
        rand_index = rand() % 26; // Generate random index for uppercase character array
        password[i] = uppercase[rand_index];
    }

    // Add digits to password
    for (i = num_lower + num_upper; i < num_lower + num_upper + num_digits; i++)
    {
        rand_index = rand() % 10; // Generate random index for digits character array
        password[i] = digits[rand_index];
    }

    // Add special symbols to password
    for (i = num_lower + num_upper + num_digits; i < length; i++)
    {
        rand_index = rand() % 23; // Generate random index for symbols character array
        password[i] = symbols[rand_index];
    }

    // Shuffle the password string to randomize the order of components
    for (i = 0; i < length; i++)
    {
        rand_index = rand() % length; // Generate random index to swap with
        char temp = password[i];
        password[i] = password[rand_index];
        password[rand_index] = temp;
    }

    // Print the generated password
    printf("Your secure password is: %s\n", password);

    return 0;
}