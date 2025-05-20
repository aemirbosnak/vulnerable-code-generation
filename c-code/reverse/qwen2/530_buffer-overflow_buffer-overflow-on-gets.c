#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 256

int main() {
    char sentence[MAX_WORD_LENGTH];
    int wordCount[256] = {0};
    char *token;

    printf("Enter a sentence: ");
    gets(sentence);

    token = strtok(sentence, " ");
    while (token != NULL) {
        if (strlen(token) < MAX_WORD_LENGTH) {
            wordCount[strlen(token)]++;
        }
        token = strtok(NULL, " ");
    }

    for (int i = 1; i < 256; i++) {
        if (wordCount[i] > 0) {
            printf("%d-length words: %d\n", i, wordCount[i]);
        }
    }

    return 0;
}
