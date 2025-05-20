//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000

typedef struct {
    char *word;
    int length;
} Word;

int compareWords(const void *a, const void *b) {
    Word *w1 = (Word *)a;
    Word *w2 = (Word *)b;
    return strcmp(w1->word, w2->word);
}

int main() {
    FILE *file;
    char filename[100];
    char line[1000];
    char *word;
    Word words[MAX_WORDS];
    int numWords = 0;

    printf("Enter the filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            if (numWords >= MAX_WORDS) {
                printf("Too many words.\n");
                exit(1);
            }
            words[numWords].word = strdup(word);
            words[numWords].length = strlen(word);
            numWords++;
            word = strtok(NULL, ",.?!;:");
        }
    }

    fclose(file);

    qsort(words, numWords, sizeof(Word), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s (%d)\n", words[i].word, words[i].length);
    }

    return 0;
}