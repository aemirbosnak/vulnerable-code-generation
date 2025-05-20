//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 100
#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main(int argc, char *argv[]) {
    FILE *inputFile;
    char sentence[MAX_SENTENCE_LENGTH];
    char word[MAX_WORD_LENGTH];
    int sentenceLength;
    int wordLength;
    int i, j;
    WordCount *wordCounts;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    wordCounts = (WordCount *) malloc(MAX_WORDS * sizeof(WordCount));
    if (wordCounts == NULL) {
        printf("Error allocating memory\n");
        return 1;
    }

    while (fgets(sentence, MAX_SENTENCE_LENGTH, inputFile)!= NULL) {
        sentenceLength = strlen(sentence);
        for (i = 0; i < sentenceLength; i++) {
            if (isalpha(sentence[i])) {
                wordLength = 0;
                while (isalpha(sentence[i]) && wordLength < MAX_WORD_LENGTH) {
                    word[wordLength++] = tolower(sentence[i++]);
                }
                word[wordLength] = '\0';
                for (j = 0; j < MAX_WORDS; j++) {
                    if (strcmp(wordCounts[j].word, word) == 0) {
                        wordCounts[j].count++;
                        break;
                    }
                }
                if (j == MAX_WORDS) {
                    strcpy(wordCounts[j].word, word);
                    wordCounts[j].count = 1;
                }
            }
        }
    }

    fclose(inputFile);

    printf("Word Counts:\n");
    for (i = 0; i < MAX_WORDS; i++) {
        if (wordCounts[i].count > 0) {
            printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
        }
    }

    free(wordCounts);

    return 0;
}