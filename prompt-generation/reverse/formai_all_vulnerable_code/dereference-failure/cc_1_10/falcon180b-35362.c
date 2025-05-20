//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define WORD_SIZE 20

struct word_freq {
    char word[WORD_SIZE];
    int freq;
};

int compare_words(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main() {
    FILE *fp;
    char line[1000];
    char *word;
    struct word_freq *words = (struct word_freq *)malloc(MAX_WORDS * sizeof(struct word_freq));
    int num_words = 0;

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        word = strtok(line, ",.!?;:");
        while (word!= NULL) {
            if (num_words >= MAX_WORDS) {
                printf("Too many words!\n");
                exit(1);
            }
            strcpy(words[num_words].word, word);
            words[num_words].freq = 1;
            num_words++;
            word = strtok(NULL, ",.!?;:");
        }
    }

    qsort(words, num_words, sizeof(struct word_freq), compare_words);

    printf("Word\tFrequency\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s\t%d\n", words[i].word, words[i].freq);
    }

    free(words);
    fclose(fp);

    return 0;
}