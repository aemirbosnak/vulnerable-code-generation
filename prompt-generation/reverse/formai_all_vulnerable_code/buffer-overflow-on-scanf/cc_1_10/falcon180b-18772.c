//Falcon-180B DATASET v1.0 Category: Text processing ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_file(FILE *fp, char *filename) {
    char ch;
    int in_word = 0;
    char word[MAX_WORD_LENGTH];
    WordCount words[MAX_WORDS];
    int num_words = 0;
    int i;

    while ((ch = fgetc(fp))!= EOF) {
        if (isspace(ch)) {
            if (in_word) {
                in_word = 0;
                strcpy(word, "");
            }
        } else {
            if (!in_word) {
                in_word = 1;
                strcpy(word, "");
            }
            strcat(word, &ch);
        }
    }

    if (in_word) {
        strcpy(word, "");
    }

    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    FILE *fp;
    char filename[100];

    printf("Enter filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    read_file(fp, filename);

    fclose(fp);
    return 0;
}