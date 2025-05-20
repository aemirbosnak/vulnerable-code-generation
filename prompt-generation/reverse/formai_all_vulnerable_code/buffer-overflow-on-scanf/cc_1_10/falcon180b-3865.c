//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH + 1];
    int count;
} WordCount;

int compare_words(const void *a, const void *b) {
    const WordCount *wc1 = a;
    const WordCount *wc2 = b;

    if (wc1->count > wc2->count) {
        return -1;
    } else if (wc1->count < wc2->count) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    FILE *input_file = NULL;
    char filename[100];
    char line[1000];
    char *word = NULL;
    int line_count = 0;
    int word_count = 0;
    WordCount *word_counts = NULL;
    int num_words = 0;

    printf("Enter the name of the input file: ");
    scanf("%s", filename);

    input_file = fopen(filename, "r");

    if (input_file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    word_counts = malloc(sizeof(WordCount) * 1000);

    while (fgets(line, sizeof(line), input_file)!= NULL) {
        line_count++;

        word = strtok(line, ",.?!;:");

        while (word!= NULL) {
            word_count++;

            if (num_words >= 1000) {
                printf("Error: Too many unique words (max 1000)\n");
                exit(1);
            }

            strcpy(word_counts[num_words].word, word);
            word_counts[num_words].count = 1;

            num_words++;

            word = strtok(NULL, ",.?!;:");
        }
    }

    fclose(input_file);

    qsort(word_counts, num_words, sizeof(WordCount), compare_words);

    printf("Line count: %d\n", line_count);
    printf("Word count: %d\n", word_count);
    printf("Unique words:\n");

    for (int i = 0; i < num_words; i++) {
        printf("%s (%d)\n", word_counts[i].word, word_counts[i].count);
    }

    free(word_counts);

    return 0;
}