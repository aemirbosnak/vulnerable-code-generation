//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

#define MAX 100
#define TIME_LIMIT 60

int main() {
    char input[MAX];
    int i = 0, correct = 0, mistakes = 0, elapsed = 0, characters = 0;
    float speed = 0;

    time_t start, end;
    srand(time(NULL));

    printf("Try to type the following sentence as fast and accurately as possible within %d seconds:\n", TIME_LIMIT);
    printf("The quick brown fox jumps over the lazy dog.\n");

    start = time(NULL);

    while (elapsed < TIME_LIMIT) {
        char c = getchar();

        if(c == '\n') break; // Exit if user presses enter

        if(!isspace(c)) { // Only count non-space characters
            characters++;
        }
        if(c == input[i]) { // Check if input matches
            correct++;
            i++;
        } else if(isalpha(c)) { // Check for mistakes
            mistakes++;
        }
        if(i == MAX - 1) break; // Exit if input length exceeds maximum

        printf("\r"); // Move cursor to beginning of the line

        for(int j = 0; j < i; j++) { // Print current input
            printf("%c", input[j]);
        }

        if(c == 127) { // Backspace
            if(i > 0) {
                i--;
                characters--;
                correct--;
                mistakes--;
                printf(" \r");
            }
        } else {
            input[i] = c;
            i++;
        }
    }

    end = time(NULL);
    elapsed = end - start;

    printf("\n\n");

    speed = (float) characters / elapsed * 60; // Calculate speed in characters per minute
    printf("Time elapsed: %d s\n", elapsed);
    printf("Input length: %d characters\n", characters);
    printf("Correct: %d\n", correct);
    printf("Mistakes: %d\n", mistakes);
    printf("Typing speed: %0.2f CPM\n", speed);

    return 0;
}