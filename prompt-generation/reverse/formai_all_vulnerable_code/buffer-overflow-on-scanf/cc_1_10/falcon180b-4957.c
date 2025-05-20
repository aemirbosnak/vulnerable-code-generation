//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LENGTH 100
#define MAX_WORDS 100
#define MAX_CHARS 26

typedef struct {
    char word[MAX_LENGTH];
    int length;
} Word;

typedef struct {
    Word words[MAX_WORDS];
    int numWords;
} Sentence;

void initSentence(Sentence *sentence) {
    sentence->numWords = 0;
}

void addWord(Sentence *sentence, char *word) {
    sentence->words[sentence->numWords].length = strlen(word);
    strcpy(sentence->words[sentence->numWords].word, word);
    sentence->numWords++;
}

void printSentence(Sentence *sentence) {
    for (int i = 0; i < sentence->numWords; i++) {
        printf("%s ", sentence->words[i].word);
    }
    printf("\n");
}

int main() {
    char sentence[MAX_LENGTH];
    int length;
    Sentence sentenceStruct;
    Word wordStruct;

    initSentence(&sentenceStruct);

    printf("Enter sentence: ");
    scanf("%s", sentence);

    length = strlen(sentence);

    for (int i = 0; i < length; i++) {
        if (isalpha(sentence[i])) {
            wordStruct.length = 0;
            while (isalpha(sentence[i]) && wordStruct.length < MAX_LENGTH) {
                strncat(wordStruct.word, &sentence[i], 1);
                i++;
                wordStruct.length++;
            }
            addWord(&sentenceStruct, wordStruct.word);
        } else if (isspace(sentence[i])) {
            sentence[i] = '\0';
            addWord(&sentenceStruct, sentence);
            strcpy(sentence, "");
        }
    }

    printSentence(&sentenceStruct);

    return 0;
}