//Falcon-180B DATASET v1.0 Category: Text processing ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

#define MAX_WORD_SIZE 50
#define MAX_LINE_SIZE 1000

// Data structure to store each word in the file
typedef struct _word_count {
    char word[MAX_WORD_SIZE];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *wordA = (WordCount *)a;
    WordCount *wordB = (WordCount *)b;

    return strcmp(wordA->word, wordB->word);
}

int compareWordCounts(const void *a, const void *b) {
    WordCount *wordA = (WordCount *)a;
    WordCount *wordB = (WordCount *)b;

    return wordA->count - wordB->count;
}

void printWordCounts(WordCount *wordCounts, int numWords) {
    qsort(wordCounts, numWords, sizeof(WordCount), compareWordCounts);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char filename[MAX_LINE_SIZE];
    strcpy(filename, argv[1]);

    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    WordCount wordCounts[MAX_WORD_SIZE];
    memset(wordCounts, 0, sizeof(wordCounts));

    char line[MAX_LINE_SIZE];
    while (fgets(line, sizeof(line), file)!= NULL) {
        char *token = strtok(line, ",.?!;:");

        while (token!= NULL) {
            int len = strlen(token);
            if (len > MAX_WORD_SIZE) {
                len = MAX_WORD_SIZE;
            }

            strncpy(wordCounts[len-1].word, token, MAX_WORD_SIZE);
            wordCounts[len-1].count++;

            token = strtok(NULL, ",.?!;:");
        }
    }

    fclose(file);

    printWordCounts(wordCounts, MAX_WORD_SIZE);

    return 0;
}