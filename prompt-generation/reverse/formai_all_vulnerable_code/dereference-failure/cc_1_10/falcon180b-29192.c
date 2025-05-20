//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50
#define MAX_SENTENCE_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

typedef struct {
    char sentence[MAX_SENTENCE_LENGTH];
    int length;
} Sentence;

void generateSentence(Sentence* sentence, Word* words, int numWords) {
    char* sentenceString = (char*)malloc(sizeof(char) * (sentence->length + 1));
    strcpy(sentenceString, sentence->sentence);

    int lastIndex = sentence->length - 1;
    for (int i = 0; i < numWords; i++) {
        int index = rand() % lastIndex;
        strcat(sentenceString, " ");
        strcat(sentenceString, words[i].word);
        strcat(sentenceString, " ");
        strcat(sentenceString, &sentenceString[index]);
    }

    strcat(sentenceString, "\n");
    printf("%s", sentenceString);

    free(sentenceString);
}

int main() {
    FILE* inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: input file not found.\n");
        return 1;
    }

    char* inputString = (char*)malloc(sizeof(char) * (MAX_SENTENCE_LENGTH + 1));
    fgets(inputString, MAX_SENTENCE_LENGTH, inputFile);

    int numWords = 0;
    Word* words = (Word*)malloc(sizeof(Word) * MAX_WORDS);
    char* token = strtok(inputString, " ");
    while (token!= NULL) {
        if (numWords >= MAX_WORDS) {
            printf("Error: too many words.\n");
            return 2;
        }

        strcpy(words[numWords].word, token);
        words[numWords].count = 1;
        numWords++;

        token = strtok(NULL, " ");
    }

    Sentence* sentence = (Sentence*)malloc(sizeof(Sentence));
    strcpy(sentence->sentence, inputString);
    sentence->length = strlen(sentence->sentence);

    srand(time(NULL));
    for (int i = 0; i < numWords; i++) {
        words[i].count++;
    }

    int totalWords = 0;
    while (totalWords < sentence->length) {
        int randIndex = rand() % numWords;
        if (words[randIndex].count > 0) {
            words[randIndex].count--;
            totalWords++;
        }
    }

    generateSentence(sentence, words, numWords);

    free(words);
    free(inputString);
    fclose(inputFile);

    return 0;
}