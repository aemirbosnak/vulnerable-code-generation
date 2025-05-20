//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

int compareWords(const void* a, const void* b) {
    const Word* wordA = (const Word*)a;
    const Word* wordB = (const Word*)b;

    return strcmp(wordA->word, wordB->word);
}

int main() {
    FILE* file;
    char filename[100];
    char line[100];
    int numWords = 0;
    Word words[MAX_WORDS];

    printf("Enter the name of the file: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, 100, file)!= NULL) {
        int wordIndex = 0;
        char* wordStart = line;
        char* wordEnd = strtok(line, ",.?!;:");

        while (wordEnd!= NULL) {
            int wordLength = strlen(wordStart);

            if (wordLength > MAX_WORD_LENGTH) {
                printf("Error: Word is too long.\n");
                exit(1);
            }

            strcpy(words[wordIndex].word, wordStart);
            words[wordIndex].count = 1;

            wordIndex++;
            wordStart = wordEnd + 1;
            wordEnd = strtok(NULL, ",.?!;:");
        }

        numWords += wordIndex;
    }

    fclose(file);

    qsort(words, numWords, sizeof(Word), compareWords);

    printf("Word Frequency:\n");

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}