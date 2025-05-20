//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRING_LENGTH 256
#define TEST_DURATION 30

// Function to show a beautiful romance quote
void displayQuote() {
    const char *quote = "In the melody of your words, my heart finds its rhythm.";
    printf("%s\n", quote);
}

// Function to generate a random romantic sentence for the typing test
void generateSentence(char *sentence) {
    const char *romanticSentences[] = {
        "You are the light in my darkness.",
        "Your smile ignites my soul.",
        "With every beat of my heart, I love you more.",
        "Your laughter is my favorite sound.",
        "In your eyes, I see my forever.",
        "Our love story is my favorite fairy tale.",
        "You are my dream that I never want to wake up from.",
        "Every moment with you is a treasure.",
        "My heart is a canvas painted with your love.",
        "With you, I am home."
    };

    int index = rand() % (sizeof(romanticSentences) / sizeof(romanticSentences[0]));
    strcpy(sentence, romanticSentences[index]);
}

// Function to calculate typing speed
void calculateTypingSpeed(int charactersTyped, double timeTaken) {
    double speed = (charactersTyped / timeTaken) * 60; // Calculating speed in words per minute
    printf("Your typing speed is: %.2f words per minute.\n", speed / 5.0); // assuming 5 characters per word
}

int main() {
    char romanticSentence[MAX_STRING_LENGTH];
    char userInput[MAX_STRING_LENGTH];
    time_t startTime, endTime;

    // Seed the random number generator
    srand(time(NULL));

    // Display a romance quote
    displayQuote();

    // Generate a romantic sentence
    generateSentence(romanticSentence);
    printf("Type the following sentence within %d seconds:\n", TEST_DURATION);
    printf("\"%s\"\n", romanticSentence);

    // Start the typing test
    startTime = time(NULL);
    
    printf("Begin typing: ");
    fgets(userInput, MAX_STRING_LENGTH, stdin);
    
    // Get the end time
    endTime = time(NULL);

    // Calculate time taken
    double timeTaken = difftime(endTime, startTime);
    
    // Check if the time taken exceeds the test duration
    if (timeTaken > TEST_DURATION) {
        printf("Time's up! You took too long to type the sentence.\n");
    } else {
        // Trimming the user input to remove newline character
        userInput[strcspn(userInput, "\n")] = 0;
    
        // Compare user input with generated sentence
        if (strcmp(userInput, romanticSentence) == 0) {
            printf("Bravo! You typed it perfectly!\n");
        } else {
            printf("Oh no! There were some mistakes. Let's check your input:\n");
            printf("You typed: \"%s\"\n", userInput);
            printf("The correct sentence was: \"%s\"\n", romanticSentence);
        }
    }

    // Calculate the typing speed
    int charactersTyped = strlen(userInput);
    calculateTypingSpeed(charactersTyped, timeTaken);

    printf("Thank you for joining this romantic typing test!\n");
    return 0;
}