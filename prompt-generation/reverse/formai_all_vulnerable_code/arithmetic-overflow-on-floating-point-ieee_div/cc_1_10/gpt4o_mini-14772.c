//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_BUFFER 1024
#define TIME_LIMIT 30 // 30 seconds time limit
#define POEM "Roses are red,\nViolets are blue,\nDon't be a fool,\nJust type what is true."

void displayInstructions() {
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will have to type the following poem as fast as you can:\n\n");
    printf("%s\n", POEM);
    printf("\nYou have %d seconds. Press enter to start.\n", TIME_LIMIT);
    getchar(); // Wait for user to press enter
}

double calculateSpeed(int wordCount, double timeTaken) {
    return (wordCount / timeTaken) * 60; // Speed in WPM
}

void getUserInput(char *inputBuffer) {
    printf("Start typing now:\n");
    fgets(inputBuffer, MAX_BUFFER, stdin); // Read user input
}

int countWords(const char *input) {
    int count = 0;
    const char *token = strtok((char *)input, " \n");
    while (token != NULL) {
        count++;
        token = strtok(NULL, " \n");
    }
    return count;
}

void calculateAndDisplayResults(double timeTaken, const char *userInput) {
    int wordCount = countWords(userInput);
    double speed = calculateSpeed(wordCount, timeTaken);

    printf("\nTime taken: %.2f seconds\n", timeTaken);
    printf("Words typed: %d\n", wordCount);
    printf("Your typing speed: %.2f words per minute\n", speed);

    if (speed < 20) {
        printf("Keep practicing! Your speed is quite low.\n");
    } else if (speed < 40) {
        printf("You're doing okay, but there's room for improvement.\n");
    } else {
        printf("Great job! You're typing at a good speed.\n");
    }
}

int main() {
    char userInput[MAX_BUFFER];
    displayInstructions();
    
    time_t startTime = time(NULL);
    getUserInput(userInput);
    time_t endTime = time(NULL);
    
    double timeTaken = difftime(endTime, startTime);
    calculateAndDisplayResults(timeTaken, userInput);
    
    return 0;
}