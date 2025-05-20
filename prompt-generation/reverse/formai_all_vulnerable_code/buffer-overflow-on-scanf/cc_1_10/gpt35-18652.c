//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 10 // Maximum number of random words
#define MAX_LENGTH 20 // Maximum length of each word
#define MAX_ATTEMPTS 3 // Maximum number of attempts per word

int main() {
    char words[MAX_WORDS][MAX_LENGTH] = {"apple", "banana", "cherry", "dragonfruit", "elderberry", "fig", "grapes", "honeydew", "kiwi", "lemon"}; // Array of 10 random words
    char input[MAX_LENGTH]; // User input
    int score = 0; // User's score
    int i, j; // Loop counters
    
    srand(time(NULL)); // Seed the random number generator
    
    // Welcome message
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be given %d random words to type.\n", MAX_WORDS);
    printf("You have %d attempts per word.\n", MAX_ATTEMPTS);
    printf("Get ready to test your typing speed!\n\n");
    
    // Main loop
    for (i = 0; i < MAX_WORDS; i++) {
        // Pick a random word
        char word[MAX_LENGTH];
        strcpy(word, words[rand() % MAX_WORDS]);
        
        // Show the word to the user
        printf("Word %d: ", i+1);
        for (j = 0; j < strlen(word); j++) {
            printf("%c ", word[j]);
        }
        printf("\n");
        
        // Prompt the user for input
        int attempts = 0;
        while (attempts < MAX_ATTEMPTS) {
            printf("Type the word and press Enter: ");
            scanf("%s", input);
            attempts++;
            
            // Check if the input matches the word
            if (strcmp(input, word) == 0) {
                printf("Correct! You typed the word in %d attempt(s).\n", attempts);
                score += strlen(word) * (MAX_ATTEMPTS - attempts + 1);
                printf("Your current score is: %d\n\n", score);
                break;
            }
            else {
                printf("Incorrect. You have %d attempt(s) remaining.\n", MAX_ATTEMPTS - attempts);
            }
        }
        
        // User ran out of attempts
        if (attempts == MAX_ATTEMPTS) {
            printf("Sorry, you didn't type the word correctly.\n");
            printf("The correct word was: %s\n", word);
            printf("Your current score is: %d\n\n", score);
        }
    }
    
    // Game over message
    printf("Game over! Your final score is: %d\n", score);
    
    return 0;
}