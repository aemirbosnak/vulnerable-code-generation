//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

int compare_words(const void *a, const void *b) {
    const struct word_count *wc1 = a;
    const struct word_count *wc2 = b;

    return strcmp(wc1->word, wc2->word);
}

void print_word_counts(int num_words, struct word_count *word_counts) {
    qsort(word_counts, num_words, sizeof(struct word_count), compare_words);

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    FILE *fp;
    char filename[100];
    char line[1000];
    char *word;
    int num_words = 0;
    struct word_count word_counts[MAX_WORDS];

    printf("Enter the name of the file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        word = strtok(line, ",.!?;:\"'");

        while (word!= NULL) {
            if (num_words >= MAX_WORDS) {
                printf("Error: Too many words in the file.\n");
                exit(1);
            }

            strcpy(word_counts[num_words].word, word);
            word_counts[num_words].count = 1;
            num_words++;

            word = strtok(NULL, ",.!?;:\"'");
        }
    }

    fclose(fp);

    print_word_counts(num_words, word_counts);

    return 0;
}