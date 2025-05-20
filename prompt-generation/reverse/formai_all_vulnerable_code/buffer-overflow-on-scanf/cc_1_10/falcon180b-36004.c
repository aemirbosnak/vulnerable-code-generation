//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    const WordFrequency *wordA = a;
    const WordFrequency *wordB = b;
    return strcmp(wordA->word, wordB->word);
}

void readTextFile(FILE *file, char *text) {
    char c;
    int i = 0;
    while ((c = fgetc(file))!= EOF) {
        text[i++] = tolower(c);
    }
    text[i] = '\0';
}

int main() {
    char text[10000];
    WordFrequency words[MAX_WORDS];
    int numWords = 0;

    printf("Enter the name of the text file: ");
    scanf("%s", text);

    FILE *file = fopen(text, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    readTextFile(file, text);
    fclose(file);

    char *word = strtok(text, ".,!?;:\"'");
    while (word!= NULL) {
        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].count++;
                break;
            }
        }
        if (i == numWords) {
            if (numWords >= MAX_WORDS) {
                printf("Maximum number of words reached.\n");
                break;
            }
            strncpy(words[numWords].word, word, MAX_WORD_LENGTH);
            words[numWords].word[MAX_WORD_LENGTH - 1] = '\0';
            words[numWords].count = 1;
            numWords++;
        }
        word = strtok(NULL, ".,!?;:\"'");
    }

    qsort(words, numWords, sizeof(WordFrequency), compareWords);

    printf("Word\tFrequency\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s\t%d\n", words[i].word, words[i].count);
    }

    return 0;
}