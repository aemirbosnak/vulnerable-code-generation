//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 100

struct word_frequency {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

int compare_words(const void *a, const void *b) {
    struct word_frequency *word1 = (struct word_frequency *)a;
    struct word_frequency *word2 = (struct word_frequency *)b;

    return strcmp(word1->word, word2->word);
}

int main() {
    FILE *input_file;
    char word[MAX_WORD_LENGTH];
    struct word_frequency *word_frequency_table;
    int word_count = 0;

    // Open input file
    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Read words from input file and count their frequency
    word_frequency_table = malloc(MAX_WORDS * sizeof(struct word_frequency));
    if (word_frequency_table == NULL) {
        printf("Error allocating memory for word frequency table.\n");
        exit(1);
    }

    while (fscanf(input_file, "%s", word)!= EOF) {
        if (word_count >= MAX_WORDS) {
            printf("Maximum number of words reached.\n");
            break;
        }

        // Convert word to lowercase
        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }

        // Add word to frequency table
        struct word_frequency *word_ptr = bsearch(word, word_frequency_table, word_count, sizeof(struct word_frequency), compare_words);
        if (word_ptr == NULL) {
            // Word not found in table, add it
            word_frequency_table[word_count] = (struct word_frequency) {.word = word,.frequency = 1 };
            word_count++;
        } else {
            // Word found in table, increment frequency
            word_ptr->frequency++;
        }
    }

    fclose(input_file);

    // Sort words by frequency
    qsort(word_frequency_table, word_count, sizeof(struct word_frequency), compare_words);

    // Print word frequency table
    printf("Word\tFrequency\n");
    for (int i = 0; i < word_count; i++) {
        printf("%s\t%d\n", word_frequency_table[i].word, word_frequency_table[i].frequency);
    }

    free(word_frequency_table);

    return 0;
}