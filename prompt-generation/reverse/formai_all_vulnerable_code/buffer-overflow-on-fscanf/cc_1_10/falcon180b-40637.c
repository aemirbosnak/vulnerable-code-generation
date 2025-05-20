//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

struct WordFrequency {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

bool isWord(char c) {
    return isalpha(c);
}

void readWords(FILE* file, struct WordFrequency words[]) {
    char word[MAX_WORD_LENGTH];
    int i = 0;
    while (fscanf(file, "%s", word)!= EOF) {
        if (i >= MAX_WORDS) {
            printf("Error: too many words\n");
            exit(1);
        }
        strcpy(words[i].word, word);
        words[i].frequency = 1;
        i++;
    }
}

void countWords(char* text, struct WordFrequency words[]) {
    char word[MAX_WORD_LENGTH];
    int i = 0;
    while (*text!= '\0') {
        if (isWord(*text)) {
            strcpy(word, "");
            while (isWord(*text)) {
                strcat(word, tolower(*text));
                text++;
            }
            for (int j = 0; j < i; j++) {
                if (strcmp(words[j].word, word) == 0) {
                    words[j].frequency++;
                    break;
                }
            }
        } else {
            text++;
        }
    }
}

void printWords(struct WordFrequency words[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main() {
    FILE* file;
    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file\n");
        exit(1);
    }
    struct WordFrequency words[MAX_WORDS];
    readWords(file, words);
    fclose(file);

    char* text = (char*)malloc(MAX_WORD_LENGTH * sizeof(char));
    if (text == NULL) {
        printf("Error: could not allocate memory\n");
        exit(1);
    }
    strcpy(text, "");
    while (gets(text)!= NULL) {
        countWords(text, words);
    }

    printWords(words, MAX_WORDS);

    return 0;
}