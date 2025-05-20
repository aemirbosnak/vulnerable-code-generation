//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A custom function to determine if a string contains only digits
int is_numeric(const char *str) {
    while (*str) {
        if (*str < '0' || *str > '9') {
            return 0;
        }
        str++;
    }
    return 1;
}

// A custom function to reverse a string
void reverse_string(char *str) {
    int len = strlen(str);
    for (int i = 0, j = len - 1; i < len / 2; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main() {
    // Let's play a guessing game!
    printf("Hello there! I'm thinking of a number between 1 and 100. Try to guess it!\n");

    // Generate a random number
    srand(time(NULL));
    int secret_number = rand() % 100 + 1;

    // Get the user's guess
    char guess[10];
    printf("What's your guess? ");
    scanf("%s", guess);

    // Check if the user's guess is valid
    if (!is_numeric(guess)) {
        printf("Invalid input. Please enter a number between 1 and 100.\n");
        return 1;
    }

    // Convert the user's guess to an integer
    int guess_number = atoi(guess);

    // Check if the user's guess is correct
    int attempts = 1;
    while (guess_number != secret_number) {

        // Reveal a hint: the secret number is odd or even
        if (secret_number % 2 == guess_number % 2) {
            printf("Hint: The secret number is %s.\n", (secret_number % 2 == 0) ? "even" : "odd");
        }

        // Reverse the guess string to create a new guess
        reverse_string(guess);
        guess_number = atoi(guess);

        // Increment the number of attempts
        attempts++;

        // Get the user's next guess
        printf("Guess again: ");
        scanf("%s", guess);

        // Check if the user's guess is valid
        if (!is_numeric(guess)) {
            printf("Invalid input. Please enter a number between 1 and 100.\n");
            return 1;
        }

        // Convert the user's guess to an integer
        guess_number = atoi(guess);
    }

    // Congratulate the user and reveal the secret number
    printf("Congratulations! You guessed the secret number %d in %d attempts.\n", secret_number, attempts);

    return 0;
}