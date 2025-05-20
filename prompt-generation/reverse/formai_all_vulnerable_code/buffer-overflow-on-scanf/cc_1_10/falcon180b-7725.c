//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main() {
    FILE *fp;
    char ch;
    char filename[MAX_WORD_LENGTH];
    int i, j, k;
    WordCount word_counts[MAX_WORDS];

    printf("Enter the name of the file to read: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    for (i = 0; i < MAX_WORDS; i++) {
        word_counts[i].count = 0;
    }

    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            j = 0;
            while (isalpha(ch) && j < MAX_WORD_LENGTH - 1) {
                word_counts[i].word[j++] = tolower(ch);
                ch = fgetc(fp);
            }
            word_counts[i].word[j] = '\0';
            word_counts[i].count++;
            i++;
        }
    }

    fclose(fp);

    printf("Word\tCount\n");
    for (k = 0; k < i; k++) {
        printf("%s\t%d\n", word_counts[k].word, word_counts[k].count);
    }

    return 0;
}