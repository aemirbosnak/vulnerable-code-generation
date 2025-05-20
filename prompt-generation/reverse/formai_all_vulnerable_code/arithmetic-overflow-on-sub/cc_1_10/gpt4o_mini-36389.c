//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_TEXT_LENGTH 256
#define TEST_COUNT 3

void printIntroduction() {
    printf("*****************************************\n");
    printf("!! Welcome to the Typing Speed Test !!\n");
    printf("*****************************************\n\n");
    printf("Prepare yourself for a typing challenge!\n");
    printf("Type the following sentences as fast as you can...\n\n");
}

void printRandomSentence(char *sentence) {
    char *sentences[] = {
        "The quick brown fox jumps over the lazy dog.",
        "A journey of a thousand miles begins with a single step.",
        "All that glitters is not gold.",
        "To be, or not to be, that is the question.",
        "In the middle of difficulty lies opportunity."
    };
    strcpy(sentence, sentences[rand() % 5]);
}

double calculateSpeed(int charactersTyped, double timeTaken) {
    return (charactersTyped / 5.0) / (timeTaken / 60.0); // words per minute
}

void runTypingTest() {
    char sentence[MAX_TEXT_LENGTH];
    printRandomSentence(sentence);

    printf("Type this sentence:\n");
    printf("\"%s\"\n", sentence);

    // Timing the user
    printf("Ready? Press Enter to start!\n");
    getchar(); // wait for user to press Enter

    clock_t start_time = clock();
    
    char userInput[MAX_TEXT_LENGTH];
    fgets(userInput, sizeof(userInput), stdin);
    
    clock_t end_time = clock();
    double timeTaken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Calculate typing stats
    int charactersTyped = strlen(userInput) - 1; // -1 for the newline character
    double typingSpeed = calculateSpeed(charactersTyped, timeTaken);
    
    printf("Your typing speed: %.2f words per minute\n", typingSpeed);
    
    if (strcmp(sentence, userInput) == 0) {
        printf("Amazing! You typed it correctly!\n");
    } else {
        printf("Oh no! There were mistakes!\n");
        printf("Correct sentence was: \"%s\"\n", sentence);
    }
}

int main() {
    srand(time(0)); // Seed for randomness
    printIntroduction();

    for (int i = 0; i < TEST_COUNT; i++) {
        printf("\n--- Test %d ---\n", i + 1);
        runTypingTest();
        printf("Continuing to the next test!\n");
    }

    printf("\nThanks for participating in the Typing Speed Test!\n");
    return 0;
}