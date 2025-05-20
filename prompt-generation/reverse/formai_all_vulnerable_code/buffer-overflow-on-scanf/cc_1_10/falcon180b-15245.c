//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

typedef struct {
    WordCount word_counts[MAX_WORDS];
    int num_words;
} WordIndex;

void initialize_word_index(WordIndex *index) {
    for (int i = 0; i < MAX_WORDS; i++) {
        index->word_counts[i].count = 0;
        index->word_counts[i].word[0] = '\0';
    }
    index->num_words = 0;
}

void add_word(WordIndex *index, char *word) {
    int word_len = strlen(word);
    if (word_len > MAX_WORD_LENGTH) {
        word_len = MAX_WORD_LENGTH;
    }
    strncpy(index->word_counts[index->num_words].word, word, word_len);
    index->word_counts[index->num_words].count++;
    index->num_words++;
}

void print_word_index(WordIndex *index) {
    for (int i = 0; i < index->num_words; i++) {
        printf("%s: %d\n", index->word_counts[i].word, index->word_counts[i].count);
    }
}

int main() {
    char input_file_name[100];
    printf("Enter input file name: ");
    scanf("%s", input_file_name);

    FILE *input_file = fopen(input_file_name, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    WordIndex index;
    initialize_word_index(&index);

    char word[MAX_WORD_LENGTH];
    while (fscanf(input_file, "%s", word)!= EOF) {
        tolower(word);
        add_word(&index, word);
    }

    fclose(input_file);

    printf("Word Index:\n");
    print_word_index(&index);

    return 0;
}