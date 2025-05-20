//Falcon2-11B DATASET v1.0 Category: Data mining ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 100

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} Word;

int main() {
    Word words[100];
    int num_words = 0;
    FILE *fp;

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char word[MAX_WORD_LEN];
    while (fscanf(fp, "%s", word)!= EOF) {
        if (strlen(word) > MAX_WORD_LEN) {
            printf("Word too long.\n");
            continue;
        }

        Word* w = &words[num_words];
        strcpy(w->word, word);
        w->count = 1;
        num_words++;
    }

    fclose(fp);

    if (num_words == 0) {
        printf("No words found.\n");
        return 1;
    }

    int max_count = 0;
    char* most_freq_word = NULL;
    for (int i = 0; i < num_words; i++) {
        if (words[i].count > max_count) {
            max_count = words[i].count;
            most_freq_word = words[i].word;
        }
    }

    printf("Most frequent word: %s (%d times)\n", most_freq_word, max_count);

    return 0;
}