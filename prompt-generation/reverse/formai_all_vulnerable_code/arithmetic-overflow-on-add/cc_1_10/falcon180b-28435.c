//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_SIZE 50

typedef struct {
    char word[MAX_WORD_SIZE];
    int count;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *) a;
    WordFrequency *wordB = (WordFrequency *) b;

    if (wordA->count > wordB->count) {
        return -1;
    } else if (wordA->count < wordB->count) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    FILE *file;
    char ch;
    char word[MAX_WORD_SIZE];
    int wordCount = 0;
    WordFrequency wordFrequency[MAX_WORDS];

    file = fopen("example.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            word[0] = tolower(ch);
            word[1] = '\0';
            wordCount = 0;

            while ((ch = fgetc(file))!= EOF && isalpha(ch)) {
                strcat(word, tolower(ch));
                wordCount++;
            }

            if (wordCount > 0) {
                for (int i = 0; i < MAX_WORDS; i++) {
                    if (wordFrequency[i].count == 0) {
                        strcpy(wordFrequency[i].word, word);
                        wordFrequency[i].count = 1;
                        break;
                    } else if (strcmp(wordFrequency[i].word, word) == 0) {
                        wordFrequency[i].count++;
                        break;
                    }
                }
            }
        }
    }

    fclose(file);

    qsort(wordFrequency, MAX_WORDS, sizeof(WordFrequency), compareWords);

    printf("Word\tFrequency\n");
    for (int i = 0; i < MAX_WORDS; i++) {
        if (wordFrequency[i].count > 0) {
            printf("%s\t%d\n", wordFrequency[i].word, wordFrequency[i].count);
        }
    }

    return 0;
}