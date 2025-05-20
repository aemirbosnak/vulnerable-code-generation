//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>

#define SENTENCES 3
#define MAX_SENTENCE_LENGTH 100

// Function to get user's input without echoing to console
char getch() {
    char ch;
    struct termios old, new;

    tcgetattr(0, &old);
    new = old;
    new.c_lflag &= ~ICANON;
    new.c_lflag &= ~ECHO;
    tcsetattr(0, TCSANOW, &new);

    ch = getchar();

    tcsetattr(0, TCSANOW, &old);
    return ch;
}

int main() {
    // Array of test sentences
    char testSentences[SENTENCES][MAX_SENTENCE_LENGTH] = {
        "The quick brown fox jumped over the lazy dog.",
        "Jackdaws love my big sphinx of quartz.",
        "Pack my box with five dozen liquor jugs."
    };
    // Variables for tracking test results
    int sentenceIndex, charIndex, mistakes, accuracy;
    double elapsedSeconds, wpm;

    // Welcome message and instructions
    printf("Welcome to the Typing Speed Test!\n\n");
    printf("You will be asked to type three different sentences as accurately and quickly as possible.\n");
    printf("Press enter to begin.\n\n");
    getchar();

    // Loop through each of the test sentences
    for (sentenceIndex = 0; sentenceIndex < SENTENCES; sentenceIndex++) {
        printf("Sentence %d:\n%s\n\n", sentenceIndex+1, testSentences[sentenceIndex]);

        // Variables for measuring time and user input
        clock_t start = clock(), end;
        char userInput[MAX_SENTENCE_LENGTH];

        // Get user input
        fgets(userInput, MAX_SENTENCE_LENGTH, stdin);

        // Calculate elapsed time and words per minute (assuming 5 characters per word)
        end = clock();
        elapsedSeconds = (double)(end - start) / CLOCKS_PER_SEC;
        wpm = (strlen(userInput) / 5.0) / (elapsedSeconds / 60.0);

        // Compare user input to the correct sentence and count mistakes
        mistakes = 0;
        for (charIndex = 0; charIndex < strlen(userInput); charIndex++) {
            if (userInput[charIndex] != testSentences[sentenceIndex][charIndex]) {
                mistakes++;
            }
        }

        // Calculate accuracy as a percentage
        accuracy = (int)((1.0 - ((double)mistakes / strlen(testSentences[sentenceIndex]))) * 100);

        // Print test results
        printf("Time elapsed: %.2f seconds\n", elapsedSeconds);
        printf("Words per minute: %.2f\n", wpm);
        printf("Accuracy: %d%%\n\n", accuracy);

        // Pause for 1 second before moving on to the next sentence
        sleep(1);
    }

    // Final message and instructions
    printf("Congratulations! You have completed the Typing Speed Test.\n\n");
    printf("Press any key to exit.\n");
    getch();

    return 0;
}