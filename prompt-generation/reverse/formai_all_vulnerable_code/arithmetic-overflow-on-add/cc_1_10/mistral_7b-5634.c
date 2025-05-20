//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 50

typedef struct Word {
    char str[WORD_LENGTH];
    int count;
} Word;

void toLower(char *str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

int isSpace(char c) {
    return (c == ' ' || c == '\t' || c == '\n');
}

int splitWord(char *src, Word *words, int index) {
    int i = 0;
    int wordLen = 0;

    toLower(src);

    while (src[i] != '\0') {
        if (isSpace(src[i])) {
            if (wordLen > 0) {
                strncpy(words[index].str, words[index].str, wordLen);
                words[index].count++;
                index++;
                if (index >= MAX_WORDS) {
                    printf("Error: too many words.\n");
                    exit(EXIT_FAILURE);
                }

                wordLen = 0;
            }

            src += i + 1;
            i = 0;
            continue;
        }

        words[index].str[wordLen++] = src[i];
        src++;
        i++;
    }

    if (wordLen > 0) {
        strncpy(words[index].str, words[index].str, wordLen);
        words[index].count++;
        index++;
    }

    return index;
}

int main() {
    char input[1024];
    Word words[MAX_WORDS];
    int index = 0;

    while (fgets(input, sizeof(input), stdin) != NULL) {
        input[strcspn(input, "\n")] = '\0';
        index = splitWord(input, words, index);
    }

    for (int i = 0; i < index; i++) {
        printf("%s: %d\n", words[i].str, words[i].count);
    }

    return EXIT_SUCCESS;
}