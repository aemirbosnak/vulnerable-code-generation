//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

int compare_words(const void *a, const void *b) {
    Word *word_a = (Word *)a;
    Word *word_b = (Word *)b;

    if (word_a->count > word_b->count) {
        return -1;
    } else if (word_a->count < word_b->count) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char filename[MAX_WORD_LENGTH];
    printf("Enter the name of the text file: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    int count = 0;

    while (fscanf(fp, "%s", word)!= EOF) {
        if (strlen(word) <= MAX_WORD_LENGTH) {
            count++;
        }
    }

    Word words[MAX_WORDS];
    int num_words = 0;

    rewind(fp);

    while (fscanf(fp, "%s", word)!= EOF) {
        if (strlen(word) <= MAX_WORD_LENGTH) {
            for (int i = 0; i < num_words; i++) {
                if (strcmp(words[i].word, word) == 0) {
                    words[i].count++;
                    break;
                }
            }

            if (num_words < MAX_WORDS) {
                strcpy(words[num_words].word, word);
                words[num_words].count = 1;
                num_words++;
            }
        }
    }

    qsort(words, num_words, sizeof(Word), compare_words);

    printf("Top 10 most frequent words:\n");
    for (int i = 0; i < num_words && i < 10; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    fclose(fp);

    return 0;
}