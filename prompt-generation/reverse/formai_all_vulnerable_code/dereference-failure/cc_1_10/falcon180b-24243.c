//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: surrealist
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 100

struct word_count {
    char word[MAX_WORD_LEN];
    int count;
};

int main(int argc, char *argv[]) {
    FILE *fp;
    char ch;
    struct word_count words[MAX_WORDS];
    int num_words = 0;
    int i;

    if (argc!= 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: cannot open file %s\n", argv[1]);
        exit(1);
    }

    while ((ch = fgetc(fp))!= EOF) {
        if (isspace(ch)) {
            if (num_words >= MAX_WORDS) {
                printf("Error: too many words in file\n");
                exit(1);
            }
            words[num_words].word[0] = '\0';
            words[num_words].count = 0;
            num_words++;
        } else {
            if (num_words >= MAX_WORDS) {
                printf("Error: too many words in file\n");
                exit(1);
            }
            strncat(words[num_words].word, &ch, 1);
        }
    }

    if (num_words == 0) {
        printf("Error: file is empty\n");
        exit(1);
    }

    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    fclose(fp);
    return 0;
}