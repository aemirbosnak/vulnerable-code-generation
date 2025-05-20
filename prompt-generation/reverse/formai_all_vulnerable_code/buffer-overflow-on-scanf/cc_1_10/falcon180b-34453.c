//Falcon-180B DATASET v1.0 Category: Educational ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

int compareWords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main() {
    FILE *file;
    char filename[100], line[1000];
    int i, j, numWords;
    Word words[MAX_WORDS];

    printf("Enter the name of the file: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    numWords = 0;

    while (fgets(line, 1000, file)!= NULL) {
        i = 0;
        while (line[i]!= '\0') {
            if (isalpha(line[i]) || isdigit(line[i])) {
                j = 0;
                while (line[i]!= '\0' && isalnum(line[i])) {
                    words[numWords].word[j] = line[i];
                    i++;
                    j++;
                }
                words[numWords].word[j] = '\0';
                words[numWords].count = 1;
                numWords++;
            } else {
                i++;
            }
        }
    }

    qsort(words, numWords, sizeof(Word), compareWords);

    printf("Word\tFrequency\n");

    for (i = 0; i < numWords; i++) {
        printf("%s\t%d\n", words[i].word, words[i].count);
    }

    fclose(file);

    return 0;
}