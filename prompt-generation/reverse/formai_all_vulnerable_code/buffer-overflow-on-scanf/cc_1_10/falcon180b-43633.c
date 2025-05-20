//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 100

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int main(int argc, char *argv[]) {
    FILE *fp;
    char ch;
    char filename[MAX_WORD_LEN];
    WordCount words[MAX_WORDS];
    int num_words = 0;
    int i;

    printf("Enter the name of the file to be read: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            strcpy(words[num_words].word, "");
            words[num_words].count = 0;
            while (isalpha(ch)) {
                strcat(words[num_words].word, &ch);
                ch = fgetc(fp);
            }
            words[num_words].count++;
            num_words++;
        }
    }

    fclose(fp);

    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}