//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_SIZE 50

struct Word {
    char word[WORD_SIZE];
    int count;
};

int main() {
    struct Word words[MAX_WORDS];
    int num_words = 0;
    char line[1024];

    printf("Hello and welcome to the Word Count Tool!\n");
    printf("I am here to help you count the occurrences of each word in your text.\n");
    printf("Please enter the text, one line at a time, when you are done, type \"quit\".\n");

    while (fgets(line, sizeof(line), stdin) != NULL && strcmp(line, "quit") != 0) {
        char current_word[WORD_SIZE];
        int current_word_index = -1;

        sscanf(line, "%s", current_word);
        for (int i = 0; i < num_words; ++i) {
            if (strcmp(words[i].word, current_word) == 0) {
                words[i].count++;
                current_word_index = i;
                break;
            }
        }

        if (current_word_index == -1) {
            if (num_words >= MAX_WORDS) {
                printf("I'm sorry, but I can only handle %d unique words at a time.\n", MAX_WORDS);
                break;
            }

            strcpy(words[num_words].word, current_word);
            words[num_words].count = 1;
            num_words++;
        }
    }

    printf("\nHere's the word count for your text:\n");
    for (int i = 0; i < num_words; ++i) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    printf("\nThank you for using the Word Count Tool. I hope it was helpful to you!\n");
    return 0;
}