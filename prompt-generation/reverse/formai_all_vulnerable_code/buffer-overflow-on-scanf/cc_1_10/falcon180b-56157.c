//Falcon-180B DATASET v1.0 Category: Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

Word words[MAX_WORDS];
int numWords;

void generateWords(int numWords, Word words[]) {
    char vowels[] = "aeiouAEIOU";
    int i, j;

    srand(time(NULL));

    for (i = 0; i < numWords; i++) {
        words[i].length = rand() % 5 + 3;
        for (j = 0; j < words[i].length; j++) {
            words[i].word[j] = vowels[rand() % strlen(vowels)];
        }
        words[i].word[words[i].length] = '\0';
    }
}

void printWords(int numWords, Word words[]) {
    int i;

    for (i = 0; i < numWords; i++) {
        printf("%s ", words[i].word);
    }
    printf("\n");
}

int main() {
    int numWords, i;

    printf("Enter the number of words to generate: ");
    scanf("%d", &numWords);

    if (numWords > MAX_WORDS || numWords < 1) {
        printf("Invalid number of words.\n");
        return 1;
    }

    generateWords(numWords, words);
    printWords(numWords, words);

    return 0;
}