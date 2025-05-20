//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    const WordCount *wordA = (const WordCount *)a;
    const WordCount *wordB = (const WordCount *)b;

    return strcmp(wordA->word, wordB->word);
}

void countWords(char *text) {
    char word[MAX_WORD_LENGTH];
    int wordCount = 0;
    int i = 0;

    while (i < strlen(text)) {
        if (isspace(text[i])) {
            word[wordCount] = '\0';
            wordCount++;
            i++;
        } else {
            strncat(word, &text[i], 1);
            i++;
        }
    }

    qsort(word, wordCount, sizeof(char), compareWords);

    for (i = 0; i < wordCount; i++) {
        printf("%s: %d\n", word[i], 1);
    }
}

int main() {
    char text[MAX_WORDS];

    printf("Enter text to count words: ");
    scanf("%[^\n]", text);

    countWords(text);

    return 0;
}