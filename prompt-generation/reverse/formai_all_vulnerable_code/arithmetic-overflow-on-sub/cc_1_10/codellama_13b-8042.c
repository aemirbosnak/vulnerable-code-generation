//Code Llama-13B DATASET v1.0 Category: Typing Speed Test ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 100

int main() {
    char input[MAX_LENGTH];
    char word[MAX_LENGTH];
    int i, j, k;
    int score = 0;
    int time = 0;

    // Get the input from the user
    printf("Enter a sentence: ");
    fgets(input, MAX_LENGTH, stdin);

    // Remove the newline character
    input[strcspn(input, "\n")] = '\0';

    // Get the length of the input
    int length = strlen(input);

    // Split the input into individual words
    for (i = 0, j = 0; i < length; i++) {
        if (input[i] == ' ') {
            word[j] = '\0';
            j = 0;
        } else {
            word[j++] = input[i];
        }
    }
    word[j] = '\0';

    // Start the timer
    clock_t start = clock();

    // Print each word
    for (i = 0; i < length; i++) {
        printf("%c", word[i]);
        if (word[i] == ' ') {
            printf("\n");
        }
    }

    // Calculate the score
    clock_t end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    score = (double)length / time;

    // Print the results
    printf("\nScore: %d\nTime: %f\n", score, time);

    return 0;
}