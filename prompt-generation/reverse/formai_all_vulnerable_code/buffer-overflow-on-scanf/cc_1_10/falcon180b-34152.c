//Falcon-180B DATASET v1.0 Category: Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

typedef struct {
    Word words[MAX_WORDS];
    int numWords;
} Sentence;

void generateRandomWord(Word* word) {
    int length = rand() % MAX_WORD_LENGTH + 1;
    for (int i = 0; i < length; i++) {
        char letter = tolower(rand() % 26 + 'a');
        if (isalpha(letter)) {
            word->word[i] = letter;
        } else {
            i--;
        }
    }
    word->length = length;
}

void generateRandomSentence(Sentence* sentence) {
    sentence->numWords = rand() % 10 + 1;
    for (int i = 0; i < sentence->numWords; i++) {
        generateRandomWord(&sentence->words[i]);
    }
}

void printWords(Word* words, int numWords) {
    for (int i = 0; i < numWords; i++) {
        printf("%s ", words[i].word);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    Sentence sentence;
    generateRandomSentence(&sentence);
    printf("How many words are in the sentence? ");
    int guess;
    scanf("%d", &guess);
    if (guess == sentence.numWords) {
        printf("Correct! The words are: ");
        printWords(sentence.words, sentence.numWords);
    } else {
        printf("Incorrect. The number of words is %d.\n", sentence.numWords);
    }
    return 0;
}