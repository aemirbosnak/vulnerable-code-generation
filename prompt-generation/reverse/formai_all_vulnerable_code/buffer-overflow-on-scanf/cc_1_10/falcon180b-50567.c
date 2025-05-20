//Falcon-180B DATASET v1.0 Category: Data mining ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 20

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

int compare_word_counts(const void *a, const void *b) {
    const struct word_count *wc1 = a;
    const struct word_count *wc2 = b;

    return wc2->count - wc1->count;
}

int main() {
    char filename[100];
    printf("Enter the name of the file to be analyzed: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    char line[1000];
    int num_words = 0;
    int i = 0;
    struct word_count word_counts[MAX_WORDS];

    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *word = strtok(line, ",.!?;:");
        while (word!= NULL) {
            if (num_words >= MAX_WORDS) {
                printf("Error: too many words in file.\n");
                exit(1);
            }

            int j;
            for (j = 0; j < i; j++) {
                if (strcmp(word_counts[j].word, word) == 0) {
                    word_counts[j].count++;
                    break;
                }
            }

            if (j == i) {
                strncpy(word_counts[i].word, word, MAX_WORD_LENGTH);
                word_counts[i].count = 1;
                i++;
            }

            word = strtok(NULL, ",.!?;:");
        }

        num_words++;
    }

    qsort(word_counts, num_words, sizeof(struct word_count), compare_word_counts);

    printf("Top 10 most frequent words:\n");
    for (i = 0; i < 10 && i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    fclose(fp);
    return 0;
}