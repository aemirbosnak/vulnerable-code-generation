//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN];
    int length;
} Word;

void loadWords(Word words[], int numWords) {
    FILE *fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open words.txt!\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(fp, "%s", words[i].word)!= EOF) {
        words[i].length = strlen(words[i].word);
        i++;
    }

    fclose(fp);
}

int main() {
    srand(time(NULL));

    Word words[MAX_WORDS];
    int numWords = 0;

    loadWords(words, MAX_WORDS);
    numWords = rand() % MAX_WORDS;

    int correctWords = 0;
    int wrongWords = 0;
    int totalWords = 0;

    printf("Welcome to the Post-Apocalyptic Typing Speed Test!\n");
    printf("In this world, only the fastest typists survive.\n");
    printf("You have %d words to type.\n", numWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s ", words[i].word);
        fflush(stdout);

        char input[MAX_WORD_LEN];
        fgets(input, MAX_WORD_LEN, stdin);

        if (strcmp(input, words[i].word) == 0) {
            correctWords++;
        } else {
            wrongWords++;
        }

        totalWords++;
    }

    printf("\n");

    double accuracy = (double)correctWords / totalWords * 100;
    double wpm = (double)totalWords / (5.0 * numWords);

    printf("Results:\n");
    printf("Accuracy: %.2f%%\n", accuracy);
    printf("Words per minute: %.2f\n", wpm);

    return 0;
}