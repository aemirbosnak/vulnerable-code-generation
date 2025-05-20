//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_PHRASES 5
#define BUFFER_SIZE 256
#define TIME_LIMIT 30 // seconds

const char *phrases[MAX_PHRASES] = {
    "The quick brown fox jumps over the lazy dog.",
    "Pack my box with five dozen liquor jugs.",
    "How razorback-jumping frogs can level six piqued gymnasts!",
    "Just before we quit, let’s ring the old cow bell.",
    "A big box of mixed biscuits, a mixed box of big biscuits."
};

void displayInstructions() {
    printf("Welcome to the Curious Typing Speed Test!\n");
    printf("You will be given a phrase to type.\n");
    printf("You have %d seconds to type it as fast as you can.\n", TIME_LIMIT);
    printf("Let’s see how fast you can go!\n\n");
}

void selectRandomPhrase(char *selectedPhrase) {
    int randomIndex = rand() % MAX_PHRASES;
    strcpy(selectedPhrase, phrases[randomIndex]);
}

int main() {
    srand(time(NULL));
    displayInstructions();

    char selectedPhrase[BUFFER_SIZE];
    selectRandomPhrase(selectedPhrase);

    printf("Your phrase is: \n\"%s\"\n\n", selectedPhrase);

    printf("Press Enter when you are ready to start...");
    getchar();

    printf("Go! Start typing the phrase...\n\n");

    clock_t startTime = clock();
    char userInput[BUFFER_SIZE];

    // Measure the time taken to type the phrase
    fgets(userInput, BUFFER_SIZE, stdin);
    clock_t endTime = clock();

    // Remove the newline character from the input
    userInput[strcspn(userInput, "\n")] = '\0';

    // Calculate the elapsed time
    double elapsedTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;

    // Calculate typing speed in words per minute
    int typedWords = 0;
    char *token = strtok(userInput, " ");
    while(token != NULL) {
        typedWords++;
        token = strtok(NULL, " ");
    }
    double typingSpeed = (typedWords / elapsedTime) * 60;

    // Display results
    printf("\nYou've finished typing!\n");
    printf("You typed: \"%s\"\n", userInput);
    printf("It took you %.2f seconds\n", elapsedTime);
    printf("Your typing speed is: %.2f words per minute\n", typingSpeed);

    if (strcmp(userInput, selectedPhrase) == 0) {
        printf("Congratulations! You typed the phrase correctly!\n");
    } else {
        printf("Oops! The phrase was not typed correctly.\n");
        printf("The correct phrase was: \"%s\"\n", selectedPhrase);
    }

    printf("Thank you for participating in the Curious Typing Speed Test!\n");
    return 0;
}