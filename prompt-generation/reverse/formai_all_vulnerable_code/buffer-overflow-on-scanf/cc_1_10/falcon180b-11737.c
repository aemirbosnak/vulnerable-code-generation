//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct Word {
    char word[MAX_WORD_LENGTH];
    int count;
};

void readResume(FILE *fp, struct Word words[]) {
    char line[MAX_WORD_LENGTH];
    int i = 0;

    while (fgets(line, MAX_WORD_LENGTH, fp)!= NULL) {
        int len = strlen(line);
        for (int j = 0; j < len; j++) {
            if (isalpha(line[j])) {
                words[i].word[j] = tolower(line[j]);
            }
        }
        words[i].word[len] = '\0';
        words[i].count++;
        i++;
    }
}

void printWords(struct Word words[], int numWords) {
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    FILE *fp;
    char filename[50];
    printf("Enter the name of the resume file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    struct Word words[MAX_WORDS];
    int numWords = 0;

    readResume(fp, words);
    fclose(fp);

    printWords(words, numWords);

    return 0;
}