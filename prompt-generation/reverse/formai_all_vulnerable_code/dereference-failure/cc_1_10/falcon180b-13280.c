//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

bool compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *)a;
    WordFrequency *wordB = (WordFrequency *)b;

    return (strcmp(wordA->word, wordB->word) < 0);
}

void printWords(WordFrequency words[], int n) {
    printf("Words and their frequencies:\n");
    for (int i = 0; i < n; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main() {
    FILE *file;
    char ch;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    WordFrequency words[MAX_WORDS];
    int numWords = 0;
    int wordLength;

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while ((read = getline(&line, &len, file))!= -1) {
        line[read - 1] = '\0'; // Replace newline character with null character
        wordLength = 0;
        while ((ch = toupper(line[wordLength]))!= '\0') {
            if (isalpha(ch)) {
                wordLength++;
            } else {
                break;
            }
        }

        if (wordLength > 0) {
            strncpy(words[numWords].word, line, MAX_WORD_LENGTH);
            words[numWords].word[MAX_WORD_LENGTH - 1] = '\0';
            words[numWords].frequency++;
            numWords++;

            if (numWords == MAX_WORDS) {
                printf("Maximum number of words reached.\n");
                break;
            }
        }
    }

    fclose(file);

    qsort(words, numWords, sizeof(WordFrequency), compareWords);

    printWords(words, numWords);

    return 0;
}