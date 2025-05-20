//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void to_lower(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int is_punctuation(char c) {
    return ispunct(c) || isspace(c);
}

int find_word(WordCount *word_counts, int num_words, const char *word) {
    for (int i = 0; i < num_words; i++) {
        if (strcmp(word_counts[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

void process_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    WordCount word_counts[MAX_WORDS] = {0};
    char word[MAX_WORD_LENGTH];
    int num_words = 0;

    while (fscanf(file, "%s", word) == 1) {
        // Remove punctuation from the word
        char clean_word[MAX_WORD_LENGTH];
        int j = 0;
        for (int i = 0; word[i]; i++) {
            if (!is_punctuation(word[i])) {
                clean_word[j++] = word[i];
            }
        }
        clean_word[j] = '\0';

        // Convert to lowercase
        to_lower(clean_word);

        // Check if the word already exists
        int index = find_word(word_counts, num_words, clean_word);
        if (index != -1) {
            word_counts[index].count++;
        } else {
            if (num_words < MAX_WORDS) {
                strcpy(word_counts[num_words].word, clean_word);
                word_counts[num_words].count = 1;
                num_words++;
            } else {
                printf("Maximum word limit reached!\n");
                break;
            }
        }
    }

    fclose(file);

    // Print the word counts
    printf("Word Frequency Count:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    process_file(argv[1]);
    return EXIT_SUCCESS;
}