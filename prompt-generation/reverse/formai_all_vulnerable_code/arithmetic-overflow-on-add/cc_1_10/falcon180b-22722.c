//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 5000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *)a;
    WordFrequency *wordB = (WordFrequency *)b;

    return strcmp(wordA->word, wordB->word);
}

void translate(char *text) {
    char word[MAX_WORD_LENGTH];
    int i, j, k, wordCount = 0;
    WordFrequency words[MAX_WORDS];

    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            word[wordCount] = tolower(text[i]);
            wordCount++;
        } else {
            word[wordCount] = '\0';
            for (j = 0; j < MAX_WORDS && words[j].count > 0; j++) {
                if (strcmp(word, words[j].word) == 0) {
                    words[j].count++;
                    break;
                }
            }
            if (j == MAX_WORDS) {
                for (k = 0; k < MAX_WORDS && words[k].count == 0; k++) {
                    strcpy(words[k].word, word);
                    words[k].count = 1;
                    break;
                }
            }
            wordCount = 0;
        }
    }

    qsort(words, MAX_WORDS, sizeof(WordFrequency), compareWords);

    for (i = 0; i < MAX_WORDS && words[i].count > 0; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    char text[1000];

    printf("Enter the text to translate: ");
    fgets(text, sizeof(text), stdin);

    translate(text);

    return 0;
}