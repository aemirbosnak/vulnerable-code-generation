//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: shocked
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 32

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main(int argc, char *argv[]) {
    FILE *fp;
    char ch;
    char line[1024];
    WordCount words[MAX_WORDS];
    int num_words = 0;
    int i;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open file '%s'\n", argv[1]);
        exit(2);
    }

    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            line[0] = toupper(ch);
            strncat(line, &ch, 1);
            num_words++;
        } else if (num_words > 0) {
            words[num_words - 1].count++;
            num_words = 0;
            line[0] = '\0';
        }
    }

    if (num_words > 0) {
        words[num_words - 1].count++;
    }

    fclose(fp);

    printf("Total words: %d\n", num_words);

    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}