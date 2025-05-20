//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 10
#define MAX_WORD_LEN 10

char* words[MAX_WORDS] = {"hello", "world", "knuth", "programming", "language",
                        "computer", "algorithm", "data", "structure", "math"};
int words_count = sizeof(words) / sizeof(words[0]);

int main() {
    int i, j;
    char ch, typed_char;
    int num_chars = 0, num_words = 0, num_mistakes = 0;
    int char_typed, word_typed, time_taken;
    char input_word[MAX_WORD_LEN];

    printf("Welcome to C Typing Speed Test!\n\n");

    // Seed the random number generator
    srand(time(NULL));

    // Print the words to be typed
    printf("Type the following words as fast as you can:\n\n");
    for (i = 0; i < MAX_WORDS; i++) {
        printf("%s ", words[i]);
    }
    printf("\n\n");

    // Take user input and calculate typing speed
    printf("Type the above words and press enter:\n\n");
    time_t start = time(NULL);
    for (i = 0; i < MAX_WORDS; i++) {
        j = 0;
        while ((ch = words[i][j++]) != '\0') {
            typed_char = getchar();
            if (typed_char == '\n') {
                printf("You did not complete the test!\n");
                return 1;
            }
            // Check if typed character matches the expected character
            if (typed_char == ch) {
                num_chars++;
            } else {
                num_mistakes++;
            }
        }
        num_words++;
        scanf("%s", input_word);
        // Check if typed word matches the expected word
        if (strcmp(input_word, words[i]) != 0) {
            num_mistakes++;
        }
    }
    time_taken = (int) (time(NULL) - start);

    // Calculate statistics
    char_typed = num_chars + num_mistakes;
    word_typed = num_words + num_mistakes / MAX_WORD_LEN;
    int wpm = (int) word_typed / (time_taken / 60.0);
    int cpm = (int) char_typed / (time_taken / 60.0);

    // Print results
    printf("\n\n");
    printf("Number of characters typed: %d\n", num_chars);
    printf("Number of mistakes: %d\n", num_mistakes);
    printf("Number of words typed: %d\n", num_words);
    printf("Time taken: %d seconds\n", time_taken);
    printf("Typing speed: %d words per minute\n", wpm);
    printf("Typing speed: %d characters per minute\n", cpm);

    return 0;
}