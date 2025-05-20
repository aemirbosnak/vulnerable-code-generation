//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_CHAR 1000

int main(){
    char text[MAX_CHAR];
    int i = 0, mistakes = 0, correct = 0, word_count = 0, char_count = 0;
    double accuracy = 0.0, wpm = 0.0;
    clock_t start_t, end_t;

    printf("Welcome to the Typing Speed Test!\n");
    printf("Please type the following text as fast and accurately as possible:\n");

    // Text to be typed by the user
    sprintf(text, "The quick brown fox jumps over the lazy dog. This sentence is used to test typing speed. It contains all the letters of the alphabet.");

    printf("\n%s\n\n", text);

    // Start timer
    start_t = clock();

    // Read user input
    while (text[i] != '\0' && i < MAX_CHAR - 1){
        char c = getchar();
        char_count++;

        if(c == ' '){
            word_count++;
        }

        if (c == text[i]){
            putchar(c);
            correct++;
        } else {
            mistakes++;
        }

        i++;
    }

    // End timer
    end_t = clock();

    // Calculate accuracy and words per minute
    accuracy = (double) correct / (mistakes + correct) * 100.0;
    wpm = (double) char_count / ((double) (end_t - start_t) / CLOCKS_PER_SEC) / 5.0;

    // Display result
    printf("\n\nResult:\n");
    printf("Time elapsed: %.2f seconds\n", (double) (end_t - start_t) / CLOCKS_PER_SEC);
    printf("Words per minute: %.2f wpm\n", wpm);
    printf("Accuracy: %.2f%%\n", accuracy);

    return 0;
}