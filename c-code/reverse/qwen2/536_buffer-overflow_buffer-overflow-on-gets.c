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
    int word_count[MAX_WORDS] = {0};
    char *word;

    printf("Enter a sentence: ");
    gets(sentence);

    word = strtok(sentence, " ");
    while (word != NULL) {
        for (int i = 0; i < MAX_WORDS; i++) {
            if (strcmp(word, word_count[i]) == 0) {
                word_count[i]++;
                break;
            }
        }
        word = strtok(NULL, " ");
    }

    for (int i = 0; i < MAX_WORDS; i++) {
        if (word_count[i] > 0) {
            printf("%s: %d\n", word_count[i], word_count[i]);
        }
    }

    return 0;
}
