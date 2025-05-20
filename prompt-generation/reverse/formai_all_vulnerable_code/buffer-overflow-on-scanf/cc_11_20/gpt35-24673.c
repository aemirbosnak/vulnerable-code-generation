//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_SIZE 50
#define MAX_WORD_COUNT 10000

typedef struct {
    char word[MAX_WORD_SIZE];
    int frequency;
} word_frequency_t;

int main() {
    int i, j, k, word_count;
    char c, word[MAX_WORD_SIZE];
    word_frequency_t wfs[MAX_WORD_COUNT];

    memset(wfs, 0, sizeof(wfs));
    word_count = 0;

    printf("Enter some text:\n");

    while (scanf("%c", &c) != EOF) {
        if (isalpha(c)) {
            if (strlen(word) < MAX_WORD_SIZE - 1) {
                word[strlen(word)] = tolower(c);
            }
        } else if (strlen(word) > 0) {
            word_frequency_t *wf = NULL;
            int found = 0;

            for (i = 0; i < word_count; i++) {
                if (strcmp(wfs[i].word, word) == 0) {
                    wf = &wfs[i];
                    wf->frequency++;
                    found = 1;
                    break;
                }
            }

            if (!found && word_count < MAX_WORD_COUNT) {
                wf = &wfs[word_count++];
                strcpy(wf->word, word);
                wf->frequency = 1;
            }

            if (wf != NULL && wf->frequency == 1) {
                printf("New word: %s\n", wf->word);
            }

            memset(word, 0, sizeof(word));
        }
    }

    printf("Word frequency count:\n");

    for (i = 0; i < word_count; i++) {
        for (j = i + 1; j < word_count; j++) {
            if (strcmp(wfs[i].word, wfs[j].word) > 0) {
                word_frequency_t tmp = wfs[i];
                wfs[i] = wfs[j];
                wfs[j] = tmp;
            }
        }
    }

    for (i = 0; i < word_count; i++) {
        printf("%s: %d\n", wfs[i].word, wfs[i].frequency);
    }

    return 0;
}