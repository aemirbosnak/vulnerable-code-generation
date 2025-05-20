//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

struct Word {
    char word[MAX_WORD_LENGTH];
    int length;
};

void generateWords(struct Word words[], int numWords) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: could not open words.txt\n");
        exit(1);
    }

    int i = 0;
    while (i < numWords && fscanf(file, "%s", words[i].word)!= EOF) {
        words[i].length = strlen(words[i].word);
        i++;
    }

    fclose(file);
}

void printWords(struct Word words[], int numWords) {
    for (int i = 0; i < numWords; i++) {
        printf("%s (%d)\n", words[i].word, words[i].length);
    }
}

int main() {
    int numWords;
    printf("Enter the number of words to type: ");
    scanf("%d", &numWords);

    struct Word words[MAX_WORDS];
    generateWords(words, numWords);

    printf("The words to type are:\n");
    printWords(words, numWords);

    int correctWords = 0;
    int incorrectWords = 0;
    int totalWords = 0;

    clock_t startTime = clock();
    while (totalWords < numWords) {
        char input[MAX_WORD_LENGTH];
        printf("\nType a word: ");
        scanf("%s", input);

        for (int i = 0; i < numWords; i++) {
            if (strcmp(input, words[i].word) == 0) {
                correctWords++;
                totalWords++;
                break;
            }
        }

        if (totalWords == numWords) {
            break;
        }
    }

    clock_t endTime = clock();
    double elapsedTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;

    printf("\nResults:\n");
    printf("Correct words: %d\n", correctWords);
    printf("Incorrect words: %d\n", incorrectWords);
    printf("Total words: %d\n", totalWords);
    printf("Elapsed time: %.2f seconds\n", elapsedTime);

    return 0;
}