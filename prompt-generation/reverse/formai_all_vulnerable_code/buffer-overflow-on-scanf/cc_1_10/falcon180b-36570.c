//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORD_COUNT 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    const WordCount *wordCountA = (const WordCount *) a;
    const WordCount *wordCountB = (const WordCount *) b;
    return strcmp(wordCountA->word, wordCountB->word);
}

int main() {
    char input[1000];
    FILE *file;
    int wordCount = 0;
    WordCount words[MAX_WORD_COUNT];

    printf("Enter the name of the file: ");
    scanf("%s", input);

    file = fopen(input, "r");
    if (file == NULL) {
        printf("File not found.\n");
        return 1;
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (wordCount >= MAX_WORD_COUNT) {
            printf("Maximum word count reached.\n");
            break;
        }
        int i;
        for (i = 0; i < wordCount; i++) {
            if (strcmp(words[i].word, word) == 0) {
                words[i].count++;
                break;
            }
        }
        if (i == wordCount) {
            strcpy(words[wordCount].word, word);
            words[wordCount].count = 1;
            wordCount++;
        }
    }

    fclose(file);

    qsort(words, wordCount, sizeof(WordCount), compareWords);

    printf("Word\tCount\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s\t%d\n", words[i].word, words[i].count);
    }

    return 0;
}