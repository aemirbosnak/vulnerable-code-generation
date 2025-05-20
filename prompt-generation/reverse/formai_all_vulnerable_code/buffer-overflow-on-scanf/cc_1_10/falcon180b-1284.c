//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: puzzling
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

void ReadWords(FILE *fp, WordCount words[]) {
    char ch;
    int i = 0;
    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            if (i >= MAX_WORDS) {
                printf("Error: Too many words\n");
                exit(1);
            }
            words[i].word[0] = tolower(ch);
            int j = 1;
            while ((ch = fgetc(fp))!= EOF && isalpha(ch)) {
                if (j >= MAX_WORD_LENGTH) {
                    printf("Error: Word too long\n");
                    exit(1);
                }
                words[i].word[j++] = tolower(ch);
            }
            words[i].word[j] = '\0';
            words[i].count = 0;
            i++;
        }
    }
}

void TranslateWords(WordCount words[]) {
    for (int i = 0; i < strlen(words[0].word); i++) {
        char ch = words[0].word[i];
        if (isalpha(ch)) {
            ch = (ch - 'a' + 13) % 26 + 'a';
        }
        for (int j = 1; j < MAX_WORDS; j++) {
            if (strcmp(words[j].word, words[0].word) == 0) {
                words[j].word[i] = ch;
            }
        }
    }
}

void PrintWords(WordCount words[]) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (strcmp(words[i].word, "")!= 0) {
            printf("%s %d\n", words[i].word, words[i].count);
        }
    }
}

int main() {
    FILE *fp;
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found\n");
        exit(1);
    }
    WordCount words[MAX_WORDS];
    ReadWords(fp, words);
    TranslateWords(words);
    PrintWords(words);
    fclose(fp);
    return 0;
}