//Falcon-180B DATASET v1.0 Category: Text processing ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void readFile(FILE* file, char* buffer) {
    int ch;
    int i = 0;

    while ((ch = fgetc(file))!= EOF) {
        buffer[i++] = ch;
    }
    buffer[i] = '\0';
}

int compareWords(const void* a, const void* b) {
    return strcmp(*(char**)a, *(char**)b);
}

int main() {
    char filename[50];
    printf("Enter the filename: ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char buffer[100000];
    readFile(file, buffer);

    char* words[MAX_WORDS];
    int numWords = 0;

    char* wordStart = strtok(buffer, ",.?!;:\"'");
    while (wordStart!= NULL && numWords < MAX_WORDS) {
        int wordLength = strlen(wordStart);
        if (wordLength > 0 && wordLength <= MAX_WORD_LENGTH) {
            words[numWords] = strdup(wordStart);
            numWords++;
        }
        wordStart = strtok(NULL, ",.?!;:\"'");
    }

    qsort(words, numWords, sizeof(char*), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i], 1);
    }

    return 0;
}