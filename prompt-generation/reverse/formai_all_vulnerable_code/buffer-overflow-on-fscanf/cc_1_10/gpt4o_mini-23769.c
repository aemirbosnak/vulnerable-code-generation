//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int is_word_char(char c) {
    return (isalpha(c) || c == '\'');
}

void process_input(FILE *file, WordCount *wordCountArray, int *wordCount) {
    char buffer[MAX_WORD_LENGTH];
    int in_word = 0;

    while (fscanf(file, "%s", buffer) != EOF) {
        to_lowercase(buffer);
        int len = strlen(buffer);
        
        // Sanitize the word by stripping punctuation
        int start = 0;
        while (start < len && !is_word_char(buffer[start])) {
            start++;
        }
        
        int end = len - 1;
        while (end >= 0 && !is_word_char(buffer[end])) {
            end--;
        }
        
        if (end >= start) {
            buffer[end + 1] = '\0'; // Null-terminate after the last valid char
            strcpy(wordCountArray[*wordCount].word, buffer);
            wordCountArray[*wordCount].count = 1;
            (*wordCount)++;
        }
    }
}

void count_words(WordCount *wordCountArray, int wordCount) {
    for (int i = 0; i < wordCount; i++) {
        for (int j = i + 1; j < wordCount; j++) {
            if (strcmp(wordCountArray[i].word, wordCountArray[j].word) == 0) {
                wordCountArray[i].count += wordCountArray[j].count;
                // Shift the rest of the array left
                for (int k = j; k < wordCount - 1; k++) {
                    wordCountArray[k] = wordCountArray[k + 1];
                }
                wordCount--;
                j--; // Stay on the same index
            }
        }
    }
}

void print_word_counts(const WordCount *wordCountArray, int wordCount) {
    printf("Word Frequency Count:\n");
    printf("-----------------------\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", wordCountArray[i].word, wordCountArray[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *inputFile = fopen(argv[1], "r");
    if (!inputFile) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    WordCount wordCountArray[MAX_WORDS] = {0};
    int wordCount = 0;

    process_input(inputFile, wordCountArray, &wordCount);
    fclose(inputFile);

    count_words(wordCountArray, wordCount);
    print_word_counts(wordCountArray, wordCount);

    return EXIT_SUCCESS;
}