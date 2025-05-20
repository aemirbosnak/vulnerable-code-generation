//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Word {
    char* word;
    int frequency;
} Word;

void printWord(Word word) {
    printf("%s: %d\n", word.word, word.frequency);
}

int main() {
    char sentence[1000];
    printf("Enter a sentence: ");
    fgets(sentence, 1000, stdin);

    int length = strlen(sentence);
    if (sentence[length - 1] == '\n') {
        sentence[length - 1] = '\0';
    }

    Word* words = NULL;
    int numWords = 0;

    char* token = strtok(sentence, " ");
    while (token != NULL) {
        int found = 0;
        for (int i = 0; i < numWords; i++) {
            if (strcmp(words[i].word, token) == 0) {
                words[i].frequency++;
                found = 1;
                break;
            }
        }

        if (!found) {
            numWords++;
            words = realloc(words, sizeof(Word) * numWords);
            words[numWords - 1].word = malloc(sizeof(char) * (strlen(token) + 1));
            strcpy(words[numWords - 1].word, token);
            words[numWords - 1].frequency = 1;
        }

        token = strtok(NULL, " ");
    }

    printf("\nWord frequency:\n");
    for (int i = 0; i < numWords; i++) {
        printWord(words[i]);
    }

    for (int i = 0; i < numWords; i++) {
        free(words[i].word);
    }
    free(words);

    return 0;
}