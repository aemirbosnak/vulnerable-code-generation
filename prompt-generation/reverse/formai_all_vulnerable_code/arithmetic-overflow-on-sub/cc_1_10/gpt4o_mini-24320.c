//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_TEXT_LENGTH 512
#define PROMPT_LENGTH 256

void displayText(const char *text) {
    printf("\n--- Type the following text as quickly as you can: ---\n\n");
    printf("%s\n\n", text);
}

void getUserInput(char *input, int length) {
    printf("Your input: ");
    fgets(input, length, stdin);
    input[strcspn(input, "\n")] = 0; // Remove trailing newline
}

double calculateTimeDifference(clock_t start, clock_t end) {
    return (double)(end - start) / CLOCKS_PER_SEC;
}

int compareStrings(const char *s1, const char *s2) {
    return strcmp(s1, s2);
}

void displayResults(double timeTaken, int correctChars, int totalChars) {
    printf("\n--- Results ---\n");
    printf("Time taken: %.2f seconds\n", timeTaken);
    printf("Correct characters: %d/%d\n", correctChars, totalChars);
    
    if(totalChars > 0) {
        double accuracy = ((double)correctChars / totalChars) * 100;
        printf("Accuracy: %.2f%%\n", accuracy);
    } else {
        printf("Accuracy: 0%%\n");
    }
}

void typingSpeedTest() {
    const char *text = "Elementary, my dear Watson. A criminal mastermind always leaves a clue behind.";
    char userInput[PROMPT_LENGTH];
    int correctChars = 0;

    displayText(text);

    clock_t start = clock();
    getUserInput(userInput, PROMPT_LENGTH);
    clock_t end = clock();

    double timeTaken = calculateTimeDifference(start, end);
    
    for (int i = 0; userInput[i] && text[i]; i++) {
        if (userInput[i] == text[i]) {
            correctChars++;
        }
    }

    displayResults(timeTaken, correctChars, strlen(text));
}

void showInstructions() {
    printf("Welcome to the Typing Speed Test, a peculiar endeavor indeed.\n");
    printf("You shall be given a quote of my own making, and your task shall be to type it as rapidly and accurately as possible.\n");
    printf("Press ENTER when you are ready to begin.\n");
    getchar();
}

int main() {
    printf("Sherlock Holmes Typing Speed Test\n");
    printf("------------------------------------------\n");
    
    showInstructions();

    typingSpeedTest();

    printf("\nThank you for partaking in this cerebral exercise. Until next time, good luck solving mysteries of the mind!\n");

    return 0;
}