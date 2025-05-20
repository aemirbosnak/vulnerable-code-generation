//Falcon-180B DATASET v1.0 Category: Text processing ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compare(const void *a, const void *b) {
    WordCount *wc1 = (WordCount *)a;
    WordCount *wc2 = (WordCount *)b;

    if (wc1->count > wc2->count) {
        return -1;
    } else if (wc1->count < wc2->count) {
        return 1;
    } else {
        return 0;
    }
}

void read_file(FILE *file, WordCount words[]) {
    char word[MAX_WORD_LENGTH];
    int in_word = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        int len = strlen(word);
        if (len > MAX_WORD_LENGTH - 1) {
            len = MAX_WORD_LENGTH - 1;
        }
        strncpy(words[in_word].word, word, len);
        words[in_word].word[len] = '\0';
        words[in_word].count++;
        in_word++;
    }
}

void write_file(FILE *file, WordCount words[], int num_words) {
    qsort(words, num_words, sizeof(WordCount), compare);

    for (int i = 0; i < num_words; i++) {
        fprintf(file, "%s %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error opening input file: %s\n", argv[1]);
        return 1;
    }

    WordCount words[MAX_WORDS];
    int num_words = 0;

    read_file(input_file, words);
    fclose(input_file);

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        fprintf(stderr, "Error opening output file: %s\n", argv[2]);
        return 1;
    }

    write_file(output_file, words, num_words);
    fclose(output_file);

    return 0;
}