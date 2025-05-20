//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_WORDS 10
#define WORD_LENGTH 6
#define MAX_TRIES 3

int main() {
    char words[MAX_WORDS][WORD_LENGTH];
    int tries[MAX_WORDS];
    int i, j, k, correct, incorrect;
    int total_words, total_correct, total_incorrect;
    float accuracy;
    srand(time(NULL));

    for(i = 0; i < MAX_WORDS; i++) {
        words[i][0] = toupper(rand() % 26 + 'A');
        for(j = 1; j < WORD_LENGTH; j++) {
            words[i][j] = rand() % 26 + 'a';
        }
    }

    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be given %d words to type.\n", MAX_WORDS);
    printf("Each word will be displayed for %d seconds.\n", 5);
    printf("You will have %d tries to type each word correctly.\n\n", MAX_TRIES);

    for(i = 0; i < MAX_WORDS; i++) {
        printf("Word %d: %s\n", i+1, words[i]);
        for(j = 0; j < WORD_LENGTH; j++) {
            printf("_");
        }
        printf("\n");
        fflush(stdout);
        total_words++;
        correct = 0;
        incorrect = 0;
        while(correct < WORD_LENGTH && incorrect < MAX_TRIES) {
            scanf("%c", &k);
            if(k == words[i][correct]) {
                correct++;
                printf("%c", k);
            } else {
                incorrect++;
                printf("_");
            }
            fflush(stdout);
        }
        total_correct += correct;
        total_incorrect += incorrect;
        printf("\n");
    }

    accuracy = (float)total_correct / (total_correct + total_incorrect) * 100;
    printf("\nResults:\n");
    printf("Total words: %d\n", total_words);
    printf("Correctly typed words: %d\n", total_correct);
    printf("Incorrectly typed words: %d\n", total_incorrect);
    printf("Accuracy: %.2f%%\n", accuracy);

    return 0;
}