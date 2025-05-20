//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

struct Word {
    char word[MAX_WORD_LENGTH];
    int count;
};

void readWords(struct Word *words, int numWords, FILE *file) {
    char line[MAX_WORD_LENGTH];
    int i = 0;

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        int j = 0;
        while (line[j]!= '\0') {
            if (isalpha(line[j])) {
                strncat(words[i].word, &line[j], 1);
                j++;
            } else {
                if (words[i].word[0]!= '\0') {
                    words[i].count++;
                    i++;
                    strcpy(words[i].word, "");
                }
            }
        }
    }
}

void printWords(struct Word *words, int numWords) {
    for (int i = 0; i < numWords; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main() {
    char filename[MAX_WORD_LENGTH];
    printf("Enter the filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    int numWords = 0;
    struct Word *words = (struct Word *)malloc(sizeof(struct Word));

    while (fgets(filename, MAX_WORD_LENGTH, file)!= NULL) {
        numWords++;
    }

    rewind(file);
    readWords(words, numWords, file);

    printWords(words, numWords);

    free(words);
    fclose(file);

    return 0;
}