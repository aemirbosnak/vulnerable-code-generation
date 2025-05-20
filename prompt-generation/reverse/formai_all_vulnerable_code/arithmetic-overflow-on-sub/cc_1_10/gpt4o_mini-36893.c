//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_LENGTH 256

void clearScreen() {
    // Clear the terminal screen
    printf("\033[H\033[J");
}

void displayInstructions() {
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be presented with a sentence to type.\n");
    printf("Your typing speed will be calculated based on the accuracy and time taken.\n");
    printf("Press ENTER to start the test...\n");
    getchar();
}

void showSentence(const char *sentence) {
    printf("Type the following sentence:\n");
    printf("\"%s\"\n\n", sentence);
}

int main() {
    const char *sentence = "The quick brown fox jumps over the lazy dog.";
    char typed[MAX_LENGTH];
    clock_t start, end;
    double cpu_time_used;

    // Clear the screen
    clearScreen();
    
    // Display instructions
    displayInstructions();
    clearScreen();
    
    // Show the sentence
    showSentence(sentence);
    
    // Start the timer
    start = clock();
    
    // Get the user's input
    printf("Your input: ");
    fgets(typed, MAX_LENGTH, stdin);
    
    // Stop the timer
    end = clock();
    
    // Calculate the time taken
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    // Remove newline character from input
    size_t len = strlen(typed);
    if (len > 0 && typed[len - 1] == '\n') {
        typed[len - 1] = '\0';
    }
    
    // Calculate accuracy
    int correctCharacters = 0;
    for (int i = 0; i < strlen(sentence); i++) {
        if (i < strlen(typed) && sentence[i] == typed[i]) {
            correctCharacters++;
        }
    }

    // Calculate typing speed (words per minute)
    int wordCount = 9; // Number of words in the test sentence
    double speed = (wordCount / cpu_time_used) * 60.0;

    // Display results
    clearScreen();
    printf("Results:\n");
    printf("Typed Sentence: \"%s\"\n", typed);
    printf("Reference Sentence: \"%s\"\n", sentence);
    printf("Time taken: %.2f seconds\n", cpu_time_used);
    printf("Correct characters: %d out of %ld\n", correctCharacters, strlen(sentence));
    
    if (correctCharacters == strlen(sentence)) {
        printf("Accuracy: 100%%\n");
    } else {
        printf("Accuracy: %.2f%%\n", (double)correctCharacters / strlen(sentence) * 100);
    }
    
    printf("Typing Speed: %.2f words per minute\n", speed);
    
    return 0;
}