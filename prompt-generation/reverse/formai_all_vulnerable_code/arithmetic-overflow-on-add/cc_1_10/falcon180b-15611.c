//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 100000
#define MAX_CHARS_PER_LINE 80

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void* a, const void* b) {
    const WordFrequency* wordA = a;
    const WordFrequency* wordB = b;

    if (wordA->frequency > wordB->frequency) {
        return -1;
    } else if (wordA->frequency < wordB->frequency) {
        return 1;
    } else {
        return 0;
    }
}

void printWordFrequencyTable(WordFrequency* words, int numWords) {
    qsort(words, numWords, sizeof(WordFrequency), compareWords);

    printf("Word\tFrequency\n");
    for (int i = 0; i < numWords; i++) {
        WordFrequency* word = &words[i];
        printf("%s\t%d\n", word->word, word->frequency);
    }
}

int main() {
    FILE* inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    char line[MAX_CHARS_PER_LINE];
    WordFrequency words[MAX_WORDS];
    int numWords = 0;

    while (fgets(line, MAX_CHARS_PER_LINE, inputFile)!= NULL) {
        int lineLength = strlen(line);
        if (lineLength > 0 && line[lineLength - 1] == '\n') {
            line[--lineLength] = '\0';
        }

        char* wordStart = line;
        while (wordStart < line + lineLength) {
            char* wordEnd = wordStart;
            while (wordEnd < line + lineLength && isalnum(*wordEnd)) {
                wordEnd++;
            }

            int wordLength = wordEnd - wordStart;
            if (wordLength > 0 && wordLength <= MAX_WORD_LENGTH) {
                strcpy(words[numWords].word, wordStart);
                words[numWords].frequency++;
                numWords++;
            }

            if (numWords >= MAX_WORDS) {
                printf("Reached maximum number of words.\n");
                break;
            }

            wordStart = wordEnd;
        }
    }

    fclose(inputFile);

    printWordFrequencyTable(words, numWords);

    return 0;
}