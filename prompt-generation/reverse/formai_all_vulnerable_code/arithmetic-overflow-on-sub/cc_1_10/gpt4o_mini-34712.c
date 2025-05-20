//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_TEXT_LENGTH 1024
#define PROMPT_TEXT "To solve the case, one must type the text below with swiftness and precision:\n"

void displayPrompt(const char *text) {
    printf("%s", PROMPT_TEXT);
    printf("%s\n", text);
}

void clearScreen() {
    // Clear the terminal screen
    printf("\033[H\033[J");
}

double calculateTimeTaken(clock_t start, clock_t end) {
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

void calculateWPM(double timeTaken, int wordCount) {
    // Words per minute = (total words / time in minutes)
    double wpm = (wordCount / timeTaken) * 60.0;
    printf("Your typing speed is: %.2f WPM\n", wpm);
}

int countWords(const char *text) {
    int count = 0;
    char *textCopy = strdup(text); // Duplicate the string to avoid mutating original
    char *word = strtok(textCopy, " ");
    
    while (word != NULL) {
        count++;
        word = strtok(NULL, " ");
    }
    
    free(textCopy); // Free the duplicated string
    return count;
}

void typingTest(const char *text) {
    clearScreen();
    displayPrompt(text);
    
    char userInput[MAX_TEXT_LENGTH];
    printf("\nReady... Set... Type!\n\n");
    
    clock_t startTime = clock();
    fgets(userInput, sizeof(userInput), stdin); // Reading user input
    clock_t endTime = clock();
    
    // Remove newline character from fgets
    userInput[strcspn(userInput, "\n")] = 0;
    
    // Calculate the time taken
    double timeTaken = calculateTimeTaken(startTime, endTime);
    int wordCount = countWords(text);
    
    // Display Results
    if (strcmp(userInput, text) == 0) {
        printf("Well done! You've typed the text correctly.\n");
    } else {
        printf("There were some errors in your typing.\n");
    }
    calculateWPM(timeTaken, wordCount);
    printf("Time taken: %.2f seconds\n", timeTaken);
}

const char *getRandomText() {
    const char *texts[] = {
        "Elementary, my dear Watson. The game's afoot.",
        "When you have eliminated the impossible, whatever remains, however improbable, must be the truth.",
        "To a great mind, nothing is little.",
        "In my personal opinion, the time for action is now.",
        "It is a capital mistake to theorize before one has data.",
        "There is nothing more deceptive than an obvious fact."
    };
    
    // Get a random index to return a random text
    int index = rand() % (sizeof(texts) / sizeof(texts[0]));
    return texts[index];
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    const char *randomText = getRandomText();
    
    printf("Welcome to the Sherlock Holmes Typing Speed Test!\n");
    printf("Prepare yourself for a most intriguing exercise of speed and accuracy.\n");
    
    typingTest(randomText);
    
    printf("\nThank you for participating! Until next time, Watson.\n");
    return 0;
}