//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_SENTENCES 5
#define MAX_LENGTH 256

const char *sentences[MAX_SENTENCES] = {
    "The quick brown fox jumps over the lazy dog.",
    "A journey of a thousand miles begins with a single step.",
    "To be or not to be, that is the question.",
    "All that glitters is not gold.",
    "In the middle of difficulty lies opportunity."
};

void displayInstructions() {
    printf("Welcome to the C Typing Speed Test!\n");
    printf("You will be shown a sentence to type as quickly as you can.\n");
    printf("Type the sentence and press Enter.\n");
    printf("Let's see how fast you can type!\n\n");
}

char *generateRandomSentence() {
    srand(time(NULL));
    return (char *)sentences[rand() % MAX_SENTENCES];
}

void calculateTypingSpeed(double seconds, int typedLength) {
    double wordsPerMinute = (typedLength / 5.0) / (seconds / 60.0);
    printf("Your typing speed is: %.2f words per minute.\n", wordsPerMinute);
}

int main() {
    char typedInput[MAX_LENGTH];
    char *sentenceToType;
    double startTime, endTime;

    displayInstructions();
    
    // Generate a random sentence to type
    sentenceToType = generateRandomSentence();
    printf("Type the following sentence:\n\n");
    printf("\"%s\"\n\n", sentenceToType);

    // Start the timer
    startTime = (double)clock() / CLOCKS_PER_SEC;

    // Get user input
    printf("Start typing: ");
    fgets(typedInput, MAX_LENGTH, stdin);

    // End the timer
    endTime = (double)clock() / CLOCKS_PER_SEC;

    // Remove trailing newline character from input
    size_t len = strlen(typedInput);
    if (len > 0 && typedInput[len - 1] == '\n') {
        typedInput[len - 1] = '\0';
    }

    // Calculate time taken
    double timeTaken = endTime - startTime;

    // Check if the input matches the expected sentence
    if (strcmp(typedInput, sentenceToType) == 0) {
        printf("Great job! You typed the sentence correctly.\n");
    } else {
        printf("Oops! The sentence you typed was incorrect.\n");
    }

    // Calculate and display typing speed
    int typedLength = strlen(typedInput);
    calculateTypingSpeed(timeTaken, typedLength);

    return 0;
}