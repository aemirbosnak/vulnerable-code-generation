//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 5000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    const WordFrequency *word1 = a;
    const WordFrequency *word2 = b;
    return strcmp(word1->word, word2->word);
}

void readWords(FILE *file, WordFrequency *words, int *numWords) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (*numWords >= MAX_WORDS) {
            printf("Error: Too many words.\n");
            exit(1);
        }
        strcpy(words[*numWords].word, word);
        words[*numWords].frequency = 0;
        (*numWords)++;
    }
}

void countWordFrequencies(char *text, WordFrequency *words, int numWords) {
    char word[MAX_WORD_LENGTH];
    int i, j, k;
    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            j = 0;
            while (isalpha(text[i + j])) {
                word[j] = tolower(text[i + j]);
                j++;
            }
            word[j] = '\0';
            for (k = 0; k < numWords; k++) {
                if (strcmp(word, words[k].word) == 0) {
                    words[k].frequency++;
                    break;
                }
            }
        }
    }
}

void printWordFrequencies(WordFrequency *words, int numWords) {
    qsort(words, numWords, sizeof(WordFrequency), compareWords);
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    WordFrequency words[MAX_WORDS];
    int numWords = 0;
    readWords(file, words, &numWords);

    char text[1000000];
    fseek(file, 0, SEEK_SET);
    fgets(text, sizeof(text), file);

    countWordFrequencies(text, words, numWords);

    printWordFrequencies(words, numWords);

    fclose(file);
    return 0;
}