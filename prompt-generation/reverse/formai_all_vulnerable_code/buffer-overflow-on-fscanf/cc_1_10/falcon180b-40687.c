//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000000 // Maximum number of words to count
#define MAX_WORD_LENGTH 100 // Maximum length of a word

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", argv[1]);
        return 1;
    }

    struct word_count words[MAX_WORDS];
    int num_words = 0;

    char word[MAX_WORD_LENGTH];
    int word_length = 0;

    while (fscanf(fp, "%s", word)!= EOF) {
        if (word_length >= MAX_WORD_LENGTH) {
            printf("Error: Word %s is too long (max %d characters)\n", word, MAX_WORD_LENGTH);
            return 1;
        }

        if (num_words >= MAX_WORDS) {
            printf("Error: Too many words in file\n");
            return 1;
        }

        struct word_count *wc = &words[num_words];
        strcpy(wc->word, word);
        wc->count = 1;

        num_words++;
    }

    fclose(fp);

    printf("Word count:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}