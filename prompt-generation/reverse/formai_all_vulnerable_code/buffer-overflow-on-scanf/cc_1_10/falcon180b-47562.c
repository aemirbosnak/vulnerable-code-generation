//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 100

typedef struct {
    char word[WORD_LENGTH];
    int count;
} WordCount;

bool isAlphabet(char c) {
    if (isalpha(c))
        return true;
    else
        return false;
}

int main() {
    setlocale(LC_ALL, "");
    FILE *fp;
    char ch;
    char word[WORD_LENGTH];
    int i = 0;
    WordCount words[MAX_WORDS];

    printf("Enter the file name: ");
    scanf("%s", word);

    fp = fopen(word, "r");

    if (fp == NULL) {
        printf("Error opening file");
        exit(0);
    }

    while ((ch = fgetc(fp))!= EOF) {
        if (isAlphabet(ch)) {
            strcat(word, &ch);
        } else {
            if (i >= MAX_WORDS) {
                printf("Error: Maximum number of words exceeded");
                exit(0);
            }

            strcpy(words[i].word, word);
            words[i].count = 1;
            i++;

            word[0] = '\0';
        }
    }

    if (i == 0) {
        printf("Error: No words found in file");
        exit(0);
    }

    for (int j = 0; j < i; j++) {
        if (words[j].count > 1) {
            printf("%s: %d\n", words[j].word, words[j].count);
        }
    }

    fclose(fp);
    return 0;
}