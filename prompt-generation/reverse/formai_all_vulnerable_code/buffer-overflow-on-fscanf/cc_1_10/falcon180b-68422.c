//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define WORD_SIZE 10

typedef struct {
    char word[WORD_SIZE];
    int count;
} word_t;

void load_dictionary(const char* filename, word_t* dictionary) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error loading dictionary: %s\n", filename);
        exit(1);
    }

    char line[WORD_SIZE];
    while (fscanf(file, "%s", line)!= EOF) {
        strcpy(dictionary->word, line);
        dictionary->count = 0;
        dictionary++;
    }

    fclose(file);
}

int compare_words(const void* a, const void* b) {
    const word_t* word1 = (const word_t*) a;
    const word_t* word2 = (const word_t*) b;

    return strcmp(word1->word, word2->word);
}

void sort_dictionary(word_t* dictionary, int size) {
    qsort(dictionary, size, sizeof(word_t), compare_words);
}

int main() {
    char input[10000];
    word_t dictionary[MAX_WORDS];

    load_dictionary("dictionary.txt", dictionary);
    sort_dictionary(dictionary, sizeof(dictionary) / sizeof(word_t));

    printf("Enter text to check spelling:\n");
    fgets(input, sizeof(input), stdin);

    char* word = strtok(input, " ");
    while (word!= NULL) {
        int found = 0;

        for (int i = 0; i < sizeof(dictionary) / sizeof(word_t); i++) {
            if (strcmp(word, dictionary[i].word) == 0) {
                found = 1;
                dictionary[i].count++;
                break;
            }
        }

        if (!found) {
            printf("Possible misspelling: %s\n", word);
        }

        word = strtok(NULL, " ");
    }

    return 0;
}