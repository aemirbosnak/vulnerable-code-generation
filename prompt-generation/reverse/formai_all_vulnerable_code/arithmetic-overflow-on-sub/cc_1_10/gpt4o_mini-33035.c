//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_TEXT 256
#define TIMER_DURATION 30

const char *sampleTexts[] = {
    "The quick brown fox jumps over the lazy dog.",
    "Pack my box with five dozen liquor jugs.",
    "How razorback-jumping frogs can level six piqued gymnasts!",
    "Bright v lamps and fat pigs jump through the fox's beady eyes.",
    "The five boxing wizards jump quickly."
};

void displayWelcomeMessage() {
    printf("--------------------------------------------------\n");
    printf("              Typing Speed Test                   \n");
    printf("--------------------------------------------------\n");
    printf("Welcome to the ultimate typing challenge!\n");
    printf("You'll have %d seconds to type the following text accurately.\n", TIMER_DURATION);
    printf("Are you ready? Let’s see how fast you can type!\n\n");
}

void selectRandomText(char *text) {
    srand(time(NULL));
    int index = rand() % (sizeof(sampleTexts) / sizeof(sampleTexts[0]));
    strcpy(text, sampleTexts[index]);
}

void startTimer(int *timeElapsed) {
    time_t startTime = time(NULL);
    while ((*timeElapsed = time(NULL) - startTime) < TIMER_DURATION) {
        // Intentionally left empty; just counting down
    }
}

void getUserInput(char *userInput) {
    printf("Type this text:\n");
    printf("--------------------------------------------------\n");
}

void showResults(int correctTyped, int totalTyped, int duration) {
    printf("\n--------------------------------------------------\n");
    printf("Time's up!\n");
    printf("Your results:\n");
    printf("Correctly typed: %d\n", correctTyped);
    printf("Total characters typed: %d\n", totalTyped);
    printf("Typing speed: %.2f characters per second.\n", (float)correctTyped / (float)duration);
    printf("Accuracy: %.2f%%\n", ((float)correctTyped / (float)totalTyped) * 100);
    printf("--------------------------------------------------\n");
}

int main() {
    char sampleText[MAX_TEXT];
    char userInput[MAX_TEXT];
    int timeElapsed = 0;
    int correctTyped = 0;
    int totalTyped = 0;

    displayWelcomeMessage();
    
    selectRandomText(sampleText);
    printf("%s\n", sampleText);

    // Start the timer in a separate thread
    startTimer(&timeElapsed);

    getUserInput(userInput);
    fgets(userInput, MAX_TEXT, stdin);

    totalTyped = strlen(userInput) - 1; // Subtract 1 for newline character

    // Calculate correctly typed characters
    for (int i = 0; i < totalTyped && i < strlen(sampleText); i++) {
        if (userInput[i] == sampleText[i]) {
            correctTyped++;
        }
    }

    showResults(correctTyped, totalTyped, timeElapsed);
    
    return 0;
}