//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 10
#define MAX_WORD_LENGTH 20
#define MAX_TOTAL_CHARS 200

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

void generateWords(Word words[], int numWords) {
    for (int i = 0; i < numWords; i++) {
        int length = rand() % MAX_WORD_LENGTH + 1;
        words[i].length = length;
        for (int j = 0; j < length; j++) {
            words[i].word[j] = rand() % 26 + 'a';
        }
        words[i].word[length] = '\0';
    }
}

int main() {
    srand(time(NULL));

    int numWords = rand() % MAX_WORDS + 1;
    Word words[MAX_WORDS];
    generateWords(words, numWords);

    int totalChars = 0;
    for (int i = 0; i < numWords; i++) {
        totalChars += words[i].length;
    }

    printf("Type the following words:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s\n", words[i].word);
    }

    int startTime = clock();
    int correctWords = 0;

    char input[MAX_WORD_LENGTH];
    while (scanf("%s", input)!= EOF) {
        int len = strlen(input);
        if (len > 0 && len <= MAX_WORD_LENGTH) {
            for (int i = 0; i < numWords; i++) {
                if (strcmp(input, words[i].word) == 0) {
                    correctWords++;
                    break;
                }
            }
        }
    }

    int endTime = clock();
    int timeTaken = (endTime - startTime) / CLOCKS_PER_SEC;

    printf("\nYou typed %d out of %d words correctly.\n", correctWords, numWords);
    printf("Your typing speed is %d words per minute.\n", (int)((double)correctWords / timeTaken * 60));

    return 0;
}