//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 10
#define MAX_TEST_TIME 60

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

int main() {
    srand(time(NULL));

    Word words[MAX_WORDS];
    int numWords = 0;

    printf("Enter words to test (enter 'done' when finished):\n");
    char input[MAX_WORD_LENGTH];
    while (fgets(input, sizeof(input), stdin)) {
        if (strcmp(input, "done") == 0) {
            break;
        }
        if (numWords >= MAX_WORDS) {
            printf("Maximum number of words reached.\n");
            break;
        }
        words[numWords].length = strlen(input);
        strcpy(words[numWords].word, input);
        numWords++;
    }

    int totalChars = 0;
    for (int i = 0; i < numWords; i++) {
        totalChars += words[i].length;
    }

    int testTime = MAX_TEST_TIME;
    int numErrors = 0;

    printf("Typing test starting...\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s\n", words[i].word);
        char typedWord[MAX_WORD_LENGTH];
        fgets(typedWord, sizeof(typedWord), stdin);
        int typedLength = strlen(typedWord);
        if (typedLength!= words[i].length) {
            numErrors++;
        }
        else if (strcmp(typedWord, words[i].word)!= 0) {
            numErrors++;
        }
        else {
            int timeTaken = (int) ((double) testTime / totalChars * words[i].length);
            printf("Correct! Time taken: %d seconds\n", timeTaken);
        }
        if (numErrors >= 3) {
            printf("Test ended due to too many errors.\n");
            break;
        }
    }

    printf("Test ended.\n");

    return 0;
}