//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20
#define MAX_TIME 60

typedef struct {
    char *word;
    int length;
} Word;

int main() {
    const char *words[MAX_WORDS] = {"shapeshift", "coding", "compiler", "algorithm", "programming", "language", "function", "loop", "variable", "integer", "float", "double", "pointer", "string", "array", "structure", "union", "enum", "header", "source"};
    const int num_words = sizeof(words) / sizeof(words[0]);

    srand(time(NULL)); // seed the random number generator

    Word current_word = {NULL, 0};
    char input_word[MAX_WORD_LENGTH] = {0};
    int num_correct = 0, num_total = 0, num_chars_typed = 0;
    time_t start_time = 0, elapsed_time = 0;

    printf("Welcome to the Shapeshifting Typing Speed Test!\n");
    printf("Type as many words as you can in %d seconds.\n", MAX_TIME);
    printf("Press enter to start...");

    fgets(input_word, MAX_WORD_LENGTH, stdin); // wait for enter key to start

    start_time = time(NULL);

    while ((int)elapsed_time <= MAX_TIME) {
        if (current_word.word == NULL) { // if we need a new word
            memset(input_word, 0, MAX_WORD_LENGTH); // clear the input buffer

            int index = rand() % num_words;
            current_word.word = strdup(words[index]); // copy the word to our struct
            current_word.length = strlen(current_word.word);
            printf("\n%s\n", current_word.word); // print the word for the user
        }

        char c = getchar();
        if (isspace(c) || c == '\n') { // if they've typed a full word
            if (strcmp(input_word, current_word.word) == 0) { // if it's correct
                num_correct++;
            }
            num_total++;
            num_chars_typed += current_word.length;
            free(current_word.word); // free the memory for the current word
            current_word.word = NULL; // set it to null so we'll choose a new word next iteration
        } else { // if they're in the middle of typing a word
            input_word[strlen(input_word)] = c;
        }

        elapsed_time = time(NULL) - start_time;
    }

    printf("\n\nTime's up!\n");
    printf("You typed %d words with a total of %d characters in %d seconds.\n", num_total-1, num_chars_typed, MAX_TIME);
    printf("You typed %d words correctly.\n", num_correct);
    printf("Your typing speed was %.2f words per minute and %.2f characters per minute.\n", (float)(num_total-1)*60/MAX_TIME, (float)num_chars_typed*60/MAX_TIME);

    return 0;
}