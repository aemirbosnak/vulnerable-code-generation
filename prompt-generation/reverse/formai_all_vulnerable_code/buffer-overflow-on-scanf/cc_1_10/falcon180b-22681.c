//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_WORDS 50
#define MAX_WORD_LENGTH 15
#define MAX_INPUT_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
    int correct;
} Word;

void initWords(Word words[], int numWords) {
    for (int i = 0; i < numWords; i++) {
        char word[MAX_WORD_LENGTH];
        int length = rand() % MAX_WORD_LENGTH + 1;
        int correct = 0;
        for (int j = 0; j < length; j++) {
            char c = rand() % 26 + 'a';
            word[j] = c;
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                correct++;
            }
        }
        words[i].word[0] = '\0';
        strncat(words[i].word, word, length);
        words[i].length = length;
        words[i].correct = correct;
    }
}

void printWords(Word words[], int numWords) {
    for (int i = 0; i < numWords; i++) {
        printf("%s (%d/%d)\n", words[i].word, words[i].correct, words[i].length);
    }
}

int main() {
    srand(time(NULL));
    int numWords;
    printf("How many words do you want to type? ");
    scanf("%d", &numWords);
    Word words[MAX_WORDS];
    initWords(words, numWords);
    printf("Type the following words:\n");
    printWords(words, numWords);
    char input[MAX_INPUT_LENGTH];
    int correct = 0;
    int total = 0;
    for (int i = 0; i < numWords; i++) {
        printf("\nWord %d:\n", i + 1);
        fgets(input, MAX_INPUT_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';
        int inputLength = strlen(input);
        if (inputLength == words[i].length && strcasecmp(input, words[i].word) == 0) {
            correct++;
        }
        total++;
    }
    printf("\nYou typed %d words correctly out of %d.\n", correct, total);
    return 0;
}