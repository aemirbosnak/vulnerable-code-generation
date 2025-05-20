//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: brave
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 50

typedef struct Word {
    char word[WORD_LENGTH];
    int count;
} Word;

void toLower(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

bool isDelimiter(char c) {
    return c == ' ' || c == '\t' || c == '\n';
}

bool isAlpha(char c) {
    return (isalpha(c) || isdigit(c) || c == '_');
}

void extractWord(const char *line, Word *words, int *numWords, int index) {
    int start = index;
    bool inWord = false;

    while (*line && (*numWords < MAX_WORDS)) {
        if (isDelimiter(*line)) {
            if (inWord) {
                words[index].count++;
                int len = line - (const char *)line + start - index;
                strncpy(words[index].word, line + 1, len);
                words[index].word[len] = '\0';
                inWord = false;
                (*numWords)++;
                index++;
                if (index >= MAX_WORDS) {
                    fprintf(stderr, "Too many words!\n");
                    exit(1);
                }
                start = index;
            }
            line++;
            continue;
        }

        if (!inWord && isAlpha(*line)) {
            inWord = true;
        }

        line++;
    }

    if (inWord) {
        int len = line - (const char *)line + start - index;
        strncpy(words[index].word, line - 1, len);
        words[index].word[len] = '\0';
        words[index].count++;
        (*numWords)++;
        index++;
    }
}

int main() {
    FILE *file;
    char filename[100];
    Word words[MAX_WORDS];
    int numWords = 0;

    printf("Enter file name: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        toLower(line);
        int index = 0;
        extractWord(line, words, &numWords, index);
    }

    fclose(file);

    printf("\nWord frequencies:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}