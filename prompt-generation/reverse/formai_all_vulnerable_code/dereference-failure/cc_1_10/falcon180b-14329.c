//Falcon-180B DATASET v1.0 Category: Text processing ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

void read_file(FILE *fp, struct word_count words[MAX_WORDS]) {
    char ch;
    int i = 0;
    while ((ch = fgetc(fp))!= EOF) {
        if (isspace(ch)) {
            words[i].word[strlen(words[i].word) - 1] = '\0'; // remove trailing space
            i++;
        } else {
            strncat(words[i].word, &ch, 1);
        }
    }
    words[i].word[strlen(words[i].word) - 1] = '\0'; // remove trailing space
    words[i].count = 1;
}

void count_words(struct word_count words[MAX_WORDS]) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (strcmp(words[i].word, "")!= 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main() {
    FILE *fp;
    char filename[50];
    printf("Enter the name of the text file: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    struct word_count words[MAX_WORDS];
    read_file(fp, words);
    count_words(words);
    fclose(fp);
    return 0;
}