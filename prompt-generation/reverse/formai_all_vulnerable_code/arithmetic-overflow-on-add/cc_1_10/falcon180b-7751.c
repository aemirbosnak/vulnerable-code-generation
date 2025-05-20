//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100
#define MIN_WORD_LENGTH 3

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} Word;

int compareWords(const void *a, const void *b) {
    Word wordA = *(Word *) a;
    Word wordB = *(Word *) b;

    if (wordA.frequency > wordB.frequency) {
        return -1;
    } else if (wordA.frequency < wordB.frequency) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    FILE *fp;
    char ch;
    char word[MAX_WORD_LENGTH];
    int wordCount = 0;
    Word words[MAX_WORDS];

    // Open input file
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    // Read words from file
    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            word[0] = toupper(ch);
            word[1] = '\0';
            wordCount++;
            int i = 0;
            while (i < wordCount - 1) {
                if (strcmp(word, words[i].word) == 0) {
                    words[i].frequency++;
                    break;
                }
                i++;
            }
            if (i == wordCount - 1) {
                strcpy(words[wordCount - 1].word, word);
                words[wordCount - 1].frequency = 1;
            }
        }
    }

    // Sort words by frequency
    qsort(words, wordCount, sizeof(Word), compareWords);

    // Print top 10 words
    printf("Top 10 words by frequency:\n");
    for (int i = 0; i < 10 && i < wordCount; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }

    // Close input file
    fclose(fp);

    return 0;
}