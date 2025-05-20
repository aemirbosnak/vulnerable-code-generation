//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: careful
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int compareWords(const void *p1, const void *p2) {
    WordFrequency *word1 = (WordFrequency *) p1;
    WordFrequency *word2 = (WordFrequency *) p2;
    return strcmp(word1->word, word2->word);
}

int main() {
    FILE *file;
    char word[MAX_WORD_LENGTH];
    int wordCount = 0;
    WordFrequency words[MAX_WORDS];

    printf("Enter the name of the file to check: ");
    scanf("%s", word);

    file = fopen(word, "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    while (fscanf(file, "%s", word)!= EOF) {
        if (strlen(word) > MAX_WORD_LENGTH) {
            printf("Error: Word is too long.\n");
            fclose(file);
            return 1;
        }
        int i;
        for (i = 0; i < wordCount; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].count++;
                break;
            }
        }
        if (i == wordCount) {
            if (wordCount >= MAX_WORDS) {
                printf("Error: Too many words.\n");
                fclose(file);
                return 1;
            }
            strcpy(words[wordCount].word, word);
            words[wordCount].count = 1;
            wordCount++;
        }
    }

    fclose(file);

    qsort(words, wordCount, sizeof(WordFrequency), compareWords);

    printf("Word\tFrequency\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s\t%d\n", words[i].word, words[i].count);
    }

    return 0;
}