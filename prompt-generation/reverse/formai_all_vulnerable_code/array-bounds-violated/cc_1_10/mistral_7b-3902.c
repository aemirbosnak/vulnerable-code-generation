//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define WORD_LENGTH 50

typedef struct {
    char word[WORD_LENGTH];
    int count;
} Word;

void toLower(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int isSeparator(char c) {
    return (c == ' ' || c == '\n');
}

int main() {
    Word words[MAX_WORDS];
    int numWords = 0;
    char line[1024];

    while (fgets(line, sizeof(line), stdin)) {
        char tempWord[WORD_LENGTH];
        int inWord = 0;
        int i;

        for (i = 0; line[i] && (numWords < MAX_WORDS); i++) {
            if (isSeparator(line[i])) {
                if (inWord) {
                    toLower(tempWord);
                    int j;
                    for (j = 0; words[j].count; j++) {
                        if (strcmp(words[j].word, tempWord) == 0) {
                            words[j].count++;
                            break;
                        }
                    }

                    if (words[j].count == 0) {
                        strcpy(words[numWords].word, tempWord);
                        words[numWords++].count = 1;
                    }

                    inWord = 0;
                    memset(tempWord, 0, WORD_LENGTH);
                }
            } else if (!inWord) {
                tempWord[0] = line[i];
                tempWord[1] = '\0';
                inWord = 1;
            } else {
                tempWord[i - (inWord - 1)] = line[i];
                tempWord[i - (inWord - 1) + WORD_LENGTH] = '\0';
            }
        }

        if (inWord) {
            toLower(tempWord);
            int j;
            for (j = 0; words[j].count; j++) {
                if (strcmp(words[j].word, tempWord) == 0) {
                    words[j].count++;
                    break;
                }
            }

            if (words[j].count == 0) {
                strcpy(words[numWords].word, tempWord);
                words[numWords++].count = 1;
            }
        }
    }

    printf("Word frequencies:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}