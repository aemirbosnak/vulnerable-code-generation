//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: optimized
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
    FILE *fp;
    char line[MAX_WORD_LEN];
    char *token;
    WordCount words[MAX_WORDS];
    int num_words = 0;

    printf("Enter a file name: ");
    scanf("%s", line);

    fp = fopen(line, "r");
    if (fp == NULL) {
        printf("Error: file not found.\n");
        return 1;
    }

    while (fgets(line, MAX_WORD_LEN, fp)!= NULL) {
        token = strtok(line, ",.?!;:");
        while (token!= NULL) {
            if (num_words >= MAX_WORDS) {
                printf("Error: too many words in file.\n");
                return 1;
            }
            strcpy(words[num_words].word, token);
            words[num_words].count = 1;
            num_words++;
            token = strtok(NULL, ",.?!;:");
        }
    }

    fclose(fp);

    printf("Word count:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}