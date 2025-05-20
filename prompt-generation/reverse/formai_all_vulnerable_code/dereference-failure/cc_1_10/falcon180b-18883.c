//Falcon-180B DATASET v1.0 Category: Text processing ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void* a, const void* b) {
    WordCount* wordA = (WordCount*)a;
    WordCount* wordB = (WordCount*)b;
    return strcmp(wordA->word, wordB->word);
}

int main() {
    FILE* inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    char line[1000];
    while (fgets(line, sizeof(line), inputFile)!= NULL) {
        int wordCount = 0;
        char* wordStart = line;
        char* wordEnd = strtok(line, " ");
        while (wordEnd!= NULL) {
            char* nextWordStart = wordEnd + 1;
            while (isspace(*nextWordStart)) {
                nextWordStart++;
            }
            int wordLength = nextWordStart - wordEnd;
            if (wordLength > MAX_WORD_LENGTH) {
                wordLength = MAX_WORD_LENGTH;
            }
            strncpy(wordStart, wordEnd, wordLength);
            wordStart[wordLength] = '\0';
            wordCount++;
            wordEnd = strtok(NULL, " ");
        }
        if (wordCount > 0) {
            WordCount* wordArray = malloc(sizeof(WordCount) * wordCount);
            int i = 0;
            char* wordStart = line;
            char* wordEnd = strtok(line, " ");
            while (wordEnd!= NULL) {
                char* nextWordStart = wordEnd + 1;
                while (isspace(*nextWordStart)) {
                    nextWordStart++;
                }
                int wordLength = nextWordStart - wordEnd;
                if (wordLength > MAX_WORD_LENGTH) {
                    wordLength = MAX_WORD_LENGTH;
                }
                strncpy(wordArray[i].word, wordEnd, wordLength);
                wordArray[i].word[wordLength] = '\0';
                wordArray[i].count = 1;
                i++;
                wordEnd = strtok(NULL, " ");
            }
            qsort(wordArray, wordCount, sizeof(WordCount), compareWords);
            for (i = 0; i < wordCount; i++) {
                printf("%s: %d\n", wordArray[i].word, wordArray[i].count);
            }
            free(wordArray);
        }
    }

    fclose(inputFile);
    return 0;
}