//Falcon-180B DATASET v1.0 Category: Data mining ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compare_words(const void *a, const void *b) {
    WordFrequency *word_a = (WordFrequency *) a;
    WordFrequency *word_b = (WordFrequency *) b;

    return strcmp(word_a->word, word_b->word);
}

void read_words(char *filename, WordFrequency *words, int *num_words) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (*num_words >= MAX_WORDS) {
            printf("Warning: reached maximum number of words (%d)\n", MAX_WORDS);
            break;
        }

        WordFrequency *word_ptr = &words[*num_words];
        strncpy(word_ptr->word, word, MAX_WORD_LENGTH - 1);
        word_ptr->word[MAX_WORD_LENGTH - 1] = '\0';
        word_ptr->frequency = 1;

        (*num_words)++;
    }

    fclose(file);
}

void print_frequencies(WordFrequency *words, int num_words) {
    qsort(words, num_words, sizeof(WordFrequency), compare_words);

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    WordFrequency words[MAX_WORDS];
    int num_words = 0;

    read_words(filename, words, &num_words);
    print_frequencies(words, num_words);

    return 0;
}