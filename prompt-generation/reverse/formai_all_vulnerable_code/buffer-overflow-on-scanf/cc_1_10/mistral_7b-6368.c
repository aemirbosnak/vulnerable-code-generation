//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: mathematical
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>

// Function to check if a number is prime
bool is_prime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Function to check if a word is a prime word
bool is_prime_word(char *word) {
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        // Convert character to ASCII value
        int letter = word[i];
        // Check if the ASCII value is a prime number
        if (!is_prime(letter)) {
            return false;
        }
    }
    return true;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Word to be checked
    char word[50];

    printf("Enter a word to check: ");
    scanf("%s", word);

    // Check if the word is a prime word
    if (is_prime_word(word)) {
        printf("The word '%s' is a prime word.\n", word);
    } else {
        printf("The word '%s' is not a prime word.\n", word);

        // Generate a random prime word of the same length
        char prime_word[50];
        int len = strlen(word);
        for (int i = 0; i < len; i++) {
            // Generate a random prime number between 65 and 90 (A to Z)
            int letter = rand() % 26 + 65;
            prime_word[i] = (char) letter;

            // Check if the generated letter is a prime number
            while (!is_prime(letter)) {
                // If not, generate a new random prime number
                letter = rand() % 26 + 65;
            }
        }

        prime_word[len] = '\0'; // Add null terminator
        printf("A prime word of the same length as '%s' is: '%s'\n", word, prime_word);
    }

    return 0;
}