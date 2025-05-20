//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_QUOTES 5
#define MAX_LENGTH 256

// Function prototypes
void displayInstructions();
void selectRandomQuote(char* quote);
void getCurrentTime(double* startTime, double* endTime);
void calculateTypingSpeed(double startTime, double endTime, int wordCount);
int countWords(const char* str);
void clearInputBuffer();

const char* quotes[MAX_QUOTES] = {
    "The only way to do great work is to love what you do.",
    "The best way to predict the future is to create it.",
    "Life is what happens when you're busy making other plans.",
    "You only live once, but if you do it right, once is enough.",
    "In the end, we will remember not the words of our enemies, but the silence of our friends."
};

int main() {
    char typedQuote[MAX_LENGTH];
    char selectedQuote[MAX_LENGTH];
    double startTime, endTime;

    displayInstructions();
    selectRandomQuote(selectedQuote);

    printf("\nType the following quote:\n\n%s\n\n", selectedQuote);
    
    getCurrentTime(&startTime, &endTime);

    printf("Start typing: ");
    fgets(typedQuote, sizeof(typedQuote), stdin);

    // Remove newline character from the input
    typedQuote[strcspn(typedQuote, "\n")] = 0;

    getCurrentTime(&startTime, &endTime);

    // Calculate typing speed
    int wordCount = countWords(typedQuote);
    calculateTypingSpeed(startTime, endTime, wordCount);

    return 0;
}

void displayInstructions() {
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be shown a quote and you have to type it as quickly as possible.\n");
    printf("Your typing speed will be calculated in words per minute (WPM).\n");
    printf("Press Enter to start...\n");
    clearInputBuffer();
}

void selectRandomQuote(char* quote) {
    srand(time(NULL));
    int index = rand() % MAX_QUOTES;
    strcpy(quote, quotes[index]);
}

void getCurrentTime(double* startTime, double* endTime) {
    if (!startTime) {
        *startTime = (double)clock() / CLOCKS_PER_SEC;
    } else {
        *endTime = (double)clock() / CLOCKS_PER_SEC;
    }
}

void calculateTypingSpeed(double startTime, double endTime, int wordCount) {
    double totalTime = endTime - startTime;
    if (totalTime <= 0) totalTime = 1; // prevent division by zero
    double wpm = (wordCount / totalTime) * 60; // convert to WPM

    printf("\nYour typing speed is: %.2f WPM\n", wpm);
}

int countWords(const char* str) {
    int count = 0;
    int inWord = 0;
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (isspace(str[i])) {
            inWord = 0;
        } else if (inWord == 0) {
            inWord = 1;
            count++;
        }
    }
    return count;
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}