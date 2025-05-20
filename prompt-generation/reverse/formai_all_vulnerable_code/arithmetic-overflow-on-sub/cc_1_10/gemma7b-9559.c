//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: satisfied
#include <stdio.h>
#include <time.h>

#define MAX_WORDS 10

typedef struct Word {
    char word[20];
    int frequency;
} Word;

Word words[MAX_WORDS];

int main() {
    int i, j, time_start, time_end, total_time = 0, total_words = 0;
    char input_word[20];

    // Initialize the words array
    for (i = 0; i < MAX_WORDS; i++) {
        words[i].word[0] = '\0';
        words[i].frequency = 0;
    }

    // Start the timer
    time_start = clock();

    // Get the user input
    printf("Enter a word: ");
    scanf("%s", input_word);

    // Add the word to the array
    for (i = 0; i < MAX_WORDS; i++) {
        if (strcmp(words[i].word, input_word) == 0) {
            words[i].frequency++;
            break;
        }
    }

    // Get the user input again
    printf("Enter a word: ");
    scanf("%s", input_word);

    // Add the word to the array
    for (i = 0; i < MAX_WORDS; i++) {
        if (strcmp(words[i].word, input_word) == 0) {
            words[i].frequency++;
            break;
        }
    }

    // Stop the timer
    time_end = clock();

    // Calculate the total time and words
    total_time = time_end - time_start;
    total_words = words[0].frequency + words[1].frequency;

    // Print the results
    printf("Total time: %d seconds\n", total_time);
    printf("Total words: %d\n", total_words);
    printf("Words list:\n");
    for (i = 0; i < MAX_WORDS; i++) {
        if (words[i].word[0] != '\0') {
            printf("%s - %d\n", words[i].word, words[i].frequency);
        }
    }

    return 0;
}