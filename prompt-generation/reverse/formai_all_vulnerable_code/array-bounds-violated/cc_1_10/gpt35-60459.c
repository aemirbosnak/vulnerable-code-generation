//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 10000

int main() {
    char text[MAX_NUM_WORDS * MAX_WORD_LENGTH];
    int length = 0, num_words = 0;
    int word_freq[MAX_NUM_WORDS] = {0};
    char *words[MAX_NUM_WORDS];
    char *current_word = strtok(text, " ,.-!?");

    printf("Enter text: ");
    fgets(text, MAX_NUM_WORDS * MAX_WORD_LENGTH, stdin);
    length = strlen(text);
    if (text[length - 1] == '\n') {
        text[length - 1] = '\0';
        length--;
    }

    while (current_word != NULL) {
        int i, match = 0;
        for (i = 0; i < num_words; i++) {
            if (strcasecmp(current_word, words[i]) == 0) {
                word_freq[i]++;
                match = 1;
                break;
            }
        }

        if (!match) {
            words[num_words] = current_word;
            word_freq[num_words] = 1;
            num_words++;
        }

        if (num_words >= MAX_NUM_WORDS) {
            printf("Error: Too many words!\n");
            return 1;
        }

        current_word = strtok(NULL, " ,.-!?");
    }

    printf("\nWord frequency:\n");
    int max_word_length = 0;
    for (int i = 0; i < num_words; i++) {
        int word_length = strlen(words[i]);
        if (word_length > max_word_length) {
            max_word_length = word_length;
        }
    }

    for (int i = 0; i < num_words; i++) {
        printf("%-*s %d times\n", max_word_length, words[i], word_freq[i]);
    }

    return 0;
}