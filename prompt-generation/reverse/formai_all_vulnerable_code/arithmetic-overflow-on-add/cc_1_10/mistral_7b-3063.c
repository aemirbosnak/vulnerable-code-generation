//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_LEN 50

typedef struct Word {
    char word[WORD_LEN];
    int count;
} Word;

void toLower(char *str) {
    int i;
    for (i = 0; str[i]; i++)
        str[i] = tolower(str[i]);
}

int isSeparator(char c) {
    return (isspace(c) || c == '\n' || c == ',' || c == '.' || c == ';' || c == ':' || c == '!' || c == '?' || c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}');
}

void addWord(Word *words, char *str) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (strcmp(words[i].word, str) == 0) {
            words[i].count++;
            return;
        }
    }

    strcpy(words[i].word, str);
    words[i].count = 1;
}

int main() {
    int i, j, len;
    char str[1024], temp[WORD_LEN];
    Word words[MAX_WORDS];

    while (fgets(str, sizeof(str), stdin) != NULL) {
        toLower(str);
        len = strlen(str);
        for (i = 0, j = 0; i < len; i++) {
            if (isSeparator(str[i])) {
                if (j) {
                    toLower(temp);
                    addWord(words, temp);
                    j = 0;
                }
            } else {
                temp[j++] = str[i];
                if (j >= WORD_LEN - 1) break;
            }
        }

        if (j) {
            toLower(temp);
            addWord(words, temp);
        }
    }

    for (i = 0; i < MAX_WORDS; i++)
        if (words[i].count)
            printf("%s: %d\n", words[i].word, words[i].count);

    return 0;
}