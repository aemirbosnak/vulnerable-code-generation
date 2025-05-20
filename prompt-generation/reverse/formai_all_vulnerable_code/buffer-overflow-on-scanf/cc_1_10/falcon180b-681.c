//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: brave
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void readFile(FILE *file, char *buffer) {
    int ch;
    int index = 0;

    while ((ch = fgetc(file))!= EOF) {
        if (isspace(ch)) {
            buffer[index] = '\0';
            index = 0;
        } else {
            buffer[index++] = ch;
        }
    }

    if (index > 0) {
        buffer[index] = '\0';
    }
}

int compareWords(const void *a, const void *b) {
    const WordCount *wc1 = a;
    const WordCount *wc2 = b;

    return strcmp(wc1->word, wc2->word);
}

int main() {
    FILE *file;
    char filename[100];
    char buffer[1000];
    WordCount words[MAX_WORDS];
    int numWords = 0;

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    readFile(file, buffer);

    int i = 0;
    char *word = strtok(buffer, ",.?!;:\"'");

    while (word!= NULL && numWords < MAX_WORDS) {
        strcpy(words[numWords].word, word);
        words[numWords].count = 1;
        numWords++;

        word = strtok(NULL, ",.?!;:\"'");
    }

    qsort(words, numWords, sizeof(WordCount), compareWords);

    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    fclose(file);

    return 0;
}