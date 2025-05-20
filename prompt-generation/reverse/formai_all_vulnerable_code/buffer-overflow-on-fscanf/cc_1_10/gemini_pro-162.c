//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

int compare_words(const void *a, const void *b) {
    return strcmp(((Word *)a)->word, ((Word *)b)->word);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s dictionary text\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *dictionary_file = fopen(argv[1], "r");
    if (dictionary_file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    Word dictionary[MAX_WORDS];
    int num_words = 0;

    while (fscanf(dictionary_file, "%s", dictionary[num_words].word) != EOF) {
        dictionary[num_words].count = 0;
        num_words++;
    }

    fclose(dictionary_file);

    qsort(dictionary, num_words, sizeof(Word), compare_words);

    FILE *text_file = fopen(argv[2], "r");
    if (text_file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(text_file, "%s", word) != EOF) {
        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }

        int left = 0;
        int right = num_words - 1;
        int middle;

        while (left <= right) {
            middle = (left + right) / 2;

            int comparison = strcmp(word, dictionary[middle].word);

            if (comparison == 0) {
                dictionary[middle].count++;
                break;
            } else if (comparison < 0) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }
    }

    fclose(text_file);

    for (int i = 0; i < num_words; i++) {
        if (dictionary[i].count == 0) {
            printf("%s\n", dictionary[i].word);
        }
    }

    return EXIT_SUCCESS;
}