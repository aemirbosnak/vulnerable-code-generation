#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

int compare(const void *a, const void *b) {
    return ((Word *)b)->count - ((Word *)a)->count;
}

int main() {
    FILE *file = fopen("words.txt", "r");
    if (!file) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    Word words[MAX_WORDS] = {0};
    int word_count = 0;

    while (word_count < MAX_WORDS && fscanf(file, "%s", words[word_count].word) != EOF) {
        for (int i = 0; i <= word_count; i++) {
            if (strcmp(words[i].word, words[word_count].word) == 0) {
                words[i].count++;
                goto next_word;
            }
        }
        words[word_count].count = 1;
        word_count++;
next_word:
        continue;
    }

    fclose(file);

    qsort(words, word_count, sizeof(Word), compare);

    for (int i = 0; i < word_count; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return EXIT_SUCCESS;
}
