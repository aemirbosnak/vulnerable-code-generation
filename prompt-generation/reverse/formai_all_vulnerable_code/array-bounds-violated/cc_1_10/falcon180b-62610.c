//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 20
#define MAX_WORD_LENGTH 10

int main() {
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int num_words = 0;
    int word_lengths[MAX_WORDS];
    int i, j, k, score = 0;
    float wpm = 0;
    struct timespec start_time, end_time;

    srand(time(NULL));

    // Fill array with random words
    for (i = 0; i < MAX_WORDS; i++) {
        words[i][0] = rand() % 26 + 'a';
        for (j = 1; j < MAX_WORD_LENGTH; j++) {
            words[i][j] = rand() % 26 + 'a';
        }
        words[i][j] = '\0';
        word_lengths[i] = strlen(words[i]);
        num_words++;
    }

    // Print instructions
    printf("Welcome to the Post-Apocalyptic Typing Speed Test!\n");
    printf("In this world, only the fastest typists survive.\n");
    printf("You will be given %d words to type.\n", num_words);
    printf("Your score will be based on your Words Per Minute (WPM).\n");
    printf("Press ENTER to begin...\n");

    // Get user input to start test
    getchar();

    // Start timer
    clock_gettime(CLOCK_REALTIME, &start_time);

    // Loop through words and get user input
    for (i = 0; i < num_words; i++) {
        printf("%s ", words[i]);
        fflush(stdout);
        if (scanf("%s", words[i])!= 1) {
            printf("Invalid input. Test aborted.\n");
            return 1;
        }
    }

    // Stop timer
    clock_gettime(CLOCK_REALTIME, &end_time);

    // Calculate WPM
    for (i = 0; i < num_words; i++) {
        score += word_lengths[i];
    }
    wpm = (float)score / (end_time.tv_sec - start_time.tv_sec + (end_time.tv_nsec - start_time.tv_nsec) / 1000000000.0);

    // Print results
    printf("\nTest complete!\n");
    printf("You typed %d words in %d seconds.\n", num_words, (int)(end_time.tv_sec - start_time.tv_sec));
    printf("Your Words Per Minute (WPM) is: %.2f\n", wpm);

    return 0;
}