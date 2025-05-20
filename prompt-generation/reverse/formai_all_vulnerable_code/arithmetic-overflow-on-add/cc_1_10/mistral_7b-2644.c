//MISTRAL-7B DATASET v1.0 Category: Text Summarizer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WINDOW_SIZE 10
#define VOCAB_SIZE 5000

typedef struct {
    char word[20];
    int count;
} Word;

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int isDelimiter(char c) {
    return c == ' ' || c == '\n' || c == '\t';
}

void extractWords(char *text, Word words[VOCAB_SIZE]) {
    int index = 0, wordIndex = 0;
    char word[20];

    toLowerCase(text);

    for (int i = 0; text[i]; i++) {
        if (isDelimiter(text[i])) {
            if (index > 0 && wordIndex < VOCAB_SIZE) {
                strcpy(words[wordIndex++].word, word);
                words[wordIndex - 1].count += index - strlen(word) - 1;
                index = 0;
            }
            continue;
        }

        word[index++] = text[i];

        if (index == sizeof(word) - 1) {
            if (index > 0 && wordIndex < VOCAB_SIZE) {
                strcpy(words[wordIndex++].word, word);
                words[wordIndex - 1].count += index;
                index = 0;
            }
        }
    }

    if (index > 0 && wordIndex < VOCAB_SIZE) {
        strcpy(words[wordIndex++].word, word);
        words[wordIndex - 1].count += index;
    }
}

int main() {
    char text[1000];
    Word words[VOCAB_SIZE];

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    text[strcspn(text, "\n")] = '\0';

    extractWords(text, words);

    printf("\nTop %d most frequent words:\n", WINDOW_SIZE);
    for (int i = 0, j = 0; i < VOCAB_SIZE && j < WINDOW_SIZE; i++) {
        if (words[i].count > 0) {
            printf("%d. %s - %d\n", j++, words[i].word, words[i].count);
        }
    }

    return 0;
}