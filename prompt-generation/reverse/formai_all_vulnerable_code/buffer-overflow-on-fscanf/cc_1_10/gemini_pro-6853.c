//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

Word dictionary[MAX_WORDS];
int dictionary_size = 0;

void load_dictionary(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening dictionary file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s", dictionary[dictionary_size].word) != EOF) {
        dictionary_size++;
    }

    fclose(file);
}

int binary_search(const char *word) {
    int low = 0;
    int high = dictionary_size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        int cmp = strcmp(word, dictionary[mid].word);

        if (cmp == 0) {
            return mid;
        } else if (cmp < 0) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <dictionary> <text>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    load_dictionary(argv[1]);

    FILE *file = fopen(argv[2], "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening text file: %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) != EOF) {
        int index = binary_search(word);

        if (index == -1) {
            printf("%s\n", word);
        }
    }

    fclose(file);

    return EXIT_SUCCESS;
}