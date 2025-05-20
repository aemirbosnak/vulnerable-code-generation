//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 50
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

void generateWords(Word words[], int numWords) {
    const char vowels[] = "aeiouAEIOU";
    const char consonants[] = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
    char word[MAX_WORD_LENGTH];
    int i;

    for (i = 0; i < numWords; i++) {
        word[0] = consonants[rand() % 26];
        int j;
        for (j = 1; j < MAX_WORD_LENGTH - 1; j++) {
            if (rand() % 2 == 0) {
                word[j] = vowels[rand() % 6];
            } else {
                word[j] = consonants[rand() % 26];
            }
        }
        word[MAX_WORD_LENGTH - 1] = '\0';
        words[i].length = strlen(word);
        strcpy(words[i].word, word);
    }
}

int main() {
    int numWords;
    Word words[MAX_WORDS];
    char input[MAX_WORD_LENGTH];
    int i, j, correctWords = 0, incorrectWords = 0;
    double elapsedTime;

    printf("Enter the number of words for the test (1 to %d): ", MAX_WORDS);
    scanf("%d", &numWords);

    srand(time(NULL));
    generateWords(words, numWords);

    for (i = 0; i < numWords; i++) {
        printf("Word %d: ", i + 1);
        for (j = 0; j < words[i].length; j++) {
            printf("_");
        }
        printf("\n");
    }

    printf("Press enter to begin the test.\n");
    getchar();

    elapsedTime = -difftime(NULL, NULL);

    while (elapsedTime < 60.0) {
        fgets(input, MAX_WORD_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, words[i].word) == 0) {
            correctWords++;
        } else {
            incorrectWords++;
        }

        i++;
        if (i == numWords) {
            i = 0;
        }

        elapsedTime = difftime(NULL, NULL);
    }

    printf("Test complete.\n");
    printf("Correct words: %d\n", correctWords);
    printf("Incorrect words: %d\n", incorrectWords);
    printf("Words per minute: %.2f\n", (double)correctWords / (elapsedTime / 60.0));

    return 0;
}