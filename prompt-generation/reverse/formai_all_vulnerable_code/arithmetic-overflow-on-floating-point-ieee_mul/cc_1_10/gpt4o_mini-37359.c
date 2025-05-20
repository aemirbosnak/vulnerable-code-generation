//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_SENTENCES 5
#define BUFFER_SIZE 256

const char *sentences[MAX_SENTENCES] = {
    "The quick brown fox jumps over the lazy dog.",
    "Programming is like writing a story.",
    "C is a powerful systems programming language.",
    "Typing speed tests help improve your typing skills.",
    "Practice makes perfect in everything you do."
};

void clearScreen() {
    printf("\033[H\033[J");
}

void displaySentence(const char *sentence) {
    printf("Type the following sentence:\n\n");
    printf("%s\n\n", sentence);
}

int main() {
    char userInput[BUFFER_SIZE];
    int sentenceIndex, wordCount = 0;
    time_t startTime, endTime;

    // Seed the random number generator
    srand(time(NULL));

    // Clear the terminal screen
    clearScreen();

    // Select a random sentence from the list
    sentenceIndex = rand() % MAX_SENTENCES;

    // Display the sentence
    displaySentence(sentences[sentenceIndex]);

    // Start the timing
    printf("Press Enter to start...\n");
    getchar();
    startTime = time(NULL);

    // Get user input
    printf("Your input: ");
    fgets(userInput, BUFFER_SIZE, stdin);

    // Record the end time
    endTime = time(NULL);

    // Calculate time taken
    double timeTaken = difftime(endTime, startTime);
    
    // Remove the newline character from user input
    userInput[strcspn(userInput, "\n")] = 0;

    // Count words in user input
    char *token = strtok(userInput, " ");
    while (token != NULL) {
        wordCount++;
        token = strtok(NULL, " ");
    }

    // Calculate words per minute
    double wpm = (wordCount / timeTaken) * 60;

    // Display results
    printf("\n");
    printf("You typed: \"%s\"\n", userInput);
    printf("Time taken: %.2f seconds\n", timeTaken);
    printf("Your typing speed: %.2f words per minute\n", wpm);

    if (strcmp(userInput, sentences[sentenceIndex]) == 0) {
        printf("Great job! You typed the correct sentence!\n");
    } else {
        printf("Oops! There were some errors in your typing.\n");
        printf("The correct sentence was:\n");
        printf("\"%s\"\n", sentences[sentenceIndex]);
    }

    return 0;
}