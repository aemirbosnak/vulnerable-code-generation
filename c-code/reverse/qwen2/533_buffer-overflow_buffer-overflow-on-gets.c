#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

int main() {
    char sentence[MAX_WORDS * (MAX_WORD_LENGTH + 1)];
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int word_count = 0;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    char *token = strtok(sentence, " ");
    while (token != NULL && word_count < MAX_WORDS) {
        strcpy(words[word_count], token);
        word_count++;
        token = strtok(NULL, " ");
    }

    for (int i = 0; i < word_count; i++) {
        printf("%s appears %d time(s)\n", words[i], word_count);
    }

    return 0;
}
