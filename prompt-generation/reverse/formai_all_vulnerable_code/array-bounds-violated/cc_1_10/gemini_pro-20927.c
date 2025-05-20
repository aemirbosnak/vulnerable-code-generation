//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

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
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, file) != NULL) {
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0'; // Remove the newline character
        }

        strcpy(dictionary[dictionary_size].word, line);
        dictionary[dictionary_size].count = 0;
        dictionary_size++;
    }

    fclose(file);
}

int compare_words(const void *a, const void *b) {
    const Word *word1 = (const Word *)a;
    const Word *word2 = (const Word *)b;

    return strcmp(word1->word, word2->word);
}

int find_word(const char *word) {
    Word key;
    strcpy(key.word, word);

    void *result = bsearch(&key, dictionary, dictionary_size, sizeof(Word), compare_words);
    if (result == NULL) {
        return -1;
    } else {
        return ((Word *)result)->count;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <dictionary file> <text file>\n", argv[0]);
        exit(1);
    }

    load_dictionary(argv[1]);

    FILE *file = fopen(argv[2], "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening text file: %s\n", argv[2]);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) != EOF) {
        int count = find_word(word);
        if (count == -1) {
            printf("%s\n", word);
        }
    }

    fclose(file);

    return 0;
}