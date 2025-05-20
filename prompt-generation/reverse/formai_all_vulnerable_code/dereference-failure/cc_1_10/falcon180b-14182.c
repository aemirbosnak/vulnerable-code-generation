//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORD_COUNT 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void* a, const void* b) {
    const WordCount* wc1 = (const WordCount*)a;
    const WordCount* wc2 = (const WordCount*)b;
    return strcmp(wc1->word, wc2->word);
}

int main(int argc, char** argv) {
    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    char* line = NULL;
    size_t line_size = 0;
    WordCount words[MAX_WORD_COUNT];
    int word_count = 0;

    while ((getline(&line, &line_size, file))!= -1) {
        char* word = strtok(line, " \t\r\n\f\v");
        while (word!= NULL) {
            int i;
            for (i = 0; i < word_count; i++) {
                if (strcmp(word, words[i].word) == 0) {
                    words[i].count++;
                    break;
                }
            }
            if (i == word_count) {
                if (word_count >= MAX_WORD_COUNT) {
                    printf("Error: too many unique words in file\n");
                    return 1;
                }
                strcpy(words[word_count].word, word);
                words[word_count].count = 1;
                word_count++;
            }
            word = strtok(NULL, " \t\r\n\f\v");
        }
    }

    if (word_count == 0) {
        printf("No words found in file\n");
        return 0;
    }

    qsort(words, word_count, sizeof(WordCount), compareWords);

    printf("Word count:\n");
    for (int i = 0; i < word_count; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}