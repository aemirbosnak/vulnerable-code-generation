#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 255
#define BUFFER_SIZE 1024

typedef struct Word {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

int main() {
    char buffer[BUFFER_SIZE];
    Word words[MAX_WORD_LENGTH];
    int word_count = 0;

    printf("Enter a sentence: ");
    gets(buffer);

    for (int i = 0; buffer[i] != '\0'; ++i) {
        if (isspace(buffer[i])) {
            if (word_count > 0) {
                words[word_count - 1].count++;
            }
            int j = i + 1;
            while (isspace(buffer[j])) ++j;
            strncpy(words[word_count].word, &buffer[i + 1], j - (i + 1));
            words[word_count].word[j - i - 1] = '\0';
            word_count++;
            i = j;
        }
    }

    if (word_count > 0) {
        words[word_count - 1].count++;
    }

    for (int i = 0; i < word_count; ++i) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}
