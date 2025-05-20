//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_LEN 50
#define ALPHABET_SIZE 26

typedef struct {
    char word[WORD_LEN];
    int count;
} Word;

void toLowerCase(char *str) {
    int i = 0;

    while (str[i] != '\0') {
        str[i] = tolower(str[i]);
        i++;
    }
}

int isAlpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int indexOf(char *arr, int size, char c) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == c) {
            return i;
        }
    }

    return -1;
}

int main() {
    FILE *file;
    char filename[100];
    char line[1024];
    Word words[MAX_WORDS];
    int numWords = 0;

    printf("Enter the file name: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        char *token = strtok(line, " .,!?\t\n");

        while (token != NULL) {
            if (numWords >= MAX_WORDS) {
                printf("Maximum number of words reached.\n");
                fclose(file);
                return 1;
            }

            toLowerCase(token);

            int firstLetterIndex = indexOf(words[numWords].word, WORD_LEN, token[0]);

            if (firstLetterIndex != -1) {
                words[numWords].count += strlen(token) - words[numWords].count;
            } else {
                strcpy(words[numWords].word, token);
                words[numWords].count = strlen(token);
                numWords++;
            }

            token = strtok(NULL, " .,!?\t\n");
        }
    }

    fclose(file);

    printf("\nWord frequencies:\n");

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}