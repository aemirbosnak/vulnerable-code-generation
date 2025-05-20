//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 50

typedef struct Word {
    char word[WORD_LENGTH];
    int count;
} Word;

bool is_alphanumeric(char c) {
    return (isalpha(c) || isdigit(c) || c == '_');
}

void process_word(Word *words, int *num_words, char *line, int line_len) {
    int i;
    bool found = false;

    for (i = 0; i < *num_words; i++) {
        if (strcmp(words[i].word, line) == 0) {
            words[i].count++;
            found = true;
            break;
        }
    }

    if (!found) {
        if (*num_words == MAX_WORDS) {
            Word *new_words = (Word *)realloc(words, sizeof(Word) * (MAX_WORDS + 100));
            if (!new_words) {
                fprintf(stderr, "Failed to allocate memory for words\n");
                exit(1);
            }
            words = new_words;
        }

        strcpy(words[*num_words].word, line);
        words[*num_words].count = 1;
        (*num_words)++;
    }
}

int main() {
    Word words[MAX_WORDS];
    int num_words = 0;
    char line[1024];
    int line_len;
    bool done = false;

    while (!done) {
        printf("Enter a line or type 'quit' to exit: ");
        fgets(line, sizeof(line), stdin);
        line_len = strlen(line);

        if (line[line_len - 1] == '\n') line[line_len - 1] = '\0';

        if (strcmp(line, "quit") == 0) {
            done = true;
            continue;
        }

        for (int i = 0; i < line_len; i++) {
            if (!is_alphanumeric(line[i])) {
                line[i] = ' ';
            }
        }

        process_word(words, &num_words, line, line_len);
    }

    printf("\nWord frequencies:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}