//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_SENTENCE_LENGTH 1000
#define MAX_NUM_SENTENCES 100

typedef struct {
    char *word;
    int count;
} WordCount;

typedef struct {
    char *sentence;
    int length;
} Sentence;

int CompareWords(const void *a, const void *b) {
    WordCount *wordA = (WordCount *)a;
    WordCount *wordB = (WordCount *)b;

    return strcmp(wordA->word, wordB->word);
}

int CompareSentences(const void *a, const void *b) {
    Sentence *sentenceA = (Sentence *)a;
    Sentence *sentenceB = (Sentence *)b;

    return strcmp(sentenceA->sentence, sentenceB->sentence);
}

void PrintWordCounts(WordCount *wordCounts, int numWordCounts) {
    qsort(wordCounts, numWordCounts, sizeof(WordCount), CompareWords);

    for (int i = 0; i < numWordCounts; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

void PrintSentences(Sentence *sentences, int numSentences) {
    qsort(sentences, numSentences, sizeof(Sentence), CompareSentences);

    for (int i = 0; i < numSentences; i++) {
        printf("%s\n", sentences[i].sentence);
    }
}

int main() {
    FILE *fp;
    char filename[100];
    char ch;
    int numWords = 0, numSentences = 0, numChars = 0;
    char word[MAX_WORD_LENGTH];
    char sentence[MAX_SENTENCE_LENGTH];
    WordCount wordCounts[MAX_NUM_SENTENCES];
    Sentence sentences[MAX_NUM_SENTENCES];

    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while ((ch = fgetc(fp))!= EOF) {
        if (isspace(ch)) {
            strcpy(sentence, "");
            numChars = 0;
            numWords = 0;
        } else if (isalpha(ch)) {
            if (numWords >= MAX_NUM_SENTENCES) {
                printf("Error: Too many words in a sentence.\n");
                fclose(fp);
                return 1;
            }

            if (numChars >= MAX_WORD_LENGTH) {
                printf("Error: Word is too long.\n");
                fclose(fp);
                return 1;
            }

            strncat(word, &ch, 1);
            numChars++;

            if (isalpha(fgetc(fp))) {
                strncat(word, &ch, 1);
                numChars++;
            } else {
                strcpy(sentence, sentence);
                strcat(sentence, " ");
                strcat(sentence, word);
                numWords++;
                numChars = 0;
            }
        } else {
            if (numChars > 0) {
                strcpy(word, "");
                numChars = 0;
            }
        }
    }

    if (numChars > 0) {
        strcpy(word, "");
        numChars = 0;
    }

    fclose(fp);

    if (numWords > 0) {
        for (int i = 0; i < numWords; i++) {
            wordCounts[i].word = strdup(sentence);
            wordCounts[i].count = 1;
        }

        PrintWordCounts(wordCounts, numWords);
    }

    return 0;
}