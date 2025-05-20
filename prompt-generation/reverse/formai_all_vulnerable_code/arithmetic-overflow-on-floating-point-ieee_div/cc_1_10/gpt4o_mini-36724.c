//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_TEXT_LENGTH 500
#define MAX_INPUT_LENGTH 600
#define TEXT_COUNT 5

const char *sampleTexts[TEXT_COUNT] = {
    "The quick brown fox jumps over the lazy dog.",
    "To be or not to be, that is the question.",
    "A journey of a thousand miles begins with a single step.",
    "In the middle of difficulty lies opportunity.",
    "Success is not final; failure is not fatal: It is the courage to continue that counts."
};

void clearScreen() {
    // Clear the terminal screen
    printf("\033[H\033[J");
}

void displayText(const char *text) {
    printf("Type the following text:\n\n");
    printf("\"%s\"\n\n", text);
}

void getUserInput(char *userInput) {
    printf("Your input: ");
    fgets(userInput, MAX_INPUT_LENGTH, stdin);
    // Remove the trailing newline character if it's there
    size_t len = strlen(userInput);
    if (len > 0 && userInput[len - 1] == '\n') {
        userInput[len - 1] = '\0';
    }
}

void calculateSpeed(double timeTaken, int textLength) {
    double speed = (textLength / 5.0) / (timeTaken / 60.0); // words per minute
    printf("Your typing speed: %.2f words per minute\n", speed);
}

int main() {
    char userInput[MAX_INPUT_LENGTH];
    int selectedTextIndex;
    double startTime, endTime;

    // Seed the random number generator
    srand(time(NULL));

    // Main loop
    while (1) {
        // Clear screen
        clearScreen();

        // Select a random text
        selectedTextIndex = rand() % TEXT_COUNT;
        const char *selectedText = sampleTexts[selectedTextIndex];

        // Display the text to the user
        displayText(selectedText);

        // Start the timer
        printf("Press Enter to start...\n");
        getchar(); // Wait for the user to start
        startTime = (double)clock() / CLOCKS_PER_SEC;

        // Get the user input
        getUserInput(userInput);

        // Stop the timer
        endTime = (double)clock() / CLOCKS_PER_SEC;
        double timeTaken = endTime - startTime;

        // Calculate the typing speed
        if (strcmp(userInput, selectedText) == 0) {
            printf("Correct input! Well done!\n");
        } else {
            printf("Your input didn't match. Keep practicing!\n");
        }

        calculateSpeed(timeTaken, strlen(selectedText));

        // Prompt to continue or quit
        char choice;
        printf("\nDo you want to try again? (y/n): ");
        choice = getchar();
        while (getchar() != '\n'); // Clear buffer

        if (choice != 'y' && choice != 'Y') {
            break; // Exit the loop
        }
    }

    printf("Thank you for playing the typing speed test!\n");

    return 0;
}