//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int compareWords(const void* a, const void* b) {
    WordFrequency* wordA = (WordFrequency*)a;
    WordFrequency* wordB = (WordFrequency*)b;

    return strcmp(wordA->word, wordB->word);
}

int main() {
    FILE* file;
    char ch;
    char word[MAX_WORD_LENGTH] = {0};
    int wordLength = 0;
    int totalWords = 0;
    WordFrequency words[MAX_WORDS];

    file = fopen("input.txt", "r");

    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            word[wordLength++] = tolower(ch);
        } else {
            if (wordLength > 0) {
                word[wordLength] = '\0';
                totalWords++;

                for (int i = 0; i < totalWords; i++) {
                    if (strcmp(words[i].word, word) == 0) {
                        words[i].count++;
                        break;
                    }
                }

                if (totalWords >= MAX_WORDS) {
                    printf("Maximum number of words reached\n");
                    break;
                }

                strcpy(words[totalWords].word, word);
                words[totalWords].count = 1;
            }

            wordLength = 0;
        }
    }

    fclose(file);

    qsort(words, totalWords, sizeof(WordFrequency), compareWords);

    printf("Word\tFrequency\n");

    for (int i = 0; i < totalWords; i++) {
        printf("%s\t%d\n", words[i].word, words[i].count);
    }

    return 0;
}