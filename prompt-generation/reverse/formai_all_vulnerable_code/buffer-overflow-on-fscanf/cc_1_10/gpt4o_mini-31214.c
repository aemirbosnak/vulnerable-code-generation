//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int add_word(WordFrequency *wordList, int *wordCount, char *word) {
    for (int i = 0; i < *wordCount; i++) {
        if (strcmp(wordList[i].word, word) == 0) {
            wordList[i].count++;
            return 0; // Word found and incremented
        }
    }
    if (*wordCount < MAX_WORDS) {
        strcpy(wordList[*wordCount].word, word);
        wordList[*wordCount].count = 1;
        (*wordCount)++;
        return 1; // New word added
    }
    return -1; // No space for new words
}

void sort_word_list(WordFrequency *wordList, int wordCount) {
    for (int i = 0; i < wordCount - 1; i++) {
        for (int j = i + 1; j < wordCount; j++) {
            if (wordList[i].count < wordList[j].count) {
                WordFrequency temp = wordList[i];
                wordList[i] = wordList[j];
                wordList[j] = temp;
            }
        }
    }
}

void print_word_frequencies(WordFrequency *wordList, int wordCount) {
    printf("Word Frequencies:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", wordList[i].word, wordList[i].count);
    }
}

void clean_word(char *word) {
    int len = strlen(word);
    while (len > 0 && !isalnum(word[len - 1])) {
        word[len - 1] = '\0';
        len--;
    }
    while (*word && !isalnum(*word)) {
        word++;
    }
}

void count_word_frequencies(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        return;
    }

    WordFrequency wordList[MAX_WORDS];
    int wordCount = 0;
    char word[MAX_WORD_LENGTH];

    while (fscanf(file, "%s", word) != EOF) {
        clean_word(word);
        to_lowercase(word);
        if (strlen(word) > 0) {
            int result = add_word(wordList, &wordCount, word);
            if (result == -1) {
                fprintf(stderr, "Word list is full. Some words may not be counted.\n");
                break;
            }
        }
    }

    fclose(file);
    sort_word_list(wordList, wordCount);
    print_word_frequencies(wordList, wordCount);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    count_word_frequencies(argv[1]);
    return EXIT_SUCCESS;
}