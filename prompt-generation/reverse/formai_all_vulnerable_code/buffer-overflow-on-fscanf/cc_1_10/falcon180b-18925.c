//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    const WordFrequency *wordA = (const WordFrequency *)a;
    const WordFrequency *wordB = (const WordFrequency *)b;

    return strcmp(wordA->word, wordB->word);
}

int main() {
    char input[MAX_WORD_LENGTH];
    char *word;
    FILE *dictionaryFile;
    WordFrequency words[MAX_WORDS];
    int numWords = 0;
    int wordIndex;

    printf("Enter the path to the dictionary file: ");
    scanf("%s", input);

    dictionaryFile = fopen(input, "r");

    if (dictionaryFile == NULL) {
        printf("Error opening dictionary file.\n");
        return 1;
    }

    while (fscanf(dictionaryFile, "%s", word)!= EOF) {
        if (numWords >= MAX_WORDS) {
            printf("Dictionary is too large.\n");
            fclose(dictionaryFile);
            return 1;
        }

        strcpy(words[numWords].word, word);
        words[numWords].count = 0;
        numWords++;
    }

    fclose(dictionaryFile);

    printf("Enter the text to check spelling:\n");
    while (fgets(input, MAX_WORD_LENGTH, stdin)!= NULL) {
        word = strtok(input, ",.?!;:");

        while (word!= NULL) {
            wordIndex = -1;

            for (int i = 0; i < numWords; i++) {
                if (strcmp(words[i].word, word) == 0) {
                    words[i].count++;
                    wordIndex = i;
                    break;
                }
            }

            if (wordIndex == -1) {
                printf("%s is not in the dictionary.\n", word);
            }

            word = strtok(NULL, ",.?!;:");
        }
    }

    qsort(words, numWords, sizeof(WordFrequency), compareWords);

    printf("Word frequencies:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}