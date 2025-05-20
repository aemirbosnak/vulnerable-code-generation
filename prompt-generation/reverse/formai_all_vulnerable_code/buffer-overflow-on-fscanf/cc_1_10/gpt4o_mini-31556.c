//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: accurate
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

int compare(const void *a, const void *b) {
    return strcmp(((WordCount *)a)->word, ((WordCount *)b)->word);
}

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <textfile>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    WordCount wordCounts[MAX_WORDS] = {0};
    int totalWords = 0;
    char word[MAX_WORD_LENGTH];

    while (fscanf(file, "%s", word) == 1) {
        to_lowercase(word);
        int found = 0;

        for (int i = 0; i < totalWords; i++) {
            if (strcmp(wordCounts[i].word, word) == 0) {
                wordCounts[i].count++;
                found = 1;
                break;
            }
        }

        if (!found && totalWords < MAX_WORDS) {
            strcpy(wordCounts[totalWords].word, word);
            wordCounts[totalWords].count = 1;
            totalWords++;
        }
    }

    fclose(file);

    qsort(wordCounts, totalWords, sizeof(WordCount), compare);

    printf("Word Frequency Count:\n");
    for (int i = 0; i < totalWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    return 0;
}