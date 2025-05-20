//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WORD_COUNT 10
#define WORD_LENGTH 10
#define TIME_LIMIT 60

int main() {
    char words[WORD_COUNT][WORD_LENGTH];
    int i, j, correct = 0, incorrect = 0, total = 0;
    int score = 0, wpm = 0;
    int start_time, end_time;

    srand(time(NULL));

    // Generate random words
    for (i = 0; i < WORD_COUNT; i++) {
        for (j = 0; j < WORD_LENGTH; j++) {
            words[i][j] = rand() % 26 + 'a';
        }
        words[i][WORD_LENGTH] = '\0';
    }

    printf("Welcome to the Typing Speed Test!\n");
    printf("You have %d seconds to type %d words.\n", TIME_LIMIT, WORD_COUNT);
    printf("Press Enter to begin...\n");
    getchar();

    // Start timer
    start_time = time(NULL);

    for (i = 0; i < WORD_COUNT; i++) {
        printf("%s\n", words[i]);
        fflush(stdout);
        char input[WORD_LENGTH + 1];
        scanf("%s", input);
        total++;

        if (strcmp(input, words[i]) == 0) {
            correct++;
        } else {
            incorrect++;
        }
    }

    // Stop timer
    end_time = time(NULL);
    double elapsed_time = difftime(end_time, start_time);

    if (elapsed_time > TIME_LIMIT) {
        printf("Time's up! You typed %d words.\n", total);
    } else {
        printf("You typed %d words in %.2f seconds.\n", total, elapsed_time);
    }

    score = (int) (correct * 100.0 / total);
    wpm = (int) (total / (elapsed_time / 60.0));

    printf("Your accuracy is %d%% and your WPM is %d.\n", score, wpm);

    return 0;
}