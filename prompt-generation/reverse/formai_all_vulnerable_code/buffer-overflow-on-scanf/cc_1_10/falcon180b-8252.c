//Falcon-180B DATASET v1.0 Category: Text processing ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *word1 = (WordCount *)a;
    WordCount *word2 = (WordCount *)b;
    return strcmp(word1->word, word2->word);
}

int main() {
    char text[10000];
    char word[MAX_WORD_LENGTH];
    char *token;
    FILE *file;
    int numWords = 0;
    WordCount words[MAX_WORDS];

    printf("Enter the name of the text file: ");
    scanf("%s", text);

    file = fopen(text, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fscanf(file, "%s", word)!= EOF) {
        word[strcspn(word, "\n")] = '\0';
        numWords++;
    }

    fclose(file);

    qsort(words, numWords, sizeof(WordCount), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}