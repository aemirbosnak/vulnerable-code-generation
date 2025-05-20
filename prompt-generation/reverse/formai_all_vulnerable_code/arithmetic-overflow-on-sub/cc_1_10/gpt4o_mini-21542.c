//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TEXT_LENGTH 256
#define NUM_TESTS 3

// Function prototypes
void displayInstructions();
void startTest(const char *text);
int calculateWPM(int wordsTyped, double timeSpent);
void provideFeedback(int wpm);

int main() {
    const char *testTexts[NUM_TESTS] = {
        "The quick brown fox jumps over the lazy dog.",
        "Programming is like writing a book. Except, when you miss a single comma, the whole thing makes no sense.",
        "C language is a powerful general-purpose programming language."
    };

    displayInstructions();
    
    for (int i = 0; i < NUM_TESTS; i++) {
        printf("\n--- Test %d: ---\n\n", i + 1);
        startTest(testTexts[i]);
        printf("\n------------------------------------------\n");
    }

    printf("\nThank you for participating! Keep practicing and improve your typing skills!\n");
    return 0;
}

void displayInstructions() {
    printf("Welcome to the Typing Speed Test!\n");
    printf("===================================\n");
    printf("Your goal is to type the given text as fast and as accurately as possible.\n");
    printf("You will have to type each test three times. Let's see how fast you can go!\n");
    printf("Good luck and happy typing!\n");
}

void startTest(const char *text) {
    char userInput[MAX_TEXT_LENGTH];
    int wordsTyped = 0;
    clock_t start, end;

    printf("Text to type: \n\"%s\"\n\n", text);
    printf("Press Enter when you are ready to start typing...\n");
    getchar();  // Wait for the user to press enter

    start = clock();  // Start timer

    printf("Start typing now!\n");
    fgets(userInput, sizeof(userInput), stdin);  // Get user input

    end = clock();  // End timer
    double timeSpent = (double)(end - start) / CLOCKS_PER_SEC;

    // Count words in user input
    char *token = strtok(userInput, " \n");
    while (token != NULL) {
        wordsTyped++;
        token = strtok(NULL, " \n");
    }

    // Calculate and display WPM
    int wpm = calculateWPM(wordsTyped, timeSpent);
    printf("You typed %d words in %.2f seconds.\n", wordsTyped, timeSpent);
    provideFeedback(wpm);
}

int calculateWPM(int wordsTyped, double timeSpent) {
    if (timeSpent == 0) return 0;  // Avoid division by zero
    return (int)((wordsTyped / timeSpent) * 60);  // Calculate words per minute
}

void provideFeedback(int wpm) {
    if (wpm < 20) {
        printf("Keep practicing! Your typing speed is %d WPM. You can do better!\n", wpm);
    } else if (wpm < 40) {
        printf("Good job! Your typing speed is %d WPM. You're getting there!\n", wpm);
    } else if (wpm < 60) {
        printf("Great speed! You've typed at %d WPM. You're a fast typist!\n", wpm);
    } else {
        printf("Incredible! Your typing speed is %d WPM! You're a typing master!\n", wpm);
    }
}