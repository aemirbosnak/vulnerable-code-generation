//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_TEXT_LENGTH 256
#define TYPING_TIME_LIMIT 60  // seconds
#define WORD_COUNT 5

// Sample text for typing test
const char *sampleTexts[] = {
    "The quick brown fox jumps over the lazy dog.",
    "A journey of a thousand miles begins with a single step.",
    "To be or not to be, that is the question.",
    "All that glitters is not gold.",
    "In the middle of every difficulty lies opportunity."
};

// Function to display the instructions
void displayInstructions() {
    printf("\n------------------------Typing Speed Test------------------------\n");
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be given a sentence to type.\n");
    printf("Try to type it as fast and accurately as you can.\n");
    printf("You have %d seconds to finish typing each given sentence.\n", TYPING_TIME_LIMIT);
    printf("Press Enter to start...\n");
    getchar();
}

// Function to select a random sentence from the array
const char* getRandomText() {
    srand(time(NULL)); // Seed for random number generation
    return sampleTexts[rand() % WORD_COUNT];
}

// Function to measure typing speed and accuracy
void measureTypingSpeed(const char *textToType) {
    char userInput[MAX_TEXT_LENGTH];
    time_t startTime, endTime;

    printf("Your text to type: \n%s\n", textToType);
    printf("Start typing now:\n");

    startTime = time(NULL);
    fgets(userInput, MAX_TEXT_LENGTH, stdin);
    endTime = time(NULL);

    // Calculate elapsed time
    double elapsed = difftime(endTime, startTime);
    
    // Check for time limit
    if (elapsed > TYPING_TIME_LIMIT) {
        printf("\nTime's up! You took too long to type the sentence.\n");
    } else {
        // Calculate accuracy and speed
        int totalChars = strlen(textToType);
        int correctChars = 0;

        for (int i = 0; i < totalChars; i++) {
            if (userInput[i] == textToType[i]) {
                correctChars++;
            }
        }

        double accuracy = ((double)correctChars / totalChars) * 100;
        double speed = (totalChars / (elapsed / 60)); // Characters per minute

        printf("\nResults:\n");
        printf("Elapsed Time: %.2f seconds\n", elapsed);
        printf("Typing Speed: %.2f characters per minute\n", speed);
        printf("Accuracy: %.2f%%\n", accuracy);
    }
}

// Main function
int main() {
    displayInstructions();

    char again;
    do {
        const char *textToType = getRandomText();
        measureTypingSpeed(textToType);

        printf("\nDo you want to try again? (y/n): ");
        scanf(" %c", &again);
        getchar(); // Consume newline character after scanning for char
    } while (again == 'y' || again == 'Y');

    printf("Thank you for participating in the Typing Speed Test! Goodbye!\n");
    return 0;
}