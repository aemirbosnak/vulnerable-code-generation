//Falcon-180B DATASET v1.0 Category: Educational ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compare(const void *a, const void *b) {
    WordCount *wc1 = (WordCount *)a;
    WordCount *wc2 = (WordCount *)b;
    return strcmp(wc1->word, wc2->word);
}

int main() {
    FILE *fp;
    char ch;
    char filename[50];
    char line[100];
    WordCount words[MAX_WORDS];
    int numWords = 0;
    int i;

    printf("Enter the name of the text file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while ((ch = fgetc(fp))!= EOF) {
        if (isspace(ch)) {
            line[numWords] = '\0';
            strcpy(words[numWords].word, line);
            words[numWords].count = 1;
            numWords++;
            memset(line, 0, strlen(line));
        } else {
            strncat(line, &ch, 1);
        }
    }

    line[numWords] = '\0';
    strcpy(words[numWords].word, line);
    words[numWords].count = 1;
    numWords++;

    fclose(fp);

    qsort(words, numWords, sizeof(WordCount), compare);

    printf("Word\tCount\n");
    for (i = 0; i < numWords; i++) {
        printf("%s\t%d\n", words[i].word, words[i].count);
    }

    return 0;
}