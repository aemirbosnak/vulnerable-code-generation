#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_WORDS 1000
#define WORD_LENGTH 50

typedef struct Word {
    char word[WORD_LENGTH];
    int count;
} Word;

int main() {
    Word words[MAX_WORDS];
    int num_words = 0;
    char line[1024];

    while (fgets(line, sizeof(line), stdin) != NULL) {
        char *token = strtok(line, " .,!?\t\n");
        while (token != NULL) {
            for (int i = 0; i < WORD_LENGTH; ++i) {
                if (token[i] == '\0' || token[i] == '\n') {
                    token[i] = '\0';
                    break;
                }
                token[i] = tolower(token[i]);
            }
            int found = 0;
            for (int j = 0; j < num_words; ++j) {
                if (strcmp(words[j].word, token) == 0) {
                    words[j].count++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                strcpy(words[num_words].word, token);
                words[num_words].count = 1;
                ++num_words;
            }
            token = strtok(NULL, " .,!?\t\n");
        }
    }

    for (int i = 0; i < num_words; ++i) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}
