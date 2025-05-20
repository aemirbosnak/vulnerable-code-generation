//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int main() {
    FILE *fp;
    char ch;
    char word[MAX_WORD_LEN];
    int i = 0;

    WordCount words[MAX_WORDS];

    fp = fopen("input.txt", "r");

    if (fp == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            word[i] = tolower(ch);
            i++;
        } else if (i > 0) {
            word[i] = '\0';
            for (int j = 0; j < MAX_WORDS; j++) {
                if (strcmp(words[j].word, word) == 0) {
                    words[j].count++;
                    break;
                }
            }
        }
        if (i >= MAX_WORD_LEN) {
            i = 0;
        }
    }

    fclose(fp);

    printf("Word\tFrequency\n");
    for (int j = 0; j < MAX_WORDS; j++) {
        if (strcmp(words[j].word, "")!= 0) {
            printf("%s\t%d\n", words[j].word, words[j].count);
        }
    }

    return 0;
}