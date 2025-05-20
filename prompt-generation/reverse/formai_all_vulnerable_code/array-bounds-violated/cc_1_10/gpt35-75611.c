//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 10 // Maximum number of words in the test
#define MAX_ATTEMPTS 3 // Maximum number of attempts for each word
#define MAX_WORD_LENGTH 10 // Maximum length of each word in the test

int main() {
    char words[MAX_WORDS][MAX_WORD_LENGTH+1] = { // Initialize array of words to be used in the test
        "programming",
        "algorithm",
        "variable",
        "function",
        "pointer",
        "array",
        "structure",
        "operator",
        "compiler",
        "debugger"
    };
    
    int word_index, attempt, correct_attempts = 0, total_attempts = 0;
    char input[MAX_WORD_LENGTH+1];
    time_t start_time, end_time; // Variables to store start and end time of the test
    
    srand(time(NULL)); // Seed the random number generator
    
    printf("Welcome to the typing speed test! You will be given %d words to type, and you have %d attempts for each word.\n", MAX_WORDS, MAX_ATTEMPTS);
    printf("Press ENTER when you are ready to begin.\n");
    getchar(); // Wait for user to press ENTER
    
    start_time = time(NULL); // Record the start time of the test
    
    for (word_index = 0; word_index < MAX_WORDS; word_index++) {
        attempt = 0;
        do {
            printf("\nWord %d of %d: %s\n", word_index+1, MAX_WORDS, words[word_index]);
            printf("Attempt %d of %d: ", attempt+1, MAX_ATTEMPTS);
            fgets(input, sizeof(input), stdin); // Read user input
            
            // Remove newline character from input
            if (input[strlen(input)-1] == '\n') {
                input[strlen(input)-1] = '\0';
            }
            
            // Convert input to lowercase
            for (int i = 0; input[i]; i++) {
                input[i] = tolower(input[i]);
            }
            
            // Check if input is correct
            if (strcmp(input, words[word_index]) == 0) {
                printf("Correct!\n");
                correct_attempts++;
                total_attempts++;
                break;
            } else {
                printf("Incorrect. ");
                total_attempts++;
                attempt++;
            }
        } while (attempt < MAX_ATTEMPTS);
        
        if (attempt == MAX_ATTEMPTS) {
            printf("\nYou have used all your attempts for this word. The correct answer was: %s\n", words[word_index]);
        }
    }
    
    end_time = time(NULL); // Record the end time of the test
    
    int total_time = (int)(end_time - start_time); // Calculate total time of the test in seconds
    int average_time = (total_time * 1.0) / MAX_WORDS; // Calculate average time per word in seconds
    double accuracy = (correct_attempts * 1.0 / total_attempts) * 100.0; // Calculate accuracy percentage
    
    printf("\nTest complete!\n");
    printf("Total time: %d seconds\n", total_time);
    printf("Average time per word: %d seconds\n", average_time);
    printf("Accuracy: %.2f%%\n", accuracy);
    
    return 0;
}