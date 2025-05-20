//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void loadWords(char* filename, WordCount* words) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    int numWords = 0;
    while (fscanf(file, "%s", words[numWords].word)!= EOF) {
        numWords++;
        if (numWords >= MAX_WORDS) {
            printf("Error: too many words in file %s\n", filename);
            exit(1);
        }
    }

    fclose(file);
}

int compareWords(const void* a, const void* b) {
    const WordCount* w1 = (const WordCount*)a;
    const WordCount* w2 = (const WordCount*)b;

    return strcmp(w1->word, w2->word);
}

void spellCheck(char* filename, WordCount* words) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    int wordCount = 0;
    while (fscanf(file, "%s", word)!= EOF) {
        wordCount++;
        if (wordCount >= MAX_WORD_LENGTH) {
            printf("Error: too many words in file %s\n", filename);
            exit(1);
        }

        int i;
        for (i = 0; i < strlen(word); i++) {
            if (!isalpha(word[i])) {
                word[i] = tolower(word[i]);
            }
        }

        WordCount* match = bsearch(word, words, MAX_WORDS, sizeof(WordCount), compareWords);
        if (match == NULL) {
            printf("%s is not in the dictionary\n", word);
        }
    }

    fclose(file);
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s <filename> <dictionary>\n", argv[0]);
        exit(1);
    }

    char* filename = argv[1];
    char* dictname = argv[2];

    WordCount words[MAX_WORDS];
    loadWords(dictname, words);

    spellCheck(filename, words);

    return 0;
}