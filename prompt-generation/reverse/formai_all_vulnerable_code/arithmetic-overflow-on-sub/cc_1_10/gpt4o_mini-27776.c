//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_PHRASES 10
#define MAX_LENGTH 256

const char* phrases[MAX_PHRASES] = {
    "The quick brown fox jumps over the lazy dog.",
    "A journey of a thousand miles begins with a single step.",
    "To be or not to be, that is the question.",
    "All that glitters is not gold.",
    "In the middle of difficulty lies opportunity.",
    "Success is not final, failure is not fatal: It is the courage to continue that counts.",
    "What we think, we become.",
    "The greatest glory in living lies not in never falling, but in rising every time we fall.",
    "Life is what happens when you're busy making other plans.",
    "To live is the rarest thing in the world. Most people exist, that is all."
};

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void printInstructions() {
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be given a phrase to type.\n");
    printf("Try to type it as quickly and accurately as possible.\n");
    printf("Press Enter to start...\n");
    clearInputBuffer();
}

int main() {
    srand(time(NULL));
    int randomIndex = rand() % MAX_PHRASES;
    const char* selectedPhrase = phrases[randomIndex];
    char userInput[MAX_LENGTH];
    
    printInstructions();

    printf("\nType this phrase:\n");
    printf("\"%s\"\n\n", selectedPhrase);

    clock_t start = clock();
    printf("Start typing: ");
    
    fgets(userInput, MAX_LENGTH, stdin);
    // Remove newline character if present
    userInput[strcspn(userInput, "\n")] = 0;
    clock_t end = clock();

    double timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("You took %.2f seconds to type.\n", timeTaken);

    // Calculate accuracy
    int correctChars = 0;
    int totalChars = strlen(selectedPhrase);
    
    for (int i = 0; i < strlen(userInput) && i < totalChars; i++) {
        if (userInput[i] == selectedPhrase[i]) {
            correctChars++;
        }
    }

    double accuracy = (double)correctChars / totalChars * 100;
    printf("Your accuracy: %.2f%%\n", accuracy);

    double wpm = (correctChars / 5.0) / (timeTaken / 60.0);
    printf("Your typing speed: %.2f words per minute (WPM)\n", wpm);

    return 0;
}