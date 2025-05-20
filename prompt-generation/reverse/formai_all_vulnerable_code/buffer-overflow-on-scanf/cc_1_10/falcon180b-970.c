//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20
#define MIN_WPM 30

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
    int index;
} Word;

void generateWords(Word words[], int numWords) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open words.txt\n");
        exit(1);
    }
    srand(time(NULL));
    int i = 0;
    char word[MAX_WORD_LENGTH];
    while (i < numWords && fscanf(file, "%s", word)!= EOF) {
        words[i].length = strlen(word);
        strcpy(words[i].word, word);
        i++;
    }
    fclose(file);
}

void displayWords(Word words[], int numWords) {
    for (int i = 0; i < numWords; i++) {
        printf("%s\n", words[i].word);
    }
}

int main() {
    int numWords;
    printf("Enter the number of words to type: ");
    scanf("%d", &numWords);
    Word words[MAX_WORDS];
    generateWords(words, numWords);
    printf("\nYou will be typing the following words:\n");
    displayWords(words, numWords);
    printf("\nPress enter to begin the test...\n");
    getchar();
    int correctWords = 0;
    int totalWords = 0;
    int startTime = clock();
    char word[MAX_WORD_LENGTH];
    while (totalWords < numWords) {
        printf("\nType the word %d: ", totalWords + 1);
        scanf(" %s", word);
        for (int i = 0; i < numWords; i++) {
            if (strcmp(word, words[i].word) == 0) {
                correctWords++;
                break;
            }
        }
        totalWords++;
    }
    int endTime = clock();
    int elapsedTime = (endTime - startTime) / (double)CLOCKS_PER_SEC;
    int wpm = (int)round((double)correctWords * 60 / (elapsedTime / numWords));
    printf("\nYou typed %d out of %d words correctly.\n", correctWords, numWords);
    printf("Your typing speed is %d words per minute.\n", wpm);
    return 0;
}