//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

int isDelimiter(char ch) {
    return isspace(ch) || ispunct(ch);
}

int findWord(WordCount *words, int n, const char *word) {
    for (int i = 0; i < n; i++) {
        if (strcmp(words[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

void addWord(WordCount *words, int *n, const char *word) {
    int index = findWord(words, *n, word);
    if (index != -1) {
        words[index].count++;
    } else {
        strcpy(words[*n].word, word);
        words[*n].count = 1;
        (*n)++;
    }
}

void sortWords(WordCount *words, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (words[j].count < words[j + 1].count) {
                WordCount temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }
}

void printWords(WordCount *words, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

void clearBuffer(char *buffer, int size) {
    for (int i = 0; i < size; i++) {
        buffer[i] = '\0';
    }
}

int main() {
    FILE *file;
    WordCount words[MAX_WORDS];
    int wordCount = 0;
    char buffer[1024];

    printf("Enter the filename (with extension): ");
    scanf("%s", buffer);

    file = fopen(buffer, "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), file)) {
        char *token = strtok(buffer, " ");
        while (token != NULL) {
            toLowerCase(token);
            if (!isDelimiter(token[0])) {
                addWord(words, &wordCount, token);
            }
            token = strtok(NULL, " ");
        }
    }
    
    fclose(file);

    sortWords(words, wordCount);
    printf("\nWord Count Result:\n");
    printWords(words, wordCount);

    return 0;
}