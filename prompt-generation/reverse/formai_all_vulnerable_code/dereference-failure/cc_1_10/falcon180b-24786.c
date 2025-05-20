//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 100
#define MAX_NUM_SENTENCES 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

typedef struct {
    int numSentences;
    int totalWords;
    WordFrequency *wordFrequencyTable;
} TextStatistics;

void initializeWordFrequencyTable(WordFrequency *wordFrequencyTable) {
    for (int i = 0; i < MAX_NUM_SENTENCES; i++) {
        wordFrequencyTable[i].frequency = 0;
    }
}

void addWordToFrequencyTable(WordFrequency *wordFrequencyTable, char *word) {
    int wordLength = strlen(word);
    if (wordLength <= MAX_WORD_LENGTH) {
        strcpy(wordFrequencyTable->word, word);
        wordFrequencyTable->frequency++;
    }
}

void printWordFrequencyTable(WordFrequency *wordFrequencyTable) {
    for (int i = 0; i < MAX_NUM_SENTENCES; i++) {
        if (wordFrequencyTable[i].frequency > 0) {
            printf("%s: %d\n", wordFrequencyTable[i].word, wordFrequencyTable[i].frequency);
        }
    }
}

void initializeTextStatistics(TextStatistics *textStats) {
    textStats->numSentences = 0;
    textStats->totalWords = 0;
    initializeWordFrequencyTable(textStats->wordFrequencyTable);
}

void processSentence(char *sentence, TextStatistics *textStats) {
    char *token = strtok(sentence, ",.?!;:");
    while (token!= NULL) {
        addWordToFrequencyTable(textStats->wordFrequencyTable, token);
        token = strtok(NULL, ",.?!;:");
    }
    textStats->totalWords += strlen(sentence) - 1;
    textStats->numSentences++;
}

void summarizeText(TextStatistics *textStats) {
    printf("Total sentences: %d\n", textStats->numSentences);
    printf("Total words: %d\n", textStats->totalWords);
    printf("Word frequency table:\n");
    printWordFrequencyTable(textStats->wordFrequencyTable);
}

int main() {
    FILE *inputFile;
    char sentence[MAX_SENTENCE_LENGTH];
    TextStatistics textStats;

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    initializeTextStatistics(&textStats);

    while (fgets(sentence, MAX_SENTENCE_LENGTH, inputFile)!= NULL) {
        processSentence(sentence, &textStats);
    }

    fclose(inputFile);
    summarizeText(&textStats);

    return 0;
}