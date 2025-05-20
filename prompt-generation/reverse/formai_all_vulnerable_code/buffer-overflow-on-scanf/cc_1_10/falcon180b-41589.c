//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20
#define MIN_WPM 10
#define MAX_WPM 200

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

int main() {
    int num_words, num_correct, num_incorrect, total_chars, wpm;
    char input[MAX_WORD_LENGTH];
    Word words[MAX_WORDS];
    int i, j, k, index;
    clock_t start_time, end_time;

    // Read in the number of words to type
    printf("Enter the number of words to type (between 1 and %d): ", MAX_WORDS);
    scanf("%d", &num_words);
    if (num_words < 1 || num_words > MAX_WORDS) {
        printf("Invalid number of words.\n");
        return 1;
    }

    // Read in the words
    printf("Enter %d words:\n", num_words);
    for (i = 0; i < num_words; i++) {
        scanf("%s", words[i].word);
        words[i].length = strlen(words[i].word);
    }

    // Shuffle the words
    for (i = 0; i < num_words; i++) {
        index = rand() % num_words;
        Word temp = words[i];
        words[i] = words[index];
        words[index] = temp;
    }

    // Start the timer
    start_time = clock();

    // Type the words
    for (i = 0; i < num_words; i++) {
        printf("%s ", words[i].word);
        fflush(stdout);

        // Read in the user's input
        scanf("%s", input);

        // Check if the input is correct
        if (strcmp(input, words[i].word) == 0) {
            num_correct++;
        } else {
            num_incorrect++;
        }

        // Update the total number of characters typed
        total_chars += strlen(input);
    }

    // Stop the timer
    end_time = clock();

    // Calculate the WPM
    wpm = (total_chars / (double) (end_time - start_time)) * 60;

    // Print the results
    printf("\nYou typed %d words correctly and %d words incorrectly.\n", num_correct, num_incorrect);
    printf("Your typing speed is %.2f words per minute.\n", wpm);

    return 0;
}