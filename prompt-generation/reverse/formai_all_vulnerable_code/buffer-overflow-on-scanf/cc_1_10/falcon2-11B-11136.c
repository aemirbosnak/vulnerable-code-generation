//Falcon2-11B DATASET v1.0 Category: Typing Speed Test ; Style: creative
#include <stdio.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 50
#define MAX_CHARS 100

int main() {
    // Create an array to store words
    char words[MAX_WORDS][MAX_CHARS];

    // Initialize an array of characters to be typed
    char input[MAX_CHARS];

    // Initialize the time to start measuring typing speed
    clock_t startTime;
    startTime = clock();

    // Prompt the user to enter a word
    printf("Enter a word to type: ");

    // Read the word from the user
    scanf("%s", words[0]);

    // Print the word to be typed
    printf("Type: %s\n", words[0]);

    // Initialize the time to start measuring typing speed
    startTime = clock();

    // Initialize the number of correct characters typed
    int correct = 0;

    // Initialize the number of total characters typed
    int total = 0;

    // Initialize the number of words typed
    int wordsTyped = 0;

    // Initialize the number of errors
    int errors = 0;

    // Loop until all words are typed
    while (wordsTyped < MAX_WORDS) {
        // Read a character from the user
        scanf("%c", input);

        // If the character is correct, increment the number of correct characters typed
        if (strcmp(input, words[wordsTyped]) == 0) {
            correct++;
        }

        // If the character is incorrect, increment the number of errors
        else {
            errors++;
        }

        // Increment the total number of characters typed
        total++;

        // Increment the number of words typed
        wordsTyped++;
    }

    // Print the number of correct characters typed
    printf("Correct characters: %d\n", correct);

    // Print the number of errors
    printf("Errors: %d\n", errors);

    // Calculate the typing speed in characters per second
    double typingSpeed = (double)correct / (double)total;

    // Print the typing speed
    printf("Typing speed: %.2f characters per second\n", typingSpeed);

    // Print the number of words typed
    printf("Words typed: %d\n", wordsTyped);

    // Print the total time in seconds
    double totalTime = (double)clock() - startTime;
    printf("Total time: %.2f seconds\n", totalTime);

    return 0;
}