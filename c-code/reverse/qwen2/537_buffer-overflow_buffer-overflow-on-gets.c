#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define WORD_LENGTH 50

int main() {
    char sentence[1000];
    int wordCount[MAX_WORDS] = {0};
    char words[MAX_WORDS][WORD_LENGTH];
    int wordIndex = 0;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    char *token = strtok(sentence, " ");
    while (token != NULL && wordIndex < MAX_WORDS) {
        strcpy(words[wordIndex], token);
        for (int i = 0; i < wordIndex; i++) {
            if (strcmp(words[i], token) == 0) {
                wordCount[i]++;
                goto nextToken;
            }
        }
        wordCount[wordIndex]++;
        wordIndex++;
nextToken:
        token = strtok(NULL, " ");
    }

    for (int i = 0; i < wordIndex; i++) {
        printf("%s: %d\n", words[i], wordCount[i]);
    }

    return 0;
}
