//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define TEXT "The quick brown fox jumps over the lazy dog."
#define BUFFER_SIZE 256

void clearScreen() {
    printf("\033[H\033[J");  // ANSI escape code to clear the screen
}

void printInstructions() {
    printf("Typing Speed Test\n");
    printf("==================\n");
    printf("Type the following text as fast as you can:\n\n");
    printf("\"%s\"\n\n", TEXT);
    printf("Press Enter when you are ready to start.\n");
    getchar();  // Wait for the user to press Enter
}

void calculateSpeed(int elapsedTime, int wordCount) {
    float minutes = elapsedTime / 60.0;
    float wpm = wordCount / minutes;
    printf("You typed %d words in %d seconds.\n", wordCount, elapsedTime);
    printf("Your typing speed is: %.2f WPM\n", wpm);
}

void getUserInput(char *input) {
    time_t start, end;
    start = time(NULL);
    
    printf("\nStart typing:\n");
    fgets(input, BUFFER_SIZE, stdin);
    end = time(NULL);
    
    int elapsed_time = (int)difftime(end, start);
    
    // Count words by splitting the input
    int word_count = 0;
    char *token = strtok(input, " \n");
    
    while (token != NULL) {
        word_count++;
        token = strtok(NULL, " \n");
    }
    
    calculateSpeed(elapsed_time, word_count);
}

int main() {
    char userInput[BUFFER_SIZE];
    clearScreen();
    printInstructions();
    getUserInput(userInput);

    printf("\nThank you for participating!\n");
    return 0;
}