//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define TEXT_SIZE 512
#define PROMPT_SIZE 128
#define MAX_TEXT_LENGTH 256

void clearScreen() {
    printf("\033[H\033[J");
}

void showInstructions() {
    printf("Welcome to the Typing Speed Test!\n");
    printf("Type the following text as quickly and accurately as you can.\n\n");
}

void displayText(const char* text) {
    printf("%s\n\n", text);
}

void getTypingInput(char* inputBuffer, int bufferSize) {
    printf("Start typing (press Enter to finish): \n");
    fgets(inputBuffer, bufferSize, stdin);
    inputBuffer[strcspn(inputBuffer, "\n")] = 0; // Remove newline character
}

double calculateSpeed(int characterCount, double timeInSeconds) {
    return (characterCount / 5.0) / (timeInSeconds / 60.0); // Words per minute (WPM)
}

int calculateAccuracy(const char* originalText, const char* typedText) {
    int correctCharacters = 0;
    int originalLength = strlen(originalText);
    
    for (int i = 0; i < originalLength; ++i) {
        if (originalText[i] == typedText[i]) {
            correctCharacters++;
        }
    }

    return (correctCharacters * 100) / originalLength; // Accuracy percentage
}

const char* peacefulText() {
    return "In the heart of nature, one finds solace and tranquility. "
           "The whisper of the wind through the trees sings a gentle melody. "
           "Soft rays of sunlight dance upon the leaves, creating a wondrous tapestry. "
           "Take a deep breath, feel the serenity, and let your soul wander. "
           "Every moment is a gift, a chance to connect with our surroundings. "
           "As you type, imagine the beauty of the world around you.";
}

int main() {
    clearScreen();
    showInstructions();
    
    const char* textToType = peacefulText();
    displayText(textToType);
    
    char userInput[MAX_TEXT_LENGTH];
    clock_t startTime, endTime;

    startTime = clock();
    getTypingInput(userInput, sizeof(userInput));
    endTime = clock();

    double timeTaken = (double)(endTime - startTime) / CLOCKS_PER_SEC;
    int characterCount = strlen(userInput);
    
    double typingSpeed = calculateSpeed(characterCount, timeTaken);
    int accuracy = calculateAccuracy(textToType, userInput);

    printf("\nTime Taken: %.2f seconds\n", timeTaken);
    printf("Typing Speed: %.2f WPM\n", typingSpeed);
    printf("Accuracy: %d%%\n", accuracy);
    
    return 0;
}