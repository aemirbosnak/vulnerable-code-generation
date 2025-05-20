//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20
#define DELAY_TIME 0.05

typedef struct {
    char word[MAX_WORD_LEN];
    int len;
    int index;
} Word;

void initWords(Word words[], int numWords) {
    FILE *fp;
    char word[MAX_WORD_LEN];
    int i;

    fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open words.txt\n");
        exit(1);
    }

    i = 0;
    while (fscanf(fp, "%s", word)!= EOF) {
        words[i].len = strlen(word);
        strcpy(words[i].word, word);
        i++;
    }

    fclose(fp);
}

void printWords(Word words[], int numWords) {
    int i;

    for (i = 0; i < numWords; i++) {
        printf("%s ", words[i].word);
    }
}

int main() {
    Word words[MAX_WORDS];
    int numWords, i, j, score;
    char input[MAX_WORD_LEN];
    int len, correct;

    initWords(words, MAX_WORDS);
    numWords = 0;

    printf("Enter the number of words: ");
    scanf("%d", &numWords);

    printf("Enter the words:\n");
    for (i = 0; i < numWords; i++) {
        scanf("%s", words[i].word);
        words[i].len = strlen(words[i].word);
        numWords++;
    }

    printf("\n");
    printf("Words:\n");
    printWords(words, numWords);

    printf("\nPress enter to start the test.\n");
    getchar();

    printf("\n");
    for (i = 0; i < numWords; i++) {
        printf("Word %d: ", i + 1);
        for (j = 0; j < words[i].len; j++) {
            printf("_");
        }
    }

    for (i = 0; i < numWords; i++) {
        printf("\n");
        printf("Word %d: ", i + 1);
        score = 0;
        correct = 0;

        while (1) {
            printf("Type the word: ");
            scanf("%s", input);

            len = strlen(input);

            if (len == words[i].len) {
                correct = 1;
                break;
            }

            if (len > words[i].len) {
                printf("Too long.\n");
            } else {
                printf("Too short.\n");
            }
        }

        if (correct) {
            score++;
        }

        printf("\n");
        printf("You scored %d/%d for word %d.\n", score, words[i].len, i + 1);
    }

    printf("\n");
    printf("Your final score is %d/%d.\n", score, numWords);

    return 0;
}