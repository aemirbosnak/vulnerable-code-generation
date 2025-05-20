//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_TEXT_LENGTH 256
#define MAX_INPUT_LENGTH 256

void printInstructions(const char* text) {
    printf("Welcome to the Typing Speed Test!\n");
    printf("Type the following text as fast as you can:\n");
    printf("\"%s\"\n", text);
    printf("Press Enter when you are ready to start...\n");
    getchar(); // Wait for user to press Enter
    printf("\nGo!\n");
    fflush(stdout);
}

void calculateSpeed(time_t start, time_t end, int inputLength) {
    double timeTaken = difftime(end, start);
    double speed = (inputLength / 5.0) / (timeTaken / 60.0); // WPM
    printf("Time taken: %.2f seconds\n", timeTaken);
    printf("Your typing speed is: %.2f words per minute.\n", speed);
}

void testTypingSpeed(const char* text) {
    char input[MAX_INPUT_LENGTH];
    time_t start, end;

    printInstructions(text);

    start = time(NULL);
    fgets(input, MAX_INPUT_LENGTH, stdin);
    end = time(NULL);

    // Remove newline character from input
    input[strcspn(input, "\n")] = 0;

    if (strcmp(input, text) == 0) {
        printf("You typed the text correctly!\n");
    } else {
        printf("There was a mistake in your input.\n");
    }

    calculateSpeed(start, end, strlen(input));
}

const char* getRandomText() {
    const char* texts[] = {
        "The quick brown fox jumps over the lazy dog.",
        "Typing speed tests are a great way to improve your skills.",
        "In a future-proof style, programming is an art.",
        "C is a powerful language that paved the path for many.",
        "Practice makes perfect, don't give up!"
    };
    int count = sizeof(texts) / sizeof(texts[0]);
    return texts[rand() % count];
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    const char* text = getRandomText();

    // Test Typing Speed
    testTypingSpeed(text);

    return 0;
}