//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_SENTENCES 5
#define MAX_LENGTH 256

// Function prototypes
void displayInstructions();
void generateRandomSentence(char *sentence, int length);
void calculateSpeed(time_t start, time_t end, int wordsTyped);
void toLowerCase(char *str);

int main() {
    char *sentences[MAX_SENTENCES] = {
        "The quick brown fox jumps over the lazy dog.",
        "Pack my box with five dozen liquor jugs.",
        "How razorback-jumping frogs can level six piqued gymnasts!",
        "The five boxing wizards jump quickly.",
        "Jinxed wizards pluck ivy from the big quilt."
    };

    char *userInput = malloc(MAX_LENGTH * sizeof(char));
    if (userInput == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    srand(time(NULL));
    displayInstructions();
    
    // Select a random sentence
    int randomIndex = rand() % MAX_SENTENCES;
    char *selectedSentence = sentences[randomIndex];

    printf("\nType the following sentence:\n\"%s\"\n\n", selectedSentence);

    time_t startTime = time(NULL);
    printf("Start typing: ");
    fgets(userInput, MAX_LENGTH, stdin);
    time_t endTime = time(NULL);

    // Remove the newline character from user input
    userInput[strcspn(userInput, "\n")] = 0;

    // Convert both user input and sentence to lowercase for comparison
    char *userInputLower = malloc(MAX_LENGTH * sizeof(char));
    if (userInputLower == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        free(userInput);
        return EXIT_FAILURE;
    }
    strcpy(userInputLower, userInput);
    toLowerCase(userInputLower);
    
    char *sentenceLower = malloc(MAX_LENGTH * sizeof(char));
    if (sentenceLower == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        free(userInput);
        free(userInputLower);
        return EXIT_FAILURE;
    }
    strcpy(sentenceLower, selectedSentence);
    toLowerCase(sentenceLower);

    // Check if the user's input matches the selected sentence
    if (strcmp(userInputLower, sentenceLower) == 0) {
        printf("Correct! Well done.\n");
    } else {
        printf("Incorrect. The correct sentence was:\n\"%s\"\n", selectedSentence);
    }

    // Calculate and display the typing speed
    int wordCount = 0;
    char *token = strtok(userInput, " ");
    while (token != NULL) {
        wordCount++;
        token = strtok(NULL, " ");
    }

    calculateSpeed(startTime, endTime, wordCount);

    // Free allocated memory
    free(userInput);
    free(userInputLower);
    free(sentenceLower);

    return 0;
}

void displayInstructions() {
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be presented with a random sentence to type.\n");
    printf("Your speed will be calculated in words per minute (WPM).\n");
    printf("Press ENTER to start...\n");
    getchar();
}

void calculateSpeed(time_t start, time_t end, int wordsTyped) {
    double duration = difftime(end, start);
    double minutesTaken = duration / 60;
    
    if (minutesTaken > 0) {
        double wpm = wordsTyped / minutesTaken;
        printf("You typed %d words in %.2f seconds.\n", wordsTyped, duration);
        printf("Your typing speed is %.2f words per minute.\n", wpm);
    } else {
        printf("It seems like you typed too quickly!\n");
    }
}

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}