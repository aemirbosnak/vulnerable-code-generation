//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 30

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordCount;

int compareWordCounts(const void* wc1, const void* wc2) {
    WordCount* a = (WordCount*) wc1;
    WordCount* b = (WordCount*) wc2;
    return a->frequency > b->frequency ? -1 : 1;
}

char* sanitizeWord(char* word) {
    char* p = word;
    while (*p != '\0') {
        if (!isalpha(*p)) {
            *p = '\0';
        } else {
            *p = tolower(*p);
        }
        p++;
    }
    return word;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Unable to open file '%s'\n", argv[1]);
        exit(1);
    }

    int count = 0;
    char word[MAX_WORD_LENGTH];
    WordCount* wordCounts = malloc(sizeof(WordCount));

    while (fscanf(file, "%s", word) != EOF) {
        sanitizeWord(word);
        if (strlen(word) == 0) {
            continue;
        }

        int found = 0;
        for (int i = 0; i < count; i++) {
            if (strcmp(wordCounts[i].word, word) == 0) {
                wordCounts[i].frequency++;
                found = 1;
                break;
            }
        }

        if (!found) {
            wordCounts = realloc(wordCounts, sizeof(WordCount) * (count + 1));
            strcpy(wordCounts[count].word, word);
            wordCounts[count].frequency = 1;
            count++;
        }
    }

    qsort(wordCounts, count, sizeof(WordCount), compareWordCounts);

    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].frequency);
    }

    free(wordCounts);
    fclose(file);
    return 0;
}