//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS_COUNT 5000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int compareWords(const void* a, const void* b) {
    const WordFrequency* wordA = (const WordFrequency*)a;
    const WordFrequency* wordB = (const WordFrequency*)b;
    return strcmp(wordA->word, wordB->word);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file '%s'.\n", argv[1]);
        exit(1);
    }

    char line[1024];
    WordFrequency words[MAX_WORDS_COUNT];
    int numWords = 0;

    while (fgets(line, sizeof(line), file)!= NULL) {
        char* wordStart = line;
        while (isspace(*wordStart)) {
            wordStart++;
        }
        char* wordEnd = wordStart;
        while (*wordEnd!= '\0' &&!isspace(*wordEnd)) {
            wordEnd++;
        }
        int wordLength = wordEnd - wordStart;
        if (wordLength > 0 && wordLength <= MAX_WORD_LENGTH) {
            strncpy(words[numWords].word, wordStart, wordLength);
            words[numWords].word[wordLength] = '\0';
            words[numWords].count++;
            numWords++;
        }
        if (numWords == MAX_WORDS_COUNT) {
            break;
        }
    }

    fclose(file);

    qsort(words, numWords, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}