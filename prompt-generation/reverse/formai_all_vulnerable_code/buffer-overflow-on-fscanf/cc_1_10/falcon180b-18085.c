//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char english[MAX_WORD_LEN];
    char cat[MAX_WORD_LEN];
} Word;

void loadWords(Word words[]) {
    FILE *fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error loading words file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(fp, "%s %s\n", words[count].english, words[count].cat)!= EOF) {
        count++;
    }

    fclose(fp);
}

int main() {
    Word words[MAX_WORDS];
    loadWords(words);

    char input[MAX_WORD_LEN];
    printf("Enter a sentence to translate:\n");
    fgets(input, MAX_WORD_LEN, stdin);

    char output[MAX_WORD_LEN];
    int outputPos = 0;

    int inputPos = 0;
    while (input[inputPos]!= '\0') {
        int wordLen = strlen(input + inputPos);
        if (wordLen > MAX_WORD_LEN) {
            printf("Error: word too long.\n");
            return 1;
        }

        char word[MAX_WORD_LEN];
        strncpy(word, input + inputPos, wordLen);
        word[wordLen] = '\0';

        int i;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(word, words[i].english) == 0) {
                strcpy(output + outputPos, words[i].cat);
                outputPos += strlen(words[i].cat);
                break;
            }
        }

        if (i == MAX_WORDS) {
            strcpy(output + outputPos, "unknown");
            outputPos += strlen("unknown");
        }

        inputPos += wordLen + 1;
    }

    printf("Cat translation: %s\n", output);

    return 0;
}