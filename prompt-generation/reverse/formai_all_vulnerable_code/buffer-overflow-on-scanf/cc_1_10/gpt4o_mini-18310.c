//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>

#define MAX_LEN 256

void disableBuffering() {
    struct termios settings;
    tcgetattr(STDIN_FILENO, &settings);
    settings.c_lflag &= ~ICANON;
    settings.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &settings);
}

void enableBuffering() {
    struct termios settings;
    tcgetattr(STDIN_FILENO, &settings);
    settings.c_lflag |= ICANON;
    settings.c_lflag |= ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &settings);
}

double getTimeElapsed(clock_t start, clock_t end) {
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

void runTypingTest() {
    const char *text = "The quick brown fox jumps over the lazy dog.";
    char userInput[MAX_LEN];
    clock_t start, end;

    printf("Typing Speed Test\n");
    printf("Type the following sentence:\n");
    printf("\"%s\"\n\n", text);
    
    printf("Press Enter to start...");
    getchar();

    disableBuffering();  // Turn off terminal buffering for real-time input
    start = clock();      // Start the timer

    // Get user input
    fgets(userInput, MAX_LEN, stdin);
    end = clock();        // End the timer
    enableBuffering();    // Re-enable terminal buffering

    // Remove the newline character from user input
    userInput[strcspn(userInput, "\n")] = 0;

    // Calculate time taken
    double timeTaken = getTimeElapsed(start, end);
    int wordCount = 0;

    // Split user input into words
    char *token = strtok(userInput, " ");
    while (token != NULL) {
        wordCount++;
        token = strtok(NULL, " ");
    }

    // Calculate words per minute
    double wpm = (wordCount / timeTaken) * 60;

    printf("\nYou typed: \"%s\"\n", userInput);
    printf("Time taken: %.2f seconds\n", timeTaken);
    printf("Your typing speed: %.2f words per minute\n", wpm);
}

int main() {
    char choice;

    do {
        runTypingTest();
        printf("\nWould you like to try again? (y/n): ");
        scanf(" %c", &choice);
        getchar();  // To consume trailing newline from previous input
    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for participating!\n");
    return 0;
}