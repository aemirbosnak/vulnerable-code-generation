//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: excited
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

char words[MAX_WORDS][MAX_WORD_LENGTH];
int numWords = 0;

void readFile(FILE *file) {
    char c;
    int i = 0;
    int wordLength = 0;
    char word[MAX_WORD_LENGTH];

    while ((c = fgetc(file))!= EOF) {
        if (isalpha(c)) {
            word[wordLength] = c;
            wordLength++;
        } else {
            word[wordLength] = '\0';
            strcpy(words[numWords], word);
            numWords++;
            i = 0;
            wordLength = 0;
        }
    }

    if (wordLength > 0) {
        word[wordLength] = '\0';
        strcpy(words[numWords], word);
        numWords++;
    }
}

void countWords() {
    int i;
    for (i = 0; i < numWords; i++) {
        printf("%s %d\n", words[i], 1);
    }
}

int main() {
    FILE *file;
    char filename[50];

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    readFile(file);
    fclose(file);

    countWords();

    return 0;
}