//MISTRAL-7B DATASET v1.0 Category: Data mining ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_SIZE 50

typedef struct {
    char word[WORD_SIZE];
    int count;
} Word;

void toLower(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

int isAlpha(int c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int splitWord(const char *line, Word *words, int *numWords, int index) {
    int currentPosition = index;
    int wordLength = 0;

    while (line[currentPosition] && isAlpha(line[currentPosition])) {
        words[index].word[wordLength] = line[currentPosition];
        wordLength++;
        currentPosition++;
    }

    if (!line[currentPosition] && wordLength > 0) {
        words[index].word[wordLength] = '\0';
        (*numWords)++;
        return 1;
    }

    if (line[currentPosition] == ' ') {
        words[index].word[wordLength] = '\0';
        (*numWords)++;
        return 1;
    }

    return 0;
}

int main() {
    FILE *file;
    Word words[MAX_WORDS];
    int numWords = 0;

    file = fopen("data.txt", "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char line[1024];

    while (fgets(line, sizeof(line), file)) {
        toLower(line);
        int index = numWords;

        while (splitWord(line, words, &numWords, index)) {
            for (int i = 0; i < numWords - 1; i++) {
                if (strcmp(words[i].word, words[index].word) == 0) {
                    words[i].count++;
                    break;
                }
            }

            for (int i = 0; i < numWords - 1; i++) {
                if (strcmp(words[i].word, words[index].word) != 0 && words[i].count < words[index].count) {
                    Word temp = words[i];
                    words[i] = words[index];
                    words[index] = temp;
                }
            }
        }
    }

    printf("Top 10 most frequently occurring words:\n");
    for (int i = 0; i < 10 && i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    fclose(file);
    return 0;
}