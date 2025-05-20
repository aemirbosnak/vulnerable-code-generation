//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

Word words[MAX_WORDS];

void generateWords() {
    FILE *file = fopen("words.txt", "r");
    int wordCount = 0;
    while (fscanf(file, "%s", words[wordCount].word)!= EOF) {
        words[wordCount].length = strlen(words[wordCount].word);
        wordCount++;
    }
    fclose(file);
}

int main() {
    srand(time(NULL));
    generateWords();
    int wordIndex = rand() % MAX_WORDS;
    char word = words[wordIndex].word[0];
    int wordLength = words[wordIndex].length;
    char *correctWord = calloc(wordLength + 1, sizeof(char));
    strcpy(correctWord, words[wordIndex].word);
    printf("Type the word: ");
    for (int i = 0; i < wordLength; i++) {
        printf("*");
    }
    printf("\n");
    int startTime = clock();
    char input[MAX_WORD_LENGTH];
    scanf("%s", input);
    int endTime = clock();
    int elapsedTime = endTime - startTime;
    int correctLetters = 0;
    for (int i = 0; i < wordLength; i++) {
        if (input[i] == correctWord[i]) {
            correctLetters++;
        }
    }
    int wordsPerMinute = (60 * wordLength) / (elapsedTime / CLOCKS_PER_SEC);
    printf("You typed %d correct letters out of %d.\n", correctLetters, wordLength);
    printf("You typed at a speed of %d words per minute.\n", wordsPerMinute);
    return 0;
}