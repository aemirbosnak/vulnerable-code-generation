//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

struct Word {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

int compareWords(const void *a, const void *b) {
    struct Word *word1 = (struct Word *) a;
    struct Word *word2 = (struct Word *) b;

    return strcmp(word1->word, word2->word);
}

int main() {
    char input[MAX_WORD_LENGTH];
    char *word;
    FILE *file;
    int numWords = 0;
    struct Word *wordArray = NULL;

    printf("Enter the filename: ");
    scanf("%s", input);

    file = fopen(input, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fscanf(file, "%s", input)!= EOF) {
        word = strtok(input, ",.?!;:");
        while (word!= NULL) {
            if (numWords >= MAX_WORDS) {
                printf("Maximum number of words reached.\n");
                break;
            }

            if (strlen(word) > MAX_WORD_LENGTH) {
                printf("Word too long: %s\n", word);
                continue;
            }

            wordArray[numWords].frequency = 1;
            strcpy(wordArray[numWords].word, word);
            numWords++;

            word = strtok(NULL, ",.?!;:");
        }
    }

    fclose(file);

    qsort(wordArray, numWords, sizeof(struct Word), compareWords);

    printf("Word\t\tFrequency\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s\t\t%d\n", wordArray[i].word, wordArray[i].frequency);
    }

    return 0;
}