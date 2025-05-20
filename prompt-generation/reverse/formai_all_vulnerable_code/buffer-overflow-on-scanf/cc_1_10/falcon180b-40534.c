//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 100

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int main() {
    FILE *fp;
    char ch;
    char filename[100];
    int i = 0;
    WordCount words[MAX_WORDS];

    printf("Enter filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            strcpy(words[i].word, "");
            words[i].count = 0;
            while (isalpha(ch)) {
                strcat(words[i].word, ch);
                ch = fgetc(fp);
            }
            strcat(words[i].word, " ");
            words[i].count++;
            i++;
            if (i >= MAX_WORDS) {
                printf("Maximum number of words reached\n");
                exit(1);
            }
        }
    }

    fclose(fp);

    printf("Word\tCount\n");
    for (i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            printf("%s\t%d\n", words[i].word, words[i].count);
        }
    }

    return 0;
}