//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_LENGTH 256

void clearBuffer() {
    while (getchar() != '\n');
}

char *getRandomSentence() {
    const char* sentences[] = {
        "The quick brown fox jumps over the lazy dog.",
        "Programming in C can be fun and exciting!",
        "Typing speed is essential for efficient work.",
        "Practice makes perfect, keep typing!",
        "Learning to code opens many doors for you."
    };
    int randomIndex = rand() % 5;
    return (char*)sentences[randomIndex];
}

void calculateSpeed(double timeTaken, int charactersTyped) {
    double speed = (charactersTyped / 5.0) / (timeTaken / 60); // calculating speed in WPM (words per minute)
    printf("Your typing speed is: %.2f WPM\n", speed);
}

void typingTest() {
    srand(time(NULL)); // Seed the random number generator
    char sentence[MAX_LENGTH];
    strcpy(sentence, getRandomSentence());

    printf("=====================================\n");
    printf("Welcome to the Typing Speed Test!\n");
    printf("=====================================\n");
    printf("Type the following sentence as fast as you can:\n\n");
    printf("\"%s\"\n\n", sentence);
    printf("Press ENTER to start the timer...\n");
    clearBuffer();
    clock_t startTime = clock();

    char userInput[MAX_LENGTH];
    fgets(userInput, MAX_LENGTH, stdin);

    clock_t endTime = clock();
    double timeTaken = (double)(endTime - startTime) / CLOCKS_PER_SEC;

    // Remove trailing newline character
    int len = strlen(userInput);
    if(userInput[len - 1] == '\n') {
        userInput[len - 1] = '\0';
    }

    // Compare user input with the original sentence
    if (strcmp(userInput, sentence) == 0) {
        printf("\nGreat job! You typed it perfectly!\n");
    } else {
        printf("\nOops! There were some mistakes in your typing.\n");
    }
    
    // Calculate and display typing speed
    int charactersTyped = strlen(userInput);
    calculateSpeed(timeTaken, charactersTyped);
    
    printf("Time taken: %.2f seconds\n", timeTaken);
}

int main() {
    char continueTest = 'y';
    while (continueTest == 'y' || continueTest == 'Y') {
        typingTest();
        printf("\nWould you like to try again? (y/n): ");
        scanf(" %c", &continueTest);
        clearBuffer(); // Clear input buffer to handle the newline character
    }
    printf("Thank you for playing! Keep practicing your typing skills. 🚀\n");
    return 0;
}