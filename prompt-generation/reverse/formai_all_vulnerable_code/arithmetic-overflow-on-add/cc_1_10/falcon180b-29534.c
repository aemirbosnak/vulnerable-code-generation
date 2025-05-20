//Falcon-180B DATASET v1.0 Category: Text processing ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compare_frequency(const void *a, const void *b) {
    WordFrequency *word_a = (WordFrequency *)a;
    WordFrequency *word_b = (WordFrequency *)b;

    if (word_a->frequency > word_b->frequency) {
        return -1;
    } else if (word_a->frequency < word_b->frequency) {
        return 1;
    } else {
        return 0;
    }
}

void count_words(char *text, int length, WordFrequency *word_frequencies) {
    char *word = malloc(MAX_WORD_LENGTH);
    int word_length = 0;
    int i = 0;

    while (i < length) {
        if (isspace(text[i])) {
            if (word_length > 0) {
                word[word_length] = '\0';
                int j;
                for (j = 0; j < i; j++) {
                    if (!isspace(text[j])) {
                        word_frequencies[j].frequency++;
                    }
                }
            }
            word_length = 0;
        } else {
            if (word_length >= MAX_WORD_LENGTH - 1) {
                printf("Error: Word is too long.\n");
                exit(1);
            }
            word[word_length++] = tolower(text[i]);
        }
        i++;
    }

    if (word_length > 0) {
        word[word_length] = '\0';
        int j;
        for (j = 0; j < i; j++) {
            if (!isspace(text[j])) {
                word_frequencies[j].frequency++;
            }
        }
    }

    free(word);
}

void print_word_frequencies(WordFrequency *word_frequencies, int num_words) {
    qsort(word_frequencies, num_words, sizeof(WordFrequency), compare_frequency);

    printf("Word frequencies:\n");
    int i;
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_frequencies[i].word, word_frequencies[i].frequency);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    int length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *text = malloc(length + 1);
    if (text == NULL) {
        printf("Error: Could not allocate memory.\n");
        fclose(file);
        return 1;
    }

    fread(text, 1, length, file);
    text[length] = '\0';
    fclose(file);

    WordFrequency word_frequencies[MAX_WORDS];
    int num_words = 0;

    count_words(text, length, word_frequencies);
    print_word_frequencies(word_frequencies, num_words);

    free(text);
    return 0;
}