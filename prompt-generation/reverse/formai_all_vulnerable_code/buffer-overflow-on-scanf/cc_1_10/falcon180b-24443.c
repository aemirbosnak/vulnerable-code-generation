//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_SENTENCE_LENGTH 200
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

typedef struct {
    Word words[MAX_WORDS];
    int numWords;
} Sentence;

Sentence generateSentence(int numWords) {
    Sentence sentence = {0};
    sentence.numWords = numWords;

    for (int i = 0; i < numWords; i++) {
        char word[MAX_WORD_LENGTH];
        int length = rand() % MAX_WORD_LENGTH + 1;

        for (int j = 0; j < length; j++) {
            word[j] = rand() % 26 + 'a';
        }
        word[length] = '\0';

        strcpy(sentence.words[i].word, word);
        sentence.words[i].length = length;
    }

    return sentence;
}

int main() {
    srand(time(NULL));

    int numSentences;
    printf("Enter the number of sentences you want to type: ");
    scanf("%d", &numSentences);

    int totalWords = 0;
    for (int i = 0; i < numSentences; i++) {
        Sentence sentence = generateSentence(rand() % MAX_WORDS + 1);
        totalWords += sentence.numWords;

        printf("Sentence %d:\n", i + 1);
        for (int j = 0; j < sentence.numWords; j++) {
            printf("%s ", sentence.words[j].word);
        }
        printf("\n");
    }

    printf("Total words typed: %d\n", totalWords);

    return 0;
}