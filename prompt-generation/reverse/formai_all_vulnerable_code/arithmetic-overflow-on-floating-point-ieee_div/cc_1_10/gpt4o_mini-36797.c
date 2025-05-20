//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_TEXT_LENGTH 500
#define MAX_ATTEMPTS 5
#define TEXTS_COUNT 3

const char* texts[TEXTS_COUNT] = {
    "The quick brown fox jumps over the lazy dog.",
    "Programming in C is both an art and a science.",
    "Typing speed tests can help to improve productivity."
};

void clearScreen() {
    // ANSI escape codes to clear the screen
    printf("\033[H\033[J");
}

void printIntroduction() {
    printf("=======================================\n");
    printf("   WELCOME TO THE TYPING SPEED TEST   \n");
    printf("=======================================\n");
    printf("You will be shown a sentence to type.\n");
    printf("Try to type it as quickly and accurately as possible!\n");
    printf("You have %d attempts to improve your score.\n", MAX_ATTEMPTS);
    printf("Good luck!\n");
}

void printTextToType(const char *text) {
    printf("Type the following sentence:\n");
    printf("\"%s\"\n", text);
}

int calculateTypingSpeed(double timeSpent) {
    // Assuming an average of 5 characters per word
    return (int)((MAX_TEXT_LENGTH / 5) / (timeSpent / 60));
}

void typingTest() {
    char userInput[MAX_TEXT_LENGTH];
    int attempt;
    
    for (attempt = 1; attempt <= MAX_ATTEMPTS; attempt++) {
        int randomIndex = rand() % TEXTS_COUNT;
        printTextToType(texts[randomIndex]);
        
        clock_t startTime = clock();
        printf("Your input: ");
        fgets(userInput, MAX_TEXT_LENGTH, stdin);
        clock_t endTime = clock();
        
        // Remove newline character from fgets
        userInput[strcspn(userInput, "\n")] = 0;

        double timeSpent = (double)(endTime - startTime) / CLOCKS_PER_SEC;

        if (strcmp(userInput, texts[randomIndex]) == 0) {
            int speed = calculateTypingSpeed(timeSpent);
            printf("Fantastic! You typed it correctly in %.2lf seconds.\n", timeSpent);
            printf("Your typing speed is: %d words per minute!\n\n", speed);
        } else {
            printf("Oops! That was not quite right. Try again!\n\n");
        }

        if (attempt < MAX_ATTEMPTS) {
            printf("Press Enter to continue to the next attempt...\n");
            getchar();
            clearScreen();
        }
    }

    printf("Thank you for participating!\n");
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    clearScreen();
    printIntroduction();
    typingTest();
    return 0;
}