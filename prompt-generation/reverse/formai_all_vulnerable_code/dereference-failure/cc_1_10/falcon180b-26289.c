//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

struct WordCount {
    char word[MAX_WORD_LENGTH];
    int count;
};

int compareWords(const void *a, const void *b) {
    struct WordCount *wordA = (struct WordCount *)a;
    struct WordCount *wordB = (struct WordCount *)b;

    return strcmp(wordA->word, wordB->word);
}

void countWords(char *text, int *wordCount, struct WordCount *wordArray) {
    char *word = strtok(text, ",.?!;:\"'");
    while (word!= NULL) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            if (!isalpha(word[i])) {
                word[i] = '\0';
                break;
            }
        }
        strcpy(wordArray[(*wordCount)++].word, word);
        word = strtok(NULL, ",.?!;:\"'");
    }
}

void printWordArray(int count, struct WordCount *wordArray) {
    qsort(wordArray, count, sizeof(struct WordCount), compareWords);

    printf("Word\tCount\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%d\n", wordArray[i].word, wordArray[i].count);
    }
}

int main(int argc, char **argv) {
    FILE *file = NULL;
    char *text = NULL;
    int wordCount = 0;
    struct WordCount *wordArray = NULL;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    text = (char *)malloc(fileSize + 1);
    fread(text, fileSize, 1, file);
    text[fileSize] = '\0';

    wordArray = (struct WordCount *)malloc(sizeof(struct WordCount) * 1000);
    countWords(text, &wordCount, wordArray);

    printWordArray(wordCount, wordArray);

    free(text);
    free(wordArray);
    fclose(file);

    return 0;
}