//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 1000000

typedef struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compare_word_counts(const void *a, const void *b) {
    const WordCount *wc1 = a;
    const WordCount *wc2 = b;
    return strcmp(wc1->word, wc2->word);
}

int main() {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int num_words = 0;
    WordCount *word_counts = malloc(MAX_NUM_WORDS * sizeof(WordCount));

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    while ((read = getline(&line, &len, fp))!= -1) {
        char *word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            int i;
            for (i = 0; i < strlen(word); i++) {
                if (!isalpha(word[i])) {
                    word[i] = '\0';
                }
            }
            int word_index = 0;
            while (word_index < num_words && strcmp(word_counts[word_index].word, word)!= 0) {
                word_index++;
            }
            if (word_index == num_words) {
                if (num_words == MAX_NUM_WORDS) {
                    printf("Error: maximum number of words reached.\n");
                    exit(1);
                }
                strcpy(word_counts[num_words].word, word);
                word_counts[num_words].count = 1;
                num_words++;
            } else {
                word_counts[word_index].count++;
            }
            word = strtok(NULL, ",.?!;:");
        }
    }

    qsort(word_counts, num_words, sizeof(WordCount), compare_word_counts);

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    free(line);
    fclose(fp);
    return 0;
}