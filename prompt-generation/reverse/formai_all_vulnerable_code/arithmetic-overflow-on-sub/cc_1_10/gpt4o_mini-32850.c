//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRING_LENGTH 256
#define NUM_TESTS 5

// Function declarations
void displayInstructions();
char* getRandomSentence();
void startTypingTest(const char* sentence);
void calculateTypingSpeed(double timeTaken, int charCount);

int main() {
    displayInstructions();
    
    for (int i = 0; i < NUM_TESTS; i++) {
        char* sentence = getRandomSentence();
        if (sentence != NULL) {
            startTypingTest(sentence);
            free(sentence);
        }
    }

    printf("Thank you for participating in the Typing Speed Test!\n");
    return 0;
}

void displayInstructions() {
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be given a sentence to type.\n");
    printf("Try to type it as quickly and accurately as you can.\n");
    printf("Let's get started!\n\n");
}

char* getRandomSentence() {
    const char* sentences[NUM_TESTS] = {
        "The quick brown fox jumps over the lazy dog.",
        "A journey of a thousand miles begins with a single step.",
        "To be or not to be, that is the question.",
        "All that glitters is not gold.",
        "In the middle of difficulty lies opportunity."
    };
    
    int randomIndex = rand() % NUM_TESTS;
    char* sentence = malloc(strlen(sentences[randomIndex]) + 1);
    if (sentence != NULL) {
        strcpy(sentence, sentences[randomIndex]);
    }
    
    return sentence;
}

void startTypingTest(const char* sentence) {
    printf("Type the following sentence:\n");
    printf("\n%s\n\n", sentence);

    // Start the timer
    clock_t startTime = clock();

    char input[MAX_STRING_LENGTH];
    fgets(input, sizeof(input), stdin);

    // Stop the timer
    clock_t endTime = clock();
    double timeTaken = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;

    // Remove newline character from input if present
    input[strcspn(input, "\n")] = 0;

    // Calculate character count (including spaces)
    int charCount = strlen(sentence);
    
    // Calculate typing speed
    calculateTypingSpeed(timeTaken, charCount);

    // Check accuracy
    if (strcmp(input, sentence) == 0) {
        printf("Perfect typing! \n");
    } else {
        printf("There were errors in your typing.\n");
    }
    
    printf("\n");
}

void calculateTypingSpeed(double timeTaken, int charCount) {
    double speed = (charCount / timeTaken) * 60; // characters per minute
    printf("Your typing speed: %.2f characters per minute\n", speed);
}