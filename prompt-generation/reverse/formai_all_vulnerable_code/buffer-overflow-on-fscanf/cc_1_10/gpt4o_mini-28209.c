//GPT-4o-mini DATASET v1.0 Category: Text Summarizer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void to_lower_case(char *word) {
    for (int i = 0; word[i]; i++) {
        word[i] = tolower((unsigned char) word[i]);
    }
}

int is_valid_word(const char *word) {
    for (int i = 0; word[i]; i++) {
        if (!isalpha(word[i]) && word[i] != '-') {
            return 0;
        }
    }
    return 1;
}

int find_word_index(WordCount *wordCountArray, int uniqueWordsCount, const char *word) {
    for (int i = 0; i < uniqueWordsCount; i++) {
        if (strcmp(wordCountArray[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

void add_word(WordCount *wordCountArray, int *uniqueWordsCount, const char *word) {
    int index = find_word_index(wordCountArray, *uniqueWordsCount, word);
    if (index != -1) {
        wordCountArray[index].count++;
    } else {
        strcpy(wordCountArray[*uniqueWordsCount].word, word);
        wordCountArray[*uniqueWordsCount].count = 1;
        (*uniqueWordsCount)++;
    }
}

void sort_word_counts(WordCount *wordCountArray, int uniqueWordsCount) {
    for (int i = 0; i < uniqueWordsCount - 1; i++) {
        for (int j = 0; j < uniqueWordsCount - i - 1; j++) {
            if (wordCountArray[j].count < wordCountArray[j + 1].count) {
                WordCount temp = wordCountArray[j];
                wordCountArray[j] = wordCountArray[j + 1];
                wordCountArray[j + 1] = temp;
            }
        }
    }
}

void print_summary(WordCount *wordCountArray, int uniqueWordsCount, int topN) {
    printf("Top %d words and their counts:\n", topN);
    for (int i = 0; i < topN && i < uniqueWordsCount; i++) {
        printf("%s: %d\n", wordCountArray[i].word, wordCountArray[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    WordCount wordCountArray[MAX_WORDS];
    int uniqueWordsCount = 0;
    char word[MAX_WORD_LENGTH];

    while (fscanf(file, "%s", word) != EOF) {
        to_lower_case(word);
        if (is_valid_word(word)) {
            add_word(wordCountArray, &uniqueWordsCount, word);
        }
    }

    fclose(file);
    sort_word_counts(wordCountArray, uniqueWordsCount);

    int topN = 10; // Change this value to get more or fewer results
    print_summary(wordCountArray, uniqueWordsCount, topN);

    return EXIT_SUCCESS;
}