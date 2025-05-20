//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

int is_word_character(char c) {
    return (isalpha(c) || c == '\'');
}

int add_word(WordCount *wordCounts, int *wordCount, const char *word) {
    for (int i = 0; i < *wordCount; i++) {
        if (strcmp(wordCounts[i].word, word) == 0) {
            wordCounts[i].count++;
            return 0;
        }
    }
    if (*wordCount < MAX_WORDS) {
        strcpy(wordCounts[*wordCount].word, word);
        wordCounts[*wordCount].count = 1;
        (*wordCount)++;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    WordCount wordCounts[MAX_WORDS];
    int wordCount = 0;
    FILE *file;
    char buffer[MAX_WORD_LEN];
    char *inputSource = NULL;

    if (argc > 1) {
        // Read from file if provided as an argument
        file = fopen(argv[1], "r");
        if (file == NULL) {
            perror("Error opening file");
            return EXIT_FAILURE;
        }
    } else {
        // Use stdin if no file argument
        file = stdin;
        printf("Reading input from stdin. Press Ctrl+D to stop reading.\n");
    }

    while (fscanf(file, "%s", buffer) != EOF) {
        to_lowercase(buffer);
        
        // Filtering to keep only valid word characters
        char filtered[MAX_WORD_LEN];
        int j = 0;
        for (int i = 0; buffer[i]; i++) {
            if (is_word_character(buffer[i])) {
                filtered[j++] = buffer[i];
            }
        }
        filtered[j] = '\0';

        if (j > 0) {  // If we have a valid word
            add_word(wordCounts, &wordCount, filtered);
        }
    }

    if (file != stdin) {
        fclose(file);
    }

    // Displaying the word frequencies
    printf("\nWord Frequencies:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    return EXIT_SUCCESS;
}