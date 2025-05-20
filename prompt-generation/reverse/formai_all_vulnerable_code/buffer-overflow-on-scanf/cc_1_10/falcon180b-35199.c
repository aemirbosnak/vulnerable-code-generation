//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 100

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordFrequency;

void readWords(FILE *file, char words[MAX_WORDS][MAX_WORD_LEN]) {
    int i = 0;
    char ch;
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            words[i][0] = tolower(ch);
            int j = 1;
            while ((ch = fgetc(file))!= EOF && isalpha(ch)) {
                words[i][j++] = tolower(ch);
            }
            words[i][j] = '\0';
            i++;
        }
    }
}

void countWords(char words[MAX_WORDS][MAX_WORD_LEN], int numWords, WordFrequency freq[MAX_WORDS]) {
    for (int i = 0; i < numWords; i++) {
        int found = false;
        for (int j = 0; j < i; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                freq[j].count++;
                found = true;
                break;
            }
        }
        if (!found) {
            strcpy(freq[i].word, words[i]);
            freq[i].count = 1;
        }
    }
}

void printFreq(WordFrequency freq[MAX_WORDS], int numWords) {
    for (int i = 0; i < numWords; i++) {
        if (freq[i].count > 0) {
            printf("%s: %d\n", freq[i].word, freq[i].count);
        }
    }
}

int main() {
    FILE *file;
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    char words[MAX_WORDS][MAX_WORD_LEN];
    readWords(file, words);
    int numWords = 0;
    while (numWords < MAX_WORDS && words[numWords][0]!= '\0') {
        numWords++;
    }
    WordFrequency freq[MAX_WORDS];
    countWords(words, numWords, freq);
    printFreq(freq, numWords);
    fclose(file);
    return 0;
}