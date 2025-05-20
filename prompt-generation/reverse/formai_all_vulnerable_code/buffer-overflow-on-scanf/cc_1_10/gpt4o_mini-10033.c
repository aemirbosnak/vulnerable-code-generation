//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define TEXT_COUNT 5
#define MAX_TEXT_LENGTH 256

const char *texts[TEXT_COUNT] = {
    "The quick brown fox jumps over the lazy dog.",
    "Pack my box with five dozen liquor jugs.",
    "How razorback-jumping frogs can level six piqued gymnasts!",
    "Just kidding around with code can lead to a perfect line.",
    "A journey of a thousand miles begins with a single step."
};

void clearScreen() {
    printf("\033[H\033[J");
}

void displayInstructions() {
    printf("===== C Typing Speed Test =====\n");
    printf("Type the following text as fast as you can:\n");
}

void displayText(const char *text) {
    printf("\n\"%s\"\n", text);
}

int getTypingSpeed(double elapsedTime, int charCount) {
    return (charCount / elapsedTime) * 60; // Characters per minute
}

void startTypingTest() {
    clearScreen();
    displayInstructions();
    
    srand(time(NULL));
    int randomIndex = rand() % TEXT_COUNT;  // Randomly select a text
    const char *selectedText = texts[randomIndex];

    displayText(selectedText);
    
    char userInput[MAX_TEXT_LENGTH];
    clock_t startTime = clock();
    
    printf("\nStart typing: ");
    fgets(userInput, MAX_TEXT_LENGTH, stdin);
    
    clock_t endTime = clock();
    double elapsedTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
    
    // Remove newline if present
    size_t len = strlen(userInput);
    if (len > 0 && userInput[len - 1] == '\n') {
        userInput[len - 1] = '\0';
    }

    printf("\nYou typed: \"%s\"\n", userInput);
    printf("Expected: \"%s\"\n", selectedText);
    
    int correctChars = 0;
    for (int i = 0; i < strlen(selectedText) && i < strlen(userInput); i++) {
        if (userInput[i] == selectedText[i]) {
            correctChars++;
        }
    }

    int speed = getTypingSpeed(elapsedTime, strlen(userInput));
    
    printf("Time taken: %.2f seconds\n", elapsedTime);
    printf("Typing speed: %d characters per minute\n", speed);
    printf("Accuracy: %.2f%%\n", ((float)correctChars / strlen(selectedText)) * 100);
}

int main() {
    char playAgain;
    do {
        startTypingTest();
        printf("\nDo you want to try again? (y/n): ");
        scanf(" %c", &playAgain);
        clearScreen();
    } while (playAgain == 'y' || playAgain == 'Y');
    
    printf("Thank you for playing the C Typing Speed Test!\n");
    return 0;
}