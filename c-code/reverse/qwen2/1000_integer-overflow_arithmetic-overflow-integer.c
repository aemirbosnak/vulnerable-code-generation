#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100000

typedef struct {
    char *word;
    int count;
} Word;

int compare(const void *a, const void *b) {
    return ((Word *)b)->count - ((Word *)a)->count;
}

int main() {
    Word words[MAX_WORDS];
    for (int i = 0; i < MAX_WORDS; i++) {
        words[i].word = NULL;
        words[i].count = 0;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), stdin)) {
        char *token = strtok(buffer, " \n");
        while (token != NULL) {
            int found = 0;
            for (int i = 0; i < MAX_WORDS; i++) {
                if (words[i].word == NULL || strcmp(words[i].word, token) == 0) {
                    if (words[i].word == NULL) {
                        words[i].word = strdup(token);
                    }
                    words[i].count++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("Integer overflow detected!\n");
                exit(1);
            }
            token = strtok(NULL, " \n");
        }
    }

    qsort(words, MAX_WORDS, sizeof(Word), compare);

    for (int i = 0; i < MAX_WORDS && words[i].word != NULL; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    for (int i = 0; i < MAX_WORDS; i++) {
        free(words[i].word);
    }

    return 0;
}
