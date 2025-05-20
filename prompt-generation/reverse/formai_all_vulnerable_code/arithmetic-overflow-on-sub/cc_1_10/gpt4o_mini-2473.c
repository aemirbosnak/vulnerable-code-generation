//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_TEXT_LENGTH 256
#define TIMER_DURATION 60

void clear_screen() {
    printf("\033[H\033[J");
}

void show_instructions(const char *referenceText) {
    clear_screen();
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will have %d seconds to type the following text:\n\n", TIMER_DURATION);
    printf("\"%s\"\n\n", referenceText);
    printf("Press ENTER to start...\n");
    getchar();
}

void start_timer(int *secondsRemaining) {
    time_t startTime = time(NULL);
    *secondsRemaining = TIMER_DURATION;

    while (*secondsRemaining > 0) {
        sleep(1);
        *secondsRemaining = TIMER_DURATION - (time(NULL) - startTime);
    }
}

int main() {
    const char referenceText[MAX_TEXT_LENGTH] = "The quick brown fox jumps over the lazy dog.";
    char userInput[MAX_TEXT_LENGTH];
    int secondsRemaining;

    show_instructions(referenceText);

    clear_screen();
    printf("Type the text as quickly as you can:\n\n");
    printf("\"%s\"\n\n", referenceText);
    printf("You have %d seconds...\n\n", TIMER_DURATION);

    // Start the timer in a separate thread
    start_timer(&secondsRemaining);
    printf("Time's up! Please stop typing.\n");

    // Collect user input while the timer runs
    printf("Your input:\n");
    fgets(userInput, MAX_TEXT_LENGTH, stdin);
    userInput[strcspn(userInput, "\n")] = 0;  // Remove the newline character

    // Calculate typing speed and accuracy
    int inputLength = strlen(userInput);
    int referenceLength = strlen(referenceText);

    int correct_chars = 0;
    for (int i = 0; i < (inputLength < referenceLength ? inputLength : referenceLength); i++) {
        if (userInput[i] == referenceText[i]) {
            correct_chars++;
        }
    }

    double timeSpent = TIMER_DURATION - secondsRemaining;
    double typingSpeed = (inputLength / 5.0) / (timeSpent / 60.0);  // WPM calculation
    double accuracy = (correct_chars / (double)referenceLength) * 100;

    clear_screen();
    printf("Results:\n");
    printf("Total characters typed: %d\n", inputLength);
    printf("Time spent: %.2f seconds\n", timeSpent);
    printf("Typing Speed: %.2f WPM\n", typingSpeed);
    printf("Accuracy: %.2f%%\n", accuracy);

    return 0;
}