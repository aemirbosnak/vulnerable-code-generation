//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Ada Lovelace
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define MAX_LENGTH 100
#define MAX_TRIES 3

int main() {
    char quote[MAX_LENGTH];
    int quoteLength, i, j, correct, wrong, tries, totalTime;
    double accuracy, wpm;
    time_t startTime, endTime;

    // Welcome message
    printf("*** WELCOME TO THE TYPING SPEED TEST ***\n");
    printf("You will be given a quote to type. You have %d tries to get it right.\n", MAX_TRIES);
    printf("Ready to start? Press Enter to begin.\n");
    getchar();

    // Randomly select a quote from the list
    char *quoteList[] = {
        "If you want to go fast, go alone. If you want to go far, go together.",
        "The best way to predict your future is to create it.",
        "I hear and I forget. I see and I remember. I do and I understand.",
        "The only way to do great work is to love what you do.",
        "Innovation distinguishes between a leader and a follower."
    };
    quoteLength = sizeof(quoteList)/sizeof(quoteList[0]);
    srand(time(NULL));
    strcpy(quote, quoteList[rand() % quoteLength]);

    // Display the quote to the user
    printf("\n\nType the following quote:\n\t%s\n\n", quote);

    // Start the timer
    time(&startTime);

    // User input
    correct = 0;
    wrong = 0;
    tries = 0;
    totalTime = 0;
    while(correct != strlen(quote) && tries < MAX_TRIES) {
        // Get user input
        printf(">> ");
        char input[MAX_LENGTH];
        fgets(input, MAX_LENGTH, stdin);
        input[strcspn(input, "\n")] = 0; // Remove newline character

        // Count the correct and wrong characters
        correct = 0;
        wrong = 0;
        for(i=0; i<strlen(quote); i++) {
            if(i<strlen(input)) {
                if(input[i] == quote[i]) {
                    correct++;
                } else {
                    wrong++;
                }
            } else {
                wrong++;
            }   
        }

        // Display the result
        printf("You typed %d characters correctly and %d characters incorrectly.\n", correct, wrong);
        tries++;
        if(correct != strlen(quote)) {
            printf("You have %d tries left.\n", MAX_TRIES-tries);
        }

        // Calculate total time
        if(correct != strlen(quote) && tries < MAX_TRIES) {
            totalTime += (int) difftime(time(NULL), startTime);
            printf("\nTime taken: %d seconds\n", totalTime);
        }
    }

    // Stop the timer
    time(&endTime);
    totalTime = (int) difftime(endTime, startTime);

    // Calculate accuracy and typing speed
    accuracy = (double) correct / strlen(quote) * 100.0;
    wpm = (double) correct / 5 / ((double) totalTime / 60.0);

    // Display the final result
    printf("\n\n");
    if(tries < MAX_TRIES) {
        printf("Congratulations! You typed the quote correctly in %d seconds.\n", totalTime);
        printf("Accuracy: %.2f%%\n", accuracy);
        printf("Typing speed: %.2f WPM (words per minute)\n", wpm);
    } else {
        printf("Sorry, you were unable to type the quote correctly within %d tries.\n", MAX_TRIES);
        printf("The quote was:\n\t%s\n", quote);
    }

    return 0;
}