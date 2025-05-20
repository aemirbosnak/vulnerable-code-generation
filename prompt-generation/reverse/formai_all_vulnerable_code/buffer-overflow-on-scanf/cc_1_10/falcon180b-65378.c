//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: detailed
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define WORDS_PER_MINUTE_GOAL 60
#define WORDS_PER_MINUTE_THRESHOLD 80

#define WORD_LENGTH 5
#define WORD_DELIMITER " "
#define WORD_FILE "words.txt"

typedef struct {
    char word[WORD_LENGTH + 1];
    int length;
} Word;

void loadWords(Word* words, int maxWords) {
    FILE* file = fopen(WORD_FILE, "r");
    if (file == NULL) {
        printf("Error: Could not open %s\n", WORD_FILE);
        exit(1);
    }

    int numWords = 0;
    Word word;
    while (fscanf(file, "%s", word.word) == 1) {
        if (numWords >= maxWords) {
            break;
        }

        word.length = strlen(word.word);
        if (word.length < WORD_LENGTH) {
            continue;
        }

        words[numWords++] = word;
    }

    fclose(file);
}

int main() {
    srand(time(NULL));

    int numWords;
    printf("Enter the number of words to type: ");
    scanf("%d", &numWords);

    Word* words = malloc(sizeof(Word) * numWords);
    loadWords(words, numWords);

    int numCorrect = 0;
    int numIncorrect = 0;
    int numSkipped = 0;

    char input[WORD_LENGTH + 1];
    int i = 0;
    int wordsPerMinute = 0;
    clock_t start = clock();

    while (i < numWords) {
        Word word = words[i];
        printf("%s ", word.word);

        fflush(stdout);
        if (scanf("%s", input)!= 1) {
            printf("\n");
            continue;
        }

        if (strcmp(input, word.word) == 0) {
            numCorrect++;
        } else {
            numIncorrect++;
        }

        i++;

        if (clock() - start >= CLOCKS_PER_SEC) {
            wordsPerMinute = (i - numSkipped) * CLOCKS_PER_SEC / (clock() - start);
            start = clock();
        }
    }

    free(words);

    printf("\n");
    printf("Words per minute: %d\n", wordsPerMinute);
    printf("Correct words: %d\n", numCorrect);
    printf("Incorrect words: %d\n", numIncorrect);

    return 0;
}