//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 100
#define TIME_LIMIT 60

int main() {
    char text[MAX_LENGTH];
    int score = 0, mistakes = 0, typed = 0, total_chars = 0;
    int elapsed_seconds = 0, seconds_left = TIME_LIMIT, cpm = 0;
    clock_t start_time, end_time;

    // Introduction
    printf("Welcome to the Typing Speed Test!\n");
    printf("You have %d seconds to type as many words as possible.\n", TIME_LIMIT);
    printf("Press ENTER to start the test.\n\n");
    getchar(); // Wait for user to press ENTER

    // Start timer
    start_time = clock();

    // Generate random text
    srand(time(NULL));
    for(int i=0; i<MAX_LENGTH; i++) {
        text[i] = rand() % 26 + 'a'; // Random lowercase letter
    }

    // Show text to user
    printf("Type the following text:\n%s\n\n", text);

    // Read input from user
    char input[MAX_LENGTH];
    fgets(input, MAX_LENGTH, stdin);

    // Stop timer
    end_time = clock();
    elapsed_seconds = (int) (end_time - start_time) / CLOCKS_PER_SEC;

    // Calculate score
    for(int i=0; i<MAX_LENGTH; i++) {
        total_chars++;
        if(input[i] == '\n') break; // Stop counting at end of line
        if(text[i] == input[i]) {
            score++;
        } else {
            mistakes++;
        }
    }

    // Calculate typing speed (CPM)
    typed = score + mistakes;
    cpm = (int) ((float) score / elapsed_seconds * 60);

    // Calculate accuracy
    float accuracy = (float) score / typed * 100;

    // Show results
    printf("Time elapsed: %d seconds\n", elapsed_seconds);
    printf("Typed characters: %d\n", typed);
    printf("Correct characters: %d\n", score);
    printf("Typing speed: %d CPM\n", cpm);
    printf("Accuracy: %.2f%%\n", accuracy);

    // Evaluate score
    if(elapsed_seconds <= TIME_LIMIT) {
        if(accuracy >= 90) {
            printf("Congratulations! You are a typing master!\n");
        } else if(accuracy >= 80) {
            printf("Well done! Your typing skills are above average.\n");
        } else if(accuracy >= 60) {
            printf("Not bad, but you need to practice more.\n");
        } else {
            printf("Sorry, you need to improve your typing skills.\n");
        }
    } else {
        printf("Time's up! You typed %d characters in %d seconds.\n", typed, elapsed_seconds);
    }

    return 0;
}