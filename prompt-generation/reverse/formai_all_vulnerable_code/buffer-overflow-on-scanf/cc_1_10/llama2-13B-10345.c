//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAGIC_NUMBER 42

int main() {
    int magic_number = MAGIC_NUMBER;
    int user_input;
    char secret_message[50];

    // Ask the user for their name
    printf("What is your name? ");
    fgets(secret_message, 50, stdin);

    // Calculate the magic square of the user's name
    for (int i = 0; i < strlen(secret_message); i++) {
        user_input = secret_message[i] - 'A';
        magic_number = (magic_number * user_input) % 26;
    }

    // Print the magic square
    printf("The magic square of your name is: %d\n", magic_number);

    // Ask the user for a number between 1 and 10
    printf("Please enter a number between 1 and 10: ");
    scanf("%d", &user_input);

    // Calculate the factorial of the user's number
    int factorial = 1;
    for (int i = 1; i <= user_input; i++) {
        factorial *= i;
    }

    // Print the factorial
    printf("The factorial of %d is: %d\n", user_input, factorial);

    // Ask the user for a word
    printf("Please enter a word: ");
    fgets(secret_message, 50, stdin);

    // Calculate the number of vowels in the user's word
    int vowel_count = 0;
    for (int i = 0; i < strlen(secret_message); i++) {
        if (secret_message[i] == 'A' || secret_message[i] == 'E' || secret_message[i] == 'I' || secret_message[i] == 'O' || secret_message[i] == 'U') {
            vowel_count++;
        }
    }

    // Print the number of vowels
    printf("The word %s contains %d vowels.\n", secret_message, vowel_count);

    return 0;
}