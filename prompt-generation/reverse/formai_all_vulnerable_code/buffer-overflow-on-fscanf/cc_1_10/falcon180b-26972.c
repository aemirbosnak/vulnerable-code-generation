//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 100

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} Word;

Word words[MAX_WORDS];
int numWords = 0;

void addWord(char* word) {
    if (numWords >= MAX_WORDS) {
        printf("Error: Too many words.\n");
        exit(1);
    }
    strcpy(words[numWords].word, word);
    words[numWords].count = 1;
    numWords++;
}

void printWords() {
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    char word[MAX_WORD_LEN];
    while (fscanf(file, "%s", word)!= EOF) {
        addWord(word);
    }

    fclose(file);
    printWords();

    return 0;
}