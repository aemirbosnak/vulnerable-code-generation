//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int main() {
    FILE* fp;
    char filename[50];
    char ch;
    int i = 0, j;
    WordCount words[MAX_WORDS];

    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            words[i].word[j++] = tolower(ch);
        } else if (j > 0) {
            words[i].word[j] = '\0';
            i++;
            j = 0;
        }
    }

    fclose(fp);

    for (i = 0; i < MAX_WORDS; i++) {
        if (words[i].word[0]!= '\0') {
            printf("Word: %s\n", words[i].word);
            printf("Count: %d\n\n", words[i].count);
        }
    }

    return 0;
}