#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 100
#define BUFFER_SIZE 1024

typedef struct Word {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

int main() {
    char buffer[BUFFER_SIZE];
    Word words[MAX_WORD_LENGTH];
    int num_words = 0;

    printf("Enter a sentence: ");
    fgets(buffer, BUFFER_SIZE, stdin);

    for (int i = 0; i < BUFFER_SIZE; ++i) {
        if (buffer[i] == '\n' || buffer[i] == '\0') {
            break;
        }

        char current_word[MAX_WORD_LENGTH];
        int j = 0;

        while (i > 0 && isspace(buffer[i - 1])) {
            --i;
        }

        while (i < BUFFER_SIZE && !isspace(buffer[i])) {
            current_word[j++] = buffer[i++];
            current_word[j] = '\0';
        }

        bool word_exists = false;
        for (int k = 0; k < num_words; ++k) {
            if (strcmp(words[k].word, current_word) == 0) {
                word_exists = true;
                words[k].count++;
                break;
            }
        }

        if (!word_exists) {
            words[num_words].count = 1;
            strcpy(words[num_words++].word, current_word);
        }
    }

    for (int i = 0; i < num_words; ++i) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}
