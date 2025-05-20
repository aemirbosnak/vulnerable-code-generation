//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 20

int main() {
    srand(time(NULL));
    char words[MAX_WORDS][MAX_WORD_LEN];
    int n_words = 0;
    int i;

    // Generate random words
    for (i = 0; i < MAX_WORDS; i++) {
        int len = rand() % MAX_WORD_LEN + 1;
        char word[MAX_WORD_LEN];
        sprintf(word, "word%d", i+1);
        strncpy(words[i], word, len);
        words[i][len] = '\0';
        n_words++;
    }

    // Print words to type
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be typing the following %d words:\n", n_words);
    for (i = 0; i < n_words; i++) {
        printf("%s\n", words[i]);
    }

    // Start typing test
    printf("\nPress enter to start the test...\n");
    fflush(stdout);
    getchar();
    clock_t start_time = clock();

    // Read input and measure time
    char input[MAX_WORD_LEN];
    int correct = 0;
    for (i = 0; i < n_words; i++) {
        printf("\nType the following word: %s\n", words[i]);
        fflush(stdout);
        gets(input);
        if (strcmp(input, words[i]) == 0) {
            correct++;
        }
    }

    // Print results
    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    int wpm = (int)((double)correct / elapsed_time * 60);
    printf("\nTest complete!\n");
    printf("You typed %d words correctly out of %d.\n", correct, n_words);
    printf("Your typing speed is %d words per minute.\n", wpm);

    return 0;
}