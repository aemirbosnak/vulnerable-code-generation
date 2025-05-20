//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 50

typedef struct Word {
    char word[WORD_LENGTH];
    int count;
} Word;

void toLower(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int searchWord(Word words[], char *wordToFind, int size) {
    for (int i = 0; i < size; i++) {
        toLower(words[i].word);
        if (strstr(words[i].word, wordToFind) != NULL) {
            return i;
        }
    }
    return -1;
}

int main() {
    char fileName[100], word[WORD_LENGTH];
    int lineNumber = 1;
    FILE *file;
    Word words[MAX_WORDS];
    int numWords = 0;
    int index;

    printf("-------------------------\n");
    printf("| Welcome to Happy Word | \n");
    printf("| Count Tool            | \n");
    printf("-------------------------\n");

    printf("Enter the file name: ");
    scanf("%s", fileName);

    file = fopen(fileName, "r");

    if (file == NULL) {
        printf("Could not open the file.\n");
        return 1;
    }

    while (fgets(word, sizeof(word), file)) {
        toLower(word);
        index = searchWord(words, word, numWords);
        if (index == -1) {
            strcpy(words[numWords].word, word);
            words[numWords++].count = 1;
        } else {
            words[index].count++;
        }
        lineNumber++;
    }

    fclose(file);

    printf("\nWord\t\tCount\n");
    printf("--------------------\n");

    for (int i = 0; i < numWords; i++) {
        printf("%s\t\t%d\n", words[i].word, words[i].count);
    }

    printf("\nTotal words found: %d\n", numWords);
    printf("\nLine numbers processed: %d\n", lineNumber);

    return 0;
}