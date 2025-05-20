//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_CHARS 256
#define TEST_DURATION 30

void clearScreen() {
    // Clear console screen
    printf("\033[H\033[J");
}

void displayHeader() {
    clearScreen();
    printf("=========================================\n");
    printf("           A Romantic Typing Test        \n");
    printf("=========================================\n");
    printf("Type the given text as quickly as you can.\n");
    printf("You have %d seconds to demonstrate your love!\n", TEST_DURATION);
    printf("=========================================\n\n");
}

char* getRandomRomanticQuote() {
    // Array of romantic quotes
    char *quotes[] = {
        "I love you not only for what you are, but for what I am when I am with you.",
        "You are my sun, my moon, and all my stars.",
        "Every love story is beautiful, but ours is my favorite.",
        "I have waited for this opportunity for more than half a century, to repeat to you once again my vow of eternal fidelity and everlasting love.",
        "Love is composed of a single soul inhabiting two bodies."
    };

    // Randomly select a quote
    srand(time(NULL));
    return quotes[rand() % (sizeof(quotes) / sizeof(quotes[0]))];
}

void waitForUserToStart() {
    printf("Press Enter to start your romantic journey...\n");
    getchar();
}

void startTypingTest(char *quote) {
    char userInput[MAX_CHARS];
    int charsTyped = 0;

    printf("Your quote to type:\n");
    printf("\"%s\"\n\n", quote);
    printf("Typing starts in...\n");
    
    for(int i = 3; i > 0; i--) {
        printf("%d...\n", i);
        sleep(1);
    }

    time_t startTime = time(NULL);
    printf("\nGo! Type now:\n");

    // Start reading user input
    while(time(NULL) - startTime < TEST_DURATION && charsTyped < MAX_CHARS) {
        if (fgets(userInput, MAX_CHARS, stdin)) {
            charsTyped += strlen(userInput);
        }
    }

    printf("Time's up! You've typed a total of %d characters.\n", charsTyped);
}

void displayResults(int charsTyped) {
    float wpm = (charsTyped / 5.0) / (TEST_DURATION / 60.0); // Assume 5 characters per word

    printf("=========================================\n");
    printf("          Your Typing Test Results       \n");
    printf("=========================================\n");
    printf("Characters Typed: %d\n", charsTyped);
    printf("Words Per Minute: %.2f\n", wpm);
    printf("=========================================\n");
}

int main() {
    int runAgain = 1;

    while(runAgain) {
        displayHeader();
        char *quote = getRandomRomanticQuote();
        waitForUserToStart();
        startTypingTest(quote);
        displayResults(strlen(quote)); // For simplicity, measure the length of the quote, you can enhance this!

        printf("Would you like to try again? (1 for Yes, 0 for No): ");
        scanf("%d", &runAgain);
        getchar(); // Clear newline from buffer
    }

    printf("Thank you for joining this romantic typing adventure. Until next time!\n");
    return 0;
}