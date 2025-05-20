//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 1000

struct Word {
    char word[MAX_WORD_LENGTH];
    int length;
};

void generateRandomWord(struct Word *word) {
    int i = 0;
    char c;

    srand(time(NULL));

    while (i < MAX_WORD_LENGTH) {
        c = rand() % 26 + 'a';
        if (isalpha(c)) {
            word->word[i++] = c;
        }
    }

    word->length = i;
}

void printWords(struct Word *words, int numWords) {
    int i;

    for (i = 0; i < numWords; i++) {
        printf("%s\n", words[i].word);
    }
}

int main(int argc, char *argv[]) {
    int numWords = 10;
    struct Word words[MAX_NUM_WORDS];

    srand(time(NULL));

    printf("Enter the number of words to generate: ");
    scanf("%d", &numWords);

    printf("Generating %d random words...\n", numWords);

    int i;
    for (i = 0; i < numWords; i++) {
        generateRandomWord(&words[i]);
    }

    printf("Words generated:\n");
    printWords(words, numWords);

    return 0;
}