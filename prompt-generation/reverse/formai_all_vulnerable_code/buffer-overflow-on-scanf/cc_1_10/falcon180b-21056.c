//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main(int argc, char *argv[]) {
    char filename[MAX_WORD_LENGTH];
    char line[MAX_WORD_LENGTH];
    char *word;
    FILE *file;
    WordCount words[MAX_WORDS];
    int numWords = 0;
    int i;

    printf("Enter the name of the file: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        word = strtok(line, ",.!?;:");

        while (word!= NULL) {
            for (i = 0; i < numWords; i++) {
                if (strcmp(word, words[i].word) == 0) {
                    words[i].count++;
                    break;
                }
            }

            if (i == numWords) {
                if (numWords == MAX_WORDS) {
                    printf("Maximum number of words reached.\n");
                    exit(1);
                }

                strcpy(words[numWords].word, word);
                words[numWords].count = 1;
                numWords++;
            }

            word = strtok(NULL, ",.!?;:");
        }
    }

    fclose(file);

    qsort(words, numWords, sizeof(WordCount), compareWords);

    printf("Word\tCount\n");

    for (i = 0; i < numWords; i++) {
        printf("%s\t%d\n", words[i].word, words[i].count);
    }

    return 0;
}