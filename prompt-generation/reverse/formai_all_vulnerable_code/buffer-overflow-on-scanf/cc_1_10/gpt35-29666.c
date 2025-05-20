//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 10 // maximum number of words for the test
#define MAX_LENGTH 20 // maximum length of each word
#define TIME_LIMIT 30 // time limit for the test in seconds

int main() {
    char words[MAX_WORDS][MAX_LENGTH] = {"hello", "world", "computer", "programming", "language", "algorithm", "memory", "function", "variable", "debugging"};
    // array of words for the test
    int i, j, k;
    int correct = 0;
    int score;
    char input[MAX_LENGTH];
    time_t start, end;
    srand(time(NULL));
    
    printf("\nWelcome to the Typing Speed Test!\n\n");
    printf("You will have %d seconds to type as many words as you can.\n", TIME_LIMIT);
    printf("Press Enter to start the test...");
    getchar();
    printf("\n");
    
    start = time(NULL);
    while ((end = time(NULL)) - start < TIME_LIMIT) {
        i = rand() % MAX_WORDS;
        printf("Type the word: %s\n", words[i]);
        scanf("%s", input);
        j = 0, k = 0;
        while (words[i][j] != '\0' && input[k] != '\0') {
            if (words[i][j] == input[k]) {
                j++;
                k++;
            }
            else {
                printf("Incorrect! Try again.\n");
                break;
            }
        }
        if (words[i][j] == '\0' && input[k] == '\0') {
            printf("Correct!\n");
            correct++;
        }
        score = (int)((double)correct / (double)(end - start) * 60);
        printf("\nScore: %d wpm\n\n", score);
    }
    
    printf("\n\nTime's up!\n\n");
    score = (int)((double)correct / (double)TIME_LIMIT * 60);
    printf("Final Score: %d wpm\n\n", score);
    
    return 0;
}