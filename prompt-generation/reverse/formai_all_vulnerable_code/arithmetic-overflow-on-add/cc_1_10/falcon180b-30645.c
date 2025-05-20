//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} Word;

int main() {
    FILE *fp;
    char line[1024];
    char delim[] = ",\t\n\r\f.";
    Word words[MAX_WORDS];
    int numWords = 0;
    int totalWords = 0;
    int i, j;

    fp = fopen("spam.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        totalWords += countWords(line, delim, words, MAX_WORDS);
    }

    fclose(fp);

    printf("Total words: %d\n", totalWords);

    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}

int countWords(char *str, char *delim, Word words[], int maxWords) {
    char *p;
    int i, j, k;

    p = strtok(str, delim);
    while (p!= NULL) {
        for (i = 0; i < maxWords; i++) {
            if (strcmp(p, words[i].word) == 0) {
                words[i].count++;
                break;
            }
        }
        if (i == maxWords) {
            for (j = 0; j < maxWords; j++) {
                if (strcmp(words[j].word, "") == 0) {
                    strcpy(words[j].word, p);
                    words[j].count = 1;
                    break;
                }
            }
        }
        p = strtok(NULL, delim);
    }

    return i;
}