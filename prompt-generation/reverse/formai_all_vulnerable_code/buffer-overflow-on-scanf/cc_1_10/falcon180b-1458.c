//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 10
#define NUM_WORDS 5

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

void generateWords(Word *words) {
    char letters[] = "abcdefghijklmnopqrstuvwxyz";
    int i, j;

    srand(time(NULL));

    for (i = 0; i < NUM_WORDS; i++) {
        int randomIndex = rand() % strlen(letters);
        char randomLetter = letters[randomIndex];
        words[i].word[0] = randomLetter;
        words[i].length = 1;

        for (j = 1; j < MAX_WORD_LENGTH; j++) {
            if (rand() % 2 == 0) {
                words[i].word[j] = randomLetter;
                words[i].length++;
            } else {
                break;
            }
        }
    }
}

int main() {
    Word words[NUM_WORDS];
    int i, j, correctWords = 0;
    double timeTaken;

    generateWords(words);

    printf("Welcome to the Typing Speed Test!\n");
    printf("You will have 60 seconds to type as many words as possible.\n");
    printf("Press ENTER to begin.\n");

    getchar();

    time_t startTime = time(NULL);

    for (i = 0; i < NUM_WORDS; i++) {
        printf("%s ", words[i].word);
    }

    printf("\n");

    for (i = 0; i < NUM_WORDS; i++) {
        char userWord[MAX_WORD_LENGTH];
        printf("Word %d: ", i + 1);
        scanf("%s", userWord);

        if (strcmp(userWord, words[i].word) == 0) {
            correctWords++;
        }
    }

    timeTaken = difftime(time(NULL), startTime);

    printf("\nYou typed %d words correctly in %.2f seconds.\n", correctWords, timeTaken);

    return 0;
}