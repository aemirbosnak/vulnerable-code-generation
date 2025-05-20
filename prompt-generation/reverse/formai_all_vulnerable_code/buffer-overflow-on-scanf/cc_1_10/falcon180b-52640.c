//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_CONSPIRACY_LENGTH 1000
#define MAX_CONSPIRACY_WORDS 100
#define MAX_WORD_LENGTH 20

struct ConspiracyTheory {
    char theory[MAX_CONSPIRACY_LENGTH];
    int length;
};

void generateTheory(struct ConspiracyTheory *theory, int wordCount) {
    int i;
    char *words[MAX_CONSPIRACY_WORDS];
    int lengths[MAX_CONSPIRACY_WORDS];

    srand(time(NULL));

    for (i = 0; i < wordCount; i++) {
        int wordLength = rand() % MAX_WORD_LENGTH + 3;
        char word[MAX_WORD_LENGTH];

        strncpy(word, "the ", strlen("the "));
        strcat(word, " ");

        while (strlen(word) < wordLength) {
            int c = rand() % 26 + 'a';
            strcat(word, &c);
        }

        words[i] = word;
        lengths[i] = strlen(word);
    }

    int totalLength = 0;
    int lastSpace = 0;

    for (i = 0; i < wordCount; i++) {
        totalLength += lengths[i];

        if (totalLength >= MAX_CONSPIRACY_LENGTH - 2) {
            break;
        }

        if (i > 0 && rand() % 2 == 0) {
            strncat(theory->theory, " ", 1);
            lastSpace = totalLength;
        }

        strncat(theory->theory, words[i], lengths[i]);
        totalLength += lengths[i];
    }

    theory->theory[totalLength] = '\0';
    theory->length = totalLength;
}

void printTheory(const struct ConspiracyTheory *theory) {
    printf("The theory is: %s\n", theory->theory);
    printf("The theory length is: %d\n", theory->length);
}

int main() {
    int wordCount;

    printf("Enter the number of words in the conspiracy theory: ");
    scanf("%d", &wordCount);

    struct ConspiracyTheory theory;
    generateTheory(&theory, wordCount);
    printTheory(&theory);

    return 0;
}