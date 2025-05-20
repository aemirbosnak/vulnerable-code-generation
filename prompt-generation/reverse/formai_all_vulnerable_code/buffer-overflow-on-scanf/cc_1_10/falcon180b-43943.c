//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 1000
#define MIN_WORD_LENGTH 3
#define MIN_WORD_CHARS 26
#define MAX_WORD_CHARS 26

#define MAX_WORDS 1000
#define MIN_WORDS 1
#define MIN_WORD_LENGTH 3
#define MAX_WORD_LENGTH 10

typedef struct {
    char *word;
    int length;
} Word;

Word *generateWords(int numWords, int minLength, int maxLength) {
    Word *words = malloc(numWords * sizeof(Word));
    for (int i = 0; i < numWords; i++) {
        int length = rand() % (maxLength - minLength + 1) + minLength;
        char *word = malloc(length + 1);
        for (int j = 0; j < length; j++) {
            word[j] = rand() % 26 + 'a';
        }
        word[length] = '\0';
        words[i].word = word;
        words[i].length = length;
    }
    return words;
}

int main() {
    srand(time(NULL));
    int numWords, minLength, maxLength;
    printf("Enter number of words: ");
    scanf("%d", &numWords);
    printf("Enter minimum word length: ");
    scanf("%d", &minLength);
    printf("Enter maximum word length: ");
    scanf("%d", &maxLength);
    if (numWords < MIN_WORDS || numWords > MAX_WORDS) {
        printf("Invalid number of words.\n");
        return 1;
    }
    if (minLength < MIN_WORD_LENGTH || minLength > MAX_WORD_LENGTH) {
        printf("Invalid minimum word length.\n");
        return 1;
    }
    if (maxLength < minLength || maxLength > MAX_WORD_LENGTH) {
        printf("Invalid maximum word length.\n");
        return 1;
    }
    Word *words = generateWords(numWords, minLength, maxLength);
    printf("Enter your name: ");
    char name[MAX_WORD_LENGTH];
    scanf("%s", name);
    int correctWords = 0;
    int totalWords = 0;
    for (int i = 0; i < numWords; i++) {
        printf("\nWord %d:\n", i + 1);
        printf("Length: %d\n", words[i].length);
        printf("Word:   ");
        for (int j = 0; j < words[i].length; j++) {
            printf("_");
        }
        printf("\n");
        char input[MAX_WORD_LENGTH];
        scanf("%s", input);
        if (strcmp(input, words[i].word) == 0) {
            correctWords++;
        }
        totalWords++;
        printf("\n");
    }
    printf("Your typing speed is %d WPM.\n", (int)((float)correctWords / (5.0 * totalWords) * 60));
    free(words);
    return 0;
}