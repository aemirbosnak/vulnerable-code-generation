//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 10

int main() {
    char *words[MAX_WORDS];
    int num_words = 0;
    int total_chars = 0;
    int num_correct = 0;
    int num_wrong = 0;
    int start_time = 0;
    int end_time = 0;

    srand(time(NULL));

    // Load words from file
    FILE *fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error loading words from file.\n");
        return 1;
    }

    while (fscanf(fp, "%s", words[num_words])!= EOF) {
        num_words++;
        total_chars += strlen(words[num_words-1]);
        if (num_words >= MAX_WORDS) break;
    }

    fclose(fp);

    // Shuffle the words
    for (int i = 0; i < num_words; i++) {
        int j = rand() % num_words;
        char *temp = words[i];
        words[i] = words[j];
        words[j] = temp;
    }

    // Start timer
    start_time = clock();

    // Display the words
    for (int i = 0; i < num_words; i++) {
        printf("%s ", words[i]);
        if (i % 10 == 9) printf("\n");
    }
    printf("\n");

    // Get user input
    char input[MAX_WORD_LENGTH];
    for (int i = 0; i < num_words; i++) {
        fgets(input, MAX_WORD_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        // Check if input is correct
        if (strcmp(input, words[i]) == 0) {
            num_correct++;
        } else {
            num_wrong++;
        }
    }

    // Stop timer
    end_time = clock();

    // Calculate WPM
    int elapsed_time = end_time - start_time;
    int wpm = (int) (MAX_WORD_LENGTH * num_words / (elapsed_time / (double) CLOCKS_PER_SEC));

    // Print results
    printf("Total words: %d\n", num_words);
    printf("Total characters: %d\n", total_chars);
    printf("Correct words: %d\n", num_correct);
    printf("Wrong words: %d\n", num_wrong);
    printf("WPM: %d\n", wpm);

    return 0;
}