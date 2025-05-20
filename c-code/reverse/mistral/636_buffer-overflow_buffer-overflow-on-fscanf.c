#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 100
#define BUFFER_SIZE 2048

typedef struct Word {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

int main() {
    FILE *file;
    char buffer[BUFFER_SIZE];
    Word words[1000];

    file = fopen("input.txt", "r");
    if (!file) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    int numWords = 0;
    while (fgets(buffer, BUFFER_SIZE, file)) {
        Word *currentWord = &words[numWords];
        strcpy(currentWord->word, buffer);
        currentWord->count = 1;
        numWords++;
    }
    fclose(file);

    for (int i = 1; i < numWords; i++) {
        for (int j = 0; j < numWords - i; j++) {
            if (strcmp(words[j].word, words[j + 1].word) > 0) {
                Word temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}
