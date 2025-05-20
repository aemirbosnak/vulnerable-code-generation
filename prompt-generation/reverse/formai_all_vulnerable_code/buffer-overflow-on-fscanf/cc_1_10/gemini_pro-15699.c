//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 20

void generate_words(char words[][MAX_WORD_LEN], int n) {
    FILE *fp = fopen("/usr/share/dict/words", "r");
    if (fp == NULL) {
        perror("Error opening word list");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        fscanf(fp, "%s", words[i]);
    }

    fclose(fp);
}

int main() {
    char words[MAX_WORDS][MAX_WORD_LEN];
    generate_words(words, MAX_WORDS);

    int start_time, end_time;
    char input[MAX_WORD_LEN];
    int correct = 0, incorrect = 0;
    int index = 0;

    printf("Welcome to the Typing Speed Test!\n");
    printf("Instructions:\n");
    printf("1. Type the words that appear on the screen.\n");
    printf("2. Press enter after typing each word.\n");
    printf("3. The test will end after you have typed %d words.\n", MAX_WORDS);

    printf("Press any key to start the test...");
    getchar();

    start_time = time(NULL);

    while (index < MAX_WORDS) {
        printf("%s: ", words[index]);
        scanf("%s", input);

        if (strcmp(input, words[index]) == 0) {
            correct++;
        } else {
            incorrect++;
        }

        index++;
    }

    end_time = time(NULL);

    double elapsed_time = difftime(end_time, start_time);
    double wpm = (correct + incorrect) / elapsed_time * 60;

    printf("Test complete!\n");
    printf("Correct words: %d\n", correct);
    printf("Incorrect words: %d\n", incorrect);
    printf("Elapsed time: %.2f seconds\n", elapsed_time);
    printf("Typing speed: %.2f WPM\n", wpm);

    return 0;
}